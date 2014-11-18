// InitFile.cpp: implementation of the CInitFile class.
//

#include "stdafx.h"
#include "InitFile.h"
#include "imagehlp.h"//���ڴ����ļ����õ�ͷ�ļ�������Ӧ���ȼ��ؿ�imagehlp.lib


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInitFile::CInitFile()
{
	m_sFileName = "";
}

CInitFile::~CInitFile()
{
}

/***************************************************************** 
** ��������: SetFileName()
** �������: �����ļ����ļ�����NewFolderName,������ļ���FileName
** ��    ��: �����ļ�����ϸ·���������������ļ���
** ��������: �����ļ��������ļ���
** �� �� ��: 
** Version : 1.01 �޸ģ��Ų���2011.6.22
******************************************************************/
CString CInitFile::SetFileName(CString NewFolderName,CString FileName)
{
	GetModulePath();
	if (NewFolderName=="")
	{
		m_strFileParaPath=m_strFileParaPath+"\\";
	} 
	else
	{
		m_strFileParaPath=m_strFileParaPath+"\\"+NewFolderName+"\\";
	}	
	BOOL bRet=MakeSureDirectoryPathExists(m_strFileParaPath); //����ļ��в����ڣ������ļ���
	ASSERT(bRet);
	if (FileName=="")
	{
		m_sFileName = m_strFileParaPath;
	}
	else
	{
		m_sFileName =m_strFileParaPath+FileName;
	}	
	bRet=MakeSureDirectoryPathExists(m_sFileName); 
	ASSERT(bRet);
	return m_sFileName;
}

/***************************************************************** 
** ��������: SetFileName()
** �������: �����ļ����ļ��������ļ���FileNameorNewFolderName
** ��    ��: �����ļ�����ϸ·��
** ��������: �����ļ��������ļ���
** �� �� ��: 
** Version : 1.01 �޸ģ��Ų���2011.6.22
******************************************************************/
CString CInitFile::SetFileName(CString FileNameorNewFolderName)
{
	GetModulePath();
	if (0 < FileNameorNewFolderName.Find(".", 0))// ��������βε����ļ���
	{
		m_sFileName=m_strFileParaPath+"\\"+FileNameorNewFolderName;
	} 
	else//��������βε����ļ�����
	{
		m_sFileName=m_strFileParaPath+"\\"+FileNameorNewFolderName+"\\";
	}		
	BOOL bRet=MakeSureDirectoryPathExists(m_sFileName); //����ļ��л��ļ������ڣ��򴴽�
	ASSERT(bRet);
	return m_sFileName;
}

/***************************************************************** 
** ��������: SetInt()
** �������: 
		Section		--ϵͳ�����ļ����Ǹ�ģ�����	
		Item		--Ҫ�޸ĵĲ�����
		Value		--Ҫ�޸ĵĲ���ֵ
** ��    ��: ��
** ��������: �޸������ļ�����Ӧ�ֶ�(����)��ֵ
** �� �� ��: 
** Version : 1.01    �޸ģ��Ų���2011.6.22
******************************************************************/
BOOL CInitFile::SetInt(CString Section, CString Item, int Value)
{
	CString strtemp;
	strtemp.Format("%d", Value);
	WriteFileString(Section, Item, strtemp);
	return TRUE;
}

/***************************************************************** 
** ��������: SetString()
** �������: 
		Section		--ϵͳ�����ļ����Ǹ�ģ�����	
		Item		--Ҫ�޸ĵĲ�����
		Value		--Ҫ�޸ĵĲ���ֵ
** ��    ��: ��
** ��������: �޸������ļ�����Ӧ�ֶ�(�ַ���)��ֵ
** �� �� ��: 
** Version : 1.01    �޸ģ��Ų���2011.6.22
******************************************************************/
BOOL CInitFile::SetString(CString Section, CString Item, CString Value)
{
	WriteFileString(Section, Item, Value);
	return TRUE;
}

/***************************************************************** 
** ��������: SetFloat()
** �������: 
		Section		--ϵͳ�����ļ����Ǹ�ģ�����	
		Item		--������
		Value		--����ֵ
** ��    ��: ��
** ��������: �޸������ļ�����Ӧ�ֶ�(������)��ֵ
** �� �� ��: 
** Version : 1.01    �޸ģ��Ų���2011.6.22
******************************************************************/
BOOL CInitFile::SetFloat(CString Section, CString Item, float Value)
{
	CString strtemp;
	strtemp.Format("%f", Value);
	WriteFileString(Section, Item, strtemp);
	return TRUE;
}

/***************************************************************** 
** ��������: GetString()
** �������: 
		Section		--ϵͳ�����ļ����Ǹ�ģ�����	
		Item		--������
		Value		--����ֵĬ��ֵ
** ��    ��: ����ֵ
** ��������: �õ������ļ�����Ӧ�ֶ�(�ַ���)��ֵ
** �� �� ��: 
** Version : 1.01        �޸ģ��Ų���2011.6.22
******************************************************************/
CString CInitFile::GetString(CString Section, CString Item, CString Value)
{
	return GetFileString(Section, Item, Value);
}

/***************************************************************** 
** ��������: GetInt()
** �������: 
		Section		--ϵͳ�����ļ����Ǹ�ģ�����	
		Item		--������
		Value		--����ֵĬ��ֵ
** ��    ��: ����ֵ
** ��������: �õ������ļ�����Ӧ�ֶ�(����)��ֵ
** �� �� ��:
** Version : 1.01     �޸ģ��Ų���2011.6.22
******************************************************************/
int CInitFile::GetInt(CString Section, CString Item, int Value)
{
	CString strtemp;
	strtemp.Format("%d", Value);
	return atoi(GetFileString(Section, Item, strtemp));
}

/***************************************************************** 
** ��������: GetFloat()
** �������: 
		Section		--ϵͳ�����ļ����Ǹ�ģ�����	
		Item		--������
		Value		--����ֵĬ��ֵ
** ��    ��: ����ֵ
** ��������: ��ȡ�����ļ�����Ӧ�ֶ�(������)��ֵ
** �� �� ��: 
** Version : 1.01        �޸ģ��Ų���2011.6.22
******************************************************************/
float CInitFile::GetFloat(CString Section, CString Item, float Value)
{
	CString strtemp;
	strtemp.Format("%f", Value);
	return (float)atof(GetFileString(Section, Item, strtemp));
}

/***************************************************************** 
** ��������: ReadIniFile()
** �������: ��
** ��    ��: ��
** ��������: ��ȡ�����ļ�
** �� �� ��: 
** Version : 1.01     �޸ģ�÷ˬ 2012.4.15
******************************************************************/
BOOL CInitFile::ReadIniFile()
{
	return TRUE;
}

/***************************************************************** 
** ��������: WriteIniFile()
** �������: ��
** ��    ��: ��
** ��������: д�����ļ�
** �� �� ��: 
** Version : 1.01      �޸ģ�÷ˬ 2012.4.15
******************************************************************/
BOOL CInitFile::WriteIniFile()
{
	return TRUE;
}

/***************************************************************** 
** ��������: GetFileString()
** �������: 
		Section		--ϵͳ�����ļ����Ǹ�ģ�����	
		Item		--������
		Value		--����ֵĬ��ֵ
** ��    ��: ����ֵ
** ��������: �õ������ļ�����Ӧ�ֶ�(�ַ���)��ֵ
** �� �� ��: 
** Version : 1.01           �޸ģ�÷ˬ 2012.4.15
******************************************************************/
CString CInitFile::GetFileString(CString Section, CString Item, CString Value)
{
	::GetPrivateProfileString(Section,Item,"",Value.GetBuffer(100),100,m_sFileName);
	return Value;
}

/***************************************************************** 
** ��������: WriteFileString()
** �������: 
		Section		--ϵͳ�����ļ����Ǹ�ģ�����	
		Item		--������
		Value		--��Ų���ֵ
** ��    ��: ��
** ��������: �޸������ļ�����Ӧ�ֶ�(�ַ���)��ֵ
** �� �� ��: 
** Version : 1.01            �޸ģ�÷ˬ 2012.4.15
******************************************************************/
void CInitFile::WriteFileString(CString Section, CString Item, CString Value)
{
	::WritePrivateProfileString(Section,Item,Value,m_sFileName);
	return;
}

/***************************************************************** 
** ��������: GetModulePath()
** �������: ��
** ��    ��: ���س���exe�����ļ��е���һ���ļ���·��
** ��������: ��ȡģ���ļ���·��
** �� �� ��: 
** Version : 1.01 �޸ģ�÷ˬ  2012.4.15
******************************************************************/
CString CInitFile::GetModulePath()
{
	m_strFileParaPath=".";
	return m_strFileParaPath;
}