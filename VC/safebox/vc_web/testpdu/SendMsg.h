// SendMsg.h
#include <windows.h>
#include <winnls.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;
// 用户信息编码方式
#define GSM_7BIT        0
#define GSM_8BIT        4
#define GSM_UCS2        8
//应答状态 
#define GSM_WAIT     0 // 等待，不确定 
#define GSM_OK    1 // OK 
#define GSM_ERR   -1 // ERROR 
// // 编码用到的常量定义
// #define   CONST91    "91"
#define     CONSTF    "F"
#define     CONSTLEN   1024
// #define     CONST1100       "1100"
// #define     CONST000800     "000800"
#define     CONST0    0
// 短消息参数结构，编码/解码共用
// 其中，字符串以0结尾
typedef struct {
    char SCA[16];       // 短消息服务中心号码(SMSC地址)
    char TPA[16];       // 目标号码或回复号码(TP-DA或TP-RA)
    char TP_PID;        // 用户信息协议标识(TP-PID)
    char TP_DCS;        // 用户信息编码方式(TP-DCS)
    char TP_SCTS[16];   // 服务时间戳字符串(TP_SCTS), 接收时用到
    char TP_UD[161];    // 原始用户信息(编码前或解码后的TP-UD)
    char index;         // 短消息序号，在读取时用到
} SM_PARAM;
typedef struct {
	int len; 
	char data[16384]; 
}SM_BUFF;
class SendMsg
{
	
public:
	
	int gsmInvertNumbers(const char* pSrc,char* pDst,int nSrcLength);
	int gsmSerializeNumbers(const char* pSrc, char* pDst, int nSrcLength);
	
	int gsmEncodeUcs2(const char* pSrc, unsigned char* pDst, int nSrcLength);
	int gsmDecodeUcs2(const unsigned char* pSrc, char* pDst, int nSrcLength);
	
	int gsmBytes2String(const unsigned char* pSrc, char* pDst, int nSrcLength);
	int gsmString2Bytes(const char* pSrc, unsigned char* pDst, int nSrcLength);
	
	int gsmEncode7bit(const char* pSrc, unsigned char* pDst, int nSrcLength);
	int gsmDecode7bit(const unsigned char* pSrc, char* pDst, int nSrcLength);
	
	int gsmEncode8bit(const char* pSrc, unsigned char* pDst,int nSrcLength) ;
	int gsmDecode8bit(const unsigned char* pSrc, char* pDst, int nSrcLength) ;
	
	int gsmEncodePdu(const SM_PARAM* pSrc, char* pDst);
	int gsmDecodePdu(const char* pSrc, SM_PARAM* pDst);
	
	BOOL gsmSendMessage(const SM_PARAM* pSrc);
	void gsmReadMessageList();
	BOOL gsmDeleteMessage(const int index);
	
	int gsmGetResponse(SM_BUFF* pBuff);
	int gsmParseMessageList(SM_PARAM* pMsg, SM_BUFF* pBuff);
	
	BOOL OpenComm(const char* pPort, int nBaudRate, int nParity, int nByteSize, int nStopBits );
	BOOL CloseComm();
	void WriteComm(void* pData, int nLength);
	int ReadComm(void* pData, int nLength);
	
	
	BOOL gsmInit();//// 初始化GSM状态
public:
	SendMsg(){}
	~SendMsg(){}
};
