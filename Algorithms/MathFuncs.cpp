#include "MathFuncs.h"

MathFuncs::MathFuncs()
{

}

//Function to return gcd of a and b
//Greatest Common Divisor最大公约数
//辗转相除法：辗转相除法是求两个自然数的最大公约数的一种方法，也叫欧几里德算法
int MathFuncs::GCD(int m, int n)
{
	try
	{
		if (0==m | 0==n)
		{
			throw 0;
		}
	}
	catch (int &e)
	{
		return 0;
	}
	int r = m % n;
	if (0==r)
		return n;
    return GCD(n, r);
}

//A simple method to evaluate Euler Totient Function
//Euler Totient Function欧拉函数
unsigned int MathFuncs::ETF1(unsigned int N)
{
    if(N==0)
    {
        return -1;
    }
    unsigned int result = 1;
    for (int i=2; i < N; i++)
    {
        if (GCD(i, N) == 1)
        {
            result++;
        }
    }
    return result;
}
unsigned int MathFuncs::ETF2(unsigned int N)
{
    int result = N;   // Initialize result as n

    // Consider all prime factors of n and subtract their
    // multiples from result
    for (int p=2; p*p<=N; ++p)
    {
        // Check if p is a prime factor.
        if (N % p == 0)
        {
            // If yes, then update n and result
            while (N % p == 0)
                N /= p;
            result -= result / p;
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (N > 1)
        result -= result / N;
    return result;
}

