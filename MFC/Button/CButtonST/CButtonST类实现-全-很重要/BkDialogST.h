//
//	Class:		CBkDialogST
//
//	Compiler:	Visual C++
//	Tested on:	Visual C++ 6.0
//
//	Version:	See GetVersionC() or GetVersionI()
//
//	Created:	01/September/2000
//	Updated:	26/July/2002
//
//	Author:		Davide Calabro'		davide_calabro@yahoo.com
//									http://www.softechsoftware.it
//
//	Disclaimer
//	----------
//	THIS SOFTWARE AND THE ACCOMPANYING FILES ARE DISTRIBUTED "AS IS" AND WITHOUT
//	ANY WARRANTIES WHETHER EXPRESSED OR IMPLIED. NO REPONSIBILITIES FOR POSSIBLE
//	DAMAGES OR EVEN FUNCTIONALITY CAN BE TAKEN. THE USER MUST ASSUME THE ENTIRE
//	RISK OF USING THIS SOFTWARE.
//
//	Terms of use
//	------------
//	In the past years SoftechSoftware has produced many free controls and code snippets.
//	All of this products were released with the full source codes included and hundreds of developers
//	all around the world have taken benefits using these easy and ready to use controls into their applications.
//	In return, SoftechSoftware asked only for a small money donation from developers.
//	Unfortunately only a very limited number of donations has been received from the large number of users
//	that rely on SoftechSoftware products for their applications.
//	Producing and updating good software costs time. So it costs money. Also, maintaning a dedicated web site
//	costs time and money.
//
//	Starting from now on almost all SoftechSoftware products will be distributed into a single general use DLL.
//	This DLL will show an annoying dialog each time your application starts. Also, this demo DLL has resource
//	and memory leaks that make your target application unstable. You can use the demo DLL only for testing
//	the SoftechSoftware product you are interested in. Then if you decide to use this product into your
//	application you must buy the full DLL version directly from SoftechSoftware.
//
//	SoftechSoftware DLL costs $100.00 (One hundred U.S. Dollars).
//
//		SoftechSoftware
//		Davide Calabro'
//		P.O. Box 65
//		21019 Somma Lombardo (VA)
//		Italy
//
//		http://www.softechsoftware.it
//
#ifndef _BKDIALOGST_H_
#define _BKDIALOGST_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Uncomment following line if you are using this class outside the DLL
//#define _BKDIALOGST_NODLL_

#ifndef _BKDIALOGST_NODLL_
#ifndef	_SOFTECHSOFTWAREDLL_NOLIB_
	#ifdef _DEBUG
		#ifdef _UNICODE
			#pragma comment(lib, "SoftechSoftwareUD.lib")
		#else
			#pragma comment(lib, "SoftechSoftwareD.lib")
		#endif
	#else
		#ifdef _UNICODE
			#pragma comment(lib, "SoftechSoftwareU.lib")
		#else
			#pragma comment(lib, "SoftechSoftware.lib")
		#endif
	#endif
#endif

	#ifdef	_SOFTECHSOFTWAREDLL_BUILDDLL_
		#define	BKDIALOGST_EXPORT	__declspec(dllexport)
	#else
		#define	BKDIALOGST_EXPORT	__declspec(dllimport)
	#endif

#else
		#define	BKDIALOGST_EXPORT
#endif

// Return values
#ifndef	BKDLGST_OK
#define	BKDLGST_OK						0
#endif
#ifndef	BKDLGST_INVALIDRESOURCE
#define	BKDLGST_INVALIDRESOURCE			1
#endif
#ifndef	BKDLGST_INVALIDMODE
#define	BKDLGST_INVALIDMODE				2
#endif
#ifndef	BKDLGST_FAILEDREGION
#define	BKDLGST_FAILEDREGION			3
#endif

// MSDN KB Article: 134980
// PRB: C4251 & C4275 Compiler Warnings While Compiling an AFXDLL
#pragma warning(disable: 4275)
#pragma warning(disable: 4251)

class BKDIALOGST_EXPORT CBkDialogST : public CDialog
{
public:
	CBkDialogST(CWnd* pParent = NULL);
	CBkDialogST(UINT uResourceID, CWnd* pParent = NULL);
	CBkDialogST(LPCTSTR pszResourceID, CWnd* pParent = NULL);

	virtual ~CBkDialogST();

	DWORD SetMode(BYTE byMode, BOOL bRepaint = TRUE);

	DWORD SetBitmap(HBITMAP hBitmap, COLORREF crTransColor = -1L);
	DWORD SetBitmap(int nBitmap, COLORREF crTransColor = -1L);

	DWORD ActivateEasyMoveMode(BOOL bActivate);
#ifndef UNDER_CE
	DWORD ShrinkToFit(BOOL bRepaint = TRUE);
#endif

	enum	{
				BKDLGST_MODE_TILE = 0,
				BKDLGST_MODE_CENTER,
				BKDLGST_MODE_STRETCH,
				BKDLGST_MODE_TILETOP,
				BKDLGST_MODE_TILEBOTTOM,
				BKDLGST_MODE_TILELEFT,
				BKDLGST_MODE_TILERIGHT,
				BKDLGST_MODE_TOPLEFT,
				BKDLGST_MODE_TOPRIGHT,
				BKDLGST_MODE_TOPCENTER,
				BKDLGST_MODE_BOTTOMLEFT,
				BKDLGST_MODE_BOTTOMRIGHT,
				BKDLGST_MODE_BOTTOMCENTER,

				BKDLGST_MAX_MODES
			};

	//{{AFX_DATA(CBkDialogST)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBkDialogST)
	//}}AFX_VIRTUAL

protected:
	// Generated message map functions
	//{{AFX_MSG(CBkDialogST)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnPostEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	static short GetVersionI()		{return 12;}
	static LPCTSTR GetVersionC()	{return (LPCTSTR)_T("1.2");}

private:
	void Init();
	void FreeResources(BOOL bCheckForNULL = TRUE);
#ifndef UNDER_CE
	HRGN ScanRegion(HBITMAP hBitmap, BYTE byTransR, BYTE byTransG, BYTE byTransB);
	LPBYTE Get24BitPixels(HBITMAP hBitmap, LPDWORD lpdwWidth, LPDWORD lpdwHeight);
#endif

	HBITMAP		m_hBitmap;			// Handle to bitmap
#ifndef UNDER_CE
	HRGN		m_hRegion;			// Handle to region
#endif
	DWORD		m_dwWidth;			// Width of bitmap
	DWORD		m_dwHeight;			// Height of bitmap
	BYTE		m_byMode;			// Current drawing bitmap mode
	BOOL		m_bEasyMoveMode;	// Indicates if EasyMove mode must be used

	DECLARE_MESSAGE_MAP()
};

#pragma warning(default: 4275)
#pragma warning(default: 4251)

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
