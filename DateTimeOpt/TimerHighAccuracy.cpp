/*
 * Linux/Windows 系统高精度计时器
 */

#include "TimerHighAccuracy.h"

#ifdef  WIN32
#include <Windows.h>
#elif  linux
#include <sys/time.h>
#endif

#ifdef WIN32
TimerHighAccuracy::TimerHighAccuracy()
{
    LARGE_INTEGER sysFreq;  // 计时器频率
    flag = QueryPerformanceFrequency( &sysFreq );
    if ( flag )
    {
        dSystemFreq = (double)sysFreq.QuadPart;
    }
}

void TimerHighAccuracy::start()
{
    LARGE_INTEGER t;
    flag &= QueryPerformanceCounter( &t );
    if ( !flag )
        return;
    dStartTime = (double)t.QuadPart;
}

double TimerHighAccuracy::stop()
{
    LARGE_INTEGER t;
    flag &= QueryPerformanceCounter( &t );

    if ( !flag )
        return -1.0;

    dStopTime = (double)t.QuadPart;
    return ( dStopTime - dStartTime ) / dSystemFreq;
}

#elif  linux

TimerHighAccuracy::TimerHighAccuracy(){}

double TimerHighAccuracy::start()
{
    gettimeofday( &tvStart, NULL );
    return tvStart.tv_usec;
}

double TimerHighAccuracy::stop()
{
    gettimeofday( &tvStop, NULL );
    return (double)(tvStop.tv_sec - tvStart.tv_sec)
            + (double)(tvStop.tv_usec - tvStart.tv_usec)/1000000.0;
}

#endif
