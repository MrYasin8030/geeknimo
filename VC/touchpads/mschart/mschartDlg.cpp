// mschartDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mschart.h"
#include "mschartDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMschartDlg dialog

CMschartDlg::CMschartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMschartDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMschartDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMschartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMschartDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMschartDlg, CDialog)
	//{{AFX_MSG_MAP(CMschartDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_ORIGINAL, OnButtonOriginal)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMschartDlg message handlers

BOOL CMschartDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	RECT r;
	SystemParametersInfo( SPI_GETWORKAREA, sizeof(RECT), &r, 0 );
	SetWindowPos(NULL,
		r.left, r.top,
		r.right, r.bottom,
		SWP_SHOWWINDOW);

	//GetDlgItem(IDC_BUTTON_EXIT)->SetWindowPos(NULL,r.left-20,r.top-20,r.left,r.top,SWP_SHOWWINDOW);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMschartDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMschartDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMschartDlg::OnButtonExit() 
{
	// TODO: Add your control notification handler code here
	this->OnCancel();	
}


// ����˵����
// count:����Ҫ��������ݵ�����
// control��Ҫ��ʾ���Ǹ��ؼ���ID
// num�������ά��
// ����ֱ��ͼ�ĵ��ã�DrawHistogram(count,IDC_OLDHISTOGRAM,256);

void CMschartDlg::DrawHistogram(int count[],int control,int num)
{
	CClientDC dc(this);

	//�õ��ؼ��Ĵ�С
	CRect rect;
	GetDlgItem(control)->GetWindowRect(&rect);//��ȡ�ؼ��������Ļ��λ��
	ScreenToClient(rect);//ת��Ϊ�Ի����ϵ����λ��
	CPen* pPenBlue = new CPen;                                  //�������ʶ���
	pPenBlue->CreatePen(PS_SOLID, 2, RGB(0,0,255));     //��ɫ����
	CPen* pPenBlack = new CPen;                                 //�������ʶ���
	pPenBlack->CreatePen(PS_SOLID, 1, RGB(0,0,0)); //��ɫ����
	//ѡ�к�ɫ���ʣ������浱ǰ����
	CGdiObject* pOldPen = dc.SelectObject(pPenBlack);
	int i = 0;
	CString str;
	//��������ϵ
	int OriX=rect.left+40,OriY=rect.bottom-20;//����ϵԭ��OriX��OriY
	CPoint OPos(OriX,OriY),NowPos;	//OPos��ԭ������
	//����x������
	dc.MoveTo(OPos);
	int flag=1;//flag=0,ԭ�������꣬flag=1�������������
	int temp=40 + (num-1)*2 + 5;
	//str.Format("%d",temp);
	//AfxMessageBox(str);
	if(rect.right-rect.left>temp)
	{
		flag=1;
		NowPos.x = OriX + temp;
	}
	else
	{
		flag=0;
		NowPos.x = OriX + (num-1) + 5;
	}
	NowPos.y = OriY;
	dc.LineTo(NowPos);
	//���Ƽ�ͷ
	//dc.LineTo(NowPos.x-5,NowPos.y-5);
	//dc.MoveTo(NowPos);
	//dc.LineTo(NowPos.x-5,NowPos.y+5);
	//����x������ϵ��
	
	for (i = 0;i < num;i = i+5)
	{
		if (i % 10 == 0)
		{
			if(flag==1)
			{
				dc.MoveTo(OPos.x + 2 * i,OPos.y);
				dc.LineTo(CPoint(OPos.x + 2 * i,OPos.y - 5));
			}
			else
			{
				dc.MoveTo(OPos.x + i,OPos.y);
				dc.LineTo(CPoint(OPos.x + i,OPos.y - 5));
			}
		}
		if (i % 20 == 0)
		{
			str.Format("%d",i);
			if(flag==1)
			{
				dc.TextOut(OPos.x + 2 * i,OPos.y + 1,str);
			}
			else
			{
				dc.TextOut(OPos.x + i,OPos.y + 1,str);
			}
		}
	}
	
	//��������255
	str.Format("%d",(num-1));
	if(flag==1)
	{
		dc.MoveTo(OPos.x + 2 * (num-1),OPos.y);
		dc.LineTo(CPoint(OPos.x + 2 * (num-1),OPos.y - 5));
		dc.TextOut(OPos.x + 2 * (num-1),OPos.y + 1,str);
	}
	else
	{
		dc.MoveTo(OPos.x + (num-1),OPos.y);
		dc.LineTo(CPoint(OPos.x + (num-1),OPos.y - 5));
		dc.TextOut(OPos.x + (num-1),OPos.y + 1,str);
	}
	//AfxMessageBox("a");
	//����y������ϵ��
	dc.MoveTo(OPos);
	NowPos.x = OPos.x;
	NowPos.y = rect.top;
	dc.LineTo(NowPos);
	//���Ƽ�ͷ
	//dc.LineTo(NowPos.x - 5,NowPos.y + 5);
	//dc.MoveTo(NowPos);
	//dc.LineTo(NowPos.x + 5,NowPos.y + 5);
	
	//Ѱ������������������
	int max = 0;
	for (i = 0;i < num;i++)
	{
		if (max < count[i])
		{
			max = count[i];
		}
	}
	//y������ϵ�������ݲ���
	int Tstep = max / 10;	//10������
	//y������ϵ���Ŀ̶Ȳ���
	int Ystep = (OriY-rect.top) / 21;//����21��ԭ���ǣ���20����Ϊ��������ݲ�����10������20����2����ʾһ������������һ��1�Ƕ�����ĺÿ�
	//��ʾy����Ŀ̶Ⱥ�����
	for (i = 1;i != 22;i++)//��ʾ21���̶�
	{
		dc.MoveTo(OPos.x,OPos.y - Ystep * i );
		dc.LineTo(CPoint(OPos.x + 5,OPos.y - Ystep * i));
		if (i % 2 == 0)
		{
			str.Format("%d",Tstep * i / 2);
			dc.TextOut(rect.left,OPos.y - Ystep * i - 10,str);
		}
	}
	
	//���ƻҶ�ͼ���ֱ��ͼ
	int RealStep = OPos.y-rect.top-(OriY-rect.top-Ystep*21);
	dc.SelectObject(pPenBlue); //ѡ����ɫ����
	for (i = 0;i < num;i++)
	{
		if(flag==1)
		{
			NowPos.x = OPos.x + (2 * i);
		}
		else
		{
			NowPos.x = OPos.x + i;
		}
		NowPos.y = OPos.y;
		dc.MoveTo(NowPos);
		NowPos.y = long(OPos.y - (float)(((float)(RealStep*20))/(21*max))*count[i]);
		//˵�������������ҿ��ܲ���Ϊʲô����ע��һ�������y������ϵ�������ݲ�����y������ϵ���Ŀ̶Ȳ���
		//������������ģ�(RealStep/21):(max/10)=X:1,Ȼ��Ҫ��X��X��ʾ1�������ö��ٸ��ʾ
		dc.LineTo(NowPos);
	}


	//�ָ���ǰ�Ļ���
	dc.SelectObject(pOldPen);
	delete pPenBlue;
	delete pPenBlack;
}

void CMschartDlg::OnButtonOriginal() 
{
	// TODO: Add your control notification handler code here
	
	//IDD_MSCHART_DIALOG
	//int count[30]={1,2,3,4,5,6,7,8,9};
	//DrawHistogram(count,IDC_BITMAP_1,30);
}
