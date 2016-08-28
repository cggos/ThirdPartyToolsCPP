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
std::string TypeConvert::stdwstring2stdstring(const std::wstring& wstr)
{
	int nBufSize = WideCharToMultiByte(CP_ACP, 0,wstr.c_str(), -1, NULL, 0, NULL, NULL);

	char* chBuf =new char[nBufSize*sizeof(char)];
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, chBuf, nBufSize, NULL, NULL);

	std::string str(chBuf);
	delete chBuf;
	chBuf = NULL;

	return str;
}

std::wstring TypeConvert::stdstring2stdwstring(const std::string& str)
{
	int nBufSize = ::MultiByteToWideChar(GetACP(), 0,str.c_str(), -1, NULL, 0);

	wchar_t* wchBuf =new wchar_t[nBufSize];
	::MultiByteToWideChar(GetACP(), 0,str.c_str(), -1,wchBuf,nBufSize);

	std::wstring wstr(wchBuf);
	delete wchBuf;
	wchBuf = NULL;

	return wstr;
}

std::string TypeConvert::stdwstring2utf8(const std::wstring& wstr)
{
	int size = ::WideCharToMultiByte(CP_UTF8,0,wstr.c_str(),wstr.size(),NULL,0,NULL,NULL);
	if (size == 0)
	{
		return "";
	}

	std::string strBuffer;
	strBuffer.resize(size);
	::WideCharToMultiByte(CP_UTF8,0,wstr.c_str(),wstr.size(),const_cast<char*>(strBuffer.c_str()),size,NULL,NULL);

	return strBuffer;
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
	// wide char to multi char
	int iTextLen = WideCharToMultiByte( CP_ACP,0,str.c_str(),-1,NULL,0,NULL,NULL );
	char* pElementText = new char[iTextLen + 1];
	memset( ( void* )pElementText, 0, sizeof( char ) * ( iTextLen + 1 ) );
	::WideCharToMultiByte( CP_ACP,0,str.c_str(),-1,pElementText,iTextLen,NULL,NULL );
	std::string strText;
	strText = pElementText;
	delete[] pElementText;

	return strText;
}

inline char* Unicode2Ansi(const wchar_t* unicode)    
{    
	int len;    
	len = WideCharToMultiByte(CP_ACP, 0, unicode, -1, NULL, 0, NULL, NULL);    
	char *szUtf8 = (char*)malloc(len + 1);    
	memset(szUtf8, 0, len + 1);    
	WideCharToMultiByte(CP_ACP, 0,unicode, -1, szUtf8, len, NULL,NULL);    
	return szUtf8;    
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




void TypeConvert::Utf8ToGBK(std::string &strUtf8)
{
	int len=MultiByteToWideChar(CP_UTF8, 0, strUtf8.c_str(), -1, NULL,0);
	wchar_t * wszGBK = new wchar_t[len];
	memset(wszGBK,0,len);
	MultiByteToWideChar(CP_UTF8, 0, strUtf8.c_str(), -1, wszGBK, len); 

	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char *szGBK=new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte (CP_ACP, 0, wszGBK, -1, szGBK, len, NULL,NULL);

	strUtf8 = szGBK;
	delete[] szGBK;
	delete[] wszGBK;
}

void TypeConvert::GBKToUtf8(std::string &strGBK)
{
	int len=MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL,0);
	wchar_t * wszUtf8 = new wchar_t [len];
	memset(wszUtf8, 0, len);
	MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, wszUtf8, len);

	len = WideCharToMultiByte(CP_UTF8, 0, wszUtf8, -1, NULL, 0, NULL, NULL);
	char *szUtf8=new char[len + 1];
	memset(szUtf8, 0, len + 1);
	WideCharToMultiByte (CP_UTF8, 0, wszUtf8, -1, szUtf8, len, NULL,NULL);

	strGBK = szUtf8;
	delete[] szUtf8;
	delete[] wszUtf8;
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

