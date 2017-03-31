#pragma once

#include <objbase.h>  
#include <string>
#include <cmath>

std::string GenerateGUID();

long RSA(unsigned int baseNum, unsigned int key, long message);