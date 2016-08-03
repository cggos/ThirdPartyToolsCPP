#include "stdafx.h"
#include "GenericMFC.h"
#include "GenericMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDS_MAILADDR	_T("mailto:davide_calabro@yahoo.com")
#define IDS_WEBADDR		_T("http://www.softechsoftware.it")

CGenericMFCDlg::CGenericMFCDlg(CWnd* pParent /*=NULL*/)
	: CBkDialogST(CGenericMFCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGenericMFCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGenericMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CBkDialogST::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGenericMFCDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

	DDX_Control(pDX, IDC_LISTPAGES, m_Pages);
	DDX_Control(pDX, IDCANCEL, m_btnExit);

	DDX_Control(pDX, IDC_EMAILLINK, m_EMailLink);
	DDX_Control(pDX, IDC_HOMEPAGELINK, m_HomePageLink);
}

BEGIN_MESSAGE_MAP(CGenericMFCDlg, CBkDialogST)
	//{{AFX_MSG_MAP(CGenericMFCDlg)
	//}}AFX_MSG_MAP

	ON_MESSAGE(WM_USER + 150, On_PageActivationCallback)
END_MESSAGE_MAP()

BOOL CGenericMFCDlg::OnInitDialog()
{
	CBkDialogST::OnInitDialog();

//	SetBitmap(IDB_BACKGROUND);

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	// Button exit
	m_btnExit.SetThemeHelper(&m_Theme);
	m_btnExit.SetIcon(IDI_NO3, (int)BTNST_AUTO_GRAY);
	m_btnExit.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_btnExit.SetTooltipText(_T("Close the application"));
#ifdef	BTNST_USE_SOUND
	m_btnExit.SetSound(MAKEINTRESOURCE(IDR_WAVSTART), ::GetModuleHandle(NULL), TRUE, FALSE);
#endif
	// Set HyperLink for E-Mail
	m_EMailLink.SetURL(IDS_MAILADDR);
	m_EMailLink.SetUnderline(CHyperLink::ulAlways);

	// Set HyperLink for Home Page
	m_HomePageLink.SetURL(IDS_WEBADDR);
	m_HomePageLink.SetUnderline(CHyperLink::ulAlways);
	
	BOOL bRetValue = CreatePages();
	if (bRetValue == FALSE) MessageBox(_T("Failed creating pages!"));

	// Activate first page
	m_Pages.ActivatePage(0);
	m_Pages.SetItemState(0, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);

	return TRUE;
} // End of OnInitDialog

BOOL CGenericMFCDlg::CreatePages()
{
	DWORD	dwRetValue = 0;
	
	// Create image list
	BOOL bRetValue = m_ImageList.Create(32, 32, ILC_COLOR32 | ILC_MASK, 25, 1);
	if (bRetValue == FALSE)	return FALSE;

	HICON hIcon = ::LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_PAGE01));
	m_ImageList.Add(hIcon);
	hIcon = ::LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_PAGE02));
	m_ImageList.Add(hIcon);
	hIcon = ::LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_PAGE03));
	m_ImageList.Add(hIcon);
	hIcon = ::LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_PAGE04));
	m_ImageList.Add(hIcon);
	hIcon = ::LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	m_ImageList.Add(hIcon);
	m_Pages.SetImageList(&m_ImageList, LVSIL_NORMAL);

	CRect rc;
	m_Pages.GetClientRect(rc);
	
	// Set new icon spacing
	m_Pages.SetIconSpacing(rc.Width(), 12);

	// Change colors
	m_Pages.SetTextColor(RGB(255,255,255));
	m_Pages.SetTextBkColor(RGB(128,128,128));
	m_Pages.SetBkColor(RGB(128,128,128));	

	// Insert column
	m_Pages.InsertColumn(0, _T("OutlookBar"));

	dwRetValue = m_Pages.CreateFromStatic(IDC_STCPLACEHOLDER, this);
	if (dwRetValue != PAGEMANAGERST_OK)	return FALSE;

	m_Pages.SetPageActivationCallback(m_hWnd, WM_USER + 150);

	dwRetValue = m_Pages.AddPageToListCtrl(new CDlgBasic(), CDlgBasic::IDD, _T("Basic"), 0);
	if (dwRetValue != PAGEMANAGERST_OK)	return FALSE;
	//
	dwRetValue = m_Pages.AddPageToListCtrl(new CDlgAdvanced(), CDlgAdvanced::IDD, _T("Advanced"), 1);
	if (dwRetValue != PAGEMANAGERST_OK)	return FALSE;
	//
	dwRetValue = m_Pages.AddPageToListCtrl(new CDlgTransparent(), CDlgTransparent::IDD, _T("Transparent"), 2);
	if (dwRetValue != PAGEMANAGERST_OK)	return FALSE;
	//
	dwRetValue = m_Pages.AddPageToListCtrl(new CDlgShadeButtonST(), CDlgShadeButtonST::IDD, _T("Shaded"), 3);
	if (dwRetValue != PAGEMANAGERST_OK)	return FALSE;
	//
	dwRetValue = m_Pages.AddPageToListCtrl(new CDlgAbout(), CDlgAbout::IDD, _T("About"), 4);
	if (dwRetValue != PAGEMANAGERST_OK)	return FALSE;
	//

	return TRUE;
} // End of CreatePages

LRESULT CGenericMFCDlg::On_PageActivationCallback(WPARAM wParam, LPARAM lParam)
{
	if (lParam)
	{
		CString	sPageTitle;

		m_Pages.GetPageTitle((DWORD)wParam, sPageTitle);
		sPageTitle += _T(" - SoftechSoftware");
		SetWindowText(sPageTitle);
	} // if

	return 0;
} // End of On_PageActivationCallback

void CGenericMFCDlg::OnPostEraseBkgnd(CDC* pDC)
{
//	m_Pages.SendMessageToPage(2, WM_USER + 100, (WPARAM)pDC);
} // End of OnPostEraseBkgnd
