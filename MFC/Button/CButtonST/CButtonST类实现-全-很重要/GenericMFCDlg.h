#ifndef _GENERICMFCDLG_H_
#define _GENERICMFCDLG_H_

#include "BkDialogST.h"
#include "PageManagerEx1ST.h"
#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"

#include "DlgBasic.h"
#include "DlgAdvanced.h"
#include "DlgTransparent.h"
#include "DlgShadeButtonST.h"
#include "DlgAbout.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGenericMFCDlg : public CBkDialogST
{
public:
	CGenericMFCDlg(CWnd* pParent = NULL);

	//{{AFX_DATA(CGenericMFCDlg)
	enum { IDD = IDD_GENERICMFC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGenericMFCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGenericMFCDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG

private:
	virtual void OnPostEraseBkgnd(CDC* pDC);
	LRESULT On_PageActivationCallback(WPARAM wParam, LPARAM lParam);
	BOOL CreatePages();
	CPageManagerEx1ST	m_Pages;
	CImageList			m_ImageList;

	CThemeHelperST		m_Theme;
	CXPStyleButtonST	m_btnExit;

	CHyperLink			m_EMailLink;
	CHyperLink			m_HomePageLink;

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
