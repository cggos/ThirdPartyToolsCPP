#pragma once

#include <string>
#include <vector>

class StdStringOpt
{
public:
	StdStringOpt(void);
	~StdStringOpt(void);

public:
	static std::vector<std::string> SplitStringByChar(std::string strSrc,char chSeparator);
};

