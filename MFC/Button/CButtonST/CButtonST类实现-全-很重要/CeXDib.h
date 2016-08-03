//
//	Class:		CCeXDib
//
//	Compiler:	Visual C++
//				eMbedded Visual C++
//	Tested on:	Visual C++ 6.0
//				Windows CE 3.0
//
//	Author:		Davide Calabro'		davide_calabro@yahoo.com
//									http://www.softechsoftware.it
//
//	Note:		This class uses code snippets taken from a similar class written
//				for the Win32 enviroment by Davide Pizzolato (ing.davide.pizzolato@libero.it)
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
#ifndef _CEXDIB_H_
#define _CEXDIB_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Uncomment following line if you are using this class outside the DLL
//#define _CEXDIB_NODLL_

#ifndef _CEXDIB_NODLL_
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
		#define	CEXDIB_EXPORT	__declspec(dllexport)
	#else
		#define	CEXDIB_EXPORT	__declspec(dllimport)
	#endif

#else
		#define	CEXDIB_EXPORT
#endif

#ifndef	HDIB
#define HDIB	HANDLE
#endif

#ifndef WIDTHBYTES
#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4)
#endif

#ifndef BFT_BITMAP
#define BFT_BITMAP 0x4d42   // 'BM'
#endif

class CEXDIB_EXPORT CCeXDib  
{
public:
	CCeXDib();
	virtual ~CCeXDib();

	HDIB Create(DWORD dwWidth, DWORD dwHeight, WORD wBitCount);
	void Clone(CCeXDib* src);
	void Draw(HDC hDC, DWORD dwX, DWORD dwY);
	LPBYTE GetBits();
	void Clear(BYTE byVal = 0);

	void SetGrayPalette();
	void SetPaletteIndex(BYTE byIdx, BYTE byR, BYTE byG, BYTE byB);
	void SetPixelIndex(DWORD dwX, DWORD dwY, BYTE byI);
	void BlendPalette(COLORREF crColor, DWORD dwPerc);

	WORD GetBitCount();
	DWORD GetLineWidth();
	DWORD GetWidth();
	DWORD GetHeight();
	WORD GetNumColors();

	BOOL WriteBMP(LPCTSTR bmpFileName);

private:
	void FreeResources();

	DWORD GetPaletteSize();
	DWORD GetSize();

	RGBQUAD RGB2RGBQUAD(COLORREF cr);

	HDIB				m_hDib;
    BITMAPINFOHEADER    m_bi;
	DWORD				m_dwLineWidth;
	WORD				m_wColors;

	HBITMAP				m_hBitmap;	// Handle to bitmap
	HDC					m_hMemDC;	// Handle to memory DC
	LPVOID				m_lpBits;	// Pointer to actual bitmap bits
};

#endif 
