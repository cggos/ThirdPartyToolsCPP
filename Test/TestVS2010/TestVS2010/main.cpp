#include <iostream>
using namespace std;

#include "../../../ExcelOpt/ExcelOpt.h"
#pragma comment(lib,"../../../ExcelOpt/libxl-3.7.0.1/lib/libxl.lib")
const wchar_t *excelPath = L"..\\..\\..\\ExcelOpt\\Test.xls";

int main()
{
	double data=0.0;
	ExcelOpt excelOpt(excelPath);
	bool ret = excelOpt.ReadCellData(0,2,2,data);
	if (ret)
	{
		std::cout<<data<<std::endl;
	}

	system("pause");
	return 0;
}