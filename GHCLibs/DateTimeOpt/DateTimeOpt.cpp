//#include "stdafx.h"

#include "DateTimeOpt.h"

CDateTimeOpt::CDateTimeOpt(void)
{
}

CDateTimeOpt::~CDateTimeOpt(void)
{
}

#ifdef USE_MFC
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
#endif

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

//根据格式字符串生成字符串,只能精确到秒级
std::string CDateTimeOpt::GetLocaltime()
{
	//time_t 这种类型就是用来存储从1970年到现在经过了多少秒，
	//要想更精确一点，可以用结构struct timeval，它精确到微妙
	time_t tt = time(NULL);//返回的只是一个时间戳
	tm* t= localtime(&tt);
	/*
	%a 星期几的缩写。Eg:Tue 
	%A 星期几的全名。 Eg: Tuesday
	%b 月份名称的缩写。 
	%B 月份名称的全名。 
	%c 本地端日期时间较佳表示字符串。 
	%d 用数字表示本月的第几天 (范围为 00 至 31)。日期
	%H 用 24 小时制数字表示小时数 (范围为 00 至 23)。 
	%I 用 12 小时制数字表示小时数 (范围为 01 至 12)。 
	%j 以数字表示当年度的第几天 (范围为 001 至 366)。 
	%m 月份的数字 (范围由 1 至 12)。
	%M 分钟。 
	%p 以 ''AM'' 或 ''PM'' 表示本地端时间。 
	%S 秒数。 
	%U 数字表示为本年度的第几周，第一个星期由第一个周日开始。 
	%W 数字表示为本年度的第几周，第一个星期由第一个周一开始。 
	%w 用数字表示本周的第几天 ( 0 为周日)。 
	%x 不含时间的日期表示法。 
	%X 不含日期的时间表示法。 Eg: 15:26:30
	%y 二位数字表示年份 (范围由 00 至 99)。 
	%Y 完整的年份数字表示，即四位数。 Eg:2008
	%Z(%z) 时区或名称缩写。Eg:中国标准时间 
	%% % 字符。
	*/
	char tmp[64]; 
	//strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z",t);
	sprintf(tmp,"%d-%02d-%02d %02d:%02d:%02d\n", 
		t->tm_year + 1900,
		t->tm_mon + 1,
		t->tm_mday,
		t->tm_hour,
		t->tm_min,
		t->tm_sec);
	std::string strLocaltime = tmp;
	return strLocaltime;
}

//优点：能精确到毫秒级；缺点：使用了windows API 
std::string CDateTimeOpt::GetLocaltimeWin()
{
	SYSTEMTIME sys; 
	GetLocalTime( &sys ); 
	char tmp[64];
	sprintf( tmp,"%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d\n",
		sys.wYear,sys.wMonth,sys.wDay,
		sys.wHour,sys.wMinute, sys.wSecond,sys.wMilliseconds,
		sys.wDayOfWeek);
	 
	//strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z",t);
	std::string strLocaltime = tmp;
	return strLocaltime;
}
