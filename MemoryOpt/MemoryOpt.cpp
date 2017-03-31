#include "MemoryOpt.h"

MemoryOpt::MemoryOpt(void)
{
}

MemoryOpt::~MemoryOpt(void)
{
}

ENDIANNESS MemoryOpt::IsBigOrLittleEndian()
{
	ENDIANNESS endianness;
	static union
	{ 
		char c[4]; 
		unsigned long l; 
	}endian_test={{ 'l', '?', '?', 'b' }};
	switch(((char)endian_test.l))
	{
	case 'l':
		endianness = LittleEndian;
		break;
	case 'b':
		endianness = BigEndian;
		break;
	}
	return endianness;
}

void MemoryOpt::DWORD2BYTE(unsigned long lData,unsigned char pData[4])
{
	for (unsigned char i=0;i<4;++i)
	{
		pData[i] = ((unsigned char*)&lData)[i];
	}
}

unsigned long MemoryOpt::BYTE2DWORD(unsigned char pData[4])
{
	unsigned long lData = *((unsigned long*)pData);
	return 	lData;
}
