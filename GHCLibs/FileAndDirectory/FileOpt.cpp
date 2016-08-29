#include "FileOpt.h"


FileOpt::FileOpt(void)
{
}

void FileOpt::FilterInvalidFileNameChar(std::string &strFileTitle)  
{  
	std::string vecInvalidChar;  
	vecInvalidChar.resize(9);  
	vecInvalidChar[0] = 0x5C;  
	vecInvalidChar[1] = 0x2F;  
	vecInvalidChar[2] = 0x3A;  
	vecInvalidChar[3] = 0x2A;  
	vecInvalidChar[4] = 0x3F;  
	vecInvalidChar[5] = 0x22;  
	vecInvalidChar[6] = 0x3C;  
	vecInvalidChar[7] = 0x3E;  
	vecInvalidChar[8] = 0x7C;  
	int length = strFileTitle.length();  
	for(int i = 0; i< length; ++i)  
	{  
		if(strFileTitle[i] <= 0x1F || strFileTitle[i] == 0x7F || 
			vecInvalidChar.find(strFileTitle[i]) != std::string::npos)  
		{  
			strFileTitle[i] = 0x5F;  
		}  
	}  
}  

FileOpt::~FileOpt(void)
{
}