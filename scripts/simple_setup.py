# Headers
import sys,getopt,os
from optparse import OptionParser
import subprocess
import pdb
import shutil
from Helpers import *
import os.path
from os import path
import socket
from os.path import expanduser

folder_list = [ '~/config/',
                '~/var/log/output/',
                '~/storage/stage/',
                '~/storage/DATALOGS/',
                '~/storage/SNAPSHOT/DEVICESNAPSHOT/',
                '~/storage/SNAPSHOT/SYSTEMSNAPSHOT/',
                '~/test/']
dependency_list = [ 'libncurses5-dev',
                    'libncursesw5-dev',
                    'libtinyxml-dev',
                    'zip',
                    'caffeine',
                    'ntp',
		    'net-tools',
            'openssh-server']
config_file_list = [    'DeviceList.json',
                        'SnapshotConfig.xml',
                        'SyncConfig.xml']

def run_setup():
    cwd = os.getcwd()
    if(os.path.basename(cwd) != "eros"):
        print(CRED + "Must be run from eros directory. Exiting." + CEND)
        return
    print(CGREEN + "Running Simple Setup..." + CEND)
    print(CGREEN + "Creating Directories..." + CEND)
    for i in range(0,len(folder_list)):
        os.system("mkdir -p " + folder_list[i])
    print(CGREEN + "Installing Dependencies via apt..." + CEND)
    for i in range(0,len(dependency_list)):
        os.system("sudo apt --yes --force-yes install " + dependency_list[i])
    print(CGREEN + "Installing other dependencies from source..." + CEND)
    home = expanduser("~")
    hostname = socket.gethostname()
    # Install json
    if(path.exists("/usr/local/include/nlohmann/json.hpp") == False):
        os.system("mkdir -p ~/other_packages/")
        os.chdir(home + "/other_packages/")
        if(path.exists(home+"/other_packages/json") == True):
            shutil.rmtree(home + "/other_packages/json/")
        os.system("git clone https://github.com/nlohmann/json.git")
        os.system("cd json")
        os.system("mkdir ~/other_packages/json/build/")
        os.chdir(home + "/other_packages/json/build")
        os.system("cmake ..")
        os.system("make")
        os.system("sudo make install")
        os.chdir(cwd)
    print(CGREEN + "Generating Default Config Files..." + CEND)
    for i in range(0,len(config_file_list)):
        with open("config/" + config_file_list[i], 'r') as in_file:
            str = in_file.read()
            str = str.replace("<HOSTNAME>",hostname)
            out_file = open(home + "/config/" + config_file_list[i], "w") 
            out_file.write(str)
            out_file.close()
    print(CGREEN + "Simple Setup Complete!!!" + CEND)


# Main
def main():
    parser = OptionParser("simple_setup.py [options]")
    (opts,args) = parser.parse_args()
    run_setup()
    

if __name__ == "__main__":
    main()
