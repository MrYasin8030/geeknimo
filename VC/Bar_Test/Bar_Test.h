
// Bar_Test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CBar_TestApp:
// �йش����ʵ�֣������ Bar_Test.cpp
//

class CBar_TestApp : public CWinAppEx
{
public:
	CBar_TestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBar_TestApp theApp;