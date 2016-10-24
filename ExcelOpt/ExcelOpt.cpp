#include "./ExcelOpt.h"

ExcelOpt::ExcelOpt(const wchar_t *excelPath)
{
	isSuccess = false;
	book = xlCreateBook();
	if(book)
	{
		if(book->load(excelPath));//L".\\ParametersConfig\\Parameters.xls"
		{
			isSuccess = true;
		}
	}
}

ExcelOpt::~ExcelOpt()
{
	book->release();
}

bool ExcelOpt::ReadCellData(int sheetNum,int row,int col,double &dataOut)
{
	bool ret = false;
	if (isSuccess)
	{
		Sheet* sheet = book->getSheet(sheetNum);
		if(sheet)
		{   
			dataOut =  sheet->readNum(row-1,col-1);
			ret = true;
		}
		
	}
	return ret;
}