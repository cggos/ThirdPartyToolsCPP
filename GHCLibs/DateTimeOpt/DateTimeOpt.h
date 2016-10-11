#pragma once

#include <string>
#include <ctime>

#include <windows.h>

//#define USE_MFC 0
#ifdef USE_MFC
#include <afx.h>
#include <afxdisp.h>
#include <ATLComTime.h>
#endif

class CDateTimeOpt
{
public:
	CDateTimeOpt(void);
	~CDateTimeOpt(void);

#ifdef USE_MFC
	static COleDateTime GetOleDateTime(CString strTime);
	static CTime GetCTime(COleDateTime oleDateTime);
	static CTime GetNowTime();
	static int GetAge(int yearBirth,int monthBirth,int dayOfMonthBirth);
	static int GetAge(CTime timeBirth);
#endif

	static int GetDaysInMonth(int year,int month);

	static std::string GetLocaltime();

	static std::string GetLocaltimeWin();
};

//linux下存储时间常见的有两种存储方式，一个是从1970年到现在经过了多少秒，一个是用一个结构来分别存储年月日时分秒的
