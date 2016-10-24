#pragma once

#include <iostream>
#include <map>
#include <string>
#include <conio.h>
#include "./libxl-3.7.0.1/include_cpp/libxl.h"

using namespace libxl;

class ExcelOpt
{
private:
	Book* book;
	bool isSuccess;
public:	
	ExcelOpt(const wchar_t *excelPath);
	~ExcelOpt();
	bool ReadCellData(int sheetNum,int row,int col,double &dataOut);
};