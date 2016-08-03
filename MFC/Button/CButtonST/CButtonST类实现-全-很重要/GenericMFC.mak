# Microsoft Developer Studio Generated NMAKE File, Based on GenericMFC.dsp
!IF "$(CFG)" == ""
CFG=GenericMFC - Win32 Debug Unicode
!MESSAGE No configuration specified. Defaulting to GenericMFC - Win32 Debug Unicode.
!ENDIF 

!IF "$(CFG)" != "GenericMFC - Win32 Release" && "$(CFG)" != "GenericMFC - Win32 Debug" && "$(CFG)" != "GenericMFC - Win32 Debug Unicode" && "$(CFG)" != "GenericMFC - Win32 Release Unicode"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GenericMFC.mak" CFG="GenericMFC - Win32 Debug Unicode"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GenericMFC - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GenericMFC - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "GenericMFC - Win32 Debug Unicode" (based on "Win32 (x86) Application")
!MESSAGE "GenericMFC - Win32 Release Unicode" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GenericMFC - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : ".\Bin\CButtonST_Demo.exe"


CLEAN :
	-@erase "$(INTDIR)\DlgAbout.obj"
	-@erase "$(INTDIR)\DlgAdvanced.obj"
	-@erase "$(INTDIR)\DlgBasic.obj"
	-@erase "$(INTDIR)\DlgShadeButtonST.obj"
	-@erase "$(INTDIR)\DlgTransparent.obj"
	-@erase "$(INTDIR)\GenericMFC.obj"
	-@erase "$(INTDIR)\GenericMFC.pch"
	-@erase "$(INTDIR)\GenericMFC.res"
	-@erase "$(INTDIR)\GenericMFCDlg.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\PageManagerEx1ST.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase ".\Bin\CButtonST_Demo.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\GenericMFC.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\GenericMFC.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GenericMFC.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\CButtonST_Demo.pdb" /machine:I386 /out:"Bin/CButtonST_Demo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DlgAbout.obj" \
	"$(INTDIR)\DlgAdvanced.obj" \
	"$(INTDIR)\DlgBasic.obj" \
	"$(INTDIR)\DlgShadeButtonST.obj" \
	"$(INTDIR)\DlgTransparent.obj" \
	"$(INTDIR)\GenericMFC.obj" \
	"$(INTDIR)\GenericMFCDlg.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\PageManagerEx1ST.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\GenericMFC.res"

".\Bin\CButtonST_Demo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "GenericMFC - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : ".\Bin\CButtonST_Demo.exe"


CLEAN :
	-@erase "$(INTDIR)\DlgAbout.obj"
	-@erase "$(INTDIR)\DlgAdvanced.obj"
	-@erase "$(INTDIR)\DlgBasic.obj"
	-@erase "$(INTDIR)\DlgShadeButtonST.obj"
	-@erase "$(INTDIR)\DlgTransparent.obj"
	-@erase "$(INTDIR)\GenericMFC.obj"
	-@erase "$(INTDIR)\GenericMFC.pch"
	-@erase "$(INTDIR)\GenericMFC.res"
	-@erase "$(INTDIR)\GenericMFCDlg.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\PageManagerEx1ST.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CButtonST_Demo.pdb"
	-@erase ".\Bin\CButtonST_Demo.exe"
	-@erase ".\Bin\CButtonST_Demo.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\GenericMFC.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\GenericMFC.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GenericMFC.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\CButtonST_Demo.pdb" /debug /machine:I386 /out:"Bin/CButtonST_Demo.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\DlgAbout.obj" \
	"$(INTDIR)\DlgAdvanced.obj" \
	"$(INTDIR)\DlgBasic.obj" \
	"$(INTDIR)\DlgShadeButtonST.obj" \
	"$(INTDIR)\DlgTransparent.obj" \
	"$(INTDIR)\GenericMFC.obj" \
	"$(INTDIR)\GenericMFCDlg.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\PageManagerEx1ST.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\GenericMFC.res"

".\Bin\CButtonST_Demo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "GenericMFC - Win32 Debug Unicode"

OUTDIR=.\DebugUnicode
INTDIR=.\DebugUnicode

ALL : ".\Bin\CButtonST_Demo.exe"


CLEAN :
	-@erase "$(INTDIR)\DlgAbout.obj"
	-@erase "$(INTDIR)\DlgAdvanced.obj"
	-@erase "$(INTDIR)\DlgBasic.obj"
	-@erase "$(INTDIR)\DlgShadeButtonST.obj"
	-@erase "$(INTDIR)\DlgTransparent.obj"
	-@erase "$(INTDIR)\GenericMFC.obj"
	-@erase "$(INTDIR)\GenericMFC.pch"
	-@erase "$(INTDIR)\GenericMFC.res"
	-@erase "$(INTDIR)\GenericMFCDlg.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\PageManagerEx1ST.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CButtonST_Demo.pdb"
	-@erase ".\Bin\CButtonST_Demo.exe"
	-@erase ".\Bin\CButtonST_Demo.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\GenericMFC.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\GenericMFC.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GenericMFC.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\CButtonST_Demo.pdb" /debug /machine:I386 /out:"Bin/CButtonST_Demo.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\DlgAbout.obj" \
	"$(INTDIR)\DlgAdvanced.obj" \
	"$(INTDIR)\DlgBasic.obj" \
	"$(INTDIR)\DlgShadeButtonST.obj" \
	"$(INTDIR)\DlgTransparent.obj" \
	"$(INTDIR)\GenericMFC.obj" \
	"$(INTDIR)\GenericMFCDlg.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\PageManagerEx1ST.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\GenericMFC.res"

".\Bin\CButtonST_Demo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "GenericMFC - Win32 Release Unicode"

OUTDIR=.\ReleaseUnicode
INTDIR=.\ReleaseUnicode

ALL : ".\Bin\CButtonST_Demo.exe"


CLEAN :
	-@erase "$(INTDIR)\DlgAbout.obj"
	-@erase "$(INTDIR)\DlgAdvanced.obj"
	-@erase "$(INTDIR)\DlgBasic.obj"
	-@erase "$(INTDIR)\DlgShadeButtonST.obj"
	-@erase "$(INTDIR)\DlgTransparent.obj"
	-@erase "$(INTDIR)\GenericMFC.obj"
	-@erase "$(INTDIR)\GenericMFC.pch"
	-@erase "$(INTDIR)\GenericMFC.res"
	-@erase "$(INTDIR)\GenericMFCDlg.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\PageManagerEx1ST.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase ".\Bin\CButtonST_Demo.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\GenericMFC.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\GenericMFC.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GenericMFC.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\CButtonST_Demo.pdb" /machine:I386 /out:"Bin/CButtonST_Demo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DlgAbout.obj" \
	"$(INTDIR)\DlgAdvanced.obj" \
	"$(INTDIR)\DlgBasic.obj" \
	"$(INTDIR)\DlgShadeButtonST.obj" \
	"$(INTDIR)\DlgTransparent.obj" \
	"$(INTDIR)\GenericMFC.obj" \
	"$(INTDIR)\GenericMFCDlg.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\PageManagerEx1ST.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\GenericMFC.res"

".\Bin\CButtonST_Demo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("GenericMFC.dep")
!INCLUDE "GenericMFC.dep"
!ELSE 
!MESSAGE Warning: cannot find "GenericMFC.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "GenericMFC - Win32 Release" || "$(CFG)" == "GenericMFC - Win32 Debug" || "$(CFG)" == "GenericMFC - Win32 Debug Unicode" || "$(CFG)" == "GenericMFC - Win32 Release Unicode"
SOURCE=.\DlgAbout.cpp

"$(INTDIR)\DlgAbout.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GenericMFC.pch"


SOURCE=.\DlgAdvanced.cpp

"$(INTDIR)\DlgAdvanced.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GenericMFC.pch"


SOURCE=.\DlgBasic.cpp

"$(INTDIR)\DlgBasic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GenericMFC.pch"


SOURCE=.\DlgShadeButtonST.cpp

"$(INTDIR)\DlgShadeButtonST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GenericMFC.pch"


SOURCE=.\DlgTransparent.cpp

"$(INTDIR)\DlgTransparent.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GenericMFC.pch"


SOURCE=.\GenericMFC.cpp

"$(INTDIR)\GenericMFC.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GenericMFC.pch"


SOURCE=.\GenericMFC.rc

"$(INTDIR)\GenericMFC.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\GenericMFCDlg.cpp

"$(INTDIR)\GenericMFCDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GenericMFC.pch"


SOURCE=.\HyperLink.cpp

"$(INTDIR)\HyperLink.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GenericMFC.pch"


SOURCE=.\PageManagerEx1ST.cpp

"$(INTDIR)\PageManagerEx1ST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GenericMFC.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "GenericMFC - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\GenericMFC.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\GenericMFC.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GenericMFC - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\GenericMFC.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\GenericMFC.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GenericMFC - Win32 Debug Unicode"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\GenericMFC.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\GenericMFC.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GenericMFC - Win32 Release Unicode"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\GenericMFC.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\GenericMFC.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

