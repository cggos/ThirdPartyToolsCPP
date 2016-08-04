// CPngButton.cpp : implementation file
//
#include "StdAfx.h"
#include "PngButton.h"

// CPngButton
using namespace Gdiplus;
IMPLEMENT_DYNAMIC(CPngButton, CButton)
CPngButton::CPngButton()
{
	m_bText             = FALSE;
	m_bDisable			= FALSE;
	m_bCursorOnButton	= FALSE;
	m_bPress			= FALSE;
	m_bClick            = FALSE;
	m_strText           = "";
	m_nImageType        = 0;
	m_pImage            = NULL;
	m_pGraphics         = NULL;
	nWidth            = 0;
	nHeight           = 0;
}

CPngButton::~CPngButton()
{
	if(m_pImage != NULL)
	{
		delete m_pImage;
		m_pImage = NULL;
	}
	if(m_pGraphics != NULL)
	{
		delete m_pGraphics;
		m_pGraphics = NULL;
	}
}

BEGIN_MESSAGE_MAP(CPngButton, CButton)
    //{{AFX_MSG_MAP(CPngButton)
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MOUSEHOVER,OnMouseHover)
	ON_MESSAGE(WM_MOUSELEAVE,OnMouseLeave)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_SETCURSOR()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



// CPngButton message handlers
void CPngButton::PreSubclassWindow() 
{
	ModifyStyle(0, BS_OWNERDRAW);
	CButton::PreSubclassWindow();
}

void CPngButton::SetText(CString strText,COLORREF color)
{
	m_bText   =  TRUE;
	m_strText = strText;
	m_color   = color;
}
void CPngButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct -> hDC);
	CRect rect = lpDrawItemStruct->rcItem;
	UINT state = lpDrawItemStruct->itemState;
	m_rcText   = rect;
	m_rcText.DeflateRect(1,1);

	if(m_pGraphics == NULL)
		return;
	if(m_pImage == NULL)
		return;

	if( m_bDisable == TRUE )    
	{
		if(m_nImageType == 0)
		    m_pGraphics->DrawImage(m_pImage,Rect(0,0,m_nSliceWidth,m_nHeight),
			BUTTON_DISABLE * m_nSliceWidth,0,m_nSliceWidth, m_nHeight,UnitPixel);
		else
			m_pGraphics->DrawImage(m_pImage,Rect(0,0,m_nWidth,m_nSliceHeight),0,
			BUTTON_DISABLE * m_nSliceHeight,m_nWidth, m_nSliceHeight,UnitPixel);
	}

	else
	{
		// click state
		if( lpDrawItemStruct -> itemState & ODS_SELECTED )
		{
			if(m_nImageType == 0)
				m_pGraphics->DrawImage(m_pImage,Rect( 0  ,0 , m_nSliceWidth , m_nHeight),
				BUTTON_CLICK * m_nSliceWidth , 0  , m_nSliceWidth , m_nHeight ,UnitPixel);
			else
				m_pGraphics->DrawImage(m_pImage,Rect(0,0,m_nWidth,m_nSliceHeight),0,
				BUTTON_CLICK * m_nSliceHeight,m_nWidth, m_nSliceHeight,UnitPixel);
		}
		// hover state
		else if ( m_bPress)
		{
	        if(m_nImageType == 0)		
			m_pGraphics->DrawImage(m_pImage, Rect( 0, 0, m_nSliceWidth, m_nHeight),
				BUTTON_HOVER * m_nSliceWidth,0, m_nSliceWidth, m_nHeight,UnitPixel);
			else
				m_pGraphics->DrawImage(m_pImage,Rect(0,0,m_nWidth,m_nSliceHeight),0,
				BUTTON_HOVER * m_nSliceHeight,m_nWidth, m_nSliceHeight,UnitPixel);
		}
		// enable state
		else
		{
			if(m_nImageType == 0)
			m_pGraphics->DrawImage(m_pImage,Rect( 0, 0,m_nSliceWidth,m_nHeight),
				BUTTON_ENABLE*m_nSliceWidth,0, m_nSliceWidth, m_nHeight,UnitPixel);
			else
				m_pGraphics->DrawImage(m_pImage,Rect(0,0,m_nWidth,m_nSliceHeight),0,
				BUTTON_ENABLE * m_nSliceHeight,m_nWidth, m_nSliceHeight,UnitPixel);
		}
	}
	if (m_bText == TRUE)
	{
		if (!m_strText.IsEmpty())
		{
			CSize Extent = pDC->GetTextExtent(m_strText);
			CPoint pt( rect.CenterPoint().x - Extent.cx/2, 
				rect.CenterPoint().y - Extent.cy/2 );
			if (state & ODS_SELECTED) 
				pt.Offset(1,1);
			int nMode = pDC->SetBkMode(TRANSPARENT);
			pDC->SetTextColor(m_color);
			if (state & ODS_DISABLED)
				pDC->DrawState(pt, Extent, m_strText, DSS_DISABLED, TRUE, 0, (HBRUSH)NULL);
			else
				//pDC->TextOut(pt.x, pt.y, m_strText);
				pDC->DrawText(m_strText, &CRect(pt.x,pt.y,pt.x+ Extent.cx,pt.y+ Extent.cy),DT_CENTER);
			pDC->SetBkMode(nMode);
		}
	}
}

void CPngButton::SetButtonImage(CString str,int nImageType)
{
	m_nImageType = nImageType;
	strImage = str;
	//	Image img(str);
	m_pImage = new Image(str);
	m_nWidth = m_pImage->GetWidth();
	m_nHeight = m_pImage->GetHeight();
	if(nImageType == 0)
	{
		m_nSliceWidth = m_nWidth/4;   //图片切成四分
		CWnd *pWnd = this -> GetParent();
		GetWindowRect( &m_rectButton );
		pWnd -> ScreenToClient(m_rectButton);
		m_rectButton.right	= m_rectButton.left + m_nSliceWidth;
		m_rectButton.bottom	= m_rectButton.top  + m_nHeight;
	}
	else
	{
		m_nSliceHeight = m_nHeight/4;   //图片切成四分
		CWnd *pWnd = this -> GetParent();
		GetWindowRect( &m_rectButton );
		pWnd -> ScreenToClient(m_rectButton);
		m_rectButton.right	= m_rectButton.left + m_nWidth;
		m_rectButton.bottom	= m_rectButton.top  + m_nSliceHeight;
	}
//	MoveWindow(m_rectButton);      //调整按钮大小以适应图片
	SetWindowPos(NULL,0,0,m_rectButton.Width(),m_rectButton.Height(),SWP_NOMOVE);
	nWidth = m_rectButton.Width();
	nHeight = m_rectButton.Height();
	m_pGraphics = new Graphics(GetWindowDC()->m_hDC);
}

void CPngButton::OnMouseMove(UINT nFlags, CPoint point)
{
	if( m_bCursorOnButton == FALSE )
	{
		TRACKMOUSEEVENT tme;
		ZeroMemory(&tme,sizeof(TRACKMOUSEEVENT));
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE|TME_HOVER;
		tme.dwHoverTime = 1;
		m_bCursorOnButton = _TrackMouseEvent(&tme);
	}
//	::SetCursor(AfxGetApp()->LoadStandardCursor(MAKEINTRESOURCE(32649)));
	CButton::OnMouseMove(nFlags, point);
}

LRESULT CPngButton::OnMouseLeave(WPARAM wparam, LPARAM lparam)
{
	m_bCursorOnButton	= FALSE;
	m_bPress	= FALSE;
	Invalidate();
	return 0L;
}

LRESULT CPngButton::OnMouseHover(WPARAM wparam, LPARAM lparam)
{
	m_bPress = TRUE;
	Invalidate();
	return 0L;
}


void CPngButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	Invalidate();
	CButton::OnLButtonDown(nFlags, point);
}

void CPngButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	Invalidate();
	CButton::OnLButtonUp(nFlags, point);
}

LRESULT CPngButton::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_LBUTTONDBLCLK)
	{
		message = WM_LBUTTONDOWN;
	}
	return CButton::DefWindowProc(message, wParam, lParam);//很重要,消除双击没反应
}

BOOL CPngButton::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

BOOL CPngButton::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	::SetCursor(AfxGetApp()->LoadStandardCursor(MAKEINTRESOURCE(32649)));
//	::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR_HAND));
	return TRUE;
}