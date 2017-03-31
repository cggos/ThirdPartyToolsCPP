#include "Encryption.h"

std::string GenerateGUID()
{
	CoInitialize(NULL);

	char buffer[64] = { 0 };  
	GUID guid;  

	if ( S_OK != CoCreateGuid(&guid) )  
	{  
		return "";  
	}  
	_snprintf_s(buffer, sizeof(buffer),   
		"%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",   
		guid.Data1, guid.Data2, guid.Data3,   
		guid.Data4[0], guid.Data4[1], guid.Data4[2],   
		guid.Data4[3], guid.Data4[4], guid.Data4[5],   
		guid.Data4[6], guid.Data4[7]); 

	CoUninitialize();

	return (std::string)buffer;
}

/**
*  加密、解密算法
* @param key 公钥或密钥，采用公匙加密，采用密匙解密
* @param message 数据
* @return
*/
long RSA(unsigned int baseNum, unsigned int key, long message)
{
	if(baseNum < 1 || key < 1)
	{
		return 0L;
	}
	if(std::abs(message)>=baseNum)
	{
		return 0L;
	}

	//加密或者解密之后的数据
	long rsaMessage = 0L;

	//加密核心算法
	rsaMessage = ((long long)((long double)std::pow((long double)message, (int)key)))%baseNum;
	return rsaMessage;
}
