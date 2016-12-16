#pragma once

#include <Windows.h>

#include <io.h> 
#include <direct.h>

#include <string>
#include <tchar.h>

class PathOpt
{
public:
	PathOpt(void);
	~PathOpt(void);

public:
	TCHAR szDirExeFile[MAX_PATH + 1];
	TCHAR szDirCurrent[MAX_PATH + 1];

public:
	void GetDirectoryExe();
	void GetDirectoryCurrent();

	int CheckAndCreateDirectory(std::string strDir);
	int CheckAndDeleteDirectory(std::string strDir);
};

