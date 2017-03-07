/***************AUTO-GENERATED.  DO NOT EDIT********************/
/***Created on:2017-03-06 20:23:28.322768***/
#ifndef UDPMESSAGE_H
#define UDPMESSAGE_H
#include "ros/ros.h"
#include "Definitions.h"
#include "ros/time.h"
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iostream>
#include <cv_bridge/cv_bridge.h>


class UDPMessageHandler
{
public:
	enum MessageID
	{
		UDP_RemoteControl_ID = 0xAB10,
		UDP_Resource_ID = 0xAB11,
		UDP_Diagnostic_ID = 0xAB12,
		UDP_Device_ID = 0xAB13,
		UDP_ArmControl_ID = 0xAB26,
		UDP_Arm_Command_ID = 0xAB27,
		UDP_Arm_Status_ID = 0xAB30,
		UDP_Heartbeat_ID = 0xAB31,
		UDP_FindTarget_ID = 0xAB34,
		UDP_Image_ID = 0xAB35,
	};
	UDPMessageHandler();
	~UDPMessageHandler();
	int decode_RemoteControlUDP(std::vector<std::string> items,int* axis1,int* axis2,int* axis3,int* axis4,int* axis5,int* axis6,int* axis7,int* axis8,uint8_t* button1,uint8_t* button2,uint8_t* button3,uint8_t* button4,uint8_t* button5,uint8_t* button6,uint8_t* button7,uint8_t* button8);
	std::string encode_ResourceUDP(std::string Node_Name,uint16_t RAM_Mb,uint8_t CPU_Used);
	std::string encode_DiagnosticUDP(std::string DeviceName,std::string Node_Name,uint8_t System,uint8_t SubSystem,uint8_t Component,uint8_t Diagnostic_Type,uint8_t Level,uint8_t Diagnostic_Message,std::string Description);
	std::string encode_DeviceUDP(std::string DeviceParent,std::string DeviceName,std::string DeviceType,std::string Architecture);
	int decode_ArmControlUDP(std::vector<std::string> items,uint8_t* device,int* axis1,int* axis2,int* axis3,int* axis4,int* axis5,int* axis6,uint8_t* button1,uint8_t* button2,uint8_t* button3,uint8_t* button4,uint8_t* button5,uint8_t* button6);
	int decode_Arm_CommandUDP(std::vector<std::string> items,uint8_t* Command);
	std::string encode_Arm_StatusUDP(uint8_t Status);
	int decode_HeartbeatUDP(std::vector<std::string> items,std::string* Device,uint64_t* Current_Timestamp,uint64_t* Expected_Timestamp);
	int decode_FindTargetUDP(std::vector<std::string> items,std::string* SearchDevice);
	std::string encode_ImageUDP(std::string StreamName,uint32_t width,uint32_t height,cv::Mat Image);
private:
};
#endif