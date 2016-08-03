#include "PathOpt.h"


PathOpt::PathOpt(void)
{
}


PathOpt::~PathOpt(void)
{
}

void PathOpt::GetDirectoryExe()
{
	//获得某个正在运行的EXE或者DLL所在的目录
	HMODULE hModule = GetModuleHandle(0); 
	//assert(hModule);	
	if (NULL==hModule)
	{
		OutputDebugString(_T("GetModuleHandle获取句柄失败！\n"));
		//ATLTRACE(_T("d%"),GetLastError());
	}
	else
	{
		ZeroMemory(szDirExeFile,MAX_PATH);
		GetModuleFileName(hModule, szDirExeFile, MAX_PATH);
		(_tcsrchr(szDirExeFile, _T('\\')))[1] = 0; // 删除文件名，只获得路径字串
	}
}

void PathOpt::GetDirectoryCurrent()
{
	//获取当前工作目录
	GetCurrentDirectory(MAX_PATH, szDirCurrent);
}


