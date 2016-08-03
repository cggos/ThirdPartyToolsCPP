#include "stdafx.h"
#include "PageManagerEx1ST.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CPageManagerEx1ST::CPageManagerEx1ST()
{
}

CPageManagerEx1ST::~CPageManagerEx1ST()
{
}

BEGIN_MESSAGE_MAP(CPageManagerEx1ST, CListCtrl)
	//{{AFX_MSG_MAP(CPageManagerEx1ST)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnItemChanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CPageManagerEx1ST::OnItemChanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	if (pNMListView->uNewState == (LVIS_FOCUSED | LVIS_SELECTED))
	{
		ActivatePage(pNMListView->iItem);
	} // if
	
	*pResult = 0;
} // End of OnItemChanged

DWORD CPageManagerEx1ST::AddPageToListCtrl(CWnd* pPage, UINT nID, LPCTSTR lpszTitle, int nImage, DWORD dwPageData)
{
	DWORD	dwRetValue = PAGEMANAGERST_OK;

	// Add page to page manager
	dwRetValue = AddPage(pPage, nID, lpszTitle, dwPageData);
	if (dwRetValue == PAGEMANAGERST_OK)
	{
		InsertItem(LVIF_IMAGE | LVIF_PARAM | LVIF_TEXT, GetItemCount(), lpszTitle, 0, 0, nImage, dwPageData);
	} // if

	return dwRetValue;
} // End of AddPageToListCtrl
