#ifndef RSA_H
#define RSA_H

#include <cmath>

class RSA
{
public:
    RSA();

    static long rsa(unsigned int baseNum, unsigned int key, long message);
};

#endif // RSA_H
