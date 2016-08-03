#include "typeconvert.h"

TypeConvert::TypeConvert()
{

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


/////////////////////Unicode环境
#ifdef _UNICODE
std::string TypeConvert::tchar2stdstring(wchar_t *wstr)
{
	int iLen = WideCharToMultiByte(CP_ACP, 0,wstr, -1, NULL, 0, NULL, NULL);
	char* chBuf =new char[iLen*sizeof(char)];
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, chBuf, iLen, NULL, NULL);
	std::string str(chBuf);
	return str;
}

std::wstring TypeConvert::stdstring2stdwstring(std::string str)
{
	int iLen = ::MultiByteToWideChar(GetACP(), 0,str.c_str(), -1, NULL, 0);
	wchar_t* chBuf =new wchar_t[iLen];
	::MultiByteToWideChar(GetACP(), 0,str.c_str(), -1,chBuf,iLen);
	std::wstring wstr(chBuf);
	delete chBuf;
	return wstr;
}

std::string TypeConvert::wstring2utf8(std::wstring wstr)
{
	int iLen = WideCharToMultiByte(CP_UTF8, 0,wstr.c_str(), (int)wstr.size(), NULL, 0, NULL, NULL);
	if (iLen == 0)
	{
		return "";
	}
	char* chBuf =new char[iLen];
	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), (int)wstr.size(), chBuf, iLen, NULL, NULL);
	std::string str(chBuf);
	return str;
}

std::wstring ANSIToUnicode(const std::string& str)
{
	int  len = 0;
	len = str.length();
	int  unicodeLen = ::MultiByteToWideChar( CP_ACP,0,str.c_str(),-1,NULL,0 );  
	wchar_t *  pUnicode;  
	pUnicode = new  wchar_t[unicodeLen+1];  
	memset(pUnicode,0,(unicodeLen+1)*sizeof(wchar_t));  
	::MultiByteToWideChar( CP_ACP,0,str.c_str(),-1,(LPWSTR)pUnicode,unicodeLen );  
	std::wstring  rt;  
	rt = ( wchar_t* )pUnicode;
	delete  pUnicode; 

	return  rt;  
}

std::string UnicodeToANSI(const std::wstring& str)
{
	char* pElementText;
	int iTextLen;
	// wide char to multi char
	iTextLen = WideCharToMultiByte( CP_ACP,0,str.c_str(),-1,NULL,0,NULL,NULL );
	pElementText = new char[iTextLen + 1];
	memset( ( void* )pElementText, 0, sizeof( char ) * ( iTextLen + 1 ) );
	::WideCharToMultiByte( CP_ACP,0,str.c_str(),-1,pElementText,iTextLen,NULL,NULL );
	std::string strText;
	strText = pElementText;
	delete[] pElementText;

	return strText;
}

std::wstring UTF8ToUnicode(const std::string& str)
{
	int  len = 0;
	len = str.length();
	int  unicodeLen = ::MultiByteToWideChar( CP_UTF8,0,str.c_str(),-1,NULL,0 );  
	wchar_t *  pUnicode;  
	pUnicode = new  wchar_t[unicodeLen+1];  
	memset(pUnicode,0,(unicodeLen+1)*sizeof(wchar_t));  
	::MultiByteToWideChar( CP_UTF8,0,str.c_str(),-1,(LPWSTR)pUnicode,unicodeLen );  
	std::wstring rt;  
	rt = ( wchar_t* )pUnicode;
	delete  pUnicode; 

	return  rt;  
}

std::string UnicodeToUTF8(const std::wstring& str)
{
	char*  pElementText;
	int iTextLen;
	// wide char to multi char
	iTextLen = WideCharToMultiByte( CP_UTF8,0,str.c_str(),-1,NULL,0,NULL,NULL );
	pElementText = new char[iTextLen + 1];
	memset( ( void* )pElementText, 0, sizeof( char ) * ( iTextLen + 1 ) );
	::WideCharToMultiByte( CP_UTF8,0,str.c_str(),-1,pElementText,iTextLen,NULL,NULL );
	std::string strText;
	strText = pElementText;
	delete[] pElementText;

	return strText;
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

