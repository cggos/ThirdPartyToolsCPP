#pragma once

#ifndef TYPECONVERT_H
#define TYPECONVERT_H

//#define USE_MFC 0
#ifdef USE_MFC
#include <afx.h>
#endif

#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <cwchar>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>
#include <utility>

class TypeConvert
{
public:
    TypeConvert();
    ~TypeConvert();

public:
	static std::string int2stdstring(int nData);
    static std::string intHex2stdstring(int nHex);
    static std::string intDec2stdstring(int nDecimal);
    static std::string intNormal2stdstring(int nNormal);
    static std::string float2stdstring(float fData);

    static int stdstring2intDec(std::string strDecimal);

#ifdef _UNICODE
	//其中的Unicode即为UTF16编码
	static std::wstring ANSIToUnicode(const std::string& strANSI);
	static std::string	UnicodeToANSI(const std::wstring& wstrUnicode);  

	static std::wstring UTF8ToUnicode(const std::string& strUTF8);
	static std::string	UnicodeToUTF8(const std::wstring& wstrUnicode);

	static std::string	ANSIToUTF8(const std::string& strANSI);
	static std::string	UTF8ToANSI(const std::string& strUTF8);
#endif

#ifdef USE_MFC
	static std::string cstring2stdstring(CString cstring);
	static int cstring2intDec(CString cstring);
#endif
};

#endif // TYPECONVERT_H
