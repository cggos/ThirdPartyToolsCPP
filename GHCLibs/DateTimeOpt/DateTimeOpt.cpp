#include "stdafx.h"

#include "DateTimeOpt.h"

CDateTimeOpt::CDateTimeOpt(void)
{
}


CDateTimeOpt::~CDateTimeOpt(void)
{
}

//strTime格式：1993-08-11 11:22:33 或 1993年9月22日 。。。。。
COleDateTime CDateTimeOpt::GetOleDateTime(CString strTime)
{
	COleVariant VariantTime;
	VariantTime = strTime;
	VariantTime.ChangeType(VT_DATE);
	COleDateTime DataTime = VariantTime;

	return DataTime;
}

 CTime CDateTimeOpt::GetCTime(COleDateTime oleDateTime)
 {
	 SYSTEMTIME   systime;   
	 VariantTimeToSystemTime(oleDateTime,   &systime);   
	 CTime ctm(systime); 

	 return ctm;
 }

//获取任意一年一个月中的天数
int CDateTimeOpt::GetDaysInMonth(int year,int month)
{
	int d;
	int day[]= {31,28,31,30,31,30,31,31,30,31,30,31};
	if (2==month)
	{
		d=(((0==year%4)&&(0!=year%100)||(0==year%400))?29:28);
	}
	else
	{
		d=day[month-1];

	}
	return d;
}

CTime CDateTimeOpt::GetNowTime()
{
	CTime time;
	time = CTime::GetCurrentTime();

	int year = time.GetYear() ;
	int month = time.GetMonth();
	int day = time.GetDay();
	int hour = time.GetHour();
	int minute = time.GetMinute();
	int second = time.GetSecond();
	int DayOfWeek = time.GetDayOfWeek() ;

	return time;
}

int CDateTimeOpt::GetAge(int yearBirth,int monthBirth,int dayBirth)
{
	CTime time;
	time = CTime::GetCurrentTime();

	int yearNow = time.GetYear();
	int monthNow = time.GetMonth();
	int dayNow = time.GetDay();

	int age = yearNow - yearBirth;  

	if (monthNow <= monthBirth) {  
		if (monthNow == monthBirth) {  
			if (dayNow < dayBirth) age--;  
		}else{  
			age--;  
		}  
	}  
	return age; 
}

int CDateTimeOpt::GetAge(CTime timeBirth)
{
	CTime time;
	time = CTime::GetCurrentTime();

	int yearNow = time.GetYear();
	int monthNow = time.GetMonth();
	int dayNow = time.GetDay();

	int yearBirth = timeBirth.GetYear();
	int monthBirth = timeBirth.GetMonth();
	int dayBirth = timeBirth.GetDay();

	int age = yearNow - yearBirth;  

	if (monthNow <= monthBirth) {  
		if (monthNow == monthBirth) {  
			if (dayNow < dayBirth) age--;  
		}else{  
			age--;  
		}  
	}  
	return age; 
}
