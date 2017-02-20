#include "typeconvert.h"

TypeConvert::TypeConvert()
{

}

std::string TypeConvert::int2stdstring(int nData)
{
	std::stringstream ss;
	std::string strData;
	ss<<nData;
	ss>>strData;
	return strData;
}

std::string TypeConvert::intHex2stdstring(int nHex)
{
    char charTemp[100];
    sprintf(charTemp,"%02X",nHex);//两位整数
    std::string strTemp = charTemp;
    return strTemp;
}

std::string TypeConvert::intDec2stdstring(int nDecimal)
{
    char charTemp[100];
    sprintf(charTemp,"%02d",nDecimal);//两位整数
    std::string strTemp = charTemp;
    return strTemp;
}

std::string TypeConvert::intNormal2stdstring(int nNormal)
{
    char charTemp[100];
    sprintf(charTemp,"%d",nNormal);
    std::string strTemp = charTemp;
    return strTemp;
}

std::string TypeConvert::float2stdstring(float fData)
{
    char charTemp[100];
    sprintf(charTemp,"%.1f",fData);
    std::string strTemp = charTemp;
    return strTemp;
}

int TypeConvert::stdstring2intDec(std::string strDecimal)
{
    return std::atoi(strDecimal.c_str());
}

#ifdef _UNICODE
std::wstring TypeConvert::ANSIToUnicode(const std::string& strANSI)
{
	int unicodeLen = MultiByteToWideChar(CP_ACP, 0,strANSI.c_str(), -1, NULL, 0);

	wchar_t* pUnicode =new wchar_t[unicodeLen];
	memset(pUnicode,0,(unicodeLen)*sizeof(wchar_t)); 
	MultiByteToWideChar(CP_ACP, 0,strANSI.c_str(), -1,(LPWSTR)pUnicode,unicodeLen*sizeof(wchar_t));

	std::wstring wstrUnicode=L"";
	wstrUnicode = pUnicode;
	delete pUnicode;
	pUnicode = NULL;

	return wstrUnicode;
}

std::string TypeConvert::UnicodeToANSI(const std::wstring& wstrUnicode)
{
	int ansiLen = WideCharToMultiByte(CP_ACP, 0,wstrUnicode.c_str(), -1, NULL, 0, NULL, NULL);

	char* pANSI =new char[ansiLen];
	memset((void*)pANSI, 0, ansiLen*sizeof(char));
	WideCharToMultiByte(CP_ACP, 0, wstrUnicode.c_str(), -1, pANSI, ansiLen, NULL, NULL);

	std::string strANSI="";
	strANSI = pANSI;
	delete pANSI;
	pANSI = NULL;

	return strANSI;
}

std::wstring TypeConvert::UTF8ToUnicode(const std::string& strUTF8)
{
	int unicodeLen = ::MultiByteToWideChar( CP_UTF8,0,strUTF8.c_str(),-1,NULL,0 );

	wchar_t *  pUnicode = new  wchar_t[unicodeLen];  
	memset(pUnicode,0,unicodeLen*sizeof(wchar_t));  
	::MultiByteToWideChar( CP_UTF8,0,strUTF8.c_str(),-1,(LPWSTR)pUnicode,unicodeLen*sizeof(wchar_t));  

	std::wstring wstrUnicode=L"";  
	wstrUnicode = pUnicode;
	delete  pUnicode;
	pUnicode = NULL;

	return  wstrUnicode;  
}

std::string TypeConvert::UnicodeToUTF8(const std::wstring& wstrUnicode)
{
	int utf8Len = WideCharToMultiByte( CP_UTF8,0,wstrUnicode.c_str(),-1,NULL,0,NULL,NULL );

	char* pUTF8 = new char[utf8Len];
	memset( ( void* )pUTF8, 0, utf8Len*sizeof(char));
	WideCharToMultiByte( CP_UTF8,0,wstrUnicode.c_str(),-1,pUTF8,utf8Len,NULL,NULL );

	std::string strUTF8="";
	strUTF8 = pUTF8;
	delete pUTF8;
	pUTF8 = NULL;

	return strUTF8;
}

std::string TypeConvert::ANSIToUTF8(const std::string& strANSI)
{
	return UnicodeToUTF8(ANSIToUnicode(strANSI));
}

std::string TypeConvert::UTF8ToANSI(const std::string& strUTF8)
{
	return UnicodeToANSI(UTF8ToUnicode(strUTF8));
}
#endif


/////////////////////////////////MFC
#ifdef USE_MFC
std::string TypeConvert::cstring2stdstring(CString cstring)
{
	char charTemp[0x100]={0};
	::wsprintfA(charTemp, "%ls", (LPCTSTR)cstring);
	std::string strTemp=charTemp;
	return strTemp;
}
int TypeConvert::cstring2intDec(CString cstring)
{
	return _ttoi(cstring);
}
#endif

TypeConvert::~TypeConvert()
{

}

