#pragma once

#define USE_MFC 0
#ifdef USE_MFC
#include <afx.h>
#endif

 #include <ATLComTime.h>
 #include <afxdisp.h>

class CDateTimeOpt
{
public:
	CDateTimeOpt(void);
	~CDateTimeOpt(void);

	static COleDateTime GetOleDateTime(CString strTime);

	static CTime GetCTime(COleDateTime oleDateTime);

	static int GetDaysInMonth(int year,int month);

	static CTime GetNowTime();

	static int GetAge(int yearBirth,int monthBirth,int dayOfMonthBirth);

	static int GetAge(CTime timeBirth);
};
