#if !defined(AFX_DIALOG_TAB_PCB_SETTING_H__F290015D_AA93_441C_89E3_F27DBA2229FE__INCLUDED_)
#define AFX_DIALOG_TAB_PCB_SETTING_H__F290015D_AA93_441C_89E3_F27DBA2229FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_Tab_Pcb_Setting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_Pcb_Setting dialog

class CDialog_Tab_Pcb_Setting : public CDialog
{
// Construction
public:
	CDialog_Tab_Pcb_Setting(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Tab_Pcb_Setting)
	enum { IDD = IDD_TAB_PCB_SETTING };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Tab_Pcb_Setting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Tab_Pcb_Setting)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_TAB_PCB_SETTING_H__F290015D_AA93_441C_89E3_F27DBA2229FE__INCLUDED_)
