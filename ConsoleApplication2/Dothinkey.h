#pragma once
#include <string>
#include <Windows.h>
#include "DTCCM2_SDK/dtccm2.h"
#include "DTCCM2_SDK/imagekit.h"
#include "IniParser.h"
#include <ctime>
#include <iostream> 

class Dothinkey
{
public:
	Dothinkey();
	~Dothinkey();
public: 
	void DothinkeyEnum();   //Enumerate the dothinkey devices
	void DothinkeyOpen();   //Open Camera devices
	BOOL DothinkeyLoadIniFile(int channel);   //0 is camera 0, 1 is camera1
	BOOL DothinkeyStartCamera(int channel);
	BOOL DothinkeyGrabImage(int channel);
private: 
	BOOL SetVoltageMclk(SensorTab CurrentSensor, int iDevID, float Mclk, float Avdd, float Dvdd, float Dovdd, float Afvcc, float vpp);
	BOOL SaveRawFile(std::string sFilename, BYTE *pBUffer, UINT width, UINT height, UINT type);
	BOOL SaveBmpFile(std::string sfilename, BYTE *pBuffer, UINT width, UINT height);
	void MipiRaw10ToP10(BYTE *pIn, BYTE *pOut, int width, int height);
private: 

	SensorTab   current_sensor_a;
	SensorTab   current_sensor_b;

	ULONG		m_GrabSizeA;
	ULONG		m_GrabSizeB;

	char*       m_charCurrentDeviceA;
	char*       m_charCurrentDeviceB;

	int         m_iDevIDA;
	int         m_iDevIDB;

	float		m_fMclkA;
	float		m_fMclkB;

	float		m_fAvddA;
	float		m_fDvddA;
	float		m_fDovddA;
	float		m_fAfvccA;
	float		m_fAvddB;
	float		m_fDvddB;
	float		m_fDovddB;
	float		m_fAfvccB;

	UINT		m_uFocusPosA;
	UINT		m_uFocusPosB;

	float		m_fFrameFpsA;
	int			m_iFrameErrA;
	int			m_iFrameCntA;

	float		m_fFrameFpsB;
	int			m_iFrameErrB;
	int			m_iFrameCntB;

	float m_vppA;
	float m_vppB;
};

