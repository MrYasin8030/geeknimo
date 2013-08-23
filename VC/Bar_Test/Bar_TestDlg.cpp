
// Bar_TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bar_Test.h"
#include "Bar_TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CBar_TestDlg �Ի���




CBar_TestDlg::CBar_TestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBar_TestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBar_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBar_TestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CBar_TestDlg ��Ϣ�������

BOOL CBar_TestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CRect rcClient;
	GetClientRect(&rcClient);

	if (!m_chart.Create(CRect(20, 20, rcClient.Width()-20, rcClient.Height() - 20), this, 1050 ))
	{
		if (!m_chart.GetSafeHwnd())
		{
			AfxMessageBox(_T("���ܴ���ͼ��ؼ���"));
			return FALSE;
		}

		m_chart.Reset();
		m_chart.SetAutoScale(FALSE);
	}

	m_chart.SetTitle(_T("һ������ͼ����ʾһЩ��������"));
	m_chart.SetBKColor(RGB(255, 255, 240));
	m_chart.ShowTooltip(TRUE);

	m_chart.AddBar(1600.356,_T("һ��"), RGB(255,255,0));
	m_chart.AddBar(2841.5468,_T("����"), RGB(255,0,0));
	m_chart.AddBar(1045.3258,_T("����"), RGB(100,100,200));
	m_chart.AddBar(1502.215,_T("����"), RGB(0,255,0));
	m_chart.AddBar(1467,_T("����"), RGB(255,255,255));
	m_chart.AddBar(1678.354,_T("����"), RGB(200,255,255));
	m_chart.AddBar(1785.689,_T("����"), RGB(255,240,40));
	m_chart.AddBar(1283.099,_T("����"), RGB(255,60,130));
	m_chart.AddBar(1554.879,_T("����"), RGB(255,255,200));
	m_chart.AddBar(1400.10,_T("ʮ��"), RGB(130,235,250));
	m_chart.AddBar(1600.556,_T("ʮһ��"), RGB(100,150,200));
	m_chart.AddBar(1900.3546,_T("ʮ����"), RGB(150,240,80), TRUE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CBar_TestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CBar_TestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CBar_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

