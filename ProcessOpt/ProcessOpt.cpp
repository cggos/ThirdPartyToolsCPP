#include "ProcessOpt.h"


ProcessOpt::ProcessOpt(void)
{
}


ProcessOpt::~ProcessOpt(void)
{
}

bool ProcessOpt::EnumProcess()
{
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);  
	if (hProcessSnap == INVALID_HANDLE_VALUE) 
	{ 
		return false;
	}  

	PROCESSENTRY32 pe32;  
	pe32.dwSize = sizeof(PROCESSENTRY32);

	BOOL f0k = Process32First(hProcessSnap, &pe32);  
	for (; f0k; f0k = Process32Next(hProcessSnap, &pe32)) 
	{  
		wprintf(L"Pid: %d %s\n", pe32.th32ProcessID, pe32.szExeFile);  
	}  

	CloseHandle(hProcessSnap); 

	return true;
}

bool ProcessOpt::GetPIDbyName(TCHAR *ProcessName, DWORD &dwPID)
{
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(hProcessSnap, &pe32))
	{
		CloseHandle(hProcessSnap);
		return false;
	}

	BOOL bRet = false;
	do
	{
		if (!wcscmp(ProcessName, pe32.szExeFile))
		{
			dwPID = pe32.th32ProcessID;
			bRet = true;
			break;
		}
	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);

	return bRet;
}

int ProcessOpt::KillProcess(DWORD pid)
{  
	HANDLE hProcess = NULL;	 
	hProcess=OpenProcess(PROCESS_TERMINATE,FALSE,pid); //打开目标进程  
	if (hProcess==NULL) 
	{  
		wprintf(L"\nOpen Process failed:%d\n",GetLastError());  
		return -1;  
	}
	DWORD ret=TerminateProcess(hProcess,0);  //结束目标进程  
	if(ret==0) 
	{  
		wprintf(L"%d",GetLastError());  
	}  
	return -1;  
}  