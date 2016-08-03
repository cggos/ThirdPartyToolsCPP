// UniButton.cpp : implementation file
//

#include "stdafx.h"
//#include "UniBtn.h"
#include "UniButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUniButton

CUniButton::CUniButton()
{
	m_nColor = GetSysColor(COLOR_BTNFACE);
	m_sColor = m_nColor;
	m_hColor = m_nColor;
	m_dColor = m_nColor;
	m_nBorder = 1;
	m_lfEscapement = 0;
	m_pNormal = NULL;
	m_pSelected = NULL;
	m_pHover = NULL;
	m_pDisabled = NULL;
	m_hRgn = 0;
	m_bHover = false;
	m_bCapture = false;
	m_bMouseDown = false;
	m_bNeedBitmaps = true;
}

CUniButton::~CUniButton()
{
	delete m_pNormal;
	delete m_pSelected;
	delete m_pHover;
	delete m_pDisabled;
	DeleteObject(m_hRgn);
}

BEGIN_MESSAGE_MAP(CUniButton, CButton)
	//{{AFX_MSG_MAP(CUniButton)
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUniButton message handlers

BOOL CUniButton::Create(LPCTSTR lpszCaption, DWORD dwStyle, const CPoint point, const HRGN hRgn, CWnd* pParentWnd, UINT nID)
{
	DeleteObject(m_hRgn);
	m_hRgn = CreateRectRgn(0, 0, 31, 31);
	CRect box(0, 0, 0, 0);
	if (m_hRgn != 0) 
		CombineRgn(m_hRgn, hRgn, 0, RGN_COPY);

	GetRgnBox(m_hRgn, &box);
	OffsetRgn(m_hRgn, -box.left, -box.top);
	GetRgnBox(m_hRgn, &box);

	m_CenterPoint = CPoint(box.left + box.Width() /2 , box.top + box.Height() /2);
	box.OffsetRect(point);

	return CButton::Create(lpszCaption, dwStyle, box, pParentWnd, nID);
}

BOOL CUniButton::Create(LPCTSTR lpszCaption, DWORD dwStyle, const CPoint point, const HRGN hRgn, CWnd* pParentWnd, UINT nID, COLORREF color)
{
	m_sColor = color;
	m_hColor = color;

	return Create(lpszCaption, dwStyle, point, hRgn, pParentWnd, nID);
}

BOOL CUniButton::Create(LPCTSTR lpszCaption, DWORD dwStyle, const CPoint point, const HRGN hRgn, CWnd* pParentWnd, UINT nID, UINT nBorder, LONG lfEscapement, COLORREF nColor, COLORREF sColor, COLORREF hColor, COLORREF dColor)
{
	m_lfEscapement = lfEscapement;
	return Create(lpszCaption, dwStyle, point, hRgn, pParentWnd, nID, nBorder, nColor, sColor, hColor, dColor);
}

BOOL CUniButton::Create(LPCTSTR lpszCaption, DWORD dwStyle, const CPoint point, const HRGN hRgn, CWnd* pParentWnd, UINT nID, UINT nBorder, COLORREF nColor, COLORREF sColor, COLORREF hColor, COLORREF dColor)
{
	m_nBorder = nBorder;
	m_nColor = nColor;
	m_sColor = sColor;
	m_hColor = hColor;
	m_dColor = dColor;

	return Create(lpszCaption, dwStyle, point, hRgn, pParentWnd, nID);
}

void CUniButton::PreSubclassWindow() 
{
	ModifyStyle(0, BS_OWNERDRAW | BS_PUSHBUTTON);	
	CButton::PreSubclassWindow();
}

int CUniButton::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CButton::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_bNeedBitmaps = true;
	SetWindowRgn(m_hRgn, TRUE);

	return 0;
}

void CUniButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_bMouseDown = true;
	if (!m_bCapture) {
		SetCapture();
		m_bCapture = true;
	}
	CButton::OnLButtonDown(nFlags, point);
}

void CUniButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CButton::OnLButtonUp(nFlags, point);

	m_bMouseDown = false;	
	if (m_bCapture) {
		ReleaseCapture();
		m_bCapture = false;
	}
	CheckHover(point);
}

void CUniButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (!m_bMouseDown)
		CheckHover(point);

	CButton::OnMouseMove(nFlags, point);
}

void CUniButton::CheckHover(CPoint point)
{
	if (HitTest(point))
	{
		if (!m_bCapture)
		{
			SetCapture();
			m_bCapture = true;
		}
		if (!m_bHover)
		{
			m_bHover = true;
			RedrawWindow();
		}
	}
	else
	{
		if (m_bCapture)
		{
			ReleaseCapture();
			m_bCapture = false;
		}
		m_bHover = false;
		RedrawWindow();
	}
}

LRESULT CUniButton::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == WM_LBUTTONDBLCLK)
		message = WM_LBUTTONDOWN;
	
	return CButton::DefWindowProc(message, wParam, lParam);
}

BOOL CUniButton::HitTest(CPoint point)
{
	BOOL result = FALSE;

	HRGN hRgn = CreateRectRgn(0, 0, 0, 0);
	GetWindowRgn(hRgn);
	CRect rgnRect;
	GetRgnBox(hRgn, &rgnRect);

	result = PtInRect(&rgnRect, point) && PtInRegion(hRgn, point.x, point.y);

	DeleteObject(hRgn);
	return result;
}

BOOL CUniButton::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

void CUniButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct -> hDC);
	CRect rect;
	GetClientRect(rect);

	if (m_bNeedBitmaps)
		PrepareStateBitmaps(pDC, &rect);

	DrawButton(pDC, &rect, lpDrawItemStruct -> itemState);
}

void CUniButton::PrepareStateBitmaps(CDC * pDC, CRect * pRect)
{
	CDC * pMemDC;
	pMemDC = new CDC;
	pMemDC -> CreateCompatibleDC(pDC);

	PrepareNormalState(pDC, pMemDC, pRect);
	PrepareSelectedState(pDC, pMemDC, pRect);
	PrepareHoverState(pDC, pMemDC, pRect);
	PrepareDisabledState(pDC, pMemDC, pRect);

	delete pMemDC; 
	m_bNeedBitmaps = false;
}


void CUniButton::PrepareNormalState(CDC * pDC, CDC * pMemDC, CRect * pRect)
{
	delete m_pNormal;
	m_pNormal = new CBitmap;
	PaintRgn(pDC, pMemDC, m_pNormal, m_nColor, pRect, true, false);
}

void CUniButton::PrepareSelectedState(CDC * pDC, CDC * pMemDC, CRect * pRect)
{
	delete m_pSelected;
	m_pSelected = new CBitmap;
	PaintRgn(pDC, pMemDC, m_pSelected, m_sColor, pRect, true, true);
}

void CUniButton::PrepareHoverState(CDC * pDC, CDC * pMemDC, CRect * pRect)
{
	delete m_pHover;
	m_pHover = new CBitmap;
	PaintRgn(pDC, pMemDC, m_pHover, m_hColor, pRect, true, false);
}

void CUniButton::PrepareDisabledState(CDC * pDC, CDC * pMemDC, CRect * pRect)
{
	delete m_pDisabled;
	m_pDisabled = new CBitmap;
	PaintRgn(pDC, pMemDC, m_pDisabled, m_dColor, pRect, false, false);
}

void CUniButton::PaintRgn(CDC * pDC, CDC * pMemDC, CBitmap * pBitmap, COLORREF color, CRect * pRect, BOOL bEnabled, BOOL bSunken)
{
	pBitmap -> CreateCompatibleBitmap(pDC, pRect -> Width(), pRect -> Height());
	CBitmap * pOldBitmap = pMemDC -> SelectObject(pBitmap); 

	HRGN hRgn = CreateRectRgn(0, 0, 0, 0);
	GetWindowRgn(hRgn);

	HBRUSH hBrush = CreateSolidBrush(color);
	pMemDC -> FillSolidRect(pRect, RGB(0, 0, 0));
	FillRgn(pMemDC -> GetSafeHdc(), hRgn, hBrush);
	DeleteObject(hBrush);

	DrawButtonCaption(pMemDC -> GetSafeHdc(), pRect, bEnabled, bSunken);
	FrameRgn3D(pMemDC -> GetSafeHdc(), hRgn, bSunken);

	DeleteObject(hRgn);
	pMemDC -> SelectObject(pOldBitmap); 
}

void CUniButton::DrawButtonCaption(HDC hDC, CRect * pRect, BOOL bEnabled, BOOL bSunken) 
{
	int nOldMode = SetBkMode(hDC, TRANSPARENT);
	CString text;
	GetWindowText(text);
	LOGFONT lf;
	GetParent() -> GetFont() -> GetLogFont(&lf);
	HFONT hFont = CreateFontIndirect(&lf);
	HFONT hOldFont = (HFONT) SelectObject(hDC, hFont);

	TEXTMETRIC tm;
	GetTextMetrics(hDC, &tm);
	CPoint p = CPoint(m_CenterPoint.x, m_CenterPoint.y + tm.tmHeight/ 2); 
	if (bSunken) 
		p.Offset(m_nBorder, m_nBorder); 

	if (bEnabled) {
		SetTextColor(hDC, GetSysColor(COLOR_BTNTEXT));
		SetTextAlign(hDC, TA_CENTER | TA_BOTTOM);
		TextOut(hDC, p.x, p.y, text, text.GetLength());
	}
	else {
		SetTextColor(hDC, GetSysColor(COLOR_3DHILIGHT));
		TextOut(hDC, p.x + 1, p.y + 1, text, text.GetLength());
		SetTextColor(hDC, GetSysColor(COLOR_3DSHADOW));
		TextOut(hDC, p.x, p.y, text, text.GetLength());
	}

	SelectObject(hDC, hOldFont);
	DeleteObject(hFont);
	SetBkMode(hDC, nOldMode);
}

void CUniButton::FrameRgn3D(HDC hDC, const HRGN hRgn, BOOL bSunken)
{
	HBRUSH hBrush;
	HRGN hBaseRgn = CreateRectRgn(0, 0, 0, 0);

	COLORREF ltOuter, ltInner, rbOuter, rbInner;

	if (!bSunken) {
		ltOuter = GetSysColor(COLOR_3DLIGHT);
		ltInner = GetSysColor(COLOR_3DHILIGHT);
		rbOuter = GetSysColor(COLOR_3DDKSHADOW);
		rbInner = GetSysColor(COLOR_3DSHADOW);
	}
	else {
		rbInner = GetSysColor(COLOR_3DLIGHT);
		rbOuter = GetSysColor(COLOR_3DHILIGHT);
		ltInner = GetSysColor(COLOR_3DDKSHADOW);
		ltOuter = GetSysColor(COLOR_3DSHADOW);
	}

	switch (m_nBorder)
	{
	case 2:
		CombineRgn(hBaseRgn, hRgn, 0, RGN_COPY);
		OffsetRgn(hBaseRgn, 2, 2);
		CombineRgn(hBaseRgn, hRgn, hBaseRgn, RGN_DIFF);
		hBrush = CreateSolidBrush(ltInner);
		FillRgn(hDC, hBaseRgn, hBrush);
		DeleteObject(hBrush);

		CombineRgn(hBaseRgn, hRgn, 0, RGN_COPY);
		OffsetRgn(hBaseRgn, -2, -2);
		CombineRgn(hBaseRgn, hRgn, hBaseRgn, RGN_DIFF);
		hBrush = CreateSolidBrush(rbInner);
		FillRgn(hDC, hBaseRgn, hBrush);
		DeleteObject(hBrush);

		CombineRgn(hBaseRgn, hRgn, 0, RGN_COPY);
		OffsetRgn(hBaseRgn, 1, 1);
		CombineRgn(hBaseRgn, hRgn, hBaseRgn, RGN_DIFF);
		hBrush = CreateSolidBrush(ltOuter);
		FillRgn(hDC, hBaseRgn, hBrush);
		DeleteObject(hBrush);

		CombineRgn(hBaseRgn, hRgn, 0, RGN_COPY);
		OffsetRgn(hBaseRgn, -1, -1);
		CombineRgn(hBaseRgn, hRgn, hBaseRgn, RGN_DIFF);
		hBrush = CreateSolidBrush(rbOuter);
		FillRgn(hDC, hBaseRgn, hBrush);
		DeleteObject(hBrush);
		break;
	default:
		CombineRgn(hBaseRgn, hRgn, 0, RGN_COPY);
		OffsetRgn(hBaseRgn, 1, 1);
		CombineRgn(hBaseRgn, hRgn, hBaseRgn, RGN_DIFF);
		hBrush = CreateSolidBrush(ltInner);
		FillRgn(hDC, hBaseRgn, hBrush);
		DeleteObject(hBrush);

		CombineRgn(hBaseRgn, hRgn, 0, RGN_COPY);
		OffsetRgn(hBaseRgn, -1, -1);
		CombineRgn(hBaseRgn, hRgn, hBaseRgn, RGN_DIFF);
		hBrush = CreateSolidBrush(rbOuter);
		FillRgn(hDC, hBaseRgn, hBrush);
		DeleteObject(hBrush);
		break;
	}

	DeleteObject(hBaseRgn);
}

void CUniButton::DrawButton(CDC * pDC, CRect * pRect, UINT state)
{
	CDC * pMemDC = new CDC;
	pMemDC -> CreateCompatibleDC(pDC);
	CBitmap * pOldBitmap;

	HRGN hRgn = CreateRectRgn(0, 0, 0, 0);
	GetWindowRgn(hRgn);

	if (state & ODS_DISABLED)
		pOldBitmap = pMemDC -> SelectObject(m_pDisabled);
	else
	{
		if (state & ODS_SELECTED)
			pOldBitmap = pMemDC -> SelectObject(m_pSelected);
		else
		{
			if (m_bHover)
				pOldBitmap = pMemDC -> SelectObject(m_pHover);
			else 
				pOldBitmap = pMemDC -> SelectObject(m_pNormal);
		}	
	}

	::SelectClipRgn(pDC -> GetSafeHdc(), hRgn);
	pDC -> BitBlt(0, 0, pRect -> Width(), pRect -> Height(), pMemDC, 0, 0, SRCCOPY);
	::SelectClipRgn(pDC -> GetSafeHdc(), NULL);

	DeleteObject(hRgn);
	pMemDC -> SelectObject(pOldBitmap);
	delete pMemDC;
}
