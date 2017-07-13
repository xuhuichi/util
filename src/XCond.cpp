/*************************************************************************
	> File Name: XCond.cpp
	> Author: xuhuichi
	> Desc:  
	> Created Time: 2017年02月03日 星期五 15时30分40秒
 ************************************************************************/
#include "XCond.h"

#include <sys/time.h>

XCond::XCond()
{
	pthread_cond_init(&m_cond, NULL);
}

XCond::~XCond()
{
	pthread_cond_destroy(&m_cond);
}

void XCond::Signal()
{
	pthread_cond_signal(&m_cond);
}

void XCond::Wait(XMutex * pMutex, uint32_t inTimeoutInMilSecs)
{
	struct timespec ts;
	struct timeval tv;
	struct timezone tz;
	int sec = 0; 
	int usec =0;
	if(0 == inTimeoutInMilSecs)
	{
		pthread_cond_wait(&m_cond, &pMutex->m_mutex);
	}
	else
	{
		gettimeofday(&tv, &tz);
		sec = inTimeoutInMilSecs/1000;
		inTimeoutInMilSecs = inTimeoutInMilSecs - (sec * 1000);
		usec = inTimeoutInMilSecs * 1000;
		ts.tv_sec = tv.tv_sec + sec;
		ts.tv_nsec = (tv.tv_usec + usec)*1000;
		if(ts.tv_nsec > 999999999)
		{
			ts.tv_sec++;
			ts.tv_nsec -=1000000000;
		}
		pthread_cond_timedwait(&m_cond, &pMutex->m_mutex, &ts);
	}
}

void XCond::Broadcast()
{
	pthread_cond_broadcast(&m_cond);
}
