// FullScreenTouchPadDlg.h : header file
//

#if !defined(AFX_FULLSCREENTOUCHPADDLG_H__B5481FCC_81F0_42C6_AF0E_429AD719BC4C__INCLUDED_)
#define AFX_FULLSCREENTOUCHPADDLG_H__B5481FCC_81F0_42C6_AF0E_429AD719BC4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFullScreenTouchPadDlg dialog
#include "BarChart.h"

class CFullScreenTouchPadDlg : public CDialog
{
// Construction
public:
	CFullScreenTouchPadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFullScreenTouchPadDlg)
	enum { IDD = IDD_FULLSCREENTOUCHPAD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFullScreenTouchPadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
	CBarChart m_TestBar;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFullScreenTouchPadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FULLSCREENTOUCHPADDLG_H__B5481FCC_81F0_42C6_AF0E_429AD719BC4C__INCLUDED_)
