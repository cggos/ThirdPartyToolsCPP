// ShowAllProcessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShowAllProcess.h"
#include "ShowAllProcessDlg.h"
#include "TLHELP32.H"//一定要加如这个头文件
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowAllProcessDlg dialog

CShowAllProcessDlg::CShowAllProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowAllProcessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowAllProcessDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShowAllProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowAllProcessDlg)
	DDX_Control(pDX, IDC_LIST_SHOW, m_showlist);
	DDX_Control(pDX, IDOK, m_show);
	DDX_Control(pDX, IDCANCEL, m_exit);
	DDX_Control(pDX, IDC_STOP, m_stop);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShowAllProcessDlg, CDialog)
	//{{AFX_MSG_MAP(CShowAllProcessDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, OnGetProcess)
	ON_BN_CLICKED(IDC_STOP, OnStopProcess)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowAllProcessDlg message handlers

BOOL CShowAllProcessDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_stop.SetIcon(IDI_ICON_STOP,25,25);
	m_exit.SetIcon(IDI_ICON_EXIT,25,25);
	m_show.SetIcon(IDI_ICON_SHOW,25,25);

	m_showlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_showlist.InsertColumn(0,"进程映像名称");
	m_showlist.InsertColumn(1,"进程开启的线程数");
	m_showlist.InsertColumn(2,"PID");
	m_showlist.InsertColumn(3,"优先级");
	for(int i=0;i<4;i++)
		m_showlist.SetColumnWidth(i,120);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShowAllProcessDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShowAllProcessDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShowAllProcessDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShowAllProcessDlg::OnGetProcess() 
{
	// TODO: Add your control notification handler code here
	HANDLE Snapshot;
	Snapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	//获得某一时刻系统的进程、堆（heap）、模块（module）或线程的快照信息
	PROCESSENTRY32 processListStr;
	processListStr.dwSize=sizeof(PROCESSENTRY32);
	BOOL return_value;
	return_value=Process32First(Snapshot,&processListStr);
	//获得系统进程链表中第一个进程的信息
	m_showlist.DeleteAllItems();
	int i=0;//item index
	while(return_value)
	{
	m_showlist.InsertItem(i,processListStr.szExeFile,0);
	CString s;
	s.Format("%d",processListStr.cntThreads);
	m_showlist.SetItemText(i,1,s);
	s.Format("%d",processListStr.th32ParentProcessID);
	m_showlist.SetItemText(i,2,s);
	s.Format("%d",processListStr.pcPriClassBase);
	m_showlist.SetItemText(i,3,s);
	
	int memory=processListStr.cntThreads;
	m_ProcessIndex[i]=processListStr.th32ProcessID;//save ID into array to teminate 
	return_value=Process32Next(Snapshot,&processListStr);
	//获得系统进程链表中下一个进程的信息
	i++;
	}

}

void CShowAllProcessDlg::OnStopProcess() 
{
	// TODO: Add your control notification handler code here
	POSITION pos = m_showlist.GetFirstSelectedItemPosition();
	int currentSelect=m_showlist.GetNextSelectedItem(pos);
	if(currentSelect>0)
	{	
		//选择某项
		CString FileBuffer;//获得进程的可执行文件的文件名
		FileBuffer=CString(TEXT("确实要终止进程")+m_showlist.GetItemText(currentSelect,0)+TEXT("?"));
		if(AfxMessageBox(FileBuffer,MB_OKCANCEL,0)==IDOK)
		{//先获得该进程句柄，通过进程标识
			HANDLE ProcessHandle;
			ProcessHandle=OpenProcess(PROCESS_ALL_ACCESS,FALSE,m_ProcessIndex[currentSelect]);
			//利用数组ID指定的获得存在的一个进程的句柄
			if(ProcessHandle)
			{TerminateProcess(ProcessHandle,0);
			AfxMessageBox("指定进程已终止！");
				OnGetProcess();//刷新显示
			}
			else
			{AfxMessageBox("系统不允许终止指定进程！");}
		}
	}
	else
	{AfxMessageBox("请先选择一个需要终止的进程！",MB_OK);
	}

}


