#include "ExceptionOpt.h"

CExceptionOpt::CExceptionOpt(void)
{
}

CExceptionOpt::~CExceptionOpt(void)
{
}

void CExceptionOpt::ShowErrorMsg(LPTSTR lpszFunction) 
{ 
	// Retrieve the system error message for the last-error code

	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError(); 

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0, NULL );

	// Display the error message and exit the process

	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, 
		(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR)); 
	StringCchPrintf((LPTSTR)lpDisplayBuf, 
		LocalSize(lpDisplayBuf) / sizeof(TCHAR),
		TEXT("%s failed with error %d: %s"), 
		lpszFunction, dw, lpMsgBuf); 
	MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Message of GetLastError"), MB_OK); 

	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
	//ExitProcess(dw); 
}

//生产DUMP文件  
int CExceptionOpt::GenerateMiniDump(HANDLE hFile, PEXCEPTION_POINTERS pExceptionPointers, PWCHAR pwAppName)  
{  
	BOOL bOwnDumpFile = FALSE;  
	HANDLE hDumpFile = hFile;  
	MINIDUMP_EXCEPTION_INFORMATION ExpParam;  

	typedef BOOL(WINAPI * MiniDumpWriteDumpT)(  
		HANDLE,  
		DWORD,  
		HANDLE,  
		MINIDUMP_TYPE,  
		PMINIDUMP_EXCEPTION_INFORMATION,  
		PMINIDUMP_USER_STREAM_INFORMATION,  
		PMINIDUMP_CALLBACK_INFORMATION  
		);  

	MiniDumpWriteDumpT pfnMiniDumpWriteDump = NULL;  
	HMODULE hDbgHelp = LoadLibrary(L"DbgHelp.dll");  
	if (hDbgHelp)  
		pfnMiniDumpWriteDump = (MiniDumpWriteDumpT)GetProcAddress(hDbgHelp, "MiniDumpWriteDump");  

	if (pfnMiniDumpWriteDump)  
	{  
		if (hDumpFile == NULL || hDumpFile == INVALID_HANDLE_VALUE)  
		{  
			TCHAR szPath[MAX_PATH] = { 0 };  
			TCHAR szFileName[MAX_PATH] = { 0 };  
			TCHAR* szAppName = pwAppName;  
			TCHAR* szVersion = L"v1.0";  
			TCHAR dwBufferSize = MAX_PATH;  
			SYSTEMTIME stLocalTime;  

			GetLocalTime(&stLocalTime);  
			GetTempPath(dwBufferSize, szPath);  

			StringCchPrintf(szFileName, MAX_PATH, L"%s%s", szPath, szAppName);  
			CreateDirectory(szFileName, NULL);  

			StringCchPrintf(szFileName, MAX_PATH, L"%s%s//%s-%04d%02d%02d-%02d%02d%02d-%ld-%ld.dmp",  
				szPath, szAppName, szVersion,  
				stLocalTime.wYear, stLocalTime.wMonth, stLocalTime.wDay,  
				stLocalTime.wHour, stLocalTime.wMinute, stLocalTime.wSecond,  
				GetCurrentProcessId(), GetCurrentThreadId());  
			hDumpFile = CreateFile(szFileName, GENERIC_READ | GENERIC_WRITE,  
				FILE_SHARE_WRITE | FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);  

			bOwnDumpFile = TRUE;  
			OutputDebugString(szFileName);  
		}  

		if (hDumpFile != INVALID_HANDLE_VALUE)  
		{  
			ExpParam.ThreadId = GetCurrentThreadId();  
			ExpParam.ExceptionPointers = pExceptionPointers;  
			ExpParam.ClientPointers = FALSE;  

			pfnMiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),  
				hDumpFile, MiniDumpWithDataSegs, (pExceptionPointers ? &ExpParam : NULL), NULL, NULL);  

			if (bOwnDumpFile)  
				CloseHandle(hDumpFile);  
		}  
	}  

	if (hDbgHelp != NULL)  
		FreeLibrary(hDbgHelp);  

	return EXCEPTION_EXECUTE_HANDLER;  
}  

LONG WINAPI CExceptionOpt::ExceptionFilter(LPEXCEPTION_POINTERS lpExceptionInfo)  
{  
	if (IsDebuggerPresent())  
	{  
		return EXCEPTION_CONTINUE_SEARCH;  
	}  

	return GenerateMiniDump(NULL, lpExceptionInfo, L"test");  
} 