; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgAdvanced
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "genericmfc.h"
LastPage=0

ClassCount=15
Class1=CBkDialogST
Class2=CButtonST
Class3=CDlgAbout
Class4=CDlgAdvanced
Class5=CDlgBasic
Class6=CDlgPage01
Class7=CDlgPage02
Class8=CDlgShadeButtonST
Class9=CDlgTransparent
Class10=CGenericMFCApp
Class11=CGenericMFCDlg
Class12=CHyperLink
Class13=CListBoxST
Class14=CPageManagerEx1ST
Class15=CTransparentStaticST

ResourceCount=10
Resource1=IDD_GENERICMFC_DIALOG (Neutral)
Resource2=IDD_PAGE01 (Neutral)
Resource3=IDD_TRANSPARENT (Neutral)
Resource4=IDD_SHADED (Neutral)
Resource5=IDD_ABOUT (Neutral)
Resource6=IDD_PAGE02 (Neutral)
Resource7=IDR_MENU (Neutral)
Resource8=IDD_ADVANCED (Neutral)
Resource9=IDD_BASIC (Neutral)
Resource10=IDR_TOOLBAR (Neutral)

[CLS:CBkDialogST]
Type=0
BaseClass=CDialog
HeaderFile=BkDialogST.h
ImplementationFile=BkDialogST.cpp
LastObject=CBkDialogST

[CLS:CButtonST]
Type=0
BaseClass=CButton
HeaderFile=BtnST.h
ImplementationFile=BtnST.cpp

[CLS:CDlgAbout]
Type=0
BaseClass=CDialog
HeaderFile=DlgAbout.h
ImplementationFile=DlgAbout.cpp

[CLS:CDlgAdvanced]
Type=0
BaseClass=CDialog
HeaderFile=DlgAdvanced.h
ImplementationFile=DlgAdvanced.cpp
Filter=D
VirtualFilter=dWC
LastObject=CDlgAdvanced

[CLS:CDlgBasic]
Type=0
BaseClass=CDialog
HeaderFile=DlgBasic.h
ImplementationFile=DlgBasic.cpp

[CLS:CDlgPage01]
Type=0
BaseClass=CDialog
HeaderFile=DlgPage01.h
ImplementationFile=DlgPage01.cpp

[CLS:CDlgPage02]
Type=0
BaseClass=CDialog
HeaderFile=DlgPage02.h
ImplementationFile=DlgPage02.cpp

[CLS:CDlgShadeButtonST]
Type=0
BaseClass=CDialog
HeaderFile=DlgShadeButtonST.h
ImplementationFile=DlgShadeButtonST.cpp

[CLS:CDlgTransparent]
Type=0
BaseClass=CBkDialogST
HeaderFile=DlgTransparent.h
ImplementationFile=DlgTransparent.cpp

[CLS:CGenericMFCApp]
Type=0
BaseClass=CWinApp
HeaderFile=GenericMFC.h
ImplementationFile=GenericMFC.cpp

[CLS:CGenericMFCDlg]
Type=0
BaseClass=CBkDialogST
HeaderFile=GenericMFCDlg.h
ImplementationFile=GenericMFCDlg.cpp

[CLS:CHyperLink]
Type=0
BaseClass=CStatic
HeaderFile=HyperLink.h
ImplementationFile=HyperLink.cpp

[CLS:CListBoxST]
Type=0
BaseClass=CListBox
HeaderFile=ListBoxST.h
ImplementationFile=ListBoxST.cpp

[CLS:CPageManagerEx1ST]
Type=0
BaseClass=CListCtrl
HeaderFile=PageManagerEx1ST.h
ImplementationFile=PageManagerEx1ST.cpp

[CLS:CTransparentStaticST]
Type=0
BaseClass=CStatic
HeaderFile=TransparentStaticST.h
ImplementationFile=TransparentStaticST.cpp

[DLG:IDD_ABOUT]
Type=1
Class=CDlgAbout

[DLG:IDD_ADVANCED]
Type=1
Class=CDlgAdvanced

[DLG:IDD_BASIC]
Type=1
Class=CDlgBasic

[DLG:IDD_SHADED]
Type=1
Class=CDlgShadeButtonST

[DLG:IDD_TRANSPARENT]
Type=1
Class=CDlgTransparent

[DLG:IDD_GENERICMFC_DIALOG]
Type=1
Class=CGenericMFCDlg

[DLG:IDD_ADVANCED (Neutral)]
Type=1
Class=CDlgAdvanced
ControlCount=18
Control1=IDC_STATIC,button,1342177287
Control2=IDC_BTNDERIVED,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_BTNHYPERLINK,button,1342242816
Control5=IDC_STATIC,button,1342177287
Control6=IDC_BTNCURSOR,button,1342242816
Control7=IDC_STATIC,button,1342177287
Control8=IDC_BTNBITMAP,button,1342242816
Control9=IDC_STATIC,button,1342177287
Control10=IDC_RADIO1,button,1342308361
Control11=IDC_RADIO2,button,1342177289
Control12=IDC_RADIO3,button,1342177289
Control13=IDC_STATIC,button,1342177287
Control14=IDC_BTNFOCUSRECT,button,1342242816
Control15=IDC_STATIC,button,1342177287
Control16=IDC_CHECK,button,1342242819
Control17=IDC_STATIC,button,1342177287
Control18=IDC_BTNAUTOFIRE,button,1342242816

[DLG:IDD_GENERICMFC_DIALOG (Neutral)]
Type=1
Class=?
ControlCount=5
Control1=IDC_LISTPAGES,SysListView32,1342242828
Control2=IDC_STCPLACEHOLDER,static,1350696960
Control3=IDCANCEL,button,1342242817
Control4=IDC_EMAILLINK,static,1342308352
Control5=IDC_HOMEPAGELINK,static,1342308352

[DLG:IDD_PAGE01 (Neutral)]
Type=1
Class=?
ControlCount=1
Control1=IDC_LBXST,listbox,1352728929

[DLG:IDD_PAGE02 (Neutral)]
Type=1
Class=?
ControlCount=5
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_COMBO1,combobox,1344340226
Control3=IDC_MONTHCALENDAR1,SysMonthCal32,1342242820
Control4=IDC_LINE1,static,1342308352
Control5=IDC_LINE2,static,1342308352

[DLG:IDD_ABOUT (Neutral)]
Type=1
Class=?
ControlCount=7
Control1=IDC_BTNSTLOGO,button,1476460544
Control2=IDC_VERSION,static,1342308481
Control3=IDC_STATIC,static,1342308353
Control4=IDC_BTNFACE,button,1476460544
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342177283
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_BASIC (Neutral)]
Type=1
Class=?
ControlCount=13
Control1=IDC_BTNSTANDARD,button,1342242816
Control2=IDC_BTNHALLOWEEN,button,1342242816
Control3=IDC_BTNDISABLED,button,1342242816
Control4=IDC_BTNLAMP,button,1342242816
Control5=IDC_BTNKEYMANAGER,button,1342242816
Control6=IDC_BTNZIP,button,1342242816
Control7=IDC_BTNSEARCH,button,1342242816
Control8=IDC_BTNCDROM,button,1342242816
Control9=IDC_BTNJPEG,button,1342242816
Control10=IDC_BTNBACK,button,1342242816
Control11=IDC_BTNNEXT,button,1342242816
Control12=IDC_BTNTOOLTIP,button,1342242816
Control13=IDC_STATIC,button,1342177287

[DLG:IDD_TRANSPARENT (Neutral)]
Type=1
Class=?
ControlCount=11
Control1=IDC_BTNLOGOFF,button,1342242816
Control2=IDC_BTNOPEN,button,1342242816
Control3=IDC_BTNSEARCH,button,1342242816
Control4=IDC_BTNEXPLORER,button,1342242816
Control5=IDC_BTNHELP,button,1342242816
Control6=IDC_BTNABOUT,button,1342242816
Control7=IDC_BTNWORKGROUP,button,1342242816
Control8=IDC_BTNCANNIBAL,button,1342242816
Control9=IDC_CHECK,button,1342242819
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,button,1342177287

[DLG:IDD_SHADED (Neutral)]
Type=1
Class=?
ControlCount=9
Control1=IDC_BTNSHADE1,button,1342242816
Control2=IDC_BTNSHADE4,button,1342242816
Control3=IDC_BTNSHADE7,button,1342242816
Control4=IDC_BTNSHADE2,button,1342242816
Control5=IDC_BTNSHADE5,button,1342242816
Control6=IDC_BTNSHADE8,button,1342242816
Control7=IDC_BTNSHADE3,button,1342242816
Control8=IDC_BTNSHADE6,button,1342242816
Control9=IDC_BTNSHADE9,button,1342242816

[MNU:IDR_MENU (Neutral)]
Type=1
Class=?
Command1=IDM_ITEM1
Command2=IDM_ITEM2
Command3=IDM_ITEM3
CommandCount=3

[TB:IDR_TOOLBAR (Neutral)]
Type=1
Class=?
Command1=IDM_ITEM1
Command2=IDM_ITEM2
CommandCount=2

