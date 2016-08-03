//
//	Class:		CThemeHelperST
//
//	Compiler:	Visual C++
//	Tested on:	Visual C++ 6.0
//
//	Version:	See GetVersionC() or GetVersionI()
//
//	Created:	09/January/2002
//	Updated:	31/October/2002
//
//	Author:		Davide Calabro'		davide_calabro@yahoo.com
//									http://www.softechsoftware.it
//
//	Note:		Based on the CVisualStylesXP code 
//				published by David Yuheng Zhao (yuheng_zhao@yahoo.com)
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
#ifndef _THEMEHELPERST_H_
#define _THEMEHELPERST_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Uncomment following line if you are using this class outside the DLL
//#define _THEMEHELPERST_NODLL_

#ifndef _THEMEHELPERST_NODLL_
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
		#define	THEMEHELPERST_EXPORT	__declspec(dllexport)
	#else
		#define	THEMEHELPERST_EXPORT	__declspec(dllimport)
	#endif

#else
		#define	THEMEHELPERST_EXPORT
#endif

#ifndef	HTHEME
#define	HTHEME	HANDLE
#endif

class THEMEHELPERST_EXPORT CThemeHelperST  
{
public:
	CThemeHelperST();
	virtual ~CThemeHelperST();

	HTHEME OpenThemeData(HWND hwnd, LPCWSTR pszClassList);
	HRESULT CloseThemeData(HTHEME hTheme);
	HRESULT DrawThemeBackground(HTHEME hTheme, HWND hWnd, HDC hdc, int iPartId, int iStateId, const RECT* pRect, const RECT* pClipRect);
	HRESULT DrawThemeText(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, LPCWSTR pszText, int iCharCount, DWORD dwTextFlags, DWORD dwTextFlags2, const RECT* pRect);
	BOOL IsThemeActive();
	BOOL IsAppThemed();

	static short GetVersionI()		{return 11;}
	static LPCTSTR GetVersionC()	{return (LPCTSTR)_T("1.1");}

private:
	LPVOID GetProc(LPCSTR szProc, LPVOID pfnFail);

	typedef HTHEME(__stdcall *PFNOPENTHEMEDATA)(HWND hwnd, LPCWSTR pszClassList);
	static HTHEME __stdcall OpenThemeDataFail(HWND, LPCWSTR)	{return NULL;}

	typedef HRESULT(__stdcall *PFNCLOSETHEMEDATA)(HTHEME hTheme);
	static HRESULT __stdcall CloseThemeDataFail(HTHEME)	{return E_FAIL;}

	typedef HRESULT(__stdcall *PFNDRAWTHEMEBACKGROUND)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT* pRect,  const RECT* pClipRect);
	static HRESULT __stdcall DrawThemeBackgroundFail(HTHEME, HDC, int, int, const RECT*, const RECT*)	{return E_FAIL;}

	typedef HRESULT(__stdcall *PFNDRAWTHEMEPARENTBACKGROUND)(HWND hWnd, HDC hdc, RECT* pRect);

	typedef HRESULT (__stdcall *PFNDRAWTHEMETEXT)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, LPCWSTR pszText, int iCharCount, DWORD dwTextFlags, DWORD dwTextFlags2, const RECT* pRect);
	static HRESULT __stdcall DrawThemeTextFail(HTHEME, HDC, int, int, LPCWSTR, int, DWORD, DWORD, const RECT*)	{return E_FAIL;}

	typedef BOOL(__stdcall *PFNISAPPTHEMED)();
	static BOOL __stdcall IsAppThemedFail()	{return FALSE;}

	typedef BOOL (__stdcall *PFNISTHEMEACTIVE)();
	static BOOL __stdcall IsThemeActiveFail()	{return FALSE;}

	HMODULE		m_hDll;
};

#endif 
