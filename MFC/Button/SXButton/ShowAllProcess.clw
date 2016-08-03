; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShowAllProcessDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ShowAllProcess.h"

ClassCount=3
Class1=CShowAllProcessApp
Class2=CShowAllProcessDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SHOWALLPROCESS_DIALOG

[CLS:CShowAllProcessApp]
Type=0
HeaderFile=ShowAllProcess.h
ImplementationFile=ShowAllProcess.cpp
Filter=N

[CLS:CShowAllProcessDlg]
Type=0
HeaderFile=ShowAllProcessDlg.h
ImplementationFile=ShowAllProcessDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST_SHOW

[CLS:CAboutDlg]
Type=0
HeaderFile=ShowAllProcessDlg.h
ImplementationFile=ShowAllProcessDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SHOWALLPROCESS_DIALOG]
Type=1
Class=CShowAllProcessDlg
ControlCount=5
Control1=IDOK,button,1342242827
Control2=IDCANCEL,button,1342242827
Control3=IDC_STOP,button,1342242827
Control4=IDC_STATIC,button,1342177287
Control5=IDC_LIST_SHOW,SysListView32,1350631437

