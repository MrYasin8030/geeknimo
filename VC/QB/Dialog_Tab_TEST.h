#if !defined(AFX_DIALOG_TAB_TEST_H__D0F2BA54_7B43_4393_8FAF_8E6E0CCD50A6__INCLUDED_)
#define AFX_DIALOG_TAB_TEST_H__D0F2BA54_7B43_4393_8FAF_8E6E0CCD50A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_Tab_Test.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_TEST dialog

class CDialog_Tab_Test : public CDialog
{
// Construction
public:
	CDialog_Tab_Test(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Tab_TEST)
	enum { IDD = IDD_TAB_TEST };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Tab_TEST)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Tab_TEST)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_TAB_TEST_H__D0F2BA54_7B43_4393_8FAF_8E6E0CCD50A6__INCLUDED_)
