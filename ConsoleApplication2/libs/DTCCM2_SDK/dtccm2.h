/******************************************************************************
DTCCM�ڶ���
******************************************************************************/

#ifndef _DTCCM2_H_
#define _DTCCM2_H_

//#define _DTCALL_ _stdcall
#define _DTCALL_ 

#include "imagekit.h"

#ifdef DTCCM2_EXPORTS

	#define DTCCM_API extern "C"  __declspec(dllexport)

#else

	#define DTCCM_API extern "C"  __declspec(dllimport)

#endif

/*! \mainpage DOTHINKEY ImageKit API Manual
*
* \section ��Ʒ����
*
* - USB2.0ϵ��
* -# HS128
* -# HS280
* -# HS300
* -# HS300D
* -# HV810
* -# HV810D
* -# HV910
* -# HV910D
* - PCIEϵ��
* -# PE300
* -# PE300D
* -# PE810
* -# PE810D
* -# PE910
* -# PE910D
* -# PE350
* -# PE950
* - USB3.0ϵ��
* -# UT300
* -# UV910
* -# UH910
* -# DTLC2
* -# UH920
* -# UF920
*
*
* \section  ��˾��ַ
* http://www.dothinkey.com
* 
* 
*
* \section �ĵ������汾��¼
* -# 2013/8/22 ����DTCC2APIGuide��\n
*			   DTCCM2APIGuide�汾Ϊ��1.0.0.0��
*
* -# 2014/5/13 ������ExtI2cWrite��ExtI2cRead�����ӿ������ⲿ��չ��I2C��д��\n
*    		   DTCCM2APIGuide�汾Ϊ��1.0.2.2�� 
*
* -# 2014/5/15 ����������EEPROM����½����ϵ��豸��Ϣ�½ڣ�\n
*			   DTCCM2APIGuide�汾Ϊ��1.0.3.3��
*
*/

/* ����Ĭ�ϴ򿪵��豸ID */
#define DEFAULT_DEV_ID		0

	
/******************************************************************************
�豸��Ϣ���
******************************************************************************/
/** @defgroup group1 �豸��Ϣ���
@{

*/


/// @brief ö���豸������豸�����豸������
///
/// @param DeviceName��ö�ٵ��豸��
/// @param iDeviceNumMax��ָ��ö���豸��������
/// @param pDeviceNum��ö�ٵ��豸����
///
/// @retval DT_ERROR_OK��ö�ٲ����ɹ�
/// @retval DT_ERROR_FAILED:ö�ٲ���ʧ��
/// @retval DT_ERROR_INTERNAL_ERROR:�ڲ�����
///
/// @note ��ȡ���豸�����ַ�����Ҫ�û��������GlobalFree()����ͷš�
DTCCM_API int _DTCALL_ EnumerateDevice(char *DeviceName[],int iDeviceNumMax,int *pDeviceNum);

/// @brief ��ȡ����İ汾��ţ���������Է����Լ��İ汾��š�
///
/// @param Version:����İ汾��
///
/// @retval DT_ERROR_OK����ȡ����İ汾�ųɹ�
DTCCM_API int _DTCALL_ GetLibVersion(DWORD Version[4],int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ�̼��汾,iChipָ���ĸ�оƬ�Ĺ̼���
///
/// @param iChip��оƬ���
/// @param Version���̼��İ汾��
///
/// @retval DT_ERROR_OK����ȡָ����оƬ�̼��汾�ųɹ�
/// @retval DT_ERROR_FAILED����ȡָ����оƬ�̼��汾��ʧ��
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND��ָ����оƬ�̼���ų����˷�Χ
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_TIME_OUT����ȡ�汾�ų�ʱ
DTCCM_API int _DTCALL_ GetFwVersion(int iChip,DWORD Version[4],int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ�豸�����кš�
///
/// @param pSN�����ص��豸���к�
/// @param iBufferSize������Ҫ��ȡ���к��ֽڳ���
/// @param pRetLen������ʵ���豸���к��ֽڳ���
/// 
/// @retval DT_ERROR_OK����ȡ�豸�����кųɹ�
/// @retval DT_ERROR_FAILED����ȡ�豸�����к�ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetDeviceSN(BYTE *pSN,int iBufferSize,int *pRetLen,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ�豸��Ӳ���汾��
///
/// @param Version��Ӳ���汾��
///
/// @retval DT_ERROR_OK����ȡ�豸��Ӳ���汾�ųɹ�
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetHardwareVersion(DWORD Version[4],int iDevID=DEFAULT_DEV_ID);

/// @bfief ��ȡ�豸��Ӳ����Ϣ���ɶ����ַ����� 
///
/// @param pBuf�����ص��豸Ӳ����Ϣ
/// @param iBufferSize������Ҫ��ȡ���豸Ӳ����Ϣ�ֽڳ���
/// @param pRetLen�����ص��豸���к��ֽڳ���
///
/// @retval DT_ERROR_OK����ȡ�豸��Ӳ����Ϣ�ɹ�
/// @retval DT_ERROR_FAILED����ȡ�豸��Ӳ����Ϣʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ���� 
DTCCM_API int _DTCALL_ GetHardwareInfo(BYTE* pBuf,int iBufferSize,int *pRetLen,int iDevID=DEFAULT_DEV_ID);

/// @brief д�û��Զ�������
///
/// @param pName���û����������
/// @param iSize���û������ֽڳ��ȣ����126�ֽ�
///
/// @retval DT_ERROR_OK�������û��Զ������Ƴɹ�
/// @retval DT_ERROR_FAILED�������û��Զ�������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ���� 
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND��iSize����Խ��
DTCCM_API int _DTCALL_ WriteUserDefinedName(char *pName, int iSize, int iDevID=DEFAULT_DEV_ID);

/// @brief д�û��Զ�������
///
/// @param pName���û����������
/// @param iSize���û������ֽڳ��ȣ����126�ֽ�
/// @param bMaster: Ϊ1���õ�ǰ�豸Ϊ������ע�ⲻҪ����̨�豸����Ϊ�������ߴӻ�������һ��һ��
///
/// @retval DT_ERROR_OK�������û��Զ������Ƴɹ�
/// @retval DT_ERROR_FAILED�������û��Զ�������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ���� 
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND��iSize����Խ��
DTCCM_API int _DTCALL_ WriteUserDefinedNameEx(char *pName, int iSize ,BOOL bMaster, int iDevID=DEFAULT_DEV_ID);

/// @brief ���û��Զ�������
///
/// @param pName�������û����������
/// @param iBufferSize������Ҫ��ȡ���û������ֽڳ���
/// @param pRetLen�����ص��û������ֽڳ���
///
/// @retval DT_ERROR_OK����ȡ�û��������Ƴɹ�
/// @retval DT_ERROR_FAILED����ȡ�û���������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ���� 
DTCCM_API int _DTCALL_ ReadUserDefinedName(char *pName, int iBufferSize,int *pRetLen,int iDevID=DEFAULT_DEV_ID);

/// @brief �ж��豸�Ƿ�򿪡� 
///
/// @retval DT_ERROR_OK���豸�Ѿ����Ӵ�
/// @retval DT_ERROR_FAILED���豸û�����ӳɹ�
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ IsDevConnect(int iDevID=DEFAULT_DEV_ID);

/// @brief �����豸���ͺţ����ֲ�ͬ�Ĳ��԰塣
///
/// @retval 0x0010��HS128���԰�
/// @retval 0x0020��HS230���԰�
/// @retval 0x0030��HS300���԰�
/// @retval 0x0031��HS300D���԰�
/// @retval 0x0092��HV910���԰�
/// @retval 0x0093��HV910D���԰�
/// @retval 0x0082��HV810���԰�
/// @retval 0x0083��HV810D���԰�
///
/// @retval 0x0130��PE300���԰�
/// @retval 0x0131��PE300D���԰�
/// @retval 0x0190��PE910���԰�
///	@retval 0x0191��PE910D���԰�
/// @retval 0x0180��PE810���԰�
///	@retval 0x0181��PE810D���԰�
/// @retval 0x0132��PE350���԰�
/// @retval 0x0192��PE950���԰�
/// @retval 0x0193��MP950���԰�
///
///	@retval 0x0231��UT300���԰�
/// @retval 0x0232��UO300���԰�
/// @retval 0x0233: UM330���԰�
///	@retval 0x0292��UV910���԰�
///	@retval 0x0293��UH910���԰�
///	@retval 0x02A1��DTLC2���԰�
/// @retval 0x0295��UF920���԰�
/// @retval 0x0295��UM900���԰�
/// @retval 0x0296��MU950���԰�
/// @retval 0x0297��DMU956���԰�
/// @retval 0x0239��ULV330���԰�
/// @retval 0x0298: CMU958���԰�
/// @retval 0x0299��ULV913���԰�
/// @retval 0x029a: ULV966���԰�
/// @retval 0x029b: ULM928���԰�

///	@retval 0x0294��UH920���԰�
DTCCM_API DWORD _DTCALL_ GetKitType(int iDevID=DEFAULT_DEV_ID);

/******************************************************************************
EEPROM���
******************************************************************************/

/// @brief ��EEPROM��һ���֡�
///
/// @param uAddr��EEPROM�ļĴ�����ַ
/// @param pValue����EEPROM������
///
/// @retval DT_ERROR_OK����EEPROM�ɹ�
/// @retval DT_ERROR_FAILD����EEPROMʧ��
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ ReadWordFromEEProm(USHORT uAddr, USHORT *pValue,int iDevID=DEFAULT_DEV_ID);

/** @} */ // end of group1



/******************************************************************************
ISP���
******************************************************************************/
/** @defgroup group2 ISP���


* @{

*/

/// @brief ��ȡGAMMA����ֵ��
/// 
/// @param pGamma�����ص�GAMMA����ֵ
DTCCM_API int _DTCALL_ GetGamma(int *pGamma,int iDevID=DEFAULT_DEV_ID);

/// @brief ����GAMMAֵ��
///
/// @param iGamma�����õ�GAMMAֵ
DTCCM_API int _DTCALL_ SetGamma(int iGamma,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ�Աȶ�����ֵ��
///
/// @param pContrast�����صĶԱȶ�����ֵ
DTCCM_API int _DTCALL_ GetContrast(int *pContrast,int iDevID=DEFAULT_DEV_ID);

/// @brief ���öԱȶȡ�
///
/// @param iContrast�����öԱȶ�ֵ
DTCCM_API int _DTCALL_ SetContrast(int iContrast,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ���Ͷ�����ֵ��
///
/// @param pSaturation�����صı��Ͷ�����ֵ
DTCCM_API int _DTCALL_ GetSaturation(int *pSaturation,int iDevID=DEFAULT_DEV_ID);

/// @brief ���ñ��Ͷȡ�
///
/// @param iSaturation�����ñ��Ͷ�ֵ
DTCCM_API int _DTCALL_ SetSaturation(int iSaturation,int iDevID=DEFAULT_DEV_ID);

/// @brief ������ȡ�
///
/// @param iSharpness���������ֵ
DTCCM_API int _DTCALL_ SetSharpness(int iSharpness, int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ�������ֵ��
///
/// @param pSharpness�����ص��������ֵ
DTCCM_API int _DTCALL_ GetSharpness(int *pSharpness, int iDevID=DEFAULT_DEV_ID);

/// @brief ����������
///
/// @param iLevel����������ֵ
DTCCM_API int _DTCALL_ SetNoiseReduction(int iLevel, int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ��������ֵ��
/// 
/// @param pLevel���������õ�����ֵ
DTCCM_API int _DTCALL_ GetNoiseReduction(int *pLevel, int iDevID=DEFAULT_DEV_ID);

/// @brief ������ر������㡣
/// 
/// @param bDeadPixCleanEn��ΪTRUE���������㣬ΪFALSE�ر�������
DTCCM_API int _DTCALL_ SetDeadPixelsClean(BOOL bDeadPixCleanEn,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ�����㿪����ر�״̬��
/// 
/// @param pbDeadPixCleanEn�����������������㿪����ر�״̬
DTCCM_API int _DTCALL_ GetDeadPixelsClean(BOOL *pbDeadPixCleanEn, int iDevID=DEFAULT_DEV_ID);

/// @brief ���òʵ㷧ֵ
/// 
/// @param iHotCpth�����õĲʵ㷧ֵ�����ڷ�ֵ�����ص��ж�Ϊ�ʵ�
DTCCM_API int _DTCALL_ SetHotCpth(int iHotCpth, int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ���õĲʵ㷧ֵ
/// 
/// @param pHotCpth�����صĲʵ㷧ֵ����ֵ
DTCCM_API int _DTCALL_ GetHotCpth(int *pHotCpth, int iDevID=DEFAULT_DEV_ID);

/// @brief ���ð��㷧ֵ
/// 
/// @param iDeadCpth�����õİ��㷧ֵ��С�ڷ�ֵ�����ص��ж�Ϊ����
DTCCM_API int _DTCALL_ SetDeadCpth(int iDeadCpth, int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ���õİ��㷧ֵ
/// 
/// @param pHotCpth�����صİ��㷧ֵ����ֵ
DTCCM_API int _DTCALL_ GetDeadCpth(int *pDeadCpth, int iDevID=DEFAULT_DEV_ID);

/// @brief ����rawתrgb�㷨��
///
/// @param Algrithm��ramתrgb�㷨����ֵ,�μ��궨�塰RAWתRGB�㷨���塱
DTCCM_API int _DTCALL_ SetRaw2RgbAlgorithm(BYTE Algrithm, int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡrawתrgb�㷨����ֵ��
///
/// @param ����rawתrgb�㷨����ֵ
DTCCM_API int _DTCALL_ GetRaw2RgbAlgorithm(BYTE *pAlgrithm, int iDevID=DEFAULT_DEV_ID);

/// @brief ����RGB�������档
///
/// @param fRGain��R����ֵ
/// @param fGGain��G����ֵ
/// @param fBGain��B����ֵ
DTCCM_API int _DTCALL_ SetDigitalGain(float fRGain,float fGGain,float fBGain,int iDevID=DEFAULT_DEV_ID);

/// @brief ������ر�ɫ�ʾ���
/// 
/// @param bEnable��ΪTRUE��������ΪFALSE�رվ���
DTCCM_API int _DTCALL_ SetMatrixEnable(BOOL bEnable, int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡRGB�������档
/// 
/// @param pRGain�����ص�R��������ֵ
/// @param pGGain�����ص�G��������ֵ
/// @param pBGain�����ص�B��������ֵ
DTCCM_API int _DTCALL_ GetDigitalGain(float *pRGain,float *pGGain,float *pBGain,int iDevID=DEFAULT_DEV_ID);

/// @brief ������رհ�ƽ�⡣
///
/// @param bAWBEn����ƽ��ʹ�ܣ�ΪTRUE������ƽ�⣬ΪFALSE�رհ�ƽ��
DTCCM_API int _DTCALL_ SetAWB(BOOL bAWBEn,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ��ƽ�⿪��״̬��
///
/// @param pAwb�����صİ�ƽ��״̬
DTCCM_API int _DTCALL_ GetAWB(BOOL *pAwb,int iDevID=DEFAULT_DEV_ID);

/// @brief ������ɫ����
///
/// @param Matrix�����õ���ɫ����
DTCCM_API int _DTCALL_ SetMatrixData(float Matrix[3][3],int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ��ɫ����
///
/// @param Matrix�����ص���ɫ����
DTCCM_API int _DTCALL_ GetMatrixData(float Matrix[3][3],int iDevID=DEFAULT_DEV_ID);

/// @brief ������ر�MONOģʽ��
///
/// @param bEnable��MONOģʽʹ�ܣ�ΪTRUE����MONOģʽ��ΪFALSE�ر�MONOģʽ
DTCCM_API int _DTCALL_ SetMonoMode(BOOL bEnable,int iDevID=DEFAULT_DEV_ID);

/// @brief ������ر�ͼ��ˮƽ����
///
/// @param bEnable��ͼ��ˮƽ����ʹ�ܣ�ΪTRUE����ˮƽ����ΪFALSE�ر�ˮƽ����
DTCCM_API int _DTCALL_ SetHFlip(BOOL bEnable,int iDevID=DEFAULT_DEV_ID);

/// @brief ������ر�ͼ��ֱ����
///
/// @param bEnable��ͼ��ֱ����ʹ�ܣ�ΪTRUE������ֱ����ΪFALSE�رմ�ֱ����
DTCCM_API int _DTCALL_ SetVFlip(BOOL bEnable,int iDevID=DEFAULT_DEV_ID);

/// @brief ������رա�ʮ�����ߡ�
///
/// @param bEnable����ʮ������ʹ�ܣ�ΪTRUE����ʮ���ߣ�ΪFALSE�ر�ʮ����
DTCCM_API int _DTCALL_ SetCrossOn(BOOL bEnable,int iDevID=DEFAULT_DEV_ID);

//RGB24 to YUV422 (YcbYcr mode)
//pBmp24 :RGB24 data pointer;
//pOut   :YUV422 pointer
//width  :Image width;
//height :Image height;

/// @brief RGB24תYUV422��
///
/// @param pBmp24��RGB24����
/// @param pOut��YUV422����
/// @param width��ͼ�����ݿ��
/// @param height��ͼ�����ݸ߶�
DTCCM_API int _DTCALL_ RGB24ToYUV422(BYTE* pBmp24, BYTE* pOut, USHORT uWidth, USHORT uHeight, int iDevID=DEFAULT_DEV_ID);

//RGB24 to YUV444 (Ycbcr )
//pBmp24 :RGB24 data pointer;
//pOut   :YUV422 pointer
//width  :Image width;
//height :Image height;

/// @brief RGB24תYUV444��
///
/// @param pBmp24��RGB24����
/// @param pOut��YUV422����
/// @param width��ͼ�����ݿ��
/// @param height��ͼ�����ݸ߶�
DTCCM_API int _DTCALL_ RGB24ToYUV444(BYTE *pBmp24, BYTE *pOut, USHORT uWidth, USHORT uHeight, int iDevID=DEFAULT_DEV_ID);


/// @brief ��ʾRGBͼ�����ݡ�
///
/// @param pBmp24������ʾ��RGB24��ʽ������
/// @param pInfo��֡��Ϣ���μ��ṹ�塰FrameInfo��
///
/// @retval DT_ERROR_OK����ʾRGBͼ��ɹ�
/// @retval DT_ERROR_FAILD����ʾRGBͼ��ʧ�� 
DTCCM_API int _DTCALL_ DisplayRGB24(BYTE *pBmp24,FrameInfo *pInfo=NULL,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ʾRGBͼ�����ݡ�
///
/// @param pBmp24������ʾ��RGB24��ʽ������
/// @param pInfo��֡��Ϣ���μ��ṹ�塰FrameInfoEx��
///
/// @retval DT_ERROR_OK����ʾRGBͼ��ɹ�
/// @retval DT_ERROR_FAILD����ʾRGBͼ��ʧ�� 
DTCCM_API int _DTCALL_ DisplayRGB24Ex(BYTE *pBmp24,FrameInfoEx *pInfo,int iDevID=DEFAULT_DEV_ID);

/// @brief RAW/YUVתRGB��Դ���ݸ�ʽ��ImgFormatָ����
///
/// @param pIn��Դͼ������
/// @param pOut��תΪRGB24������
/// @param uWidth��ͼ�����ݿ��
/// @param uHeight��ͼ�����ݸ߶�
/// @param byImgFormat��Դ���ݵĸ�ʽ
DTCCM_API int _DTCALL_ DataToRGB24(BYTE *pIn, BYTE *pOut, USHORT uWidth, USHORT uHeight, BYTE byImgFormat,int iDevID=DEFAULT_DEV_ID);


/// @brief RAW/YUVתRGB��Դ���ݸ�ʽ��ImgFormatָ����(˫ͨ����ƷUH920ʹ��ʱҪָ��ͨ��)
///
/// @param pIn��Դ����
/// @param pOut��תΪRGB24������
/// @param uWidth��ͼ�����ݿ��
/// @param uHeight��ͼ�����ݸ߶�
/// @param byImgFormat��Դ���ݵĸ�ʽ
/// @param byChannel: ָ��ͨ��
DTCCM_API int _DTCALL_ DataToRGB24Ex(BYTE *pIn, BYTE *pOut, USHORT uWidth, USHORT uHeight, BYTE byImgFormat,BYTE byChannel,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ʾRAW/YUVͼ�����ݣ�Դ���ݸ�ʽ��Init�����е�byImgFormat����ָ����
///
/// @param pData������ʾ��ͼ������
/// @param pInfo��֡��Ϣ���μ��ṹ�塰FrameInfo��
///
/// @retval DT_ERROR_OK����ʾͼ��ɹ�
/// @retval DT_ERROR_FAILD����ʾͼ��ʧ�� 
/// @retval DT_ERROR_NOT_INITIALIZED��û�г�ʼ��
DTCCM_API int _DTCALL_ DisplayVideo(BYTE *pData,FrameInfo *pInfo=NULL,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ʾRAW/YUVͼ�����ݣ�Դ���ݸ�ʽ��Init�����е�byImgFormat����ָ����
///
/// @param pData������ʾ��ͼ������
/// @param pInfo��֡��Ϣ���μ��ṹ�塰FrameInfoEx��
///
/// @retval DT_ERROR_OK����ʾͼ��ɹ�
/// @retval DT_ERROR_FAILD����ʾͼ��ʧ�� 
/// @retval DT_ERROR_NOT_INITIALIZED��û�г�ʼ��
DTCCM_API int _DTCALL_ DisplayVideoEx(BYTE *pData,FrameInfoEx *pInfo,int iDevID=DEFAULT_DEV_ID);

/// @brief ��RAWͼ�����ݽ���ͼ����(MONO,WB,ColorChange,Gamma,Contrast)��
///
/// @param pImage��RAWͼ������
/// @param pBmp24������ͼ����������
/// @param uWidth��ͼ�����ݿ��
/// @param uHeight��ͼ�����ݸ߶�
/// @param pInfo��֡��Ϣ���μ��ṹ�塰FrameInfo��
/// 
/// @retval DT_ERROR_OK��ͼ����ɹ�
/// @retval DT_ERROR_PARAMETER_INVALID��pData��Ч�Ĳ���
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
DTCCM_API int _DTCALL_ ImageProcess(BYTE *pImage, BYTE *pBmp24, int nWidth, int nHeight,FrameInfo *pInfo,int iDevID=DEFAULT_DEV_ID);

/// @brief ��RAWͼ�����ݽ���ͼ����(MONO,WB,ColorChange,Gamma,Contrast)��
///
/// @param pImage��RAWͼ������
/// @param pBmp24������ͼ����������
/// @param uWidth��ͼ�����ݿ��
/// @param uHeight��ͼ�����ݸ߶�
/// @param pInfo��֡��Ϣ���μ��ṹ�塰FrameInfoEx��
/// 
/// @retval DT_ERROR_OK��ͼ����ɹ�
/// @retval DT_ERROR_PARAMETER_INVALID��pData��Ч�Ĳ���
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
DTCCM_API int _DTCALL_ ImageProcessEx(BYTE *pImage, BYTE *pBmp24, int nWidth, int nHeight,FrameInfoEx *pInfo,int iDevID=DEFAULT_DEV_ID);

/// @brief ����RAW��ʽ���μ�ö�����͡�RAW_FORMAT����
///
/// @param byRawMode��RAW��ʽ����
///
/// @see RAW_FORMAT
DTCCM_API int _DTCALL_ SetRawFormat(BYTE byRawMode,int iDevID=DEFAULT_DEV_ID);

/// @brief ����YUV��ʽ���μ�ö�����͡�YUV_FORMAT����
///
/// @param byYuvMode��YUV��ʽ����
///
/// @see YUV_FORMAT
DTCCM_API int _DTCALL_ SetYUV422Format(BYTE byYuvMode,int iDevID=DEFAULT_DEV_ID);

/// @brief ����YUVתRGBʱ��һЩϵ����
///
///	@param Y=(Y-yoff)*ycoef
///	@param r=Y+(cr-128)*bdif
///	@param g=Y-cbcoef*(cb-128)-crcoef*(cr-128)
///	@param b=Y+(cb-128)*rdif
DTCCM_API int _DTCALL_ SetYuvCoefficient(int yoff, 
										 float ycoef, 
										 float cbcoef, 
										 float crcoef, 
										 float rdif, 
										 float bdif,
										 int iDevID=DEFAULT_DEV_ID);

/// @brief ��ʼ����ʾ��֧��2��������ʾ�����ʹ��2��sensor����Ҫʹ��hWndExָ���ڶ������ڡ�
///
/// @param hWnd����ʾAͨ��ͼ��Ĵ��ھ��
/// @param uImgWidth��ͼ�����ݿ��
/// @param uHeight��ͼ�����ݸ߶�
/// @param byImgFormat��ͼ�����ݸ�ʽ���磺RAW/YUV
/// @param hWndEx��hWndEx����ʾBͨ��ͼ��Ĵ��ھ��
DTCCM_API int _DTCALL_ InitDisplay(HWND hWnd, 
								   USHORT uImgWidth, 
								   USHORT uImgHeight,
								   BYTE byImgFormat,
								   BYTE byChannel=CHANNEL_A,
								   HWND hWndEx=NULL,
								   int iDevID=DEFAULT_DEV_ID);

DTCCM_API int _DTCALL_ GrabDataToRaw8(BYTE *pIn, BYTE *pOut,int uWidth ,int uHeight,BYTE ImgFormat,int iDevID=DEFAULT_DEV_ID);

DTCCM_API int _DTCALL_ GrabDataToRaw16(BYTE *pIn, USHORT *pOut,int uWidth ,int uHeight,BYTE ImgFormat,int iDevID=DEFAULT_DEV_ID);


/// @brief ��RAWͼ�����ݽ���ͼ����(MONO,WB,ColorChange,Gamma,Contrast)��
///
/// @param pImage��RAWͼ������
/// @param pBmp24������ͼ����������
/// @param uWidth��ͼ�����ݿ��
/// @param uHeight��ͼ�����ݸ߶�
/// @param pInfo��֡��Ϣ���μ��ṹ�塰FrameInfo��
/// 
/// @retval DT_ERROR_OK��ͼ����ɹ�
/// @retval DT_ERROR_PARAMETER_INVALID��pData��Ч�Ĳ���
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
DTCCM_API int _DTCALL_ ImageProcessForRaw8(BYTE *pImage, BYTE *pBmp24, int nWidth, int nHeight,FrameInfo *pInfo,int iDevID=DEFAULT_DEV_ID);

/** @} */ // end of group2


/******************************************************************************
SENSOR���
*******************************************************************************/
/** @defgroup group3 SENSOR���


* @{

*/
/// @brief ������sensorͨѶ���������ͣ�Ŀǰ��I2C��SPI
///
/// @param iChannel��sensorͨѶ�����������ã�Ϊ0��I2C��Ϊ1��SPI
//DTCCM_API int _DTCALL_ SetSensorBusChannel(int iChannel, int iDevID=DEFAULT_DEV_ID);


//DTCCM_API int _DTCALL_ SetSensorSpiBusCtrl(int );

//DTCCM_API int _DTCALL_ SetSensorSpi()

/// @brief ��λ��SensorͨѶ��I2C���ߡ�
///
/// @retval DT_ERROR_OK����λI2C�����ɹ�
/// @retval DT_ERROR_FAILED����λI2C����ʧ��
DTCCM_API int _DTCALL_ ResetSensorI2cBus(int iDevID=DEFAULT_DEV_ID);

/// @brief ����I2C���ֽڼ��(HSϵ��,PE950֧��)
///
/// @brief uInterval���ֽڼ������,��λus
DTCCM_API int _DTCALL_ SetI2CInterval(UINT uInterval, int iDevID=DEFAULT_DEV_ID);

/// @brief ����I2CͨѶACK��ʱ�ȴ�ʱ�䡣
/// 
/// @param nUsWait������ACK��ʱ�ȴ�ʱ�䣬��λus
///
/// @retval DT_ERROR_OK������I2CͨѶACK��ʱ�ȴ�ʱ��ɹ�
DTCCM_API int _DTCALL_ SetSensorI2cAckWait(UINT uAckWait,int iDevID=DEFAULT_DEV_ID);

/// @brief ������SENSORͨѶ��I2C�������ʣ�400Kbps��100Kbps��
///
/// @param b400K��b400K=TURE��400Kbps��b400K=FALSE,100Kbps
///							 
/// @retval DT_ERROR_OK�������������ʲ����ɹ�
DTCCM_API int _DTCALL_ SetSensorI2cRate(BOOL b400K,int iDevID=DEFAULT_DEV_ID);

/// @brief ������SENSORͨѶ��I2C�������ʣ���Χ10Khz-2Mhz��
///
/// @param uKpbs������I2C�������ʣ���ΧֵΪ10-2000
///							 
/// @retval DT_ERROR_OK�������������ʲ����ɹ�
DTCCM_API int _DTCALL_ SetSensorI2cRateEx(UINT uKpbs,int iDevID=DEFAULT_DEV_ID);

/// @brief ʹ����SENSORͨѶ��I2C����ΪRapidģʽ��
///
/// @param  bRapid=1��ʾ��ǿ�ƹ��������ߵ�ƽ;=0��I2C�ܽ�Ϊ����״̬�������ⲿ������ɸߵ�ƽ
///							 
/// @retval DT_ERROR_OK������I2C����Rapidģʽ�ɹ�
DTCCM_API int _DTCALL_ SetSensorI2cRapid(BOOL bRapid,int iDevID=DEFAULT_DEV_ID);

/// @brief sensor i2c�ⲿ��������ѡ��
/// 
/// @param byPullupResistorSel=PULLUP_RESISTOR_1_5K,��ʾ1.5K��=PULLUP_RESISTOR_4_7K����ʾ4.7K��=PULLUP_RESISTOR_0_88K��ʾ0.88K
///
/// @retval DT_ERROR_OK�����óɹ�
/// @retval DT_ERROR_PARAMETER_INVALID��byPullupResistorSel������Ч
/// @retval DT_ERROR_TIME_OUT��ͨѶ��ʱ
DTCCM_API int _DTCALL_ SetSensorI2cPullupResistor(BYTE byPullupResistorSel,int iDevID=DEFAULT_DEV_ID);


/// @brief ����sensor i2c д�Ĺ��̵�ACK����ACKӦ��Ҳ�����������һ������
/// 
/// @param bIgnoreAck=TRUE,����ACK��=FALSE,��ʾ������ACK
///
/// @retval DT_ERROR_OK�����óɹ�
/// @retval DT_ERROR_PARAMETER_INVALID��byPullupResistorSel������Ч
/// @retval DT_ERROR_TIME_OUT��ͨѶ��ʱ
DTCCM_API int _DTCALL_ SetI2cIgnoreAck(BOOL bIgnoreAck,int iDevID=DEFAULT_DEV_ID);

/// @brief дSENSOR�Ĵ���,I2CͨѶģʽbyI2cMode������ֵ��I2CMODE���塣
/// 
/// @param uAddr����������ַ
/// @param uReg���Ĵ�����ַ
/// @param uValue��д��Ĵ�����ֵ
/// @param byMode��I2Cģʽ
///
/// @retval DT_ERROR_OK��дSENSOR�Ĵ��������ɹ�
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_INVALID��byMode������Ч
/// @retval DT_ERROR_TIME_OUT��ͨѶ��ʱ
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
///
/// @see I2CMODE
DTCCM_API int _DTCALL_ WriteSensorReg(UCHAR uAddr, USHORT uReg, USHORT uValue, BYTE byMode,int iDevID=DEFAULT_DEV_ID);

/// @brief ��SESNOR�Ĵ���,I2CͨѶģʽbyI2cMode������ֵ��I2CMODE���塣
///
/// @param uAddr����������ַ
/// @param uReg���Ĵ�����ַ
/// @param pValue�������ļĴ�����ֵ
/// @param byMode��I2Cģʽ
///
/// @retval DT_ERROR_OK����SENSOR�Ĵ��������ɹ�
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_INVALID��byMode������Ч
/// @retval DT_ERROR_TIME_OUT��ͨѶ��ʱ
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
///
/// @see I2CMODE
DTCCM_API int _DTCALL_ ReadSensorReg(UCHAR uAddr, USHORT uReg, USHORT *pValue,BYTE byMode,int iDevID=DEFAULT_DEV_ID);

/// @brief дSENSOR�Ĵ�����֧�������Ĵ���д�����ݣ����֧��16���Ĵ�������
///
/// @param uAddr����������ַ
/// @param byI2cMode��I2Cģʽ
/// @param uRegNum��д��Ĵ������������16
/// @param RegAddr[]���Ĵ�����ַ����
/// @param RegData[]��д��Ĵ���������
/// @param RegDelay[]��д��һ��Ĵ�������һ��Ĵ���֮�����ʱ,���65ms����λus
///
/// @retval DT_ERROR_OK�����дSENSOR�Ĵ��������ɹ�
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_INVALID��uSize������Ч
/// @retval DT_ERROR_TIME_OUT��ͨѶ��ʱ
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
DTCCM_API int _DTCALL_ WriteSensorMultiRegsWithDelay(UCHAR uAddr, BYTE byI2cMode, USHORT uRegNum, USHORT RegAddr[], USHORT RegData[],USHORT RegDelay[],int iDevID=DEFAULT_DEV_ID);

/// @brief дSENSOR�Ĵ�����֧����һ���Ĵ���д��һ�����ݿ飨������255�ֽڣ���
///
/// @param uDevAddr����������ַ
/// @param uRegAddr���Ĵ�����ַ
/// @param uRegAddrSize���Ĵ�����ַ���ֽ���
/// @param pData��д��Ĵ��������ݿ�
/// @param uSize��д��Ĵ��������ݿ���ֽ�����������255�ֽ�(HS300/HS300D/HV910/HV910Dһ�β��ܳ���253�ֽ�)��
///
/// @retval DT_ERROR_OK�����дSENSOR�Ĵ���������ɹ�
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_INVALID��uSize������Ч
/// @retval DT_ERROR_TIME_OUT��ͨѶ��ʱ
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
DTCCM_API int _DTCALL_ WriteSensorI2c(UCHAR uDevAddr,USHORT uRegAddr,UCHAR uRegAddrSize,BYTE *pData,USHORT uSize,int iDevID=DEFAULT_DEV_ID);

/// @brief ��SENSOR�Ĵ�����֧����һ���Ĵ�������һ�����ݿ飨������255�ֽڣ���
///
/// @param uDevAddr����������ַ
/// @param uRegAddr���Ĵ�����ַ
/// @param uRegAddrSize���Ĵ�����ַ���ֽ���
/// @param pData�������Ĵ�����ֵ
/// @param uSize�������Ĵ��������ݿ���ֽ�����������255�ֽڣ�
/// @param bNoStop���Ƿ񷢳�I2C��STOP���һ�������Ĭ��ΪFALSE��bNoStop=TRUE��ʾд�Ĺ��̲�����I2C��ֹͣ���bNoStop=FALSE��I2C��ֹͣ����
///
/// @retval DT_ERROR_OK����ɶ�SENSOR�Ĵ���������ɹ�
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_INVALID��uSize������Ч
/// @retval DT_ERROR_TIME_OUT��ͨѶ��ʱ
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
DTCCM_API int _DTCALL_ ReadSensorI2c(UCHAR uDevAddr,USHORT uRegAddr,UCHAR uRegAddrSize,BYTE *pData,USHORT uSize,BOOL bNoStop=FALSE,int iDevID=DEFAULT_DEV_ID);

/// @brief дSENSOR�Ĵ�����֧����һ���Ĵ���д��һ�����ݿ飨������255�ֽڣ���
///
/// @param uDevAddr����������ַ
/// @param uRegAddr���Ĵ�����ַ
/// @param uRegAddrSize���Ĵ�����ַ���ֽ���
/// @param pData��д��Ĵ��������ݿ�
/// @param uSize��д��Ĵ��������ݿ���ֽ�����������255�ֽ�(HS300/HS300D/HV910/HV910Dһ�β��ܳ���253�ֽ�)��
///
/// @retval DT_ERROR_OK�����дSENSOR�Ĵ���������ɹ�
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_INVALID��uSize������Ч
/// @retval DT_ERROR_TIME_OUT��ͨѶ��ʱ
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
DTCCM_API int _DTCALL_ WriteSensorI2cEx(UCHAR uDevAddr,UINT uRegAddr,UCHAR uRegAddrSize,BYTE *pData,USHORT uSize,int iDevID=DEFAULT_DEV_ID);

/// @brief ��SENSOR�Ĵ�����֧����һ���Ĵ�������һ�����ݿ飨������255�ֽڣ���
///
/// @param uDevAddr����������ַ
/// @param uRegAddr���Ĵ�����ַ
/// @param uRegAddrSize���Ĵ�����ַ���ֽ���
/// @param pData�������Ĵ�����ֵ
/// @param uSize�������Ĵ��������ݿ���ֽ�����������255�ֽڣ�
/// @param bNoStop���Ƿ񷢳�I2C��STOP���һ�������Ĭ��ΪFALSE��bNoStop=TRUE��ʾд�Ĺ��̲�����I2C��ֹͣ���bNoStop=FALSE��I2C��ֹͣ����
///
/// @retval DT_ERROR_OK����ɶ�SENSOR�Ĵ���������ɹ�
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_INVALID��uSize������Ч
/// @retval DT_ERROR_TIME_OUT��ͨѶ��ʱ
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
DTCCM_API int _DTCALL_ ReadSensorI2cEx(UCHAR uDevAddr,UINT uRegAddr,UCHAR uRegAddrSize,BYTE *pData,USHORT uSize,BOOL bNoStop=FALSE,int iDevID=DEFAULT_DEV_ID);


/// @brief ����SENSOR�ĵ���ֵ��100mA��300mA��
///
/// @param iLimit������ֵ��ֻ������Ϊ100����300��
/// 
/// @retval DT_ERROR_OK�����õ���ֵ�ɹ�
/// @retval DT_ERROR_FAILED�����õ���ֵʧ��
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
///
/// @note �˺������ܽ�HS��PEϵ��������Ч
DTCCM_API int _DTCALL_ SetSensorCurrentLimit(int iLimit,int iDevID=DEFAULT_DEV_ID);

/// @brief ͨ��Reset,PWDN�ܽſ�����ر�SENSOR��
///
/// @param byPin��Reset��PWDN��PWDN2
/// @param bEnable��������ر�SENSOR
///
/// @retval DT_ERROR_OK��������ر�SENSOR�����ɹ�
/// @retval DT_ERROR_FAILED��������ر�SENSOR����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SensorEnable(BYTE byPin, BOOL bEnable,int iDevID=DEFAULT_DEV_ID);

/// @brief ���Reset,PWDN�ܽ��Ƿ��SENSOR�����á�
///
/// @param pInfo��SENSOR�Ĳ�����Ϣ
/// @param bRstChkEn��ʹ�ܼ��Reset
/// @param bPwdnChkEn��ʹ�ܼ��PWDN
/// @param byChannel��A/Bͨ��ѡ��
/// @param pErrorx�����ص�Reset��PWDN�ļ����Ϣ
///
/// @retval DT_ERROR_OK�������ɹ�
DTCCM_API int _DTCALL_ CheckRstPwdnPin(SensorTab *pInfo, BOOL bRstChkEn, BOOL bPwdnChkEn, BYTE byChannel,BYTE *pErrorx,int iDevID=DEFAULT_DEV_ID);

/// @brief ���Reset,PWDN�ܽ��Ƿ��SENSOR�����á�
///
/// @param pInfo��SENSOR�Ĳ�����Ϣ
/// @param bRstChkEn��ʹ�ܼ��Reset
/// @param bPwdnChkEn��ʹ�ܼ��PWDN
/// @param byChannel��A/Bͨ��ѡ��
/// @param pErrorx�����ص�Reset��PWDN�ļ����Ϣ
///
/// @retval DT_ERROR_OK�������ɹ�
DTCCM_API int _DTCALL_ CheckRstPwdnPin2(SensorTab2 *pInfo, BOOL bRstChkEn, BOOL bPwdnChkEn, BYTE byChannel,BYTE *pErrorx,int iDevID=DEFAULT_DEV_ID);


/// @brief ����SENSOR������ʱ�ӡ�
///
/// @param bOnOff��ʹ��SENSOR������ʱ�ӣ�ΪTRUE��������ʱ�ӣ�ΪFALSE�ر�����ʱ��
/// @param uHundKhz��SENSOR������ʱ��ֵ����λΪ100Khz
///
/// @retval DT_ERROR_OK������SENSOR����ʱ�ӳɹ�
/// @retval DT_ERROR_FAILED������SENSOR����ʱ��ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetSensorClock(BOOL bOnOff,USHORT uHundKhz,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡMIPI�ӿڵ�ͬ��ʱ��Ƶ�ʡ�
///
/// @param pFreq������MIPI�ӿڵ�ͬ��ʱ��Ƶ��ֵ
/// @param byChannel��Aͨ��/Bͨ��
///
/// @retval DT_ERROR_OK����ȡMIPI�ӿڵ�ͬ��ʱ��Ƶ�ʳɹ�
/// @retval DT_ERROR_FAILED����ȡMIPI�ӿڵ�ͬ��ʱ��Ƶ��ʧ��
/// @retval DT_ERROR_PARAMETER_INVALID��ͨ��������Ч
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetMipiClkFrequency(ULONG *pFreq,BYTE byChannel=CHANNEL_A,int iDevID=DEFAULT_DEV_ID);

/// @brief ����MIPI�ӿڽ�����ʱ����λ��
///
/// @param byPhase��MIPI�ӿڽ�����ʱ����λ���������õ�ֵ��0-7��
///
/// @retval DT_ERROR_OK������MIPI�ӿڽ�����ʱ����λ�ɹ�
/// @retval DT_ERROR_FAILED������MIPI�ӿڽ�����ʱ����λʧ��
/// @retval DT_ERROR_TIME_OUT�����ó�ʱ
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetMipiClkPhase(BYTE byPhase,int iDevID=DEFAULT_DEV_ID);

/// @brief ����MIPI�ܽ�ʹ���ź�
///
/// @param bEnable��ΪFalseʱMIPI����HS״̬��ΪTRUE����LP״̬
///
/// @retval DT_ERROR_OK��ROI���óɹ�
/// @retval DT_ERROR_FAILD��ROI����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetMipiEnable(BOOL bEnable, int iDevID=DEFAULT_DEV_ID);

/// @brief ����MIPI��,ָ��Ҫ���˵İ���ID�ż����˵İ�����
///
/// @param PackID[]������Ҫ���˵İ���ID��
/// @param iCount�����˵İ�ID�ĸ�����DMU950���64
///
/// @retval DT_ERROR_OK��ROI���óɹ�
/// @retval DT_ERROR_FAILD��ROI����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetMipiPacketFilter(int PackID[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ���˵İ���ID��
///
/// @param PackID[]�����صĹ��˵İ���ID��
/// @param pCount�����ع��˰��ĸ���
/// @param MaxCount������Ҫ��ȡ�İ�ID���������DMU950���64
///
/// @retval DT_ERROR_OK��ROI���óɹ�
/// @retval DT_ERROR_FAILD��ROI����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetMipiPacketFilter(int PackID[], int *pCount, int MaxCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡMIPI�ӿڽ�����ʱ����λֵ��
///
/// @param pPhase������MIPI�ӿڽ�����ʱ����λֵ
///
/// @retval DT_ERROR_OK����ȡMIPI�ӿڽ�����ʱ����λֵ�ɹ�
/// @retval DT_ERROR_FAILED����ȡMIPI�ӿڽ�����ʱ����λֵʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetMipiClkPhase(BYTE *pPhase,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡMIPI�ӿڽ�����CRC���������
///
/// @param pCount������MIPI�ӿڽ�����CRC�������ֵ
/// @param byChannel��A/Bͨ��ѡ��
///
/// @retval DT_ERROR_OK����ȡMIPI�ӿڽ�����CRC�������ֵ�ɹ�
/// @retval DT_ERROR_FAILED����ȡMIPI�ӿڽ�����CRC�������ֵʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetMipiCrcErrorCount(UINT *pCount,BYTE byChannel=CHANNEL_A,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡMIPI�ӿڽ�����ECC���������
///
/// @param pCount������MIPI�ӿڽ�����ECC�������ֵ
/// @param byChannel��A/Bͨ��ѡ��
///
/// @retval DT_ERROR_OK����ȡMIPI�ӿڽ�����ECC�������ֵ�ɹ�
/// @retval DT_ERROR_FAILED����ȡMIPI�ӿڽ�����ECC�������ֵʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetMipiEccErrorCount(UINT *pCount,BYTE byChannel=CHANNEL_A,int iDevID=DEFAULT_DEV_ID);


/// @brief ��ȡMIPI�ӿڵ�LOCK״̬��
///
/// @param pMipiLockState����ȡMIPI�ӿڵ�LOCK״̬����bit0-bit3���α�ʾLANE1��LANE2��LANE3��LANE4
///
/// @retval DT_ERROR_OK����ȡMIPI�ӿ�LOCK״̬�ɹ�
/// @retval DT_ERROR_FAILED����ȡLOCK״̬ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetMipiLockState(DWORD *pMipiLockState,BYTE byChannel,int iDevID=DEFAULT_DEV_ID);

/// @brief ����MIPI�ӿڿ�������
///
/// @param dwCtrl��MIPI�ӿڿ����������룬�μ��궨�塰MIPI���������Ե�λ���塱
///
/// @retval DT_ERROR_OK������MIPI�ӿڿ������ɹ�
/// @retval DT_ERROR_FAILED������MIPI�ӿڿ�����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetMipiCtrl(DWORD dwCtrl,int iDevID=DEFAULT_DEV_ID);

/// @brief ��������ͨ����
/// 
/// @param uVC�����ý��յ�ͼ��ͨ���ţ�0/1/2/3
/// @param bVCFileterEn��ʹ�ܹ�������������ͨ��
///
/// @retval DT_ERROR_OK������MIPI�ӿڿ������ɹ�
/// @retval DT_ERROR_FAILED������MIPI�ӿڿ�����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetMipiImageVC(UINT uVC, BOOL bVCFilterEn, BYTE byChannel=CHANNEL_A, int iDevID=DEFAULT_DEV_ID);


/// @brief ��ȡMIPI�ӿڿ�����
/// 
/// @param pdwCtrl������MIPI�ӿڿ�����
///
/// @retval DT_ERRORO_OK�� ��ȡ�ɹ�
DTCCM_API int _DTCALL_ GetMipiCtrl(DWORD *pdwCtrl,int iDevID=DEFAULT_DEV_ID);


/// @brief ���ò��нӿڿ�������
///
/// @param dwCtrl�����нӿڿ����������룬�μ��궨�塰ͬ�����нӿ����Ե�λ���塱
///
/// @retval DT_ERROR_OK�����ò��нӿڿ������ɹ�
/// @retval DT_ERROR_FAILED�����ò��нӿڿ�����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetParaCtrl(DWORD dwCtrl,int iDevID=DEFAULT_DEV_ID);

/// @brief ����HiSPI�ӿڿ�������
///
/// @param dwCtrl��HiSPI�ӿڿ����������룬�μ��궨�塰HiSPI�ӿ����Ե�λ���塱
///
/// @retval DT_ERROR_OK������HiSPI�ӿڿ������ɹ�
/// @retval DT_ERROR_FAILED������HiSPI�ӿڿ�����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetHispiCtrl(DWORD dwCtrl,int iDevID=DEFAULT_DEV_ID);

/// @brief ����ģ��ͼ���������
///
/// @param dwCtrl��ģ��ͼ�������������
/// @param byRefByte��ģ��ͼ�����ݶ���
///
/// @retval DT_ERROR_OK������ģ��ͼ��������ɹ�
/// @retval DT_ERROR_FAILED������ģ��ͼ�������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetSimCtrl(DWORD dwCtrl,BYTE byRefByte,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ʼ��SENSOR��
///
/// @param uDevAddr��SENSOR������ַ
/// @param pParaList��SENSOR�Ĳ����б�
/// @param uLength��pParaList�Ĵ�С
/// @param byI2cMode������SENSOR��I2Cģʽ���μ�ö������I2CMODE
///
/// @retval DT_ERROR_OK����ʼ��SENSOR�ɹ�
/// @retval DT_ERROR_FAILED����ʼ��SENSORʧ��
///
/// @see I2CMODE
DTCCM_API int _DTCALL_ InitSensor(UCHAR uDevAddr,USHORT *pParaList,USHORT uLength,BYTE byI2cMode,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ʼ��SENSOR��
///
/// @param uDevAddr��SENSOR������ַ
/// @param pParaList��SENSOR�Ĳ����б�
/// @param uLength��pParaList�Ĵ�С
/// @param byI2cMode������SENSOR��I2Cģʽ���μ�ö������I2CMODE
///
/// @retval DT_ERROR_OK����ʼ��SENSOR�ɹ�
/// @retval DT_ERROR_FAILED����ʼ��SENSORʧ��
///
/// @see I2CMODE
DTCCM_API int _DTCALL_ InitSensor2(UINT uDevAddr,UINT *pParaList,UINT uLength,UINT byI2cMode,int iDevID=DEFAULT_DEV_ID);


/// @brief �����ϵ�SENSOR�ǲ��ǵ�ǰָ���ģ����ҿ���ͬʱ��SENSOR����һ�θ�λ��
///
/// @param pInfo��SENSOR��Ϣ���μ�SensorTab�ṹ��
/// @param byChannel��ͨ��ѡ��A/Bͨ�����μ��궨�塰��SENSORģ��ͨ�����塱
/// @param bReset����SENSOR��λ
///
/// @retval DT_ERROR_OK���ҵ�SENSOR
/// @retval DT_ERROR_FAILED��û���ҵ�SENSOR
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SensorIsMe(SensorTab *pInfo,BYTE byChannel,BOOL bReset,int iDevID=DEFAULT_DEV_ID);

/// @brief �����ϵ�SENSOR�ǲ��ǵ�ǰָ���ģ����ҿ���ͬʱ��SENSOR����һ�θ�λ��
///
/// @param pInfo��SENSOR��Ϣ���μ�SensorTab2�ṹ��
/// @param byChannel��ͨ��ѡ��A/Bͨ�����μ��궨�塰��SENSORģ��ͨ�����塱
/// @param bReset����SENSOR��λ
///
/// @retval DT_ERROR_OK���ҵ�SENSOR
/// @retval DT_ERROR_FAILED��û���ҵ�SENSOR
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SensorIsMe2(SensorTab2 *pInfo,BYTE byChannel,BOOL bReset,int iDevID=DEFAULT_DEV_ID);


/// @brief ͨ��ѡ��
/// 
/// @param byI2cChannel��ͨ��ѡ��A/Bͨ�����μ��궨�塰��SENSORģ��ͨ�����塱
/// 
/// @retval DT_ERROR_OK�����óɹ�
/// @retval DT_ERROR_FAILED������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetChannelSel(BYTE byI2cChannel,int iDevID=DEFAULT_DEV_ID);

/// @brief ͼ��ͨ��ʹ��
/// 
/// @param byI2cChannel��ͨ��ѡ��A/Bͨ�����μ��궨�塰��SENSORģ��ͨ�����塱
/// 
/// @retval DT_ERROR_OK�����óɹ�
/// @retval DT_ERROR_FAILED������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetGrabChannelEnable(BYTE byGrabChannelEnabel,int iDevID=DEFAULT_DEV_ID);

/// @brief �������Խӿڡ�
///
/// @param PinConfig�����Խӿ����ö���
///
/// @retval DT_ERROR_OK�����Խӿ����óɹ�
/// @retval DT_ERROR_FAILED�����Խӿ�����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetSoftPin(BYTE PinConfig[26],int iDevID=DEFAULT_DEV_ID);

/// @brief �������Խӿ��Ƿ�ʹ���������衣
///
/// @param bPullup�����Խӿ�����ʹ�ܣ�bPullup=TRUEʹ���������裬bPullup=FALSE�ر���������
///
/// @retval DT_ERROR_OK�����óɹ�
/// @retval DT_ERROR_FAILED������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetSoftPinPullUp(BOOL bPullup,int iDevID=DEFAULT_DEV_ID);

/// @brief �����Ƿ�ʹ�����Խӿڣ�ûʹ��ʱΪ����״̬��
///
/// @param bEnable�����Խӿ�ʹ��
///
/// @retval DT_ERROR_OK�����óɹ�
/// @retval DT_ERROR_FAILED������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ EnableSoftPin(BOOL bEnable,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ���Խӿڵ�ƽ��ÿBIT��Ӧһ���ܽţ�bit0��ӦPIN_1��
/// 
/// @param pPinLevel�����Խӿڵ�ƽ
///
/// @retval DT_ERROR_OK����ȡ���Խӿڵ�ƽ�ɹ�
/// @retval DT_ERROR_FAILED����ȡ���Խӿڵ�ƽʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetSoftPinLevel(DWORD *pPinLevel,int iDevID=DEFAULT_DEV_ID);

/// @brief ʹ��GPIO��
///
/// @param bEnable��ʹ��GPIO
///
/// @retval DT_ERROR_OK�����óɹ�
/// @retval DT_ERROR_FAILED������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ EnableGpio(BOOL bEnable,int iDevID=DEFAULT_DEV_ID);

/// @brief ���õ���GPIO�ĵ�ƽ��iPin�ı��ֵ��1��ʼ��1��ʾGPIO1��
///
/// @param iPin��GPIO���ֵ��iPin�ı��ֵ��1��ʼ��1��ʾGPIO1
/// @param bLevel������GPIO�ĵ�ƽ
///
/// @retval DT_ERROR_OK�����õ���GPIO�ĵ�ƽֵ�ɹ�
/// @retval DT_ERROR_FAILED�����õ���GPIO�ĵ�ƽֵʧ��
/// @retval DT_ERROR_PARAMETER_INVALID��GPIO���ֵ������Ч
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetGpioPinLevel(int iPin,BOOL bLevel,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡĳ��GPIO�ĵ�ƽ����������룬�����ⲿ��ƽ��������������Ϊ���õ�ƽ��  
///
/// @param iPin��GPIO���ֵ��iPin�ı��ֵ��1��ʼ��1��ʾGPIO1
/// @param pLevel��GPIO�ĵ�ƽֵ
///
/// @retval DT_ERROR_OK����ȡGPIO�ĵ�ƽֵ�ɹ�
/// @retval DT_ERROR_FAILED����ȡGPIO�ĵ�ƽֵʧ��
/// @retval DT_ERROR_PARAMETER_INVALID��GPIO���ֵ������Ч
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetGpioPinLevel(int iPin,BOOL *pLevel,int iDevID=DEFAULT_DEV_ID);

/// @brief ���ö��GPIO�ĵ�ƽ��Pin�д洢�ı��ֵ��1��ʼ��1��ʾGPIO1��
///
/// @param Pin��GPIO���
/// @param Level��GPIO��ƽֵ
/// @param iCount��Ҫ���õ�GPIO����
///
/// @retval DT_ERROR_OK�����ö��GPIO�ĵ�ƽ�ɹ�
/// @retval DT_ERROR_FAILED�����ö��GPIO�ĵ�ƽʧ��
/// @retval DT_ERROR_PARAMETER_INVALID��GPIO���ֵ������Ч
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetMultiGpioPinLevel(int Pin[],BOOL Level[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ����ĳ��GPIO��IO�ܽŷ���bDir��TRUEΪ���룬FALSEΪ�����
///
/// @param iPin��GPIO���
/// @param bDir��GPIO�ܽŷ���,bDir��TRUEΪ���룬FALSEΪ���
///
/// @retval DT_ERROR_OK������GPIO��IO�ܽŷ���ɹ�
/// @retval DT_ERROR_FAILED������GPIO��IO�ܽŷ���ʧ��
/// @retval DT_ERROR_PARAMETER_INVALID��GPIO���ֵ������Ч
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetGpioPinDir(int iPin, BOOL bDir,int iDevID=DEFAULT_DEV_ID);

/// @brief ���ö��GPIO��IO�ܽŷ���Dir��TRUEΪ���룬FALSEΪ��� ��
///
/// @param Pin��GPIO���
/// @param Dir��TRUEΪ���룬FALSEΪ���
/// @param iCount��Ҫ���õ�GPIO����
///
/// @retval DT_ERROR_OK�����ö��GPIO��IO�ܽŷ���ɹ�
/// @retval DT_ERROR_FAILED�����ö��GPIO��IO�ܽŷ���ʧ��
/// @retval DT_ERROR_PARAMETER_INVALID��GPIO���ֵ������Ч
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetMultiGpioPinDir(int Pin[], BOOL Dir[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡĳ��GPIO�ĵ�ƽ����������룬�����ⲿ��ƽ��������������Ϊ���õ�ƽ��
///
/// @param Pin��GPIO�ܽű��
/// @param Level��GPIO��ƽ
/// @param iCount��Ҫ���õ�GPIO����
///
/// @retval DT_ERROR_OK����ȡĳ��GPIO��IO�ܽŷ���ɹ�
/// @retval DT_ERROR_FAILED����ȡĳ��GPIO��IO�ܽŷ���ʧ��
/// @retval DT_ERROR_PARAMETER_INVALID��GPIO���ֵ������Ч
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetMultiGpioPinLevel(int Pin[],BOOL Level[],int iCount,int iDevID=DEFAULT_DEV_ID);
/****************************************************************************************
SPI����
*****************************************************************************************/

/// @brief uPort:SPI������ѡ��
/// 
/// @brief pSPIConfig:SPI���ýṹ�壬�μ�imagekit.h
/// 
/// @retval DT_ERROR_OK��SPI���óɹ�
/// @retval DT_ERROR_FAILD��SPI����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ MasterSpiConfig(UCHAR uPort,MasterSpiConfig_t *pSPIConfig,int iDevID = DEFAULT_DEV_ID);

/// @brief SPI������ʹ�ܡ��ٶȡ�ģʽ���ã�UT300/UV910����ע�⣺�ڲ���SensorSpiRW֮ǰ����ʹ��SPI���ߣ��������������ر�SPI���ߣ�����Ӱ��SENSOR i2c�ķ��ʡ�
/// 
/// @param bEnable��ΪTrue�ǿ���SPI���ߣ�ΪFalse�ǹر�SPI����
/// @param iRate��ΪTrue��500Kbps ΪFalse��250Kbps
/// @param bType�����߻�����ͨѶѡ��ΪFalse������SPIͨѶ��ΪTrue������SPIͨѶ
///
/// @retval DT_ERROR_OK�������ɹ�
///
/// @note �ڲ���SensorSpiRW֮ǰ����ʹ��SPI���ߣ��������������ر�SPI���ߣ�����Ӱ��SENSOR i2c�ķ���
DTCCM_API int _DTCALL_ SensorSpiInit(BOOL bEnable, int iRate=0, BOOL bType=FALSE, int iDevID=DEFAULT_DEV_ID);

/// @brief SPI�������ӿڣ�֧�����߻�����ͨѶ��֧�ֵ��ֽڴ���Ͷ��ֽ��������䣬֧�ֶ�дҪ��
///
/// @param bStart��ΪTrueƬѡ�ź����ͣ�ΪFalseƬѡ�źŲ�����
/// @param bStop��ΪTrueƬѡ�ź����ߣ�ΪFalseƬѡ�źŲ�����
/// @param bMsb��ΪTrue�Ǹ�λ�ȳ���ΪFalse�ǵ�λ�ȳ�
/// @param TxData��д�������BUFFER
/// @param RxData�����ص�����BUFFER
/// @param TxLen��д�����ݵĴ�С���ֽ���
/// @param RxLen����ȡ���ݵĴ�С���ֽ���

/// @retval DT_ERROR_OK�������ɹ�
/// @retval DT_ERROR_FAILD������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SensorSpiRW(BOOL bStart,BOOL bStop,BOOL bMsb,UCHAR *TxData,UCHAR *RxData,UCHAR TxLen,UCHAR RxLen,int iDevID=DEFAULT_DEV_ID);



/****************************************************************************************
���Խӿ�ʱ�����
*****************************************************************************************/
/// @brief ���Խӿڿɵ���ʱ�ӣ�֧�����Թܽ����0-200Khz�ɵ���ʱ�ӡ�
///
/// @param uHz�����ʱ�Ӵ�С����λHz��0-200Khz�ɵ���
/// @param bOnOff���ɵ���ʱ�����ʹ�ܣ�TrueΪ���ʹ�ܣ�FalseΪ�ر����
///
/// @retval DT_ERROR_OK������ʱ������ɹ�
/// @retval DT_ERROR_FAILD������ʱ�����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetSoftPinAdjClk1(UINT uHz,BOOL bOnOff,int iDevID=DEFAULT_DEV_ID);

/// @brief ���Խӿڿɵ���ʱ�ӣ�֧�����Թܽ����0-18Mhz�ɵ���ʱ�ӡ�
/// 
/// @param uHundkHz���������ʱ�Ӵ�С����λ100KHz��0-18Mhz�ɵ���
/// @param bOnOff���ɵ���ʱ�����ʹ�ܣ�TrueΪ���ʹ�ܣ�FalseΪ�ر����
///
/// @retval DT_ERROR_OK������ʱ������ɹ�
/// @retval DT_ERROR_FAILD������ʱ�����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetSoftPinAdjClk2(UINT uHundkHz,BOOL bOnOff,int iDevID=DEFAULT_DEV_ID);

/** @} */ // end of group3

/******************************************************************************
ͼ�����ݲɼ����
******************************************************************************/
/** @defgroup group4 ͼ�����ݲɼ����


* @{

*/
/// @brief ����ͼ�����ݲɼ���
///
/// @param uImgBytes��ͼ�����ݴ�С����λ�ֽ�
///
/// @retval DT_ERROR_OK������ͼ�����ݲɼ��ɹ�
/// @retval DT_ERROR_FAILD������ͼ�����ݲɼ�ʧ��
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ OpenVideo(UINT uImgBytes,int iDevID=DEFAULT_DEV_ID);

/// @brief �ر�ͼ�����ݲɼ���
///
/// @retval DT_ERROR_OK���ر�ͼ�����ݲɼ��ɹ�
/// @retval DT_ERROR_FAILD���ر�ͼ�����ݲɼ�ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ CloseVideo(int iDevID=DEFAULT_DEV_ID);

/// @brief ���òɼ�һ֡������
/// 
/// @param uGrabFrameSize������һ֡����������С����λ�ֽ�
DTCCM_API int _DTCALL_ SetGrabFrameSize(ULONG uGrabFrameSize,int iDevID=DEFAULT_DEV_ID);


/// @brief ����SENSORͼ�����ݽӿ����͡�
///
/// @param byPort��SENSORͼ�����ݽӿ����ͣ��μ�ö�����͡�SENSOR_PORT��
/// @param uWidth��ͼ�����ݿ��
/// @param uHeight��ͼ�����ݸ߶�
///
/// @retval DT_ERROR_OK������SENSORͼ�����ݽӿ����ͳɹ�
/// @retval DT_ERROR_FAILD������SENSORͼ�����ݽӿ�����ʧ�� 
/// @retval DT_ERROR_PARAMETER_INVALID����Ч��ͼ�����ݽӿ����Ͳ���
///
/// @see SENSOR_PORT
DTCCM_API int _DTCALL_ SetSensorPort(BYTE byPort,USHORT uWidth,USHORT uHeight,int iDevID=DEFAULT_DEV_ID);

/// @brief ��λSENSORͼ�����ݽӿ�
/// 
/// @param byPort��SENSORͼ�����ݽӿ����ͣ��μ�ö�����͡�SENSOR_PORT��
///
/// @retval DT_ERROR_OK�����óɹ�
/// @retval DT_ERROR_FAILD������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
///
/// @see SENSOR_PORT
DTCCM_API int _DTCALL_ ResetSensorPort(BYTE byPort,int iDevID=DEFAULT_DEV_ID);

/// @brief ����FrameBuffer
/// 
/// @param pConfig��FrameBuffer���ýṹ��,�ýṹ��˵���μ�imagekit.hͷ�ļ�
DTCCM_API int _DTCALL_ SetFrameBufferConfig(FrameBufferConfig *pConfig,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡFrameBuffer��������Ϣ
/// 
/// @param pConfig��FrameBuffer���ýṹ��,�ýṹ��˵���μ�imagekit.hͷ�ļ�
DTCCM_API int _DTCALL_ GetFrameBufferConfig(FrameBufferConfig *pConfig,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ղ��ԺеĻ���
/// 
/// @retval DT_ERROR_OK����ճɹ�
/// @retval DT_ERROR_FAILD�����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ ResetFrameBuffer(int iDevID=DEFAULT_DEV_ID);

/// @brief ����ROI��
///
/// @param roi_x0����ʼ��ˮƽ���꣬��λ�ֽ�
/// @param roi_y0����ʼ�㴹ֱ���꣬��λ�ֽ�
/// @param roi_hw��ˮƽ����ROIͼ���ȣ���λ�ֽ�
/// @param roi_vw����ֱ����ROIͼ��߶ȣ���λ�ֽ�
/// @param roi_hb��ˮƽ����blank��ȣ���λ�ֽ�
/// @param roi_vb��ˮƽ����blank�߶ȣ���λ�ֽ�
/// @param roi_hnum��ˮƽ����ROI��������λ�ֽ�
/// @param roi_vnum����ֱ����ROI��������λ�ֽ�
/// @param roi_en��ROIʹ��
///
/// @retval DT_ERROR_OK��ROI���óɹ�
/// @retval DT_ERROR_FAILD��ROI����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
///
/// @note �ú�����ָ����Ⱥ�ˮƽλ�������ֽ�Ϊ��λ�����ұ�֤���Ϊ4�ֽڵ���������
///
/// @image html roi.png

DTCCM_API int _DTCALL_ SetRoi(USHORT roi_x0, 
							  USHORT roi_y0, 
							  USHORT roi_hw, 
							  USHORT roi_vw, 
							  USHORT roi_hb, 
							  USHORT roi_vb, 
							  USHORT roi_hnum, 
							  USHORT roi_vnum, 
							  BOOL roi_en,
							  int iDevID=DEFAULT_DEV_ID);

/// @brief ����ROI��
///
/// @param roi_x0����ʼ��ˮƽ���꣬��λ����
/// @param roi_y0����ʼ�㴹ֱ���꣬��λ����
/// @param roi_hw��ˮƽ����ROIͼ���ȣ���λ����
/// @param roi_vw����ֱ����ROIͼ��߶ȣ���λ����
/// @param roi_hb��ˮƽ����blank��ȣ���λ����
/// @param roi_vb��ˮƽ����blank�߶ȣ���λ����
/// @param roi_hnum��ˮƽ����ROI��������λ����
/// @param roi_vnum����ֱ����ROI��������λ����
/// @param roi_en��ROIʹ��
///
/// @retval DT_ERROR_OK��ROI���óɹ�
/// @retval DT_ERROR_FAILD��ROI����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
///
/// @note �ú�����ָ����Ⱥ�ˮƽλ����������Ϊ��λ������Ҫ��֤���תΪ�ֽں���16�ֽڵ���������
///
/// @image html roi.png
DTCCM_API int _DTCALL_ SetRoiEx(USHORT roi_x0, 
								USHORT roi_y0, 
								USHORT roi_hw, 
								USHORT roi_vw, 
								USHORT roi_hb, 
								USHORT roi_vb, 
								USHORT roi_hnum, 
								USHORT roi_vnum, 
								BOOL roi_en,
								int iDevID=DEFAULT_DEV_ID);

/// @brief ���òɼ����ݳ�ʱ����λ��ms��������¼���û�вɼ���ͼ�����ݣ�GrabFrame���������س�ʱ����
///
/// @param uTimeOut���ɼ����ݳ�ʱʱ�����ã���λms
DTCCM_API int _DTCALL_ SetGrabTimeout(ULONG uTimeOut,int iDevID=DEFAULT_DEV_ID);

/// @brief ����ISP����ģʽģʽ,�μ�enum ISP_MODE
///
/// @param byMode��ISP����ģʽ��0Ϊnormal��1ΪS2DFAST��2ΪS2DFAST GPU
DTCCM_API int _DTCALL_ SetImageProcessMode(BYTE byMode,int iDevID=DEFAULT_DEV_ID);


/// @brief S2DFASTģʽץȡ���ݣ��õ�����RGB����
///
/// @param pBuf: ֡buffer
/// 
/// retval:DT_ERROR_FAILED:ץȡʧ�ܣ��õ�����֡
/// retval:DT_ERROR_TIMEOUT:ץȡ��ʱ��û��ץ������
DTCCM_API int _DTCALL_ S2DGrabFrameDirect(BYTE **ppBuf,FrameInfoEx *pInfo,int iDevID=DEFAULT_DEV_ID);

/// @brief �ͷ�buf��ÿ�ε���S2DGrabFrameDirectץ�����ݣ���ʾ�꣬�����ͷ�

DTCCM_API int _DTCALL_ S2DReleaseBufferDirect(BYTE *pBuf,int iDevID=DEFAULT_DEV_ID);

/// @brief У׼sensor���գ�����openvideo֮����ã�У׼�ɹ��ٽ���ץ֡����,���鳬ʱʱ�����1000ms
/// 
/// @param uTimeOut��У׼��ʱʱ�����ã���λms
/// 
/// @retval DT_ERROR_OK��У׼�ɹ������Բɼ�ͼ��
/// @retval DT_ERROR_TIME_OUT��У׼��ʱ
DTCCM_API int _DTCALL_ CalibrateSensorPort(ULONG uTimeOut,int iDevID=DEFAULT_DEV_ID);


/// @brief �ɼ�һ֡ͼ�񣬲��ҷ���֡��һЩ��Ϣ��Aͨ����Bͨ������ʹ��GrabFrame������ȡͼ�����ݣ�ͨ��֡��Ϣ��������ͼ������������ͨ����
///
/// @param pInBuffer���ɼ�ͼ��BUFFER
/// @param uBufferSize���ɼ�ͼ��BUFFER��С����λ�ֽ�
/// @param pGrabSize��ʵ��ץȡ��ͼ�����ݴ�С����λ�ֽ�
/// @param pInfo�����ص�ͼ��������Ϣ
///
/// @retval DT_ERROR_OK���ɼ�һ֡ͼ��ɹ�
/// @retval DT_ERROR_FAILD���ɼ�һ֡ͼ��ʧ�ܣ����ܲ���������һ֡ͼ������
/// @retval DT_ERROR_TIME_OUT���ɼ���ʱ
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ����� 
/// 
/// @note ���øú���֮ǰ�����ȸ���ͼ���С��ȡ���㹻��Ļ���������װ��ͼ�����ݡ�\n
/// ͬʱ���������Ĵ�СҲ��Ҫ��Ϊ�������뵽GrabFrame�������Է�ֹ�쳣����µ��µ��ڴ����Խ�����⡣ 
DTCCM_API int _DTCALL_ GrabFrame(BYTE *pInBuffer, ULONG uBufferSize,ULONG *pGrabSize,FrameInfo *pInfo,int iDevID=DEFAULT_DEV_ID);


/// @brief �ɼ�һ֡ͼ�񣬲��ҷ���֡��һЩ��Ϣ��ͨ��֡��Ϣ�ṹ����Ի�ȡ֡��ʱ�����ECC��CRC�ȡ�
///
/// @param pInBuffer���ɼ�ͼ��BUFFER
/// @param uBufferSize���ɼ�ͼ��BUFFER��С����λ�ֽ�
/// @param pGrabSize��ʵ��ץȡ��ͼ�����ݴ�С����λ�ֽ�
/// @param pInfo�����ص�ͼ��������Ϣ
///
/// @retval DT_ERROR_OK���ɼ�һ֡ͼ��ɹ�
/// @retval DT_ERROR_FAILD���ɼ�һ֡ͼ��ʧ�ܣ����ܲ���������һ֡ͼ������
/// @retval DT_ERROR_TIME_OUT���ɼ���ʱ
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ����� 
/// 
/// @note ���øú���֮ǰ�����ȸ���ͼ���С��ȡ���㹻��Ļ���������װ��ͼ�����ݡ�\n
/// ͬʱ���������Ĵ�СҲ��Ҫ��Ϊ�������뵽GrabFrameEx�������Է�ֹ�쳣����µ��µ��ڴ����Խ�����⡣ 
DTCCM_API int _DTCALL_ GrabFrameEx(BYTE *pInBuffer, ULONG uBufferSize,ULONG *pGrabSize,FrameInfoEx *pInfo,int iDevID=DEFAULT_DEV_ID);

/// @brief ͼ��ץ�����ã�����ʹ�ܺ�һ��ץ�ĵ�֡����
///
/// @param bSnapEn��ͼ��ץ��ʹ��
/// @param uSnapCount��һ��ץ�ĵ�֡��
///
/// @retval DT_ERROR_OK��ͼ��ץ�����óɹ�
/// @retval DT_ERROR_FAILD��ͼ��ץ������ʧ�� 
/// @retval DT_ERROR_COMM_ERROR��ͨѶ���� 
DTCCM_API int _DTCALL_ SetSnap(BOOL bSnapEn, UINT uSnapCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ����һ��ץ�ġ�
///
/// @retval DT_ERROR_OK����������һ��ץ�ĳɹ�
/// @retval DT_ERROR_FAILD����������һ��ץ��ʧ�� 
/// @retval DT_ERROR_COMM_ERROR��ͨѶ���� 
DTCCM_API int _DTCALL_ TriggerSnap(int iDevID=DEFAULT_DEV_ID);

/// @brief �ط���һ֡ͼ��
///
/// @retval DT_ERROR_OK�������ط���һ֡ͼ��ɹ�
/// @retval DT_ERROR_FAILD�������ط���һ֡ͼ��ʧ�� 
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ ReSendImage(int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ�ɼ�ͼ��Ŀ����Ϣ��ע�⣺*pWidth�ĵ�λΪ�ֽڡ�
///
/// @param pWidth����ȡ�Ĳɼ�ͼ������Ϣ
/// @param pHeight����ȡ�Ĳɼ�ͼ��߶���Ϣ
/// @param byChannel��A/Bͨ��ѡ��
///
/// @retval DT_ERROR_OK����ȡ�ɼ�ͼ��Ŀ����Ϣ�ɹ�
/// @retval DT_ERROR_FAILD����ȡ�ɼ�ͼ��Ŀ����Ϣʧ�� 
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetGrabImageSize(USHORT *pWidth,USHORT *pHeight,BYTE byChannel,int iDevID=DEFAULT_DEV_ID);

/// @brief ����ʵ��ץȡͼ�����ݵĴ�С����λ�ֽڣ���
/// 
/// @param pGrabSize������ʵ��ץȡͼ�����ݴ�С
DTCCM_API int _DTCALL_ CalculateGrabSize(ULONG *pGrabSize,int iDevID=DEFAULT_DEV_ID);


/// @brief ������λ�������е��ֽ�λ�á�
///
/// @param iPixelPos������λ��
/// @param byImgFormat��ͼ�����ݸ�ʽ
///
/// @retval ������������λ�������е��ֽ�λ��
DTCCM_API int _DTCALL_ GetByteOffset(int iPixelPos,BYTE byImgFormat,int iDevID=DEFAULT_DEV_ID);

/// @brief ����ʱ��㣬���óɹ����豸��ʱ���ֵ���Ӹ�ʱ��㿪ʼ��ʱ����λus��
/// 
/// @param uTimeStamp: ʱ���
/// 
/// @retval DT_ERROR_OK�����óɹ�
/// @retval DT_ERROR_FAILD������ʧ�� 
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetTimerClock(double uTime, int iDevID = DEFAULT_DEV_ID);

/// @brief ��ȡʱ���(��λus)
/// 
/// @param pTimeStamp: ʱ���ֵ
/// 
/// @retval DT_ERROR_OK�����óɹ�
/// @retval DT_ERROR_FAILD������ʧ�� 
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetTimeStamp(double *pTimeStamp, int iDevID = DEFAULT_DEV_ID);
/** @} */ // end of group4


/** @defgroup group5 ��Դ����Ԫ���


* @{

*/
/// @brief PMU��λ���п��ܵ���ϵͳ��Դ����������ģ�������ϵ硣
///
/// @retval DT_ERROR_OK��PMU��λ�ɹ�
/// @retval DT_ERROR_FAILD��PMU��λʧ��
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ PmuReset(int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡϵͳ��Դ״̬(��ѹ������)��
///
/// @param Power��ϵͳ��Դ���ͣ��μ�ö�����͡�SYS_POWER��
/// @param Voltage����ȡ��ϵͳ��ѹֵ����λmV
/// @param Current����ȡ��ϵͳ����ֵ����λmA
/// @param iCount��Ҫ��ȡ��ϵͳ��Դ��·��
///
/// @retval DT_ERROR_OK����ȡϵͳ��Դ״̬�ɹ�
///	@retval DT_ERROR_COMM_ERROR��ͨѶ����
///
/// @see SYS_POWER
/// 
/// @note �ú�����UV910/DTLC2/UH910/UH920/UF920/PE350/PE950֧�֡�
DTCCM_API int _DTCALL_ PmuGetSysPowerVA(SYS_POWER Power[],int Voltage[],int Current[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ���õ�Դģʽ��
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param Mode����Դģʽ���μ�ö�����͡�POWER_MODE��
/// @param iCount����Դ·��
/// 
/// @retval DT_ERROR_OK�����õ�Դģʽ�ɹ�
/// @retval DT_ERROR_FAILD�����õ�Դģʽʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
///
/// @see SENSOR_POWER
/// @see POWER_MODE
/// 
/// @note �ú�����UV910/DTLC2/UH910/UH920/UF920/PE350/PE950֧�֡�
DTCCM_API int _DTCALL_ PmuSetMode(SENSOR_POWER Power[],POWER_MODE Mode[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ���õ�Դ��ѹ��
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param Voltage�����õĵ�Դ��ѹֵ����λmV
/// @param iCount����Դ·��
///
/// @retval DT_ERROR_OK�����õ�Դ��ѹ�ɹ�
/// @retval DT_ERROR_FAILD�����õ�Դ��ѹʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
///
/// @see SENSOR_POWER
DTCCM_API int _DTCALL_ PmuSetVoltage(SENSOR_POWER Power[],int Voltage[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ��Դ��ѹ������ܻ�ȡ��⵽�ģ�����ʹ�ü�⵽�����ݣ����򷵻ص�ѹ����ֵ��
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param Voltage����ȡ�ĵ�Դ��ѹֵ����λmV
/// @param iCount����Դ·��
///
/// @retval DT_ERROR_OK�����õ�Դ��ѹ�ɹ�
/// @retval DT_ERROR_FAILD�����õ�Դ��ѹʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
///
/// @see SENSOR_POWER
DTCCM_API int _DTCALL_ PmuGetVoltage(SENSOR_POWER Power[],int Voltage[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ���õ�Դ�������̡�
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param Range����Դ�������̣��μ�ö�����͡�CURRENT_RANGE��
/// @param iCount����Դ·��
///
/// @retval DT_ERROR_OK�����õ�Դ�������̳ɹ�
/// @retval DT_ERROR_FAILD�����õ�Դ��������ʧ��
///
/// @see SENSOR_POWER
/// @see CURRENT_RANGE
///
/// @note �ú�����UV910/DTLC2/UH910/UH920/UF920/PE350/PE950֧�֡�
DTCCM_API int _DTCALL_ PmuSetCurrentRange(SENSOR_POWER Power[],CURRENT_RANGE Range[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ��Դ������
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param Current������ֵ,��λnA
/// @param iCount����Դ·��
///
/// @retval DT_ERROR_OK����ȡ��Դ�����ɹ�
/// @retval DT_ERROR_FAILD����ȡ��Դ����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
///
/// @see SENSOR_POWER
///
/// @note �ú�����UV910/DTLC2/UH910/UH920/UF920/PE350/PE950֧�֡�
DTCCM_API int _DTCALL_ PmuGetCurrent(SENSOR_POWER Power[],int Current[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ���õ�ѹ�����أ��趨ֵ(Rise)��λ:mV/mS��
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param Rise����ѹ������ֵ����λ:mV/mS
/// @param iCount����Դ·��
///
/// @retval DT_ERROR_OK�����õ�ѹ�����سɹ�
/// @retval DT_ERROR_FAILD�����õ�ѹ������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
///
/// @see SENSOR_POWER
/// 
/// @note �ú�����UV910/DTLC2/UH910/UH920/UF920/PE350/PE950֧�֡�
DTCCM_API int _DTCALL_ PmuSetRise(SENSOR_POWER Power[],int Rise[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ���õ����ɼ��ٶȣ��趨ֵ(SampleSpeed)10-200��
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param SampleSpeed�������ɼ��ٶȣ���Χ10-200
/// @param iCount����Դ·��
///
/// @retval DT_ERROR_OK�����õ����ɼ��ٶȳɹ�
/// @retval DT_ERROR_FAILD�����õ����ɼ��ٶ�ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
///
/// @see SENSOR_POWER
/// 
/// @note �ú�����UV910/DTLC2/UH910/UH920/UF920/PE350/PE950֧�֡�
DTCCM_API int _DTCALL_ PmuSetSampleSpeed(SENSOR_POWER Power[],int SampleSpeed[],int iCount,int iDevID=DEFAULT_DEV_ID);


/// @brief ���õ�Դ����״̬��
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param OnOff�����õ�Դ����״̬��TRUEΪ������FALSEΪ�ر�
/// @param iCount����Դ·��
///
/// @retval DT_ERROR_OK�����õ�Դ����״̬�ɹ�
/// @retval DT_ERROR_FAILD�����õ�Դ����״̬ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
///
/// @see SENSOR_POWER
DTCCM_API int _DTCALL_ PmuSetOnOff(SENSOR_POWER Power[],BOOL OnOff[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ��Դ����״̬��
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param OnOff����ȡ��Դ����״̬��TRUEΪ������FALSEΪ�ر�
/// @param iCount����Դ·��
///
/// @retval DT_ERROR_OK����ȡ��Դ����״̬�ɹ�
/// @retval DT_ERROR_FAILD����ȡ��Դ����״̬ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
///
/// @see SENSOR_POWER
DTCCM_API int _DTCALL_ PmuGetOnOff(SENSOR_POWER Power[],BOOL OnOff[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ���ù��������ĵ�������,�趨ֵ(CurrentLimit)��λ:mA��
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param CurrentLimit�����ù��������ĵ�������ֵ����λmA
/// @param iCount����Դ·��
///
/// @retval DT_ERROR_OK�����ù��������ĵ������Ƴɹ�
/// @retval DT_ERROR_FAILD�����ù��������ĵ�������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
///
/// @see SENSOR_POWER
DTCCM_API int _DTCALL_ PmuSetOcpCurrentLimit(SENSOR_POWER Power[],int CurrentLimit[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ����OCP��ʱ(����ʱ����ۼ�),�趨ֵ(Delay)��λ:mS��
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param Delay��OCP��ʱ�趨ֵ
/// @param iCount����Դ·��
///
/// @retval DT_ERROR_OK������OCP��ʱ�ɹ�
/// @retval DT_ERROR_FAILD������OCP��ʱʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
///
/// @see SENSOR_POWER
/// 
/// @note �ú�����UV910/DTLC2/UH910/UH920/UF920/PE350/PE950֧�֡�
DTCCM_API int _DTCALL_ PmuSetOcpDelay(SENSOR_POWER Power[],int Delay[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ����OCP�ض�ʱ��(���жϹ��������󣬹ض�һ��ʱ��),�趨ֵ(Hold)��λ:mS��
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param Hold��OCP�ض�ʱ��
/// @param iCount����Դ·��
///
/// @retval DT_ERROR_OK������OCP�ض�ʱ��ɹ�
/// @retval DT_ERROR_FAILD������OCP�ض�ʱ��ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
///
/// @see SENSOR_POWER
/// 
/// @note �ú�����UV910/DTLC2/UH910/UH920/UF920/PE350/PE950֧�֡�
DTCCM_API int _DTCALL_ PmuSetOcpHold(SENSOR_POWER Power[],int Hold[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ����״̬,������Ϣ(State)TRUE:��������,FALSE:������
///
/// @param Power����Դ���ͣ��μ�ö�����͡�SENSOR_POWER��
/// @param State����ȡ���Ĺ���״̬
/// @param iCount����Դ·��
///
/// @retval DT_ERROR_OK������OCP�ض�ʱ��ɹ�
/// @retval DT_ERROR_FAILD������OCP�ض�ʱ��ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
///
/// @see SENSOR_POWER
/// 
/// @note �ú�����UV910/DTLC2/UH910/UH920/UF920/PE350/PE950֧�֡�
DTCCM_API int _DTCALL_ PmuGetOcpState(SENSOR_POWER Power[],BOOL State[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ����SENSOR��Դ���ء�
///
/// @param bOnOff��SENSOR��Դ��������ֵ��TRUEΪ������FALSEΪ�ر�
///
/// @retval DT_ERROR_OK������SENSOR��Դ���سɹ�
/// @retval DT_ERROR_FAILD������SENSOR��Դ����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_OUT_OF_BOUND�����������˷�Χ
/// 
/// @note �ú�����UV910/DTLC2/UH910/UH920/UF920/PE350/PE950֧�֡�
DTCCM_API int _DTCALL_ SetSensorPowerOnOff(BOOL bOnOff,int iDevID=DEFAULT_DEV_ID);


/** @} */ // end of group5


/******************************************************************************
��ʼ�����������
******************************************************************************/
/** @defgroup group6 ��ʼ���������


* @{

*/
/// @brief ���豸��ֻ�д򿪳ɹ����豸���ܲ���;�豸���������ID��Ӧ����iDevID=1 �򴴽��豸����m_device[1]��iDevID=0 �򴴽��豸����m_device[0]��
///
/// @param pszDeviceName�����豸������
/// @param pDevID�����ش��豸��ID��
///
/// @retval DT_ERROR_OK�����豸�ɹ�
/// @retval DT_ERROR_FAILD�����豸ʧ��
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
/// @retval DT_ERROR_PARAMETER_INVALID��������Ч
DTCCM_API int _DTCALL_ OpenDevice(const char *pszDeviceName,int *pDevID,int iDevID=DEFAULT_DEV_ID);

/// @brief ���������豸��usb3.0�豸��Ч
///
/// @retval DT_ERROR_OK�����豸�ɹ�
/// @retval DT_ERROR_FAILD�����豸ʧ��
DTCCM_API int _DTCALL_ DeviceReset(int iDevID=DEFAULT_DEV_ID);


/// @brief �������̼�ģʽ���豸��ֻ�д򿪳ɹ����豸���ܲ�����
///
/// @param pszDeviceName�����豸������
/// @param pDevID�����ش��豸��ID��
///
/// @retval DT_ERROR_OK�����豸�ɹ�
/// @retval DT_ERROR_FAILD�����豸ʧ��
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
/// @retval DT_ERROR_PARAMETER_INVALID��������Ч
DTCCM_API int _DTCALL_ OpenDeviceUpgradeMode(const char *pszDeviceName,int *pDevID,int iDevID=DEFAULT_DEV_ID);

/// @brief �ر��豸���ر��豸�󣬲����ٲ�����
///
/// @retval DT_ERROR_OK���ر��豸�ɹ�
/// @retval DT_ERROR_FAILD���ر��豸ʧ��
DTCCM_API int _DTCALL_ CloseDevice(int iDevID=DEFAULT_DEV_ID);

/// @brief ��ʼ���豸���ú�����Ҫ���ڳ�ʼ���豸��SENSOR�ӿ����ͣ�ͼ���ʽ��ͼ������Ϣ��ͬʱ��Ҫ���û�����������Ƶ��ʾ�Ĵ��ھ����
///
/// @param hWnd����ʾAͨ��ͼ��Ĵ��ھ��
/// @param uImgWidth��uImgHeight������SENSOR����Ŀ����Ϣ����λ�����أ�����ROI֮��Ľ����
/// @param bySensorPort��SENSOR����ӿ����ͣ��磺MIPI/����
/// @param byImgFormat��ͼ�����ݸ�ʽ���磺RAW/YUV
/// @param byChannel��Aͨ��/Bͨ��/ABͬʱ����
/// @param hWndEx����ʾBͨ��ͼ��Ĵ��ھ��
///
/// @retval DT_ERROR_OK����ʼ���ɹ�
/// @retval DT_ERROR_FAILD����ʼ��ʧ��
/// @retval DT_ERROR_PARAMETER_INVALID��bySensorPort������Ч
///
/// @note InitDevice����֧�ֳ�ʼ��˫ͨ�����԰壨��DTLC2/UH910���������Ҫʹ��������԰��Bͨ�����������¶��������
/// @note byChannel��������CHANNEL_A|CHANNEL_B��hWndEx������������Bͨ����Ƶ��ʾ�Ĵ��ھ����
DTCCM_API int _DTCALL_ InitDevice(HWND hWnd, 
								  USHORT uImgWidth, 
								  USHORT uImgHeight,
								  BYTE bySensorPort,
								  BYTE byImgFormat,
								  BYTE byChannel=CHANNEL_A,
								  HWND hWndEx=NULL,
								  int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ�豸�ϰ�ť�İ���ֵ��
///
/// @param pKey����ȡ���İ���ֵ
///
/// @retval DT_ERROR_OK����ȡ����ֵ�ɹ�
/// @retval DT_ERROR_FAILED����ȡ����ֵʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
DTCCM_API int _DTCALL_ GetKey(DWORD *pKey,int iDevID=DEFAULT_DEV_ID);

/// @brief ���ñ������ȡ�
///
/// @param uBeepTime������������ʱ�䣬��λΪmS
/// @param iBeepCount�����������д���
///
/// @retval DT_ERROR_OK�����ñ������ȳɹ�
/// @retval DT_ERROR_FAILED�����ñ�������ʧ��
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
DTCCM_API int _DTCALL_ SetAlarm(USHORT uBeepTime, int iBeepCount,int iDevID=DEFAULT_DEV_ID);
/** @} */ // end of group6

/// @brief ��ʼ��ISP
/// 
/// @param uImgWidth��ͼ�����ݿ��
/// @param uHeight��ͼ�����ݸ߶�
/// @param byImgFormat��ͼ�����ݸ�ʽ���磺RAW/YUV
/// @param byChannel��A/Bͨ��ѡ��
DTCCM_API int _DTCALL_ InitIsp(USHORT uImgWidth,USHORT uImgHeight,BYTE byImgFormat,BYTE byChannel=CHANNEL_A,int iDevID=DEFAULT_DEV_ID);

/// @brief ����ROI��
///
/// @param roi_x0����ʼ��ˮƽ���꣬��λ����
/// @param roi_y0����ʼ�㴹ֱ���꣬��λ����
/// @param roi_hw��ˮƽ����ROIͼ���ȣ���λ����
/// @param roi_vw����ֱ����ROIͼ��߶ȣ���λ����
/// @param roi_hb��ˮƽ����blank��ȣ���λ����
/// @param roi_vb��ˮƽ����blank�߶ȣ���λ����
/// @param roi_hnum��ˮƽ����ROI��������λ����
/// @param roi_vnum����ֱ����ROI��������λ����
/// @param byImgFormat��ͼ�����ݸ�ʽ���磺RAW/YUV
/// @param roi_en��ROIʹ��
///
/// @retval DT_ERROR_OK��ROI���óɹ�
/// @retval DT_ERROR_FAILD��ROI����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
///
/// @note �ú�����ָ����Ⱥ�ˮƽλ����������Ϊ��λ������Ҫ��֤���תΪ�ֽں���16�ֽڵ���������
///
/// @image html roi.png
DTCCM_API int InitRoi(USHORT roi_x0, 
					  USHORT roi_y0, 
					  USHORT roi_hw, 
					  USHORT roi_vw, 
					  USHORT roi_hb, 
					  USHORT roi_vb, 
					  USHORT roi_hnum, 
					  USHORT roi_vnum, 
					  BYTE byImgFormat,
					  BOOL roi_en,
					  int iDevID=DEFAULT_DEV_ID);
/******************************************************************************
AF���
******************************************************************************/

/** @defgroup group7 AF���


* @{

*/
/// @brief ��ȡAF������D/AоƬ�ͺź�������ַ��
///
/// @param pDevType����ȡAF������D/AоƬ�ͺ�
/// @param pDevAddr����ȡAF������D/A������ַ
DTCCM_API int _DTCALL_ GetAfDevType(UCHAR *pDevType, UCHAR *pDevAddr, int iDevID=DEFAULT_DEV_ID);


/// @brief ����AF������D/AоƬ�ͺź�������ַ��
///
/// @param uDevType������AF������D/AоƬ�ͺ�
/// @param uDevAddr������AF������D/A������ַ
DTCCM_API int _DTCALL_ SetAfDevType(UCHAR uDevType, UCHAR uDevAddr, int iDevID=DEFAULT_DEV_ID);

/// @brief ����AF������D/A�����ֵ��
///
/// @param uValue�����õ�AF������D/A���ֵ
/// @param uMode��AF����IC��ģʽ
///
/// @retval DT_ERROR_OK������AF������D/A�����ֵ�ɹ�
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
/// @retval DT_ERROR_PARAMETER_INVALID��I2Cģʽ��Ч
/// @retval DT_ERROR_TIME_OUT��ͨѶ��ʱ
/// @retval DT_ERROR_INTERNAL_ERROR���ڲ�����
/// @retval DT_ERROR_NOT_SUPPORTED����֧�ֵ�AF��������
/// @retval DT_ERROR_NOT_INITIALIZED��û�г�ʼ��AF������D/A������ַ
DTCCM_API int _DTCALL_ WriteAfValue(USHORT uValue, UCHAR uMode, int iDevID=DEFAULT_DEV_ID);


/// @brief ����AF�����е�D/AоƬ��
///
/// @retval DT_ERROR_OK������AF�����е�D/AоƬ�ɹ�
/// @retval DT_ERROR_FAILD������AF�����е�D/AоƬʧ��
DTCCM_API int _DTCALL_ FindAfDevice(int iDevID=DEFAULT_DEV_ID);
/** @} */ // end of group7


/****************************************************************************************
LC/OS���
****************************************************************************************/

/** @defgroup group8 LC/OS���


* @{

*/
/// @brief LC/OS���Բ������á�
/// 
/// @param Command�������룬�μ��궨�塰OS/LC�������ö��塱
/// @param IoMask����Ч�ܽű�ʶλ��ÿ�ֽڵ�ÿbit��Ӧһ���ܽţ������ЩbitΪ1����ʾ��Ӧ�ĹܽŽ��������
/// @param PinNum���ܽ������������IoMask�����С��һ�������IoMask���ֽ���Ϊ��PinNum/8+(PinNum%8!=0)
///
/// @retval DT_ERROR_OK��LC/OS���Բ������óɹ�
/// @retval DT_ERROR_FAILD��LC/OS���Բ�������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ LC_OS_CommandConfig(DWORD Command, UCHAR IoMask[], int PinNum, int iDevID=DEFAULT_DEV_ID);

/// @brief OS���Բ������á�
///
/// @param Voltage�����Ե�ѹ����λuV
/// @param HighLimit��Open���Ա�׼���飬����֮ǰӦ�ð�ÿһ������pin�Ŀ�·��׼��ʼ���ã���λuV
/// @param LowLimit��Short���Ա�׼���飬����֮ǰӦ�ð�ÿһ������pin�Ŀ�·��׼��ʼ���ã���λuV
/// @param PinNum���ܽ������������HighLimit��LowLimit�����С
/// @param PowerCurrent����Դpin��������λuA
/// @param GpioCurrent��GPIOpin��������λuA
///
/// @retval DT_ERROR_OK��OS���Բ������óɹ�
/// @retval DT_ERROR_FAILD��OS���Բ�������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ OS_Config(int Voltage, int HighLimit[], int LowLimit[], int PinNum, int PowerCurrent, int GpioCurrent, int iDevID=DEFAULT_DEV_ID);

/// @brief OS���Խ����ȡ��
///
/// @param VoltageH������pos���Խ������λuV
/// @param VoltageH������pos���Խ������λuV
/// @param Result������·���Խ�����μ��궨�塰OS���Խ�����塱
/// @param PosEn���������ʹ�� 
/// @param NegEn���������ʹ��
/// @param PinNum���ܽ������������VoltageH��VoltageL��Result�����С
/// 
/// @retval DT_ERROR_OK��OS���Խ����ȡ�ɹ�
/// @retval DT_ERROR_FAILD��OS���Խ����ȡʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ OS_Read(int VoltageH[], int VoltageL[], UCHAR Result[], BOOL PosEn, BOOL NegEn, int PinNum, int iDevID=DEFAULT_DEV_ID);

/// @brief LC���Բ������á�
///
/// @param Voltage��LC���Ե�ѹ����λmV
/// @param Range��LC�������ã�RangeΪ0������1uA��RangeΪ1������10nA
///
/// @retval DT_ERROR_OK��LC�����������óɹ�
/// @retval DT_ERROR_FAILD��LC���Բ�������ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ LC_Config(USHORT Voltage, UCHAR Range, int iDevID=DEFAULT_DEV_ID);

/// @brief LC���Խ����ȡ��
///
/// @param CurrentH��������Խ����λnA
/// @param CurrentL��������Խ����λnA
/// @param PinNum���ܽ������������CurrentH��CurrentL�������С
///
/// @retval DT_ERROR_OK��LC���Խ����ȡ�ɹ�
/// @retval DT_ERROR_FAILD��LC���Խ����ȡʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ LC_Read(ULONG CurrentH[],ULONG CurrentL[],int PinNum,int iDevID=DEFAULT_DEV_ID);

/// @brief ����״ֵ̬��ȡ��
///
/// @param Result�����ؿ���״ֵ̬
/// @param PinNum���ܽ������������CurrentH��CurrentL�������С
///
/// @retval DT_ERROR_OK��LC����״ֵ̬��ȡ�ɹ�
/// @retval DT_ERROR_FAILD��LC����״ֵ̬��ȡʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ LC_ReadSwitch(UCHAR Result[],int PinNum,int iDevID=DEFAULT_DEV_ID);
/** @} */ // end of group8

/** @defgroup group9 ��չIO


* @{

*/
/************************************************************************
 ��չIO                                                                     
************************************************************************/
/// @brief �����ⲿ��չ��3.3V��ѹ�����
///
/// @param bEnable����չ��ѹ���ʹ��
///
/// @retval DT_ERROR_OK�������ⲿ��չ��3.3V��ѹ����ɹ�
/// @retval DT_ERROR_FAILD�������ⲿ��չ��3.3V��ѹ���ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetExtPowerEnable(BOOL bEnable,int iDevID=DEFAULT_DEV_ID);

/// @brief �����ⲿ��չ��ʱ�������
///
/// @param bOnOff��ʹ��ʱ�����
/// @param uHundKhz������ʱ�����ֵ,��λKhz
///
/// @retval DT_ERROR_OK�������ⲿ��չʱ������ɹ�
/// @retval DT_ERROR_FAILD�������ⲿ��չʱ�����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetExtClock(BOOL bOnOff,USHORT uHundKhz,int iDevID=DEFAULT_DEV_ID);

/// @brief �����ⲿ��չGPIOģʽ��
///
/// @param Pin[]��GPIO��ţ��μ��궨�塰EXT_GPIO��
/// @param Mode[]��ģʽ���ã��μ�ö�����͡�EXT_GPIO_MODE��
/// @param iCount������IO����
///
/// @retval DT_ERROR_OK�������ⲿ��չGPIOģʽ�ɹ�
/// @retval DT_ERROR_FAILD�������ⲿ��չGPIOģʽʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetExtIoMode(EXT_GPIO Pin[],EXT_GPIO_MODE Mode[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief �㶨��ƽ���ģʽʱ�����ⲿ��չGPIO��ƽ��
///
/// @param Pin[]��GPIO��ţ��μ��궨�塰EXT_GPIO��
/// @param Level[]��GPIO�ĵ�ƽֵ��FALSEΪ�͵�ƽ��TRUEΪ�ߵ�ƽ
/// @param iCount������IO����
///
/// @retval DT_ERROR_OK�������ⲿ��չGPIO��ƽ�ɹ�
/// @retval DT_ERROR_FAILD�������ⲿ��չGPIO��ƽʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetExtIoLevel(EXT_GPIO Pin[],BOOL Level[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ�ⲿ��չGPIO�ĵ�ƽ��
/// 
/// @param Pin[]��GPIO��ţ��μ��궨�塰EXT_GPIO��
/// @param Level[]��GPIO�ĵ�ƽֵ��FALSEΪ�͵�ƽ��TRUEΪ�ߵ�ƽ
/// @param iCount������IO����
///
/// @retval DT_ERROR_OK����ȡ�ⲿ��չGPIO��ƽ�ɹ�
/// @retval DT_ERROR_FAILD����ȡ�ⲿ��չGPIO��ƽʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetExtIoLevel(EXT_GPIO Pin[],BOOL Level[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief ��չGPIOΪ�ߵ͵�ƽ�������ʱ���ߡ��͵�ƽʱ�����á�
/// 
/// @param Pin[]��GPIO��ţ��μ��궨�塰EXT_GPIO��
/// @param HighLevelTime[]����Ӧ��չGPIO�ߵ�ƽʱ�䣬��λus
/// @param LowLevelTime[]����Ӧ��չGPIO�͵�ƽʱ�䣬��λus
/// @param iCount������IO����
///
/// @retval DT_ERROR_OK�������ⲿ��չGPIO�ߵ͵�ƽʱ��ɹ�
/// @DT_ERROR_FAILD�����ⲿ��չGPIO�ߵ͵�ƽʱ��ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetExtIoLevelTime(EXT_GPIO Pin[],int HighLevelTime[],int LowLevelTime[],int iCount,int iDevID=DEFAULT_DEV_ID);

/// @brief �ⲿ��չI2Cд
///
/// @param uDevAddr���豸��ַ
/// @param uRegAddr���豸�Ĵ���
/// @param uRegAddrSize���Ĵ�����ַ���ֽ���
/// @param pData��д��Ĵ��������ݿ�
/// @param uSize��д��Ĵ��������ݿ��С,���Ϊ60���ֽ�
/// 
/// @retval DT_ERROR_OK��д�ɹ�
/// @retval DT_ERROR_FAILD��дʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ ExtI2cWrite(UCHAR uDevAddr,USHORT uRegAddr,UCHAR uRegAddrSize,BYTE *pData,USHORT uSize,int iDevID=DEFAULT_DEV_ID);

/// @brief �ⲿ��չI2C��
///
/// @param uDevAddr���豸��ַ
/// @param uRegAddr���豸�Ĵ���
/// @param uRegAddrSize���Ĵ�����ַ���ֽ���
/// @param pData�����Ĵ��������ݿ�
/// @param uSize�����Ĵ��������ݿ��С,���Ϊ60���ֽ�
/// @param bNoStop���Ƿ񷢳�I2C��STOP���һ�������Ĭ��ΪFALSE��bNoStop=TRUE��ʾд�Ĺ��̲�����I2C��ֹͣ���bNoStop=FALSE��I2C��ֹͣ����
/// 
/// @retval DT_ERROR_OK�����ɹ�
/// @retval DT_ERROR_FAILD����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ ExtI2cRead(UCHAR uDevAddr,USHORT uRegAddr,UCHAR uRegAddrSize,BYTE *pData,USHORT uSize,BOOL bNoStop=FALSE,int iDevID=DEFAULT_DEV_ID);

/// @brief �����ⲿ��������ӿڵ�ƽ
/// 
/// @param iTriggerOutPin����������ӿڱ�ţ���ǰ��Ÿ����Ʒ�ṩһ���������IO��
/// @param bTriggerOutFollowEnable����������ӿڸ���ʹ���źţ���Ϊ1�����TriggerIn�źŵ�ƽ��Ϊ0��Ϊ���õ�ƽֵ
/// @param bLevel����ƽֵ��0Ϊ����͵�ƽ��1Ϊ����ߵ�ƽ��
///
/// @retval DT_ERROR_OK�����ɹ�
/// @retval DT_ERROR_FAILD����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ SetTriggerOutLevel(int iTriggerOutPin,BOOL bFollowTrigIn,BOOL bLevel,int iDevID=DEFAULT_DEV_ID);

/// @brief ��ȡ�ⲿ��������ӿڵ�ƽ
/// 
/// @param iTriggerInPin����������ӿڱ�ţ���ǰ��Ÿ����Ʒ�ṩһ���������IO��
/// @param pLevel�����صĵ�ƽֵ��0Ϊ����͵�ƽ��1Ϊ����ߵ�ƽ��
///
/// @retval DT_ERROR_OK�����ɹ�
/// @retval DT_ERROR_FAILD����ʧ��
/// @retval DT_ERROR_COMM_ERROR��ͨѶ����
DTCCM_API int _DTCALL_ GetTriggerInLevel(int iTriggerInPin,BOOL *pLevel,int iDevID=DEFAULT_DEV_ID);

/** @} */ // end of group9

/*************************************************************************
�¶ȴ��������
*************************************************************************/

// �����¶ȴ������������¶�
DTCCM_API int _DTCALL_ SetTempRange(int iUpperLimit, int iLowerLimit, BOOL bEnable,int iDevID=DEFAULT_DEV_ID);

// ��ȡ��ǰ�¶�ֵ
DTCCM_API int _DTCALL_ GetCurrentTemp(int *pTemp,int iDevID=DEFAULT_DEV_ID);

// ��ȡ��ǰ���õ��¶ȷ�Χ
DTCCM_API int _DTCALL_ GetTempRange(int *pUpperLimit,int *pLowLimit,int iDevID=DEFAULT_DEV_ID);

/*************************************************************************
״̬��
*************************************************************************/
// ״̬��Ϣ����
DTCCM_API int _DTCALL_ ShowInternalStatusDialog(HWND hwnd,int iDevID=DEFAULT_DEV_ID);

DTCCM_API int _DTCALL_ ShowInternalStatusDialogEx(HWND hwnd ,HWND *pRetHwnd,int iDevID=DEFAULT_DEV_ID);

DTCCM_API int _DTCALL_ ShowMipiControllerDialog(HWND hwnd ,HWND *pRetHwnd,int iDevID=DEFAULT_DEV_ID);

DTCCM_API int _DTCALL_ ShowFrameBufferControlDialog(HWND hwnd ,HWND *pRetHwnd,int iDevID=DEFAULT_DEV_ID);

//DTCCM_API int _DTCALL_ SaveParameter(int iDevID=DEFAULT_DEV_ID);

//DTCCM_API int _DTCALL_ LoadParameter(int iDevID=DEFAULT_DEV_ID);
/****************************************************************************************
����
****************************************************************************************/
// ��չ���ƽӿ�
// dwCtrl:	�����룬�����������ඨ��
// dwParam:	��������ز���
// pIn:		��ȡ������
// pInSize:	��ȡ���ݵĴ�С���ֽ�����������ָ��Ҫ���ȡ���ֽ���������ɹ�������ʵ�ʶ�ȡ���ֽ���
// pOut:	д�������
// pOutSize:д�����ݵĴ�С���ֽ�����������ָ��Ҫ��д����ֽ���������ɹ�������ʵ��д����ֽ���
DTCCM_API int _DTCALL_ ExCtrl(DWORD dwCtrl,DWORD dwParam,PVOID pIn,int *pInSize,PVOID pOut,int *pOutSize,int iDevID=DEFAULT_DEV_ID);


#endif