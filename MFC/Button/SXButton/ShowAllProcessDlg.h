// ShowAllProcessDlg.h : header file
//

#if !defined(AFX_SHOWALLPROCESSDLG_H__B6A21A21_3ED8_4E43_9AD4_10E86295C407__INCLUDED_)
#define AFX_SHOWALLPROCESSDLG_H__B6A21A21_3ED8_4E43_9AD4_10E86295C407__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SXButton.h"
/////////////////////////////////////////////////////////////////////////////
// CShowAllProcessDlg dialog

class CShowAllProcessDlg : public CDialog
{
// Construction
public:
	DWORD m_ProcessIndex[50];//存放所有进程的ID
	CShowAllProcessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShowAllProcessDlg)
	enum { IDD = IDD_SHOWALLPROCESS_DIALOG };
	CListCtrl	m_showlist;
	CSXButton	m_show;
	CSXButton	m_exit;
	CSXButton	m_stop;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowAllProcessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShowAllProcessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetProcess();
	afx_msg void OnStopProcess();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWALLPROCESSDLG_H__B6A21A21_3ED8_4E43_9AD4_10E86295C407__INCLUDED_)
