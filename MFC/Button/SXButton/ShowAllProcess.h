// ShowAllProcess.h : main header file for the SHOWALLPROCESS application
//

#if !defined(AFX_SHOWALLPROCESS_H__21B5480D_A3F6_4B89_A4F1_0D12F76AF586__INCLUDED_)
#define AFX_SHOWALLPROCESS_H__21B5480D_A3F6_4B89_A4F1_0D12F76AF586__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowAllProcessApp:
// See ShowAllProcess.cpp for the implementation of this class
//

class CShowAllProcessApp : public CWinApp
{
public:
	CShowAllProcessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowAllProcessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShowAllProcessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWALLPROCESS_H__21B5480D_A3F6_4B89_A4F1_0D12F76AF586__INCLUDED_)
