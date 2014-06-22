//SendMsg.cpp 
#include "StdAfx.h"
#include "SendMsg.h"
HANDLE hComm;//�����豸���

// ����˳����ַ���ת��Ϊ�����ߵ����ַ�����������Ϊ��������'F'�ճ�ż��
// �磺"8613722216254" --> "683127226152F4"
// pSrc: Դ�ַ���ָ��
// pDst: Ŀ���ַ���ָ��
// nSrcLength: Դ�ַ�������
// ����: Ŀ���ַ�������
int SendMsg::gsmInvertNumbers(const char* pSrc,char* pDst,int nSrcLength)
{
int nDstLength;   // Ŀ���ַ�������
char ch;    // ���ڱ���һ���ַ�

// ���ƴ�����
nDstLength = nSrcLength;

// �����ߵ�
for(int i=0; i<nSrcLength;i+=2)
{
   ch = *pSrc++;   // �����ȳ��ֵ��ַ�
   *pDst++ = *pSrc++; // ���ƺ���ֵ��ַ�
   *pDst++ = ch;   // �����ȳ��ֵ��ַ�
}

// Դ��������������
if(nSrcLength & 1)
{
   *(pDst-2) = 'F'; // ��'F'
   nDstLength++;   // Ŀ�괮���ȼ�1
}

// ����ַ����Ӹ�������
*pDst = '\0';

// ����Ŀ���ַ�������
return nDstLength;
}
// �����ߵ����ַ���ת��Ϊ����˳����ַ���
// �磺"683127226152F4" --> "8613722216254"
// pSrc: Դ�ַ���ָ��
// pDst: Ŀ���ַ���ָ��
// nSrcLength: Դ�ַ�������
// ����: Ŀ���ַ�������
int SendMsg::gsmSerializeNumbers(const char* pSrc, char* pDst, int nSrcLength)
{
    int nDstLength;   // Ŀ���ַ�������
    char ch;          // ���ڱ���һ���ַ�
    // ���ƴ�����
    nDstLength = nSrcLength;
    
    // �����ߵ�
    for(int i=0; i<nSrcLength;i+=2)
    {
        ch = *pSrc++;        // �����ȳ��ֵ��ַ�
        *pDst++ = *pSrc++;   // ���ƺ���ֵ��ַ�
        *pDst++ = ch;        // �����ȳ��ֵ��ַ�
    }
    
    // �����ַ���'F'��
    if(*(pDst-1) == 'F')
    {
        pDst--;
        nDstLength--;        // Ŀ���ַ������ȼ�1
    }
    
    // ����ַ����Ӹ�������
    *pDst = '\0';
    
    // ����Ŀ���ַ�������
    return nDstLength;
}

// 7-bit����
// pSrc: Դ�ַ���ָ��
// pDst: Ŀ����봮ָ��
// nSrcLength: Դ�ַ�������
// ����: Ŀ����봮����
int SendMsg::gsmEncode7bit(const char* pSrc, unsigned char* pDst, int nSrcLength)
{
    int nSrc;        // Դ�ַ����ļ���ֵ
    int nDst;        // Ŀ����봮�ļ���ֵ
    int nChar;       // ��ǰ���ڴ���������ַ��ֽڵ���ţ���Χ��0-7
    unsigned char nLeft;    // ��һ�ֽڲ��������
    
    // ����ֵ��ʼ��
    nSrc = 0;
    nDst = 0;
    
    // ��Դ��ÿ8���ֽڷ�Ϊһ�飬ѹ����7���ֽ�
    // ѭ���ô�����̣�ֱ��Դ����������
    // ������鲻��8�ֽڣ�Ҳ����ȷ����
    while(nSrc<nSrcLength)
    {
        // ȡԴ�ַ����ļ���ֵ�����3λ
        nChar = nSrc & 7;
  
        // ����Դ����ÿ���ֽ�
        if(nChar == 0)
        {
            // ���ڵ�һ���ֽڣ�ֻ�Ǳ�����������������һ���ֽ�ʱʹ��
            nLeft = *pSrc;
        }
        else
        {
            // ���������ֽڣ������ұ߲��������������ӣ��õ�һ��Ŀ������ֽ�
            *pDst = (*pSrc << (8-nChar)) | nLeft;
   
            // �����ֽ�ʣ�µ���߲��֣���Ϊ�������ݱ�������
            nLeft = *pSrc >> nChar;
            // �޸�Ŀ�괮��ָ��ͼ���ֵ pDst++;
            nDst++; 
        } 
        
        // �޸�Դ����ָ��ͼ���ֵ
        pSrc++; nSrc++;
    }
    
    // ����Ŀ�괮����
    return nDst; 
}
// 7-bit����
// pSrc: Դ���봮ָ��
// pDst: Ŀ���ַ���ָ��
// nSrcLength: Դ���봮����
// ����: Ŀ���ַ�������
int SendMsg::gsmDecode7bit(const unsigned char* pSrc, char* pDst, int nSrcLength)
{
    int nSrc;        // Դ�ַ����ļ���ֵ
    int nDst;        // Ŀ����봮�ļ���ֵ
    int nByte;       // ��ǰ���ڴ���������ֽڵ���ţ���Χ��0-6
    unsigned char nLeft; // ��һ�ֽڲ��������
    
    // ����ֵ��ʼ��
    nSrc = 0;
    nDst = 0;
    
    // �����ֽ���źͲ������ݳ�ʼ��
    nByte = 0;
    nLeft = 0;
    
    // ��Դ����ÿ7���ֽڷ�Ϊһ�飬��ѹ����8���ֽ�
    // ѭ���ô�����̣�ֱ��Դ���ݱ�������
    // ������鲻��7�ֽڣ�Ҳ����ȷ����
    while(nSrc<nSrcLength)
    {
        // ��Դ�ֽ��ұ߲��������������ӣ�ȥ�����λ���õ�һ��Ŀ������ֽ�
        *pDst = ((*pSrc << nByte) | nLeft) & 0x7f;
        // �����ֽ�ʣ�µ���߲��֣���Ϊ�������ݱ�������
        nLeft = *pSrc >> (7-nByte);
  
        // �޸�Ŀ�괮��ָ��ͼ���ֵ
        pDst++;
        nDst++;
  
        // �޸��ֽڼ���ֵ
        nByte++;
  
        // ����һ������һ���ֽ�
        if(nByte == 7)
        {
            // ����õ�һ��Ŀ������ֽ�
            *pDst = nLeft;
   
            // �޸�Ŀ�괮��ָ��ͼ���ֵ
            pDst++;
            nDst++;
   
            // �����ֽ���źͲ������ݳ�ʼ��
            nByte = 0;
            nLeft = 0;
        }
  
        // �޸�Դ����ָ��ͼ���ֵ
        pSrc++;
        nSrc++;
    }
    
    *pDst = 0;
    
    // ����Ŀ�괮����
    return nDst;
}
//   8bit���� 
//   ����:   pSrc   -   Դ�ַ���ָ�� 
//               nSrcLength   -   Դ�ַ������� 
//   ���:   pDst   -   Ŀ����봮ָ�� 
//   ����:   Ŀ����봮���� 
int SendMsg::gsmEncode8bit(const char* pSrc,unsigned char* pDst,int nSrcLength) 
{ 
//   �򵥸��� 
memcpy(pDst,   pSrc,   nSrcLength); 
return   nSrcLength; 
}
//   8bit���� 
//   ����:   pSrc   -   Դ���봮ָ�� 
//   nSrcLength   -     Դ���봮���� 
//   ���:   pDst   -     Ŀ���ַ���ָ�� 
//   ����:   Ŀ���ַ������� 
int SendMsg::gsmDecode8bit(const unsigned char* pSrc, char* pDst, int nSrcLength) 
{ 
//   �򵥸��� 
memcpy(pDst,   pSrc,   nSrcLength); 
//   ����ַ����Ӹ������� 
*pDst   =   '\0 '; 
return   nSrcLength; 
}

// UCS2����
// ����: pSrc - Դ�ַ���ָ��
// nSrcLength - Դ�ַ�������
// ���: pDst - Ŀ����봮ָ��
// ����: Ŀ����봮����
int SendMsg::gsmEncodeUcs2(const char* pSrc, unsigned char* pDst, int nSrcLength)
{
     int nDstLength;        // UNICODE���ַ���Ŀ
     WCHAR wchar[128]; // UNICODE��������
    // �ַ���-->UNICODE��
     nDstLength = MultiByteToWideChar(CP_ACP, 0, pSrc, nSrcLength, wchar, 128);
     // �ߵ��ֽڶԵ������
     for(int i=0; i<nDstLength; i++)
     {
         *pDst++ = wchar[i] >> 8;         // �������λ�ֽ�
         *pDst++ = wchar[i] & 0xff;       // �������λ�ֽ�
     }
     
// ����Ŀ����봮����
     return nDstLength * 2;
}

// UCS2����

// ����: pSrc - Դ���봮ָ��

// nSrcLength - Դ���봮����

// ���: pDst - Ŀ���ַ���ָ��
// ����: Ŀ���ַ�������
// 
int SendMsg::gsmDecodeUcs2(const unsigned char* pSrc, char* pDst, int nSrcLength)
{
     int nDstLength;        // UNICODE���ַ���Ŀ
     WCHAR wchar[128]; // UNICODE��������
     // �ߵ��ֽڶԵ���ƴ��UNICODE
     for(int i=0; i<nSrcLength/2; i++)
     {
         wchar[i] = *pSrc++ << 8;    // �ȸ�λ�ֽ�
         wchar[i] |= *pSrc++;        // ���λ�ֽ�
     }
     // UNICODE��-->�ַ���
     nDstLength = WideCharToMultiByte(CP_ACP, 0, wchar, nSrcLength/2, pDst, 160, NULL, NULL);
     // ����ַ����Ӹ�������
     pDst[nDstLength] = '\0';
    
// ����Ŀ���ַ�������
     return nDstLength;
}
// �ɴ�ӡ�ַ���ת��Ϊ�ֽ�����
// �磺"C8329BFD0E01" --> {0xC8, 0x32, 0x9B, 0xFD, 0x0E, 0x01}
// pSrc: Դ�ַ���ָ��
// pDst: Ŀ������ָ��
// nSrcLength: Դ�ַ�������
// ����: Ŀ�����ݳ���
int SendMsg::gsmString2Bytes(const char* pSrc, unsigned char* pDst, int nSrcLength)
{
    for(int i=0; i<nSrcLength; i+=2)
    {
        // �����4λ
        if(*pSrc>='0' && *pSrc<='9')
        {
            *pDst = (*pSrc - '0') << 4;
        }
        else
        {
            *pDst = (*pSrc - 'A' + 10) << 4;
        }
  
        pSrc++;
  
        // �����4λ
        if(*pSrc>='0' && *pSrc<='9')
        {
            *pDst |= *pSrc - '0';
        }
        else
        {
            *pDst |= *pSrc - 'A' + 10;
        }
        pSrc++;
        pDst++;
    }
    
    // ����Ŀ�����ݳ���
    return nSrcLength / 2;
}
// �ֽ�����ת��Ϊ�ɴ�ӡ�ַ���
// �磺{0xC8, 0x32, 0x9B, 0xFD, 0x0E, 0x01} --> "C8329BFD0E01" 
// pSrc: Դ����ָ��
// pDst: Ŀ���ַ���ָ��
// nSrcLength: Դ���ݳ���
// ����: Ŀ���ַ�������
int SendMsg::gsmBytes2String(const unsigned char* pSrc, char* pDst, int nSrcLength)
{
    const char tab[]="0123456789ABCDEF";    // 0x0-0xf���ַ����ұ�
    
    for(int i=0; i<nSrcLength; i++)
    {
        // �����4λ
        *pDst++ = tab[*pSrc >> 4];
  
        // �����4λ
        *pDst++ = tab[*pSrc & 0x0f];
  
        pSrc++;
    }
    
    // ����ַ����Ӹ�������
    *pDst = '\0';
    
    // ����Ŀ���ַ�������
    return nSrcLength * 2;
}
// PDU���룬���ڱ��ơ����Ͷ���Ϣ
// pSrc: ԴPDU����ָ��
// pDst: Ŀ��PDU��ָ��
// ����: Ŀ��PDU������
int SendMsg::gsmEncodePdu(const SM_PARAM* pSrc, char* pDst)
{
    int nLength;             // �ڲ��õĴ�����
    int nDstLength;          // Ŀ��PDU������
    unsigned char buf[256]; // �ڲ��õĻ�����
    
    // SMSC��ַ��Ϣ��
    nLength = strlen(pSrc->SCA);    // SMSC��ַ�ַ����ĳ���    
    buf[0] = (char)((nLength & 1) == 0 ? nLength : nLength + 1) / 2 + 1;    // SMSC��ַ��Ϣ����
    buf[1] = 0x91;        // �̶�: �ù��ʸ�ʽ����
    nDstLength = gsmBytes2String(buf, pDst, 2);        // ת��2���ֽڵ�Ŀ��PDU��
    nDstLength +=gsmInvertNumbers(pSrc->SCA, &pDst[nDstLength], nLength);    // ת��SMSC��Ŀ��PDU��
    
    // TPDU�λ���������Ŀ���ַ��
    nLength = strlen(pSrc->TPA);    // TP-DA��ַ�ַ����ĳ���
    buf[0] = 0x11;            // �Ƿ��Ͷ���(TP-MTI=01)��TP-VP����Ը�ʽ(TP-VPF=10)
    buf[1] = 0;               // TP-MR=0
    buf[2] = (char)nLength;   // Ŀ���ַ���ָ���(TP-DA��ַ�ַ�����ʵ����)
    buf[3] = 0x91;            // �̶�: �ù��ʸ�ʽ����
    nDstLength +=gsmBytes2String(buf, &pDst[nDstLength], 4); // ת��4���ֽڵ�Ŀ��PDU��
    nDstLength +=gsmInvertNumbers(pSrc->TPA, &pDst[nDstLength], nLength); // ת��TP-DA��Ŀ��PDU��
    
    // TPDU��Э���ʶ�����뷽ʽ���û���Ϣ��
    nLength = strlen(pSrc->TP_UD);    // �û���Ϣ�ַ����ĳ���
    buf[0] = pSrc->TP_PID;        // Э���ʶ(TP-PID)
    buf[1] = pSrc->TP_DCS;        // �û���Ϣ���뷽ʽ(TP-DCS)
    buf[2] = 0;            // ��Ч��(TP-VP)Ϊ5����
    if(pSrc->TP_DCS == GSM_7BIT)    
    {
        // 7-bit���뷽ʽ
        buf[3] = nLength;            // ����ǰ����
        nLength =gsmEncode7bit(pSrc->TP_UD, &buf[4], nLength+1) + 4;    // ת��TP-DA��Ŀ��PDU��
    }
    else if(pSrc->TP_DCS == GSM_UCS2)
    {
        // UCS2���뷽ʽ
        buf[3] =gsmEncodeUcs2(pSrc->TP_UD, &buf[4], nLength);    // ת��TP-DA��Ŀ��PDU��
        nLength = buf[3] + 4;        // nLength���ڸö����ݳ���
    }
    else
    {
        // 8-bit���뷽ʽ
        buf[3] =gsmEncode8bit(pSrc->TP_UD, &buf[4], nLength);    // ת��TP-DA��Ŀ��PDU��
        nLength = buf[3] + 4;        // nLength���ڸö����ݳ���
    }
    nDstLength +=gsmBytes2String(buf, &pDst[nDstLength], nLength);        // ת���ö����ݵ�Ŀ��PDU��
    
    // ����Ŀ���ַ�������
    return nDstLength;
}
// PDU���룬���ڽ��ա��Ķ�����Ϣ
// pSrc: ԴPDU��ָ��
// pDst: Ŀ��PDU����ָ��
// ����: �û���Ϣ������
int SendMsg::gsmDecodePdu(const char* pSrc, SM_PARAM* pDst)
{
    int nDstLength;          // Ŀ��PDU������
    unsigned char tmp;       // �ڲ��õ���ʱ�ֽڱ���
    unsigned char buf[256]; // �ڲ��õĻ�����
    //printf("Msg=%s\n",pSrc);
    // SMSC��ַ��Ϣ��
    gsmString2Bytes(pSrc, &tmp, 2);    // ȡ����
    tmp = (tmp - 1) * 2;    // SMSC���봮����
    pSrc += 4;              // ָ�����
    gsmSerializeNumbers(pSrc, pDst->SCA, tmp);    // ת��SMSC���뵽Ŀ��PDU��
    pSrc += tmp;        // ָ�����
    //printf("SMSC=%s\n",pDst->SCA);
    // TPDU�λ����������ظ���ַ��
    gsmString2Bytes(pSrc, &tmp, 2);    // ȡ��������
    pSrc += 2;        // ָ�����
   // if(tmp & 0x80)
    //{
        // �����ظ���ַ��ȡ�ظ���ַ��Ϣ
        gsmString2Bytes(pSrc, &tmp, 2);    // ȡ����
        if(tmp & 1) tmp += 1;    // ������ż��
        pSrc += 4;          // ָ�����
        gsmSerializeNumbers(pSrc, pDst->TPA, tmp);    // ȡTP-RA����
        pSrc += tmp;        // ָ�����
   //printf("TP-RA=%s\n",pDst->TPA);
    //}
    
    // TPDU��Э���ʶ�����뷽ʽ���û���Ϣ��
    gsmString2Bytes(pSrc, (unsigned char*)&pDst->TP_PID, 2);    // ȡЭ���ʶ(TP-PID)
//printf("TP-PID=%c\n",pDst->TP_PID);
    pSrc += 2;        // ָ�����
    gsmString2Bytes(pSrc, (unsigned char*)&pDst->TP_DCS, 2);    // ȡ���뷽ʽ(TP-DCS)
//printf("TP-DCS=%c\n",pDst->TP_DCS);
    pSrc += 2;        // ָ�����
    gsmSerializeNumbers(pSrc, pDst->TP_SCTS, 14);        // ����ʱ����ַ���(TP_SCTS) 
//printf("TP-SCTS=%s\n",pDst->TP_SCTS);
    pSrc += 14;       // ָ�����
    gsmString2Bytes(pSrc, &tmp, 2);    // �û���Ϣ����(TP-UDL)
    pSrc += 2;        // ָ�����
    if(pDst->TP_DCS == GSM_7BIT)    
    {
        // 7-bit����
        nDstLength = gsmString2Bytes(pSrc, buf, tmp & 7 ? (int)tmp * 7 / 4 + 2 : (int)tmp * 7 / 4); // ��ʽת��
        gsmDecode7bit(buf, pDst->TP_UD, nDstLength);    // ת����TP-DU
        nDstLength = tmp;
    }
    else if(pDst->TP_DCS == GSM_UCS2)
    {
        // UCS2����
        nDstLength = gsmString2Bytes(pSrc, buf, tmp * 2);        // ��ʽת��
        nDstLength = gsmDecodeUcs2(buf, pDst->TP_UD, nDstLength);    // ת����TP-DU
    }
    else
    {
        // 8-bit����
        nDstLength = gsmString2Bytes(pSrc, buf, tmp * 2);        // ��ʽת��
        nDstLength = gsmDecode8bit(buf, pDst->TP_UD, nDstLength);    // ת����TP-DU
    }
    //printf("MessgeContent=%s\n",pDst->TP_UD);
    // ����Ŀ���ַ�������
    return nDstLength;
}
// ���Ͷ���Ϣ
// pSrc: ԴPDU����ָ��
BOOL SendMsg::gsmSendMessage(const SM_PARAM* pSrc)
{
    int nPduLength;        // PDU������
    unsigned char nSmscLength;    // SMSC������
    int nLength;           // �����յ������ݳ���
    char cmd[16];          // ���
    char pdu[512];         // PDU��
    char ans[128];         // Ӧ��
    
    nPduLength = gsmEncodePdu(pSrc, pdu);    // ����PDU����������PDU��
    strcat(pdu, "\x01a");        // ��Ctrl-Z����
    
    gsmString2Bytes(pdu, &nSmscLength, 2);    // ȡPDU���е�SMSC��Ϣ����
    nSmscLength++;        // ���ϳ����ֽڱ���
    
    // �����еĳ��ȣ�������SMSC��Ϣ���ȣ��������ֽڼ�
    sprintf(cmd, "AT+CMGS=%d\r", nPduLength / 2 - nSmscLength);    // ��������
    
    WriteComm(cmd, strlen(cmd));    // ��������
    nLength = ReadComm(ans, 128);   // ��Ӧ������
   
    // �����ܷ��ҵ�"\r\n> "�����ɹ����
    if(nLength == 4 && strncmp(ans, "\r\n> ", 4) == 0)
    {
        WriteComm(pdu, strlen(pdu));        // �õ��϶��ش𣬼������PDU��
  
        nLength =ReadComm(ans, 128);       // ��Ӧ������
  
        // �����ܷ��ҵ�"+CMS ERROR"�����ɹ����
        if(nLength > 0 && strncmp(ans, "+CMS ERROR", 10) != 0)
        {
            return TRUE;
        }
    }
    
    return FALSE;
}
// ɾ������Ϣ
// index: ����Ϣ��ţ���1��ʼ
BOOL SendMsg::gsmDeleteMessage(const int index)
{
    int nLength;          // �����յ������ݳ���
    char cmd[16];         // ���
    char ans[128];        // Ӧ��
    sprintf(cmd, "AT+CMGD=%d\r", index);    // ��������
    
     // ������
     WriteComm(cmd, strlen(cmd));
    // ��Ӧ������
    nLength = ReadComm(ans, 128);
        
    // �����ܷ��ҵ�"+CMS ERROR"�����ɹ����
    if(nLength > 0 && strncmp(ans, "+CMS ERROR", 10) != 0)
    {
        return TRUE;
    }
    
    return FALSE;
}
// �򿪴���
// pPort: �������ƻ��豸·��������"COM1"
// nBaudRate: ������
// nParity: ��żУ��
// nByteSize: �����ֽڿ��
// nStopBits: ֹͣλ
BOOL SendMsg::OpenComm(const char* pPort, int nBaudRate, int nParity, int nByteSize, int nStopBits)
{
DCB dcb;        // ���ڿ��ƿ�
    COMMTIMEOUTS timeouts = {    // ���ڳ�ʱ���Ʋ���
    100,        // ���ַ������ʱʱ��: 100 ms
    1,          // ������ʱÿ�ַ���ʱ��: 1 ms (n���ַ��ܹ�Ϊn ms)
    500,        // ������(�����)����ʱʱ��: 500 ms
    1,          // д����ʱÿ�ַ���ʱ��: 1 ms (n���ַ��ܹ�Ϊn ms)
    100};       // ������(�����)д��ʱʱ��: 100 ms
  
   hComm = CreateFile(pPort,    // �������ƻ��豸·��
            GENERIC_READ | GENERIC_WRITE,    // ��д��ʽ
            0,               // ����ʽ����ռ
            NULL,            // Ĭ�ϵİ�ȫ������
            OPEN_EXISTING,   // ������ʽ
            0,               // ���������ļ�����
            NULL);           // �������ģ���ļ�
  
   if(hComm == INVALID_HANDLE_VALUE) 
    return FALSE;        // �򿪴���ʧ��

   GetCommState(hComm, &dcb);        // ȡDCB
  
   dcb.BaudRate = nBaudRate;
   dcb.ByteSize = nByteSize;
   dcb.Parity = nParity;
   dcb.StopBits = nStopBits;
   //////////////////
   //PurgeComm(hComm,   PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);   
   //SetCommMask(hComm,EV_ERR|EV_RXCHAR); 
   /////////////////
   SetCommState(hComm, &dcb);        // ����DCB
  
   SetupComm(hComm, 4096, 1024);     // �������������������С
  
   SetCommTimeouts(hComm, &timeouts);    // ���ó�ʱ

   //printf("OpenComm\n");
   return TRUE;
}
// �رմ���
BOOL SendMsg::CloseComm()
{
return CloseHandle(hComm);
}
// д����
// pData: ��д�����ݻ�����ָ��
// nLength: ��д�����ݳ���
void SendMsg::WriteComm(void* pData, int nLength)
{
    DWORD dwNumWrite;    // ���ڷ��������ݳ���
    WriteFile(hComm, pData, (DWORD)nLength, &dwNumWrite, NULL);
}
// ������
// pData: ���������ݻ�����ָ��
// nLength: ������������ݳ���
// ����: ʵ�ʶ�������ݳ���
int SendMsg::ReadComm(void* pData, int nLength)
{
    DWORD dwNumRead;    // �����յ������ݳ���
    ReadFile(hComm, pData, (DWORD)nLength, &dwNumRead, NULL);
    
    return (int)dwNumRead;
}
// ��ȡ����Ϣ���������������ȡӦ��
// ��+CMGL����+CMGR����һ���Զ���ȫ������Ϣ
void SendMsg::gsmReadMessageList()
{
    WriteComm("AT+CMGL\r",8);

}
// ��ʼ��GSM״̬
BOOL SendMsg::gsmInit()
{
char ans[128];        // Ӧ��

    // ����GSM-MODEM�Ĵ�����
    WriteComm("AT\r", 3);
    Sleep(100);
ReadComm(ans, 128);

    if (strstr(ans, "OK") == NULL) //�����λ���
{   
   Sleep(100);
   WriteComm("AT\r", 3);
   ReadComm(ans, 128);
   if(strstr(ans, "OK") == NULL)
    return FALSE;
}
    // ECHO OFF
    WriteComm("ATE0\r", 5);
    ReadComm(ans, 128);

    // PDUģʽ
    WriteComm("AT+CMGF=0\r", 10);
ReadComm(ans, 128);
   ////////////////////////////////////// 
     WriteComm("AT+CSMS=1\r", 10);   
ReadComm(ans, 128);   
WriteComm("AT+CNMI=2,1\r", 12);   
ReadComm(ans, 128);   
   /////////////////////////////////////// 
// printf("InitCOMM\n");
    return TRUE;
}
// ��ȡGSM MODEM��Ӧ�𣬿�����һ����    
// ���: pBuff - ����Ӧ�𻺳���    
// ����: GSM MODEM��Ӧ��״̬, GSM_WAIT/GSM_OK/GSM_ERR    
// ��ע: ������Ҫ��ε��ò�����ɶ�ȡһ��Ӧ���״ε���ʱӦ��pBuff��ʼ��
int SendMsg::gsmGetResponse(SM_BUFF* pBuff)
{
    int nLength;        // �����յ������ݳ���
    int nState;

    // �Ӵ��ڶ����ݣ�׷�ӵ�������β��
    nLength = ReadComm(&pBuff->data[pBuff->len], 128);    
    pBuff->len += nLength;

   //ȷ��GSM MODEM��Ӧ��״̬
    nState = GSM_WAIT;
    if ((nLength > 0) && (pBuff->len >= 4))
    {
      //if (strncmp(&pBuff->data[pBuff->len - 4], "OK\r\n", 4) == 0)
   if(strstr(pBuff->data, "OK\r\n")!=NULL)   
   nState = GSM_OK;
      else if (strstr(pBuff->data, "+CMS ERROR") != NULL) 
     nState = GSM_ERR;
}

return nState;
}
// ���б��н�����ȫ������Ϣ
// ����: pBuff - ����Ϣ�б�����
// ���: pMsg - ����Ϣ������
// ����: ����Ϣ����
int SendMsg::gsmParseMessageList(SM_PARAM* pMsg, SM_BUFF* pBuff)
{
    int nMsg;            // ����Ϣ����ֵ
    char* ptr;            // �ڲ��õ�����ָ��

    nMsg = 0;
    ptr = pBuff->data;

    // ѭ����ȡÿһ������Ϣ, ��"+CMGL:"��ͷ
    while((ptr = strstr(ptr, "+CMGL:")) != NULL)
    {
        ptr += 6;        // ����"+CMGL:", ��λ�����//
        sscanf(ptr, "%d", &pMsg->index);    // ��ȡ���
   //        TRACE(" index=%d\n",pMsg->index);
   //printf("index=%d\n",pMsg->index);
        ptr = strstr(ptr, "\r\n");    // ����һ��
        if (ptr != NULL)
        {
            ptr += 2;        // ����"\r\n", ��λ��PDU
            
            gsmDecodePdu(ptr, pMsg);    // PDU������
   
           
    pMsg++;        // ׼������һ������Ϣ
            nMsg++;        // ����Ϣ������1
        }
    }

    return nMsg;
}
