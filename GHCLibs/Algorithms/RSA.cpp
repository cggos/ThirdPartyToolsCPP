#include "RSA.h"

RSA::RSA()
{

}

/**
*  加密、解密算法
* @param key 公钥或密钥，采用公匙加密，采用密匙解密
* @param message 数据
* @return
*/
long RSA::rsa(unsigned int baseNum, unsigned int key, long message)
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
    rsaMessage = ((long long)(std::pow(message, key)))%baseNum;
    return rsaMessage;
}
