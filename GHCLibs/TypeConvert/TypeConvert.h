#pragma once

#ifndef TYPECONVERT_H
#define TYPECONVERT_H

#define USE_MFC 0
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
#include <fstream>
#include <utility>

class TypeConvert
{
public:
    TypeConvert();
    ~TypeConvert();

public:
    static std::string intHex2stdstring(int nHex);
    static std::string intDec2stdstring(int nDecimal);
    static std::string intNormal2stdstring(int nNormal);
    static std::string float2stdstring(float fData);

    static int stdstring2intDec(std::string strDecimal);

	/////////////////////Unicode»·¾³
#ifdef _UNICODE
	static std::string tchar2stdstring(wchar_t *wstr);
        static std::wstring stdstring2stdwstring(std::string str);
	static std::string wstring2utf8(std::wstring wstr);
	static std::wstring ANSIToUnicode(const std::string& str);
	static std::string UnicodeToANSI(const std::wstring& str);
	static std::wstring UTF8ToUnicode(const std::string& str);
	static std::string UnicodeToUTF8(const std::wstring& str);
#endif

	/////////////////////////////////MFC
#ifdef USE_MFC
	static std::string cstring2stdstring(CString cstring);
	static int cstring2intDec(CString cstring);

#endif

};

#endif // TYPECONVERT_H
