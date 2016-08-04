#pragma once

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;

class CGdiPlusBitmap
{
public:
	Gdiplus::Bitmap* m_pBitmap;

public:
	CGdiPlusBitmap()							{ m_pBitmap = NULL; }
	CGdiPlusBitmap(LPCWSTR pFile)				{ m_pBitmap = NULL; Load(pFile); }
	virtual ~CGdiPlusBitmap()					{ Empty(); }

	void Empty()								{ delete m_pBitmap; m_pBitmap = NULL; }

	bool Load(LPCWSTR pFile)
	{
		TRACE(_T("in Load\n"));

		Empty();
		m_pBitmap = Gdiplus::Bitmap::FromFile(pFile);
		return m_pBitmap->GetLastStatus() == Gdiplus::Ok;
	}

	operator Gdiplus::Bitmap*() const			{ return m_pBitmap; }
};

class CGdiPlusBitmapResource : public CGdiPlusBitmap
{
protected:
	HGLOBAL m_hBuffer;

public:
	CGdiPlusBitmapResource()					{ m_hBuffer = NULL; }
	CGdiPlusBitmapResource(LPCTSTR pName, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL)
												{ m_hBuffer = NULL; Load(pName, pType, hInst); }
	CGdiPlusBitmapResource(UINT id, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL)
												{ m_hBuffer = NULL; Load(id, pType, hInst); }
	CGdiPlusBitmapResource(UINT id, UINT type, HMODULE hInst = NULL)
												{ m_hBuffer = NULL; Load(id, type, hInst); }
	virtual ~CGdiPlusBitmapResource()			{ Empty(); }

	void Empty();

	bool Load(LPCTSTR pName, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL, int nSize = 16);
	bool Load(UINT id, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL, int nSize = 16)
	{ 
		TRACE(_T("in Load 2\n"));
		return Load(MAKEINTRESOURCE(id), pType, hInst, nSize); 
	}
	bool Load(UINT id, UINT type, HMODULE hInst = NULL)
	{ 
		TRACE(_T("in Load 3\n"));
		return Load(MAKEINTRESOURCE(id), MAKEINTRESOURCE(type), hInst); 
	}
};

inline
void CGdiPlusBitmapResource::Empty()
{
	CGdiPlusBitmap::Empty();
	if (m_hBuffer)
	{
		::GlobalUnlock(m_hBuffer);
		::GlobalFree(m_hBuffer);
		m_hBuffer = NULL;
					delete m_pBitmap;
					m_pBitmap = NULL;
	} 
}

inline
bool CGdiPlusBitmapResource::Load(LPCTSTR pName, LPCTSTR pType, HMODULE hInst, int nSize /*= 16*/)
{
	TRACE(_T("in CGdiPlusBitmapResource::Load 1\n"));
	Empty();

	if (_tcsicmp(pType, _T("ICON")) == 0)
	{
		HICON hIcon = (HICON) ::LoadImage(hInst, 
									pName,
									IMAGE_ICON, nSize, nSize, LR_DEFAULTCOLOR);
		ASSERT(hIcon);

		if (hIcon)
		{
			m_pBitmap = Gdiplus::Bitmap::FromHICON(hIcon);

			::DestroyIcon(hIcon);

			if (m_pBitmap)
			{ 
				if (m_pBitmap->GetLastStatus() == Gdiplus::Ok)
					return true;

				TRACE(_T("GetLastStatus NOT ok\n"));
				delete m_pBitmap;
				m_pBitmap = NULL;
			}
		}
		return false;
	}

	HRSRC hResource = ::FindResource(hInst, pName, pType);
	if (!hResource)
		return false;
	
	DWORD imageSize = ::SizeofResource(hInst, hResource);
	if (!imageSize)
		return false;

	const void* pResourceData = ::LockResource(::LoadResource(hInst, hResource));
	if (!pResourceData)
		return false;

	m_hBuffer  = ::GlobalAlloc(GMEM_MOVEABLE, imageSize);
	if (m_hBuffer)
	{
		void* pBuffer = ::GlobalLock(m_hBuffer);
		if (pBuffer)
		{
			CopyMemory(pBuffer, pResourceData, imageSize);

			IStream* pStream = NULL;
			if (::CreateStreamOnHGlobal(m_hBuffer, FALSE, &pStream) == S_OK)
			{
				m_pBitmap = Gdiplus::Bitmap::FromStream(pStream);
				pStream->Release();
				if (m_pBitmap)
				{ 
					if (m_pBitmap->GetLastStatus() == Gdiplus::Ok)
						return true;

					delete m_pBitmap;
					m_pBitmap = NULL;
				}
			}
			::GlobalUnlock(m_hBuffer);
		}
		::GlobalFree(m_hBuffer);
		m_hBuffer = NULL;
	}
	return false;
}

