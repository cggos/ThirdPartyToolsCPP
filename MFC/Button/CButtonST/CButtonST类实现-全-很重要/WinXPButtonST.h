//
//	Class:		CWinXPButtonST
//
//	Compiler:	Visual C++
//				eMbedded Visual C++
//	Tested on:	Visual C++ 6.0
//				Windows CE 3.0
//
//	Created:	03/September/2001
//	Updated:	22/June/2004
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
#ifndef _WINXPBUTTONST_H_
#define _WINXPBUTTONST_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef UNDER_CE
#include "CeBtnST.h"
#define	BASE_BUTTONST	CCeButtonST
#else
#include "BtnST.h"
#define	BASE_BUTTONST	CButtonST
#endif

// Uncomment following line if you are using this class outside the DLL
//#define _WINXPBUTTONST_NODLL_

#ifndef _WINXPBUTTONST_NODLL_
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
		#define	WINXPBUTTONST_EXPORT	__declspec(dllexport)
	#else
		#define	WINXPBUTTONST_EXPORT	__declspec(dllimport)
	#endif

#else
		#define	WINXPBUTTONST_EXPORT
#endif

// MSDN KB Article: 134980
// PRB: C4251 & C4275 Compiler Warnings While Compiling an AFXDLL
#pragma warning(disable: 4275)
#pragma warning(disable: 4251)

class WINXPBUTTONST_EXPORT CWinXPButtonST : public BASE_BUTTONST
{
public:
	CWinXPButtonST();
	virtual ~CWinXPButtonST();

	DWORD SetRounded(BOOL bRounded, BOOL bRepaint = TRUE);

protected:
	virtual DWORD OnDrawBackground(CDC* pDC, CRect* pRect);
	virtual DWORD OnDrawBorder(CDC* pDC, CRect* pRect);

private:
	BOOL	m_bIsRounded;		// Borders must be rounded?
};

#pragma warning(default: 4275)
#pragma warning(default: 4251)

#endif 
