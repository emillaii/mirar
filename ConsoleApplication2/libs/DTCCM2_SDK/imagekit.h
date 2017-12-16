#ifndef __IMAGEKIT_H__
#define __IMAGEKIT_H__


/**************************************************************************************** 
*
* image kitϵ�и���Ӳ���汾����
*
****************************************************************************************/

#define VER_HS100   0x1000
#define VER_HS200   0x1020

#define VER_HS120   0x1020 
#define VER_HS128	0x1200
#define VER_HS230   0x1230

#define VER_HS280	0x1280

#define VER_HS130	0x1300
#define VER_HS300   0x1330
#define VER_HS320   0x1332

#define VER_HV810   0x1380
#define VER_HV820   0x1382
#define VER_HV910   0x1390
#define VER_HV920   0x1392

/**************************************************************************************** 
*
* SENSOR�ĳ�ʼ����������
*
****************************************************************************************/

typedef struct _SensorTab
{
	/// @brief SENSOR���
	USHORT width;          ///<SENSOR���
	/// @brief SENSOR�߶�
	USHORT height;         ///<SENSOR�߶�
	/// @brief SENSOR��������
	BYTE type;             ///<SENSOR��������
	/// @brief SENSOR��RESET��PWDN��������
	BYTE pin;              ///<SENSOR��RESET��PWDN��������
	/// @brief SENSOR��������ַ
	BYTE SlaveID;          ///<SENSOR��������ַ
	/// @brief SENSOR��I2Cģʽ
	BYTE mode;						 ///<SENSOR��I2Cģʽ
	/// @brief SENSOR��־�Ĵ���1.
	USHORT FlagReg;				 ///<SENSOR��־�Ĵ���1.
	/// @brief SENSOR��־�Ĵ���1��ֵ
	USHORT FlagData;			 ///<SENSOR��־�Ĵ���1��ֵ
	/// @brief SENSOR��־�Ĵ���1������ֵ
	USHORT FlagMask;			 ///<SENSOR��־�Ĵ���1������ֵ
	/// @brief SENSOR��־�Ĵ���2.
	USHORT FlagReg1;			 ///<SENSOR��־�Ĵ���2.
	/// @brief SENSOR��־�Ĵ���2��ֵ
	USHORT FlagData1;			 ///<SENSOR��־�Ĵ���2��ֵ
	/// @brief SENSOR��־�Ĵ���2������ֵ
	USHORT FlagMask1;			 ///<SENSOR��־�Ĵ���2������ֵ
	/// @brief SENSOR������
	char name[64];				///<SENSOR������

	/// @brief ��ʼ��SENSOR���ݱ�
	USHORT* ParaList;			///<��ʼ��SENSOR���ݱ�
	/// @brief ��ʼ��SENSOR���ݱ��С����λ�ֽ�
	USHORT  ParaListSize; ///<��ʼ��SENSOR���ݱ��С����λ�ֽ�

	/// @brief SENSOR����Sleepģʽ�Ĳ�����
	USHORT* SleepParaList;	///<SENSOR����Sleepģʽ�Ĳ�����
	/// @brief SENSOR����Sleepģʽ�Ĳ������С����λ�ֽ�
	USHORT  SleepParaListSize;///<SENSOR����Sleepģʽ�Ĳ������С����λ�ֽ�

	/// @brief SENSOR������ݸ�ʽ��YUV//0:YCbYCr;	//1:YCrYCb;	//2:CbYCrY;	//3:CrYCbY.
	BYTE outformat;         ///<SENSOR������ݸ�ʽ��YUV//0:YCbYCr;	//1:YCrYCb;	//2:CbYCrY;	//3:CrYCbY.
	/// @brief SENSOR������ʱ��MCLK��0:12M; 1:24M; 2:48M.
	int mclk;               ///<SENSOR������ʱ��MCLK��0:12M; 1:24M; 2:48M.
	/// @brief SENSOR��AVDD��ѹֵ
	BYTE avdd;              ///<SENSOR��AVDD��ѹֵ
	/// @brief SENSOR��DOVDD��ѹֵ
	BYTE dovdd;             ///<SENSOR��DOVDD��ѹֵ
	/// @brief SENSOR��DVDD��ѹֵ		
	BYTE dvdd;							///<SENSOR��DVDD��ѹֵ

	/// @brief SENSOR�����ݽӿ�����
	BYTE port; 							///<SENSOR�����ݽӿ�����
	USHORT Ext0;
	USHORT Ext1;
	USHORT Ext2; 

	/// @brief AF��ʼ��������
	USHORT* AF_InitParaList;        ///<AF��ʼ��������
	/// @brief AF��ʼ���������С����λ�ֽ�
	USHORT  AF_InitParaListSize;		///<AF��ʼ���������С����λ�ֽ�

	/// @brief AF_AUTO������
	USHORT* AF_AutoParaList;				///<AF_AUTO������
	/// @brief AF_AUTO�������С����λ�ֽ�
	USHORT  AF_AutoParaListSize;		///<AF_AUTO�������С����λ�ֽ�

	/// @brief AF_FAR������
	USHORT* AF_FarParaList;					///<AF_FAR������
	/// @brief AF_FAR�������С����λ�ֽ�
	USHORT  AF_FarParaListSize;			///<AF_FAR�������С����λ�ֽ�

	/// @brief AF_NEAR������
	USHORT* AF_NearParaList;				///<AF_NEAR������
	/// @brief AF_NEAR�������С����λ�ֽ�
	USHORT  AF_NearParaListSize;		///<AF_NEAR�������С����λ�ֽ�

	/// @brief �ع������
	USHORT* Exposure_ParaList;      ///<�ع������
	/// @brief �ع�������С����λ�ֽ�
	USHORT  Exposure_ParaListSize;	///<�ع�������С����λ�ֽ�

	/// @brief ���������
	USHORT* Gain_ParaList;          ///<���������
	/// @brief ����������С����λ�ֽ�
	USHORT	Gain_ParaListSize;			///<����������С����λ�ֽ� 

	_SensorTab()
	{
		width=0;
		height=0;
		type=0;
		pin=0;
		SlaveID=0;
		mode=0;
		FlagReg=0;
		FlagData=0;
		FlagMask=0;
		FlagReg1=0;
		FlagData1=0;
		FlagMask1=0;
		memset(name,0,sizeof(name));

		ParaList=NULL;
		ParaListSize=0;
		SleepParaList=NULL;
		SleepParaListSize=0;

		outformat=0;
		mclk=0;               //0:12M; 1:24M; 2:48M.
		avdd=0;               // 
		dovdd=0;              //
		dvdd=0;

		port=0; 	
		Ext0=0;
		Ext1=0;
		Ext2=0; 

		AF_InitParaList=NULL;        //AF_InitParaList
		AF_InitParaListSize=0;

		AF_AutoParaList=NULL;
		AF_AutoParaListSize=0;

		AF_FarParaList=NULL;
		AF_FarParaListSize=0;

		AF_NearParaList=NULL;
		AF_NearParaListSize=0;

		Exposure_ParaList=NULL;      //�ع�
		Exposure_ParaListSize=0;

		Gain_ParaList=NULL;          //����
		Gain_ParaListSize=0;
	}
}SensorTab, *pSensorTab;

//����SensorTab, ����SensorTab2����
///////////////////////////////////////////////////////////
typedef struct _SensorTab2
{
	/// @brief SENSOR���
	UINT width;          ///<SENSOR���
	/// @brief SENSOR�߶�
	UINT height;         ///<SENSOR�߶�

	UINT Quick_w;		///<Quick View ���	
	UINT Quick_h;		///<Quick View �߶�

	/// @brief SENSOR��������
	UINT type;             ///<SENSOR��������
	/// @brief SENSOR��RESET��PWDN��������
	UINT pin;              ///<SENSOR��RESET��PWDN��������
	/// @brief SENSOR��������ַ
	UINT SlaveID;          ///<SENSOR��������ַ
	/// @brief SENSOR��I2Cģʽ
	UINT mode;						 ///<SENSOR��I2Cģʽ
	/// @brief SENSOR��־�Ĵ���1.
	UINT FlagReg;				 ///<SENSOR��־�Ĵ���1.
	/// @brief SENSOR��־�Ĵ���1��ֵ
	UINT FlagData;			 ///<SENSOR��־�Ĵ���1��ֵ
	/// @brief SENSOR��־�Ĵ���1������ֵ
	UINT FlagMask;			 ///<SENSOR��־�Ĵ���1������ֵ
	/// @brief SENSOR��־�Ĵ���2.
	UINT FlagReg1;			 ///<SENSOR��־�Ĵ���2.
	/// @brief SENSOR��־�Ĵ���2��ֵ
	UINT FlagData1;			 ///<SENSOR��־�Ĵ���2��ֵ
	/// @brief SENSOR��־�Ĵ���2������ֵ
	UINT FlagMask1;			 ///<SENSOR��־�Ĵ���2������ֵ
	/// @brief SENSOR������
	char name[64];				///<SENSOR������

	/// @brief ��ʼ��SENSOR���ݱ�
	UINT* ParaList;			///<��ʼ��SENSOR���ݱ�
	/// @brief ��ʼ��SENSOR���ݱ��С����λ�ֽ�
	UINT  ParaListSize; ///<��ʼ��SENSOR���ݱ��С����λ�ֽ�

	/// @brief SENSOR����Sleepģʽ�Ĳ�����
	UINT* SleepParaList;	///<SENSOR����Sleepģʽ�Ĳ�����
	/// @brief SENSOR����Sleepģʽ�Ĳ������С����λ�ֽ�
	UINT  SleepParaListSize;///<SENSOR����Sleepģʽ�Ĳ������С����λ�ֽ�

	/// @brief SENSOR����Quick Viewģʽ�Ĳ�����
	UINT* QuickParaList;	///<SENSOR����Quick Viewģʽ�Ĳ�����
	/// @brief SENSOR����Quick Viewģʽ�Ĳ������С����λ�ֽ�
	UINT  QuickParaListSize;///<SENSOR����Quick Viewģʽ�Ĳ������С����λ�ֽ�

	/// @brief SENSOR������ݸ�ʽ��YUV//0:YCbYCr;	//1:YCrYCb;	//2:CbYCrY;	//3:CrYCbY.
	UINT outformat;         ///<SENSOR������ݸ�ʽ��YUV//0:YCbYCr;	//1:YCrYCb;	//2:CbYCrY;	//3:CrYCbY.
	/// @brief SENSOR������ʱ��MCLK��0:12M; 1:24M; 2:48M.
	UINT mclk;               ///<SENSOR������ʱ��MCLK��0:12M; 1:24M; 2:48M.
	/// @brief SENSOR��AVDD��ѹֵ
	UINT avdd;              ///<SENSOR��AVDD��ѹֵ
	/// @brief SENSOR��DOVDD��ѹֵ
	UINT dovdd;             ///<SENSOR��DOVDD��ѹֵ
	/// @brief SENSOR��DVDD��ѹֵ		
	UINT dvdd;							///<SENSOR��DVDD��ѹֵ

	/// @brief SENSOR�����ݽӿ�����
	UINT port; 							///<SENSOR�����ݽӿ�����
	UINT Ext0;
	UINT Ext1;
	UINT Ext2; 

	/// @brief AF��ʼ��������
	UINT* AF_InitParaList;        ///<AF��ʼ��������
	/// @brief AF��ʼ���������С����λ�ֽ�
	UINT  AF_InitParaListSize;		///<AF��ʼ���������С����λ�ֽ�

	/// @brief AF_AUTO������
	UINT* AF_AutoParaList;				///<AF_AUTO������
	/// @brief AF_AUTO�������С����λ�ֽ�
	UINT  AF_AutoParaListSize;		///<AF_AUTO�������С����λ�ֽ�

	/// @brief AF_FAR������
	UINT* AF_FarParaList;					///<AF_FAR������
	/// @brief AF_FAR�������С����λ�ֽ�
	UINT  AF_FarParaListSize;			///<AF_FAR�������С����λ�ֽ�

	/// @brief AF_NEAR������
	UINT* AF_NearParaList;				///<AF_NEAR������
	/// @brief AF_NEAR�������С����λ�ֽ�
	UINT  AF_NearParaListSize;		///<AF_NEAR�������С����λ�ֽ�

	/// @brief �ع������
	UINT* Exposure_ParaList;      ///<�ع������
	/// @brief �ع�������С����λ�ֽ�
	UINT  Exposure_ParaListSize;	///<�ع�������С����λ�ֽ�

	/// @brief ���������
	UINT* Gain_ParaList;          ///<���������
	/// @brief ����������С����λ�ֽ�
	UINT	Gain_ParaListSize;			///<����������С����λ�ֽ� 

	_SensorTab2()
	{
		width=0;
		height=0;
		Quick_w = 0; //20141031
		Quick_h = 0; //20141031
		type=0;
		pin=0;
		SlaveID=0;
		mode=0;
		FlagReg=0;
		FlagData=0;
		FlagMask=0;
		FlagReg1=0;
		FlagData1=0;
		FlagMask1=0;
		memset(name,0,sizeof(name));

		ParaList=NULL;
		ParaListSize=0;
		SleepParaList=NULL;
		SleepParaListSize=0;

		QuickParaList = NULL; //20141031
		QuickParaListSize = 0; //20141031

		outformat = 0;
		mclk= 0;               //0:12M; 1:24M; 2:48M.
		avdd= 0;               // 
		dovdd = 0;              //
		dvdd = 0;

		port=0; 	
		Ext0=0;
		Ext1=0;
		Ext2=0; 

		AF_InitParaList=NULL;        //AF_InitParaList
		AF_InitParaListSize=0;

		AF_AutoParaList=NULL;
		AF_AutoParaListSize=0;

		AF_FarParaList=NULL;
		AF_FarParaListSize=0;

		AF_NearParaList=NULL;
		AF_NearParaListSize=0;

		Exposure_ParaList=NULL;      //�ع�
		Exposure_ParaListSize=0;

		Gain_ParaList=NULL;          //����
		Gain_ParaListSize=0;
	}
}SensorTab2, *pSensorTab2;
/** @defgroup group3 SENSOR���
@{

*/
/** @name SENSOR���ͼ�����Ͷ���(SensorTab::type��ȡֵ����)
@{

*/
/* SENSOR���ͼ�����Ͷ���(SensorTab::type��ȡֵ����) */
#define D_RAW10				0x00 
#define D_RAW8				0x01
#define D_MIPI_RAW8			0x01
#define D_YUV				0x02 
#define D_RAW16				0x03
#define D_MIPI_RAW16		0x03
#define D_RGB565			0x04
#define D_YUV_SPI			0x05
#define D_MIPI_RAW10		0x06    // 5bytes = 4 pixel...
#define D_MIPI_RAW12		0x07    // 3bytes = 2 pixel...
#define D_RAW12				0x07
#define D_YUV_MTK_S			0x08    //MTK output...
#define D_YUV_10			0x09
#define D_YUV_12			0x0a
//#define D_HISPI_SP			0x09    //aptina hispi packet sp.
/** @} */

/** @name SENSOR�Ĵ����������и����Ŀ����ֶ���
@{

*/
/* SENSOR�Ĵ����������и����Ŀ����ֶ��� */
#define DTDELAY				0xffff
#define DTMODE				0xfffe	
#define DTOR				0xfffd
#define DTAND				0xfffc
#define DTPOLLT				0xfffb
#define DTPOLL1				0xfffa
#define DTPOLL0				0xfff9
#define DTI2CADDR			0xfff8
#define DTI2CREG			0xfff7
#define DTAFTYPE			0xfff6  //20121223 added... modify the AF Device type
#define DTAFADDR			0xfff5  //20121223 added... modify the AF Device Address..	
#define DTSPIMTKCTRL		0xfff4
#define DTEND				0xfeff	
#define DTMACRO_ON			0xfef0
#define DTMACRO_OFF			0xfef1 
#define DTSPIMTKCTRL		0xfff4

// XHS
// XVS
// V_START
// V_END
// H_START
// H_END
/** @} */

/** @name SENSOR��Դ��ѹѡ����
@{

*/
/* SENSOR��Դ��ѹѡ���� */
#define AVDD_28				0x00
#define AVDD_25				0x01
#define AVDD_18				0x02
#define AVDD_DEFAULT		0x03

#define DOVDD_28			0x00
#define DOVDD_25			0x01
#define DOVDD_18			0x02
#define DOVDD_DEFAULT		0x03

#define DVDD_18				0x00
#define DVDD_15				0x01
#define DVDD_12				0x02
#define DVDD_DEFAULT		0x03

#define AFVCC_33			0x00
#define AFVCC_28			0x01
#define AFVCC_18			0x02
#define AFVCC_DEFAULT		0x03
/** @} */

/** @name SENSOR����ʱ��ѡ����
@{

*/
/* SENSOR����ʱ��ѡ���� */
//you can use these enum type ,or use MHZ or hundred KHZ directly 
enum MCLKOUT
{
	MCLK_6M = 0,
	MCLK_8M,
	MCLK_10M,
	MCLK_11M4,
	MCLK_12M,
	MCLK_12M5,
	MCLK_13M5,
	MCLK_15M,
	MCLK_18M,
	MCLK_24M,
	MCLK_25M,
	MCLK_27M,
	MCLK_30M,
	MCLK_32M,
	MCLK_36M,
	MCLK_40M,
	MCLK_45M,
	MCLK_48M,
	MCLK_50M,
	MCLK_60M,
	MCLK_DEFAULT,
};
/** @} */

/** @name ��SENSORģ��ͨ������(Ŀǰֻ��DTLC2�д���CHANNEL_B)
@{

*/
/* ��SENSORģ��ͨ������(Ŀǰֻ��DTLC2�д���CHANNEL_B) **/
#define CHANNEL_A					0x01 /// ֻʹ��Aͨ��
#define CHANNEL_B					0x02 // ֻ����Bͨ��
#define CHANNEL_AB					0x03 // ABͨ��ͬʱʹ��
/** @} */ 

/** @name SensorEnable�����У�ʹ��SENSORʱ��RESET/PWDN�ܽŵĵ�ƽ״̬����
@{

*/
/* SensorEnable�����У�ʹ��SENSORʱ��RESET/PWDN�ܽŵĵ�ƽ״̬���� */
#define RESET_H						0x02
#define RESET_L						0x00
#define PWDN_H						0x01
#define PWDN_L						0x00
#define PWDN2_H						0x04
#define PWDN2_L						0x00
/** @} */

/** @name ֧�ֵ�SENSOR���ݽӿڶ���
@{

*/
/// ����֧�ֵ�SENSOR���ݽӿڡ�
typedef enum
{
	SENSOR_PORT_MIPI = 0,		///<MIPI�ӿ�
	SENSOR_PORT_PARA,				///<����ͬ���ӿ�
	SENSOR_PORT_MTK_SERIAL,	///<MTK��˾�Ĵ��нӿ�
	SENSOR_PORT_SPI,				///<SPI�ӿ�
	SENSOR_PORT_SIM,				///<ģ��ͼ�����ڲ���
	SENSOR_PORT_HISPI,			///<Aptina��HISPI�ӿ�,֧��packet sp��ʽ
	SENSOR_PORT_ZX_SERIAL,		///<չѶ�Ĵ��нӿ�

	SENSOR_PORT_SONY_LVDS = 0x81,
	SENSOR_PORT_SMARTSENS_LVDS = 0x82,
	SENSOR_PORT_PANASONIC_LVDS = 0x85,
}SENSOR_PORT;
/** @} */

/** @name ���ڰ汾ʹ�õĺ궨��
@{

*/
/* ���ڰ汾ʹ�õĺ궨�� */
#define PORT_MIPI			0   //MIPI output
#define PORT_PARALLEL		1   //Parallel output
#define PORT_MTK			2   //MTK output
#define PORT_SPI			3   //SPI output
#define PORT_TEST			4   //TEST ouput. FPGA output the image...
#define PORT_HISPI			5   //aptina HISPI packet sp...
#define PORT_ZX2_4			6   //zhanxun 2bit/4bit packet sp...
#define PORT_MAX			7   //maxium... can't support >=PORT_MAX
/** @} */

#define PORT_SONY_LVDS		0x81 
#define PORT_PANASONIC		0x85  
/** @name �������Խӿ��еĸ��ֹܽŹ���
@{

*/
/* �������Խӿ��еĸ��ֹܽŹ��� */
typedef enum
{
	PIN_D0 = 0,
	PIN_D1,
	PIN_D2,
	PIN_D3,
	PIN_D4,
	PIN_D5,
	PIN_D6,
	PIN_D7,
	PIN_D8,
	PIN_D9,
	PIN_PCLK,
	PIN_HSYNC,
	PIN_VSYNC,
	PIN_MCLK,
	PIN_RESET,
	PIN_PWDN,
	PIN_PWDN2,
	PIN_GPIO1,
	PIN_SDA,
	PIN_SCL,
	PIN_NC,
	PIN_GPIO2,
	PIN_GPIO3,
	PIN_GPIO4,
	PIN_NC1,
	PIN_NC2,
	PIN_D10,
	PIN_D11,
	PIN_SPI_SCK,	//���Խӿ� ����SPI�ӿ�
	PIN_SPI_CS,
	PIN_SPI_SDI,
	PIN_SPI_SDO,
	PIN_SPI_SDA,
	PIN_CLK_ADJ_200K,
	PIN_CLK_ADJ_18M,
	PIN_GPIO5,
	PIN_GPIO6,
	PIN_GPIO7,
	PIN_GPIO8
}PIN_FUNC;
/** @} */

/** @name �������Խӿڹܽ�����(���)
@{

*/
/* �������Խӿڹܽ�����(���) */
typedef enum
{
	PIN_IO1 = 0,
	PIN_IO2,
	PIN_IO3,
	PIN_IO4,
	PIN_IO5,
	PIN_IO6,
	PIN_IO7,
	PIN_IO8,
	PIN_IO9,
	PIN_IO10,
	PIN_IO11,
	PIN_IO12,
	PIN_IO13,
	PIN_IO14,
	PIN_IO15,
	PIN_IO16,
	PIN_IO17,
	PIN_IO18,
	PIN_IO19,
	PIN_IO20,
	PIN_IO21,
	PIN_IO22,
	PIN_IO23,
	PIN_IO24,
	PIN_IO25,
	PIN_IO26,
}SOFT_PIN;
/** @} */

/** @name MIPI���������Ե�λ����
@{

*/
/* MIPI���������Ե�λ���� */
#define MIPI_CTRL_LP_EN				1		// �������LP״̬
#define MIPI_CTRL_AUTO_START		(1<<1)	// ���ֲ���źź��Զ�����������OS����
#define MIPI_CTRL_NON_CONT			(1<<2)	// ʹ�÷�����ʱ��
#define MIPI_CTRL_FULL_CAP			(1<<3)	// �������ݰ���ȡ��������ͷ��CRC16У�飬
#define MIPI_CTRL_CLK_LP_CHK		(1<<4)	// ��CLK Lane��LP״̬���м�⣬ǿ��Ҫ��MIPI TX�˵�Clk Lane�������һ��LP״̬/** @} */
// ������ÿ��ͼ����������6�ֽ�

/** @name ͬ�����нӿ����Ե�λ����
@{

*/
/* ͬ�����нӿ����Ե�λ���� */
#define PARA_PCLK_RVS				(1<<3)	// PCLKȡ��
#define PARA_VSYNC_RVS				(1<<4)	// VSYNCȡ��
#define PARA_HSYNC_RVS				(1<<5)	// HSYNCȡ��
#define PARA_AUTO_POL				(1<<6)	// VSYNC,HSYNC�����Զ�ʶ��
/** @} */

/** @name ͬ�����нӿ�,3bit����ѡ��λ��
@{

*/
/* 3bit����ѡ��λ�� */
#define PARA_BW_8BIT				0		
#define PARA_BW_10BIT				1
#define PARA_BW_12BIT				2
#define PARA_BW_16BIT				3
/** @} */

/** @name HiSPI�ӿ����Ե�λ����
@{

*/
/* HiSPI�ӿ����Ե�λ���� */
// 2bit����ѡ��λ��
#define	HISPI_WW_10BIT				0
#define	HISPI_WW_12BIT				1
#define	HISPI_WW_14BIT				2
#define	HISPI_WW_16BIT				3
/** @} */

/** @name ģ��ͼ��ģ�����Ե�λ����
@{

*/
/* ģ��ͼ��ģ�����Ե�λ���� */
// 2bit����ѡ��ģ��ͼ�����ʽ
#define	SIM_STYLE1					0	// ����̶���ɫ
#define	SIM_STYLE2					1	// ˮƽ����
#define	SIM_STYLE3					2	// ��ֱ����
#define	SIM_STYLE4					3	// ÿ֡����
/** @} */

/** @} */ // end of group3

/** @defgroup group2 ISP���
@{

*/
/** @name RAWתRGB�㷨����
@{

*/
/* RAWתRGB�㷨���� */
#define RAW2RGB_NORMAL			0
#define RAW2RGB_SMOOTH			1
#define RAW2RGB_SHARP			2
/** @} */

/** @name YUVͼ��4�������ʽ����
@{

*/
/* RAW��YUVͼ��4�������ʽ����(SensorTab::outformat��ȡֵ����) */
/// YUVͼ��4�������ʽ���塣
enum OUTFORMAT_YUV
{
	OUTFORMAT_YCbYCr = 0,///<YCbYCr�����ʽ
	OUTFORMAT_YCrYCb,///<YCrYCb�����ʽ
	OUTFORMAT_CbYCrY,///<CbYCrY�����ʽ
	OUTFORMAT_CrYCbY,///<CrYCbY�����ʽ
};
/** @} */

/** @name RAWͼ��4�������ʽ����
@{

*/
/// RAWͼ��4�������ʽ���塣
enum OUTFORMAT_RGB
{
	OUTFORMAT_RGGB = 0,///<RGGB�����ʽ
	OUTFORMAT_GRBG,///<GRBG�����ʽ
	OUTFORMAT_GBRG,///<GBRG�����ʽ
	OUTFORMAT_BGGR,///<BGGR�����ʽ
};
/** @} */

/* ��ϵͳ֧�ֵ�RAW��ʽ��YUV��ʽ���� */
/** @name ֧�ֵ�RAW��ʽ����
@{

*/
/// ֧�ֵ�RAW��ʽ��
enum RAW_FORMAT
{
	RAW_RGGB = 0,	///<RAW��ʽ��RGGB����
	RAW_GRBG,			///<RAW��ʽ��GRBG����
	RAW_GBRG,			///<RAW��ʽ��GBRG����
	RAW_BGGR,			///<RAW��ʽ��BGGR����
};
/** @} */

/** @name ֧�ֵ�YUV��ʽ����
@{

*/
/// ֧�ֵ�YUV��ʽ��
enum YUV_FORMAT
{
	YUV_YCBYCR = 0,///<YUV��ʽ��YCBYCR����
	YUV_YCRYCB,		 ///<YUV��ʽ��YCRYCB����
	YUV_CBYCRY,		 ///<YUV��ʽ��CBYCRY����
	YUV_CRYCBY,		 ///<YUV��ʽ��CRYCBY����
};
/** @} */

/** @name ͼ����ģʽѡ��
@{

*/
/// ͼ����ģʽѡ��
enum ISP_MODE
{
	NORMAL = 0,	///��ͨ�Ĵ���ģʽ��ץ֡�õ�����raw����
	S2DFAST,	///S2DFASTģʽ��ץ֡�õ�����RGB����
	S2DFAST_GPU,///S2DFAST_GPUģʽ��GPU����ͼ����ץ֡�õ�����RGB����
};

/** @} */


/** @} */ // end of group2
/**************************************************************************************** 
*
* ͼ��ɼ���� 
*
****************************************************************************************/

/* FrameBufferģʽ */

#define	BUF_MODE_NORMAL		0			// һ��ģʽ������Ч���൱��FIFO����������������
										// ������������ʱ���µ�֡�����ᱻд�뵽���棻

#define BUF_MODE_SKIP		1			// ��֡ģʽ�������е�֡��������֡��Ŷӡ�����

#define	BUF_MODE_NEWEST		2			// NEWESTģʽ��Ŀǰֻ��PCI-E�ӿڵĻ�����Ч��
										// GrabFrame����ȡ���»��浽��֡��������������
										// ����Ч��SKIPģʽ


/* ��������FrameBuffer */
typedef struct _FrameBufferConfig
{
	ULONG	    uMode; 
	ULONG		uBufferSize;	// �豸�е�֡�����С(�ֽ�)
	ULONG		uUpLimit;		// ������������(�ֽ�)�������������������ʱ���µ�֡��������
	ULONG		resv[16];		// ���������0
}FrameBufferConfig;

/* ֡�����Ϣ����֡���ݶ�Ӧ������������� */
typedef struct sFrameInfo
{
	BYTE	byChannel;		
	USHORT	uWidth;	
	USHORT	uHeight;	
	UINT	uDataSize;	
	UINT64	uiTimeStamp;
}FrameInfo;

// ��չ��֡��Ϣ�ṹ��
typedef struct sFrameInfoEx
{
	BYTE	byChannel;	
	BYTE    resvl[3];		// ����3�ֽڣ����0
	BYTE    byImgFormat;	// ͼ���ʽ��D_RAW8��D_RAW10...
	USHORT	uWidth;	
	USHORT	uHeight;	
	UINT	uDataSize;	
	UINT	uFrameTag;		// ����������ʶ
	double  fFSTimeStamp;	// ֡��ʼ��ʱ���
	double  fFETimeStamp;	// ֡������ʱ���
	UINT	uEccErrorCnt;	// ÿ֡��ECC���������ֻ��MIPI�ӿ���Ч
	UINT	uCrcErrorCnt;	// ÿ֡��CRC���������ֻ��MIPI�ӿ���Ч
	UINT	uFrameID;		// ֡����
	UINT	resv[60];		// ���������0
}FrameInfoEx;
/** @defgroup group4 ͼ�����ݲɼ����
@{

*/
/** @name Ԥ�����ڶ���
@{

*/
/* Ԥ�����ڶ��� */
#define PREVIEW_ROI_B0    0x00
#define PREVIEW_ROI_B1    0x01
#define PREVIEW_ROI_B2    0x02
#define PREVIEW_ROI_B3    0x03
#define PREVIEW_ROI_B4    0x04
#define PREVIEW_ROI_GRID  0x05
#define PREVIEW_QUICK	  0x06 
#define PREVIEW_FULL      0x07
#define PREVIEW_NOTHING   0x08
/** @} */

/** @} */ // end of group4


/**************************************************************************************** 
*
* ��Դ�������
*
****************************************************************************************/
/** @defgroup group5 ��Դ����Ԫ���

@{

*/

/* ֡�����Ϣ����֡���ݶ�Ӧ������������� */
/** @name SENSOR��Ҫ�ĵ�Դ���Ͷ���
@{

*/
/* ����SENSOR��Ҫ�ĵ�Դ���� */
///����SENSOR��Ҫ�ĵ�Դ���͡�
typedef enum
{
	/* Aͨ������ֻ��һ��ͨ��ʱ */
	POWER_AVDD = 0,	///<Aͨ��AVDD
	POWER_DOVDD,		///<Aͨ��DOVDD
	POWER_DVDD,			///<Aͨ��DVDD
	POWER_AFVCC,		///<Aͨ��AFVCC
	POWER_VPP,			///<Aͨ��VPP

	/* Bͨ�� */
	POWER_AVDD_B,		///<Bͨ��AVDD
	POWER_DOVDD_B,	///<Bͨ��DOVDD
	POWER_DVDD_B,		///<Bͨ��DVDD
	POWER_AFVCC_B,	///<Bͨ��AFVCC
	POWER_VPP_B,		///<Bͨ��VPP

	/* �����ӵĵ�Դͨ������ */
	POWER_OISVDD,
	POWER_AVDD2,
	POWER_AUX1,
	POWER_AUX2,
}SENSOR_POWER;
/** @} */

/** @name SENSORϵͳ��Դ���Ͷ���
@{

*/
/* ����ϵͳ��Դ���� */
///����ϵͳ��Դ���͡�
typedef enum
{
	POWER_SYS_12V = 0,///<12Vϵͳ��Դ
	POWER_SYS_5V,			///<5Vϵͳ��Դ
	POWER_SYS_3_3V		///<3.3Vϵͳ��Դ
}SYS_POWER;
/** @} */

/** @name SENSOR��Դģʽ����
@{

*/
/* �����Դģʽ */
///�����Դģʽ��
typedef enum
{
	POWER_MODE_WORK = 0,///<SENSOR��ԴΪ����ģʽ
	POWER_MODE_STANDBY, ///<SENSOR��ԴΪ����ģʽ
	POWER_MODE_PWDN			///<SENSOR��ԴΪ����ģʽ
}POWER_MODE;
/** @} */

/** @name �����������̶���
@{

*/
/* ��������������� */
///��������������̡�
typedef enum
{
	CURRENT_RANGE_MA = 0,///<������������ΪmA
	CURRENT_RANGE_UA,		 ///<������������ΪuA
	CURRENT_RANGE_NA		 ///<������������ΪnA
}CURRENT_RANGE;
/** @} */
/** @} */ // end of group5


/**************************************************************************************** 
*
* OS/LC���
*
****************************************************************************************/
/** @defgroup group8 LC/OS���
@{

*/
/** @name OS/LC�������ö���
@{

*/
/* OS/LC�������ö��壬��LC_OS_CommandConfig������ʹ�� */
#define OS_CFG_CHANNEL_A					(1<<5)
#define OS_CFG_CHANNEL_B					(1<<4)	
#define OS_CFG_TEST_ENA						(1<<7)
#define LC_CFG_TEST_ENA						(1<<6)
#define OS_CFG_HIGH							(1<<3)
#define OS_CFG_LOW							(1<<2)
#define LC_CFG_HIGH							(1<<1)
#define LC_CFG_LOW							(1<<0)
/** @} */
/** @name OS/LC���Խ�����壬OS_Read�������صĽ��
@{

*/
/* OS/LC���Խ�����壬OS_Read�������صĽ�� */
#define	OS_TEST_RESULT_PASS					0	 // ͨ������
#define OS_TEST_RESULT_NG					1	 // δͨ������
#define OS_TEST_RESULT_FAILED				0xfe // ����ʧ��
#define OS_TEST_RESULT_INVALID				0xff // ������Ч
/** @} */
/** @} */ // end of group8



/**************************************************************************************** 
*
* I2C�������
*
****************************************************************************************/
/** @defgroup group3 SENSOR���
@{

*/
/*
* �����ļĴ�����дģʽ
* I2C mode definiton
* when read or write by I2c ,should use this definiton...
* Normal Mode:8 bit address,8 bit data,
* Samsung Mode:8 bit address,8 bit data,but has a stop between slave ID and addr...
* Micron:8 bit address,16bit data...
* Stmicro:16bit addr ,8bit data,such as eeprom and stmicro sensor...
*/
/** @name I2Cģʽ����
@{

*/
///I2Cģʽ���塣
enum I2CMODE
{
	I2CMODE_NORMAL=0,		///< 8 bit addr,8 bit value 
	I2CMODE_SAMSUNG,		///< 8 bit addr,8 bit value,Stopen
	I2CMODE_MICRON,			///< 8 bit addr,16 bit value
	I2CMODE_STMICRO,		///< 16 bit addr,8 bit value, (eeprom also)
	I2CMODE_MICRON2,		///< 16 bit addr,16 bit value
};

///sensor i2c��������ѡ��
enum I2CPULLUPRESISTOR
{
	PULLUP_RESISTOR_1_5K=0,		///< 1.5K pull up resistor
	PULLUP_RESISTOR_4_7K,		///< 4.7K pull up resistor
	PULLUP_RESISTOR_0_88K,		///< 0.88K pull up resistor
};

/** @} */

/** @name SPIģʽ����
@{

*/
///SPIģʽ����
enum SPIMODE
{
	SPIMODE_SONY_A1_D1=0x81,	///< 8 bit addr,8 bit value 
	SPIMODE_SONY_A1_D2,			///< 8 bit addr,16 bit value
	SPIMODE_SONY_A2_D1,			///< 16 bit addr,8 bit value
	SPIMODE_SONY_A2_D2,			///< 16 bit addr,16 bit value

	/* panasonic lsb */
	SPIMODE_PANASONIC_A1_D1=0x91,		///< 8 bit addr,8 bit value 
	SPIMODE_PANASONIC_A1_D2,			///< 8 bit addr,16 bit value
	SPIMODE_PANASONIC_A2_D1,			///< 16 bit addr,8 bit value
	SPIMODE_PANASONIC_A2_D2,			///< 16 bit addr,16 bit value
	
	/* smartsens msb */
	SPIMODE_SMARTSENS_A2_D1=0xcb,		///< 16 bit addr,8 bit value  bit15-bit0
};
/** @} */



#define	MASTER_CTRL_DATA_SHIFT	(1<<0)	/* ������λģʽ  0: MSB �ȳ�, 1: LSB �ȳ� */
#define	MASTER_CTRL_CPOL		(1<<1)	/* ʱ�Ӽ��ԣ�Clock polarity�� - SPI����ʱ��ʱ���źŵĵ�ƽ״̬[ 1: ����ʱ�ߵ�ƽ ��0: ����ʱ�͵�ƽ ]*/

/* ʱ����λ��Clock phase�� - SPI��SCLK�ڼ������ز���
CPHA=0����ʾ��һ������
CPOL=0��idleʱ����ǵ͵�ƽ����һ�����ؾ��Ǵӵͱ䵽�ߣ������������أ�
����CPOL=1��idleʱ����Ǹߵ�ƽ����һ�����ؾ��ǴӸ߱䵽�ͣ��������½��أ�
CPHA=1����ʾ�ڶ������أ�
CPOL=0��idleʱ����ǵ͵�ƽ���ڶ������ؾ��ǴӸ߱䵽�ͣ��������½��أ�
CPOL=1��idleʱ����Ǹߵ�ƽ����һ�����ؾ��Ǵӵͱ䵽�ߣ������������أ�
*/
#define	MASTER_CTRL_CPHA		(1<<2)	
#define MASTER_CTRL_DELAY		(1<<3)	/* 0:�Ĵ������������ʱ��1���Ĵ���д�������ʱ����ʱֵ��data�и��� */


/* SPI���ýṹ�� */
typedef struct MasterSpiConfig_s
{
	double fMhz;			/* ����SPI��ʱ�� */
	BYTE byWordLen;			/* Word length in bits. 0�� 8bit ��1��16bit��Ĭ��Ϊ0*/
	BYTE byCtrl;			/* ֧�ֵ�λ�����룺MASTER_CTRL_DATA_SHIFT/MASTER_CTRL_CPOL/ MASTER_CTRL_CPHA/MASTER_CTRL_DELAY */
	BYTE uRsv[64];			/* ���� */
}MasterSpiConfig_t;


/**************************************************************************************** 
*
* ��ϵͳ֧�ֵ�AF�����ͺŶ���
*
****************************************************************************************/
/** @defgroup group7 AF���
@{

*/
/** @name ֧�ֵ�AF�����ͺŶ���
@{

*/
#define AF_DRV_AD5820		0
#define AF_DRV_DW9710		0
#define AF_DRV_DW9714		0

#define AF_DRV_AD5823		1
#define AF_DRV_FP5512		2
#define AF_DRV_DW9718		3
#define AF_DRV_BU64241		4
#define AF_DRV_LV8498		5
#define AF_DRV_BU64291		6
#define AF_DRV_AD1457		7

#define AF_DRV_DW9761		8
#define AF_DRV_AD5816		8

#define AF_DRV_AK7345		9
#define AF_DRV_DW9800		10

#define AF_DRV_ZC533		11
#define AF_DRV_BU64295		12
#define AF_DRV_DW9719		13
//#define AF_DRV_SC9714		14
#define AF_DRV_FP5518		14

#define AF_DRV_AK7374		15

#define AF_DRV_MAX			30

/** @} */
/** @} */ // end of group7


/**************************************************************************************** 
*
* �������ܶ���
*
****************************************************************************************/
/** @defgroup group6 ��ʼ���������
@{

*/
/** @name �������ܶ���
@{

*/ 
#define KEY_ROI_B0			0x100
#define KEY_ROI_B1			0x80
#define KEY_ROI_B2			0x40
#define KEY_ROI_B3			0x10
#define KEY_ROI_B4			0x20
#define KEY_ROI_GRID		0x04
#define KEY_FULL			0x08
#define KEY_PLAY			0x01
#define KEY_CAM				0x02
#define KEY_NOTHING			0x00 
/** @} */
/** @} */ // end of group6

/************************************************************************
*
*�ⲿ��չIO����
*
/************************************************************************/
/** @defgroup group9 ��չIO
@{

*/
/** @name �ⲿ��չIO�ܽŶ���
@{

*/
typedef enum
{
	GPIO0=0,	///<GPIO0
	GPIO1,		///<GPIO1
	GPIO2,		///<GPIO2
	GPIO3,		///<GPIO3
	GPIO4,		///<GPIO4
	GPIO5,		///<GPIO5
	GPIO6,		///<GPIO6
	GPIO7,		///<GPIO7
	GPIO8,		///<GPIO8
	GPIO9,		///<GPIO9
	GPIO10,		///<GPIO10
	GPIO11,		///<GPIO11
}EXT_GPIO;
/** @} */

/** @name �ⲿ��չIOģʽ����
@{

*/
typedef enum
{
	GPIO_INPUT=0,	///<����ģʽ
	GPIO_OUTPUT,	///<���ƽ���ģʽ
	GPIO_OUTPUT_PP, ///<�ߵ͵�ƽ�������

}EXT_GPIO_MODE;
/** @} */
/** @} */ // end of group9
/**************************************************************************************** 
*
* һЩSDK�ӿں�����ʹ�õ��ĺ궨��
*
****************************************************************************************/
//PMU range....
#define PMU1_1						0x11
#define PMU1_2						0x10
#define PMU1_3						0x12
#define PMU2_1						0x21
#define PMU2_2						0x20
#define PMU2_3						0x22
#define PMU3_1						0x31
#define PMU3_2						0x30
#define PMU3_3						0x32
#define PMU4_1						0x41
#define PMU4_2						0x40
#define PMU4_3						0X42
#define PMU5_1						0x51
#define PMU5_2						0x50
#define PMU5_3						0X52

#define I2C_400K					1
#define I2C_100K					0

#define I_MAX_100mA					1
#define I_MAX_300mA					0

#define PMU_ON						0
#define PMU_OFF						1

#define POWER_ON					1
#define POWER_OFF					0

#define CLK_ON						1
#define CLK_OFF						0

#define IO_PULLUP					1
#define IO_NOPULL					0

#define MULTICAM_NORMAL				0x00
#define MULTICAM_PWDN_NOT			0x01
#define MULTICAM_RESET_PWDN_OVERLAP	0x02
#define MULTICAM_SPECIAL			0x03




/**************************************************************************************** 
*
* ���ô�����
*
****************************************************************************************/
/** @defgroup group10 ���ô�����
*  @{

*/
/// @brief ��æ(��һ�β������ڽ�����)���˴β������ܽ���
#define DT_ERROR_BUSY					   	4		///<��æ(��һ�β������ڽ�����)���˴β������ܽ���
/// @brief ��Ҫ�ȴ�(���в���������������)�������ٴγ���
#define DT_ERROR_WAIT                	   	3		///<��Ҫ�ȴ�(���в���������������)�������ٴγ���
/// @brief ���ڽ��У��Ѿ���������
#define DT_ERROR_IN_PROCESS               	2		///<���ڽ��У��Ѿ���������
/// @brief �����ɹ�
#define DT_ERROR_OK							1		///<�����ɹ�
/// @brief ����ʧ��
#define DT_ERROR_FAILED						0		///<����ʧ��
/// @brief �ڲ�����
#define DT_ERROR_INTERNAL_ERROR				-1		///<�ڲ�����
/// @brief δ֪����
#define DT_ERROR_UNKNOW						-1		///<δ֪����
/// @brief ��֧�ָù���
#define DT_ERROR_NOT_SUPPORTED				-2		///<��֧�ָù���
/// @brief ��ʼ��δ���
#define DT_ERROR_NOT_INITIALIZED         	-3		///<��ʼ��δ���
/// @brief ������Ч
#define DT_ERROR_PARAMETER_INVALID       	-4		///<������Ч
/// @brief ����Խ��
#define DT_ERROR_PARAMETER_OUT_OF_BOUND  	-5		///<����Խ��
/// @brief δʹ��
#define DT_ERROR_UNENABLED  				-6		///<δʹ��

/* IO���洢���豸���  */
/// @brief ��ʱ����
#define DT_ERROR_TIME_OUT             	   	-1000	///<��ʱ����
/// @brief Ӳ��IO����
#define DT_ERROR_IO_ERROR                 	-1001	///<Ӳ��IO����
/// @brief ͨѶ����
#define DT_ERROR_COMM_ERROR					-1002	///<ͨѶ����
/// @brief ���ߴ���
#define DT_ERROR_BUS_ERROR				   	-1003	///<���ߴ���
/// @brief û�з����豸
#define DT_ERROR_NO_DEVICE_FOUND			-1100	///<û�з����豸
/// @brief δ�ҵ��߼��豸
#define DT_ERROR_NO_LOGIC_DEVICE_FOUND   	-1101	///<δ�ҵ��߼��豸
/// @brief �豸�Ѿ���
#define DT_ERROR_DEVICE_IS_OPENED			-1102	///<�豸�Ѿ���
/// @brief �豸�Ѿ��ر�
#define DT_ERROR_DEVICE_IS_CLOSED			-1103	///<�豸�Ѿ��ر�

#define DT_ERROR_DEVICE_IS_DISCONNECTED    	-1104  	// �豸�Ѿ��Ͽ�����
/// @brief û���㹻ϵͳ�ڴ�
#define DT_ERROR_NO_MEMORY  	   		   	-1200	///<û���㹻ϵͳ�ڴ�

/// @brief �����ļ�ʧ��
#define DT_ERROR_FILE_CREATE_FAILED			-1300	///<�����ļ�ʧ��
/// @brief �ļ���ʽ��Ч
#define DT_ERROR_FILE_INVALID             	-1301	///<�ļ���ʽ��Ч

/// @brief д����������д
#define DT_ERROR_WRITE_PROTECTED			-1400	///<д����������д

/// @brief ���ݲɼ�ʧ��
#define DT_ERROR_GRAB_FAILED           	   	-1600	///<���ݲɼ�ʧ��
/// @brief ���ݶ�ʧ��������
#define DT_ERROR_LOST_DATA                	-1601	///<���ݶ�ʧ��������
/// @brief δ���յ�֡������
#define DT_ERROR_EOF_ERROR           	   	-1602	///<δ���յ�֡������
/// @brief ���ݲɼ��Ѿ�����
#define DT_ERROR_GRAB_IS_STARTED         	-1605  	// ���ݲɼ��Ѿ�����
/** @} */ // end of group10


/****************************************************************************************
*
* ���ڷ�������д����������ʱ�������ش����� 
*
****************************************************************************************/
#define CHECK_RETURN(_FUN_) \
{\
	int iChkRet = _FUN_; \
	if (iChkRet != DT_ERROR_OK) \
	return iChkRet; \
	}



#endif // __IMAGEKIT_H__
