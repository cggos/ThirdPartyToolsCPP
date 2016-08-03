#ifndef _PAGEMANAGEREX1ST_H
#define _PAGEMANAGEREX1ST_H

#include "PageManagerST.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPageManagerEx1ST : public CListCtrl, public CPageManagerST
{
// Construction
public:
	CPageManagerEx1ST();
	virtual ~CPageManagerEx1ST();

	DWORD AddPageToListCtrl(CWnd* pPage, UINT nID, LPCTSTR lpszTitle, int nImage = -1, DWORD dwPageData = 0);

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPageManagerEx1ST)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CPageManagerEx1ST)
	afx_msg void OnItemChanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
