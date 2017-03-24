//http://stackoverflow.com/questions/1387064/how-to-get-the-error-message-from-the-error-code-returned-by-getlasterror
//https://msdn.microsoft.com/en-us/library/ms680582(VS.85).aspx

#pragma once

#include <windows.h>
#include <strsafe.h>

#include <DbgHelp.h>

class CExceptionOpt
{
public:
	CExceptionOpt(void);
	~CExceptionOpt(void);

public:
	static void ShowErrorMsg(LPTSTR lpszFunction);

public:
	static int GenerateMiniDump(HANDLE hFile, PEXCEPTION_POINTERS pExceptionPointers, PWCHAR pwAppName);
	static LONG WINAPI ExceptionFilter(LPEXCEPTION_POINTERS lpExceptionInfo);
};
