#ifndef _SPLASH_HEADER_ 
#define _SPLASH_HEADER_

#pragma once
//#include "afxwin.h"

// CSplashWnd

class CSplashWnd : public CWnd
{
	//DECLARE_DYNAMIC(CSplashWnd)

public:
	CSplashWnd();
	virtual ~CSplashWnd();
	virtual void PostNcDestroy();

public:
	CBitmap m_bitmap;

protected:
	static BOOL c_bShowSplashWnd;
	static CSplashWnd* c_pSplashWnd;

public:
	static void EnableSplashScreen(BOOL bEnable = TRUE);
	static void ShowSplashScreen(CWnd* pParentWnd = NULL);
	static BOOL PreTranslateAppMessage(MSG* pMsg);

protected:
	BOOL Create(CWnd* pParentWnd = NULL);
	void HideSplashScreen();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);

protected:
	DECLARE_MESSAGE_MAP()
};
#endif 