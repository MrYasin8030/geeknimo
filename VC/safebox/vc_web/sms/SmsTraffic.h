// SmsTraffic.h: interface for the CSmsTraffic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SMSTRAFFIC_H__3A4D81DE_C363_42D6_8A47_3BA017BFBF56__INCLUDED_)
#define AFX_SMSTRAFFIC_H__3A4D81DE_C363_42D6_8A47_3BA017BFBF56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "smsclass.h"
#include "Comm.h"

#define MAX_SM_SEND		128		// 发送队列长度
#define MAX_SM_RECV		128		// 接收队列长度

class CSmsTraffic  
{
public:
	CSmsTraffic();
	virtual ~CSmsTraffic();

	int m_nSendIn;		// 发送队列的输入指针
	int m_nSendOut;		// 发送队列的输出指针

	int m_nRecvIn;		// 接收队列的输入指针
	int m_nRecvOut;		// 接收队列的输出指针

	SM_PARAM m_SmSend[MAX_SM_SEND];		// 发送短消息队列
	SM_PARAM m_SmRecv[MAX_SM_SEND];		// 接收短消息队列

	CRITICAL_SECTION m_csSend;		// 与发送相关的临界段
	CRITICAL_SECTION m_csRecv;		// 与接收相关的临界段

	HANDLE m_hKillThreadEvent;		// 通知子线程关闭的事件
	HANDLE m_hThreadKilledEvent;	// 子线程宣告关闭的事件

	void PutSendMessage(SM_PARAM* pSmParam);	// 将短消息放入发送队列
	BOOL GetSendMessage(SM_PARAM* pSmParam);	// 从发送队列中取一条短消息
	void PutRecvMessage(SM_PARAM* pSmParam, int nCount);	// 将短消息放入接收队列
	BOOL GetRecvMessage(SM_PARAM* pSmParam);	// 从接收队列中取一条短消息

	static UINT SmThread(LPVOID lpParam);	// 短消息收发处理子线程
};

#endif // !defined(AFX_SMSTRAFFIC_H__3A4D81DE_C363_42D6_8A47_3BA017BFBF56__INCLUDED_)
