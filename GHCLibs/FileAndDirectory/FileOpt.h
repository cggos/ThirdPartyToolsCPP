#pragma once

#include <string>

class FileOpt
{
public:
	FileOpt(void);
	~FileOpt(void);

public:
	//过滤Windows(MacOSX)文件名中的非法字符
	void FilterInvalidFileNameChar(std::string &strFileTitle);
};

