//
//	Class:		CPageManagerST
//
//	Compiler:	Visual C++
//	Tested on:	Visual C++ 6.0
//
//	Version:	See GetVersionC() or GetVersionI()
//
//	Created:	13/August/2002
//	Updated:	21/August/2002
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
#ifndef _PAGEMANAGERST_H
#define _PAGEMANAGERST_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Uncomment following line if you are using this class outside the DLL
//#define _PAGEMANAGERST_NODLL_

#ifndef _PAGEMANAGERST_NODLL_
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
		#define	PAGEMANAGERST_EXPORT	__declspec(dllexport)
	#else
		#define	PAGEMANAGERST_EXPORT	__declspec(dllimport)
	#endif

#else
		#define	PAGEMANAGERST_EXPORT
#endif

// Return values
#ifndef	PAGEMANAGERST_OK
#define	PAGEMANAGERST_OK				0
#endif
#ifndef	PAGEMANAGERST_ALREADYCREATED
#define	PAGEMANAGERST_ALREADYCREATED	1
#endif
#ifndef	PAGEMANAGERST_NOTCREATED
#define	PAGEMANAGERST_NOTCREATED		2
#endif
#ifndef	PAGEMANAGERST_NOMEMORY
#define	PAGEMANAGERST_NOMEMORY			3
#endif
#ifndef	PAGEMANAGERST_NOSUBCLASS
#define	PAGEMANAGERST_NOSUBCLASS		4
#endif
#ifndef	PAGEMANAGERST_INVALIDPAGE
#define	PAGEMANAGERST_INVALIDPAGE		5
#endif
#ifndef	PAGEMANAGERST_CREATEPAGEFAILED
#define	PAGEMANAGERST_CREATEPAGEFAILED	6
#endif
#ifndef	PAGEMANAGERST_NOCONTROLSTYLE
#define	PAGEMANAGERST_NOCONTROLSTYLE	7
#endif

// MSDN KB Article: 134980
// PRB: C4251 & C4275 Compiler Warnings While Compiling an AFXDLL
#pragma warning(disable: 4275)
#pragma warning(disable: 4251)

class PAGEMANAGERST_EXPORT	CPageManagerST  
{
public:
	CPageManagerST();
	virtual ~CPageManagerST();

	DWORD CreateFromStatic(UINT nID, CWnd* pParent);
	DWORD AddPage(CWnd* pPage, UINT nID, LPCTSTR lpszPageTitle = _T(""), DWORD dwPageData = 0);
	DWORD ActivatePage(DWORD dwPageNumber);
	DWORD ActivatePrevPage();
	DWORD ActivateNextPage();
	virtual DWORD ResizePage(DWORD dwPageNumber);

	DWORD GetCurrentPageNumber(LPDWORD lpdwPageNumber);
	DWORD GetPageCount(LPDWORD lpdwPageCount);

	DWORD GetPagePtr(DWORD dwPageNumber, CWnd** lpPagePtr);

	DWORD SetPageData(DWORD dwPageNumber, DWORD dwPageData);
	DWORD GetPageData(DWORD dwPageNumber, LPDWORD lpdwPageData);

	DWORD SetPageTitle(DWORD dwPageNumber, LPCTSTR lpszPageTitle);
	DWORD GetPageTitle(DWORD dwPageNumber, LPTSTR lpszPageTitle);
	DWORD GetPageTitle(DWORD dwPageNumber, CString& sPageTitle);

	DWORD SetPageActivationCallback(HWND hWnd, UINT nMessage);

	DWORD SendMessageToPage(DWORD dwPageNumber, UINT nMessage, WPARAM wParam = 0, LPARAM lParam = 0);
	DWORD PostMessageToPage(DWORD dwPageNumber, UINT nMessage, WPARAM wParam = 0, LPARAM lParam = 0);

	static short GetVersionI()		{return 10;}
	static LPCTSTR GetVersionC()	{return (LPCTSTR)_T("1.0");}

private:
	void Clean();
	DWORD Expand(BYTE byNumFreePagesToAdd);
	virtual void OnSetPageInactive(DWORD dwPageNumber);
	virtual void OnSetPageActive(DWORD dwPageNumber);
	virtual BOOL CreatePage(CWnd* pPage, UINT nIDTemplate, CWnd* pParentWnd);

	CStatic			m_stcPlaceHolder;

	typedef struct _STRUCT_PAGES
	{
		CWnd*	pPage;
		TCHAR	szPageTitle[256];
		DWORD	dwPageData;
	} STRUCT_PAGES;

	typedef struct _STRUCT_CALLBACK
	{
		HWND		hWnd;			// Handle to window
		UINT		nMessage;		// Message identifier
		WPARAM		wParam;
		LPARAM		lParam;
	} STRUCT_CALLBACK;

protected:
	STRUCT_PAGES*	m_pPages;
	STRUCT_CALLBACK	m_csCallbacks;
	DWORD			m_dwNumPages;			// Number of valid pages
	DWORD			m_dwNumAllocatedPages;	// Number of allocated pages
	DWORD			m_dwCurrentPage;		// Current active page or -1L
};

#pragma warning(default: 4275)
#pragma warning(default: 4251)

#endif
