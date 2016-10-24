#pragma once

#include <Windows.h>
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
};

