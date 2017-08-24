#ifndef __TimerHighAccuracy_H__
#define __TimerHighAccuracy_H__

#ifdef WIN32
    #include <Windows.h>
#elif linux
    #include <sys/time.h>
#endif

class TimerHighAccuracy
{
public:
    TimerHighAccuracy();
    double start();
    double stop();   // 返回从 start 到 stop 所经历的时间（单位:秒）

private:
#ifdef  WIN32
    double dSystemFreq;
    BOOL   flag;
    double dStartTime;
    double dStopTime;
#elif  linux
    struct timeval tvStart;
    struct timeval tvStop;
#endif
};

#endif
