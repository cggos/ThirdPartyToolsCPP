#pragma once

//16bits简单大小端转换的宏
#define SWAP_ENDIAN_16(x) ((short)((((short)(x)&(short)0x00ffU)<<8)|(((short)(x)&(short)0xff00U)>>8)))

enum ENDIANNESS {BigEndian, LittleEndian};

class MemoryOpt
{
public:
	MemoryOpt(void);
	~MemoryOpt(void);

	ENDIANNESS IsBigOrLittleEndian();

	void DWORD2BYTE(unsigned long lData,unsigned char pData[4]);
	unsigned long BYTE2DWORD(unsigned char pData[4]);
};
