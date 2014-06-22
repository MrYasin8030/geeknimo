// Dialog_Main.cpp : implementation file
//

#include "stdafx.h"
#include "sms.h"
#include "Dialog_Main.h"
#include "smsDlg.h"
#include "md5_password.h"
#include "Comm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_Main dialog


CDialog_Main::CDialog_Main(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Main::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Main)
	//}}AFX_DATA_INIT
}


void CDialog_Main::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Main)
	DDX_Control(pDX, IDC_PERIOD_SEND, m_Period_Send);
	DDX_Control(pDX, IDC_START_SEND, m_Start_Send);
	DDX_Control(pDX, IDC_DATA_URL, m_Data_Url);
	DDX_Control(pDX, IDC_COM_NUMBER, m_Com_Number);
	DDX_Control(pDX, IDC_TEST_GPRS, m_test_gprs);
	DDX_Control(pDX, IDC_ON_OFF_TC35, m_Open_MSCOMM);
	DDX_Control(pDX, IDC_STATUS_INFORMATION, m_Status_Information);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Main, CDialog)
	//{{AFX_MSG_MAP(CDialog_Main)
	ON_BN_CLICKED(IDC_ON_OFF_TC35, OnOnOffTc35)
	ON_BN_CLICKED(IDC_TEST_GPRS, OnTestGprs)
	ON_BN_CLICKED(IDC_START_SEND, OnStartSend)
	ON_WM_TIMER()
	ON_EN_KILLFOCUS(IDC_PERIOD_SEND, OnKillfocusPeriodSend)
	ON_EN_SETFOCUS(IDC_PERIOD_SEND, OnSetfocusPeriodSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Main message handlers

void CDialog_Main::OnOnOffTc35() 
{
	CTime tmTime = CTime::GetCurrentTime ();

	((CSmsApp*)AfxGetApp())->m_Log.LogMessage("�˿�����");
	// Get the parameter
	if (m_MSCOMM_Open)
	{
		::CloseComm();
		m_MSCOMM_Open = FALSE;

        m_Status_Information.SetSel(-1, -1);
        m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"�����ѹر�\n");

		m_test_gprs.EnableWindow(FALSE);

		m_Start_Send.SetWindowText("������ʱ����");
		m_Start_Send.EnableWindow(FALSE);

		m_Open_MSCOMM.SetWindowText("��TC35����");
		m_test_gprs.EnableWindow(FALSE);
		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("�����ѹر�");
	}
	else
	{
		// Open the COMN
		int		nRate = 9600;
		CString	tmp ;
		CTime tmTime = CTime::GetCurrentTime ();

		m_Com_Number.GetWindowText(tmp);
		//AfxMessageBox(tmp);
		if (!::OpenComm(tmp, nRate))
		{
			m_Status_Information.SetSel(-1, -1);
			m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"���ڴ��쳣���볢���л������˿�\n");
			m_test_gprs.EnableWindow(FALSE);
			
			m_Start_Send.SetWindowText("������ʱ����");
			m_Start_Send.EnableWindow(FALSE);
			
			m_Open_MSCOMM.SetWindowText("��TC35����");
			m_test_gprs.EnableWindow(FALSE);
			//AfxMessageBox("�޷��򿪴��ڣ��뻻�����˿ڻ��߼���Ƿ���������");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("���ڴ��쳣���볢���л������˿�");
		}
		else
		{
			m_MSCOMM_Open = TRUE;
			m_Status_Information.SetSel(-1, -1);
			m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"���ڴ򿪳ɹ�\n");
			m_test_gprs.EnableWindow(TRUE);
			m_Open_MSCOMM.SetWindowText("�ر�TC35����");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("���ڴ򿪳ɹ�");
		}
	}
}

void CDialog_Main::OnTestGprs() 
{
	extern CSmsApp theApp;
	
	CTime tmTime = CTime::GetCurrentTime ();

	if (!gsmInit())
	{

		m_Status_Information.SetSel(-1, -1);
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"TC35����ʧ��\n");

		m_Start_Send.SetWindowText("������ʱ����");
		m_Start_Send.EnableWindow(FALSE);

		theApp.m_Log.LogMessage("TC35����ʧ��");
	}
	else
	{
		m_Status_Information.SetSel(-1, -1);
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"TC35���ӳɹ�\n");

		m_Start_Send.SetWindowText("������ʱ����");
		m_Start_Send.EnableWindow(TRUE);

		theApp.m_Log.LogMessage("TC35���ӳɹ�");
	}
}

/************************************************************************/
/* Funtion is used to start timer 1.      
	re-click will close timer 1;                       
*/
/************************************************************************/
void CDialog_Main::OnStartSend() 
{
	// TODO: Add your control notification handler code here
	
	CTime tmTime = CTime::GetCurrentTime ();

	if (!gsmInit())
	{
		m_Status_Information.SetSel(-1, -1);
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"TC35����ʧ��\n");
		
		m_Start_Send.SetWindowText("������ʱ����");
		m_Start_Send.EnableWindow(FALSE);

		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("TC35����ʧ��");
		return;
	}

	CString	strPeriod;
	m_Period_Send.GetWindowText(strPeriod);
	
	if (strPeriod == "" || atoi(strPeriod) <= 0 )
	{
		//AfxMessageBox("�������ô���������ô���0������");
		m_Status_Information.SetSel(-1, -1);
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"�������ô�������ȷ����Ϊ����0����\n");
		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("�������ô�������ȷ����Ϊ����0����");
	} 
	else
	{
		m_Status_Timer = !m_Status_Timer;
		
		if (m_Status_Timer)
		{
			// ��ʱ��1����ʱ1000ms
			
			m_Start_Send.SetWindowText("�رն�ʱ����");
			m_Status_Information.SetSel(-1, -1);
			m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"��ʱ���Ѿ�����������Ϊ"+strPeriod+"sһ��\n");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("��ʱ���Ѿ�����������Ϊ"+strPeriod+"sһ��");
			{
				// This message is used to test.
				//CString	strSmsc = "13010888500";		//�������ĺ���(����Ķ����������ڶ������ĺ���)
				//CString	strNumber = "13006661808";		//�����͵Ķ��ź���
				//CString	strContent = "���͵���������";	//���͵�����
				
				// get the data from the sever
				// if the server response data is out of our control,will do nothing.
				// otherwise,send the message.
				// you need to get the strSmsc,strNumber,strContent.
				
				CString strSmsc = "",strNumber,strContent;	
				
				CTabCtrl *pDlg = (CTabCtrl *)GetParent();
				CSmsDlg *pSmsDlg = (CSmsDlg *)this->GetParent()->GetParent();
				
				// Get the data from server.
				CInternetSession m_session;
				CString strData;
				TCHAR	ch;
				CString	strRequestURL,strRequestData;
				
				CString	strUsername = pSmsDlg->m_Login_Tab.m_strUsername;
				CString strPassword = pSmsDlg->m_Login_Tab.m_strPassword;
				
				char* User_Password_Char=strPassword.GetBuffer(strPassword.GetLength());
				strPassword = MDString(User_Password_Char);
				
				m_Data_Url.GetWindowText(strRequestURL);
				strRequestURL.TrimLeft(); 
				strRequestURL.TrimRight();
				if (strRequestURL == "")
				{
					AfxMessageBox("�밴�ո�ʽ�����������ַ");
					((CSmsApp*)AfxGetApp())->m_Log.LogMessage("û�������������ַ");
				}
				else if (strRequestURL.Left(7) == "http://" )
				{
					strRequestData = "?username="+ strUsername +"&password="+strPassword;

					((CSmsApp*)AfxGetApp())->m_Log.LogMessage("�ֻ����������͵ķ���������:"+strRequestURL+strRequestData);
					CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(strRequestURL+strRequestData, 1, 
						INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
					
					while (pFile->Read(&ch, sizeof(TCHAR)))
					{
						strData += ch;
					}	
					
					CString* pStr;
					int iSubStrs;
					pStr = SplitString(strData, '#', iSubStrs);
					((CSmsApp*)AfxGetApp())->m_Log.LogMessage("���������ص�����Ϊ:"+strData);
					// if the substr just one.
					if (iSubStrs == 1)
					{
						// This Mean the server is not ok.
						// you need process it.
						//AfxMessageBox(strData); 
						KillTimer(1);
						m_Status_Information.SetSel(-1, -1);
						m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"��ʱ����������������ȹر�\n");
						((CSmsApp*)AfxGetApp())->m_Log.LogMessage("��ʱ����������������ȹر�");
						m_Start_Send.SetWindowText("������ʱ����");
					}
					else
					{   
						// Follow the format,i set the second parm is number,the third is content,the first is status.
						pStr[2].TrimRight("");
						
						// Send the message.
						SendTheMessage(strSmsc,pStr[1],pStr[2]);
						m_Status_Information.SetSel(-1, -1);
						m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"����"+pStr[1]+":"+pStr[2]+"\n");
						((CSmsApp*)AfxGetApp())->m_Log.LogMessage("����"+pStr[1]+":"+pStr[2]);
						delete []pStr;
					}		
					// Start the timer 1
					SetTimer(1,atoi(strPeriod)*1000,NULL);
				}
				else
				{
					AfxMessageBox("��ʹ��httpЭ��");
					((CSmsApp*)AfxGetApp())->m_Log.LogMessage("�����Э�鲻��ȷ");
				}
			}
		} 
		else
		{
			KillTimer(1);
			m_Start_Send.SetWindowText("������ʱ����");
			m_Status_Information.SetSel(-1, -1);
			m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"��ʱ���Ѿ��ر�\n");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("��ʱ���Ѿ��ر�");
		}
	}
}

void CDialog_Main::SendTheMessage(CString strSmsc,CString strNumber,CString strContent)
{
	SM_PARAM SmParam;

	memset(&SmParam, 0, sizeof(SM_PARAM));
	
	// set the default strSmsc
	strSmsc = "13010888500";

	// ȥ������ǰ��"+"
	if(strSmsc[0] == '+')  strSmsc = strSmsc.Mid(1);		//�������ĺ���
	if(strNumber[0] == '+')  strNumber = strNumber.Mid(1);	//���ź���
	
	// �ں���ǰ��"86"
	if(strSmsc.Left(2) != "86")  strSmsc = "86" + strSmsc;
	if(strNumber.Left(2) != "86")  strNumber = "86" + strNumber;

	// ������Ϣ�ṹ
	strcpy(SmParam.SCA, strSmsc);
	strcpy(SmParam.TPA, strNumber);
	strcpy(SmParam.TP_UD, strContent);		//��������
	SmParam.TP_PID = 0;
	SmParam.TP_DCS = GSM_UCS2;
	
	((CSmsApp*)AfxGetApp())->m_Log.LogMessage("���ڷ��Ͷ���Ϣ");
	// ���Ͷ���Ϣ
	m_pSmsTraffic->PutSendMessage(&SmParam);

	char ans[128];
	ReadComm(ans, 128);

	int iPos = 0;
	CString	returnByte;
	returnByte.Format("%s",ans);

	//+CMGS:

	//m_Status_Information.ReplaceSel(returnByte+"\n");

	//�鿴�Ƿ��ͳɹ�������ɹ������޸ķ��������ݵ�״̬
	iPos = returnByte.Find("CMGS");

	m_Status_Information.SetSel(-1, -1);
	CTime tmTime = CTime::GetCurrentTime ();
	if (iPos == -1)
	{
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"����ʧ��\n");
		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("����ʧ��");
    }
	else
	{
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"���ͳɹ�\n");
		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("���ͳɹ�");

		//update server status
		// Get the data from server.
		CInternetSession m_session;
		CString strData;
		TCHAR	ch;
		CString	strRequestURL,strRequestData;
		
		CTabCtrl *pDlg = (CTabCtrl *)GetParent();
		CSmsDlg *pSmsDlg = (CSmsDlg *)this->GetParent()->GetParent();

		CString	strUsername = pSmsDlg->m_Login_Tab.m_strUsername;
		CString strPassword = pSmsDlg->m_Login_Tab.m_strPassword;
		
		char* User_Password_Char=strPassword.GetBuffer(strPassword.GetLength());
		strPassword = MDString(User_Password_Char);
		
		//strRequestURL = "http://192.168.1.200/projecttest/phone/index.php";
		m_Data_Url.GetWindowText(strRequestURL);
		strRequestURL.TrimLeft(); 
		strRequestURL.TrimRight();
		if (strRequestURL == "")
		{
			AfxMessageBox("�밴�ո�ʽ�����������ַ");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("û�������������ַ");
		}
		else if (strRequestURL.Left(7) == "http://" )
		{
			strRequestData = "?username="+ strUsername +"&password="+strPassword;
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("����������url:"+strRequestURL+strRequestData);

			CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(strRequestURL+strRequestData, 1, 
										INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
			
			while (pFile->Read(&ch, sizeof(TCHAR)))
			{
				strData += ch;
			}	
			m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"���������ص���"+strData+"\n");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("���������ص���"+strData);
		}
		else
		{
			AfxMessageBox("��ʹ��httpЭ��");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("�����Э�鲻��ȷ");
		}
	}
}

void CDialog_Main::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case 1:
		//������������
		{
			// This message is used to test.
			//CString	strSmsc = "13010888500";		//�������ĺ���(����Ķ����������ڶ������ĺ���)
			//CString	strNumber = "13006661808";		//�����͵Ķ��ź���
			//CString	strContent = "���͵���������";	//���͵�����
			
			// get the data from the sever
			// if the server response data is out of our control,will do nothing.
			// otherwise,send the message.
			// you need to get the strSmsc,strNumber,strContent.

			CString strSmsc = "",strNumber,strContent;	

			CTabCtrl *pDlg = (CTabCtrl *)GetParent();
			CSmsDlg *pSmsDlg = (CSmsDlg *)this->GetParent()->GetParent();
			
			// Get the data from server.
			CInternetSession m_session;
			CString strData;
			TCHAR	ch;
			CString	strRequestURL,strRequestData;
			
			CString	strUsername = pSmsDlg->m_Login_Tab.m_strUsername;
			CString strPassword = pSmsDlg->m_Login_Tab.m_strPassword;

			char* User_Password_Char=strPassword.GetBuffer(strPassword.GetLength());
		    strPassword = MDString(User_Password_Char);
	
			//strRequestURL = "http://192.168.1.200/projecttest/phone/index.php";
			m_Data_Url.GetWindowText(strRequestURL);
			strRequestURL.TrimLeft(); 
			strRequestURL.TrimRight();
			if (strRequestURL == "")
			{
				AfxMessageBox("�밴�ո�ʽ�����������ַ");
				((CSmsApp*)AfxGetApp())->m_Log.LogMessage("û�������������ַ");
			}
			else if (strRequestURL.Left(7) == "http://" )
			{
				strRequestData = "?username="+ strUsername +"&password="+strPassword;
				
				((CSmsApp*)AfxGetApp())->m_Log.LogMessage("��������url����Ϊ:"+strRequestURL+strRequestData);

				CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(strRequestURL+strRequestData,1, 
					INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
				
				while (pFile->Read(&ch, sizeof(TCHAR)))
				{
					strData += ch;
				}	
				
				//AfxMessageBox(strData);
				((CSmsApp*)AfxGetApp())->m_Log.LogMessage("��������������������Ϊ:"+strData);

				CString* pStr;
				int iSubStrs;
				pStr = SplitString(strData, '#', iSubStrs);
				CTime tmTime = CTime::GetCurrentTime ();
				// if the substr just one.
				if (iSubStrs == 1)
				{
					// This Mean the server is not ok.
					// you need process it.
					//AfxMessageBox(strData); 
					KillTimer(1);
					m_Status_Information.SetSel(-1, -1);
					m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"��ʱ����������������ȹر�\n");
					m_Start_Send.SetWindowText("������ʱ����");

					((CSmsApp*)AfxGetApp())->m_Log.LogMessage("��ʱ����������������ȹر�");
				}
				else
				{   
					// Follow the format,i set the second parm is number,the third is content,the first is status.
					pStr[2].TrimRight("");

					// Send the message.
					SendTheMessage(strSmsc,pStr[1],pStr[2]);
					m_Status_Information.SetSel(-1, -1);
					m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"����"+pStr[1]+":"+pStr[2]+"\n");

					((CSmsApp*)AfxGetApp())->m_Log.LogMessage("����"+pStr[1]+":"+pStr[2]);
					delete []pStr;
				}		
			}
			else
			{
				AfxMessageBox("��ʹ��httpЭ��");
				((CSmsApp*)AfxGetApp())->m_Log.LogMessage("�����Э�鲻��ȷ");
			}
			//KillTimer(1);

			// Send the message.
			//SendTheMessage(strSmsc,strNumber,strContent);

			//AfxMessageBox("�����˶�ʱ����");
		}
		break;
	default:
		break;
    }

	CDialog::OnTimer(nIDEvent);
}


CString* CDialog_Main::SplitString(CString str, char split, int& iSubStrs)
{
    int iPos = 0; //�ָ��λ��
    int iNums = 0; //�ָ��������
    CString strTemp = str;
    CString strRight;
    //�ȼ������ַ���������
    while (iPos != -1)
    {
        iPos = strTemp.Find(split);
        if (iPos == -1)
        {
            break;
        }
        strRight = strTemp.Mid(iPos + 1, str.GetLength());
        strTemp = strRight;
        iNums++;
    }
    if (iNums == 0) //û���ҵ��ָ��
    {
        //���ַ����������ַ�������
        iSubStrs = 1; 
        return NULL;
    }
    //���ַ�������
    iSubStrs = iNums + 1; //�Ӵ������� = �ָ������ + 1
    CString* pStrSplit;
    pStrSplit = new CString[iSubStrs];
    strTemp = str;
    CString strLeft;
    for (int i = 0; i < iNums; i++)
    {
        iPos = strTemp.Find(split);
        //���Ӵ�
        strLeft = strTemp.Left(iPos);
        //���Ӵ�
        strRight = strTemp.Mid(iPos + 1, strTemp.GetLength());
        strTemp = strRight;
        pStrSplit[i] = strLeft;
    }
    pStrSplit[iNums] = strTemp;
    return pStrSplit;
}


void CDialog_Main::OnKillfocusPeriodSend() 
{
	// TODO: Add your control notification handler code here

	CString	strPeriod;
	CTime tmTime = CTime::GetCurrentTime ();
	m_Period_Send.GetWindowText(strPeriod);
	
	if (strPeriod == "" || atoi(strPeriod) <= 0 )
	{
		m_Period_Send.SetWindowText("1");
		m_Status_Information.SetSel(-1, -1);
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"�������ô�������ȷ����Ϊ����0������\n");
		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("�������ô�������ȷ����Ϊ����0������");
	}
	else
	{
		m_Status_Information.SetSel(-1, -1);
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"��������Ϊ"+strPeriod+"\n");
		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("��������Ϊ"+strPeriod);
	}
}

BOOL CDialog_Main::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE)  return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) 
	{

		switch (m_Status_Enter)
		{
			// set the period.
		case 0x01:
				//CDialog_Main::OnKillfocusPeriodSend();
				::SetFocus(NULL);
				m_Status_Enter = 0x00;
			break;
		case 0x02:
			break;
		default:
			{

			}
		}

		return TRUE;
	}
	else 
    return CDialog::PreTranslateMessage(pMsg);
}

void CDialog_Main::OnSetfocusPeriodSend() 
{
	// TODO: Add your control notification handler code here
	m_Status_Enter = 0x01;
}
