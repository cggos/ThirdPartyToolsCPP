#pragma once

#include <Windows.h>
#include <io.h> 
#include <direct.h>
#include <shlwapi.h>
#include <Shlobj.h>

#include <tchar.h>
#include <string>

#pragma comment(lib,"shlwapi")

class PathOpt
{
public:
	PathOpt(void);
	~PathOpt(void);

public:
	TCHAR szDirExeFile[MAX_PATH + 1];
	TCHAR szDirCurrent[MAX_PATH + 1];
	TCHAR szDirByCSIDL[MAX_PATH + 1];

public:
	void GetDirectoryExe();
	void GetDirectoryCurrent();
	void GetDirectoryByCSIDL(int csidl=CSIDL_LOCAL_APPDATA);

	int CheckAndCreateDirectory(std::string strDir);
	int CheckAndDeleteDirectory(std::string strDir);
};

