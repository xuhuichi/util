/*************************************************************************
	> File Name: XMutexRW.cpp
	> Author: xuhuichi
	> Desc:  
	> Created Time: 2017年02月03日 星期五 16时44分25秒
 ************************************************************************/
#include "XMutexRW.h"
XMutexRW::XMutexRW()
{
	pthread_rwlock_init(&m_rwlock,NULL);
}

XMutexRW::~XMutexRW()
{
	pthread_rwlock_destroy(&m_rwlock);
}

int XMutexRW::ReadLock()
{
	return pthread_rwlock_rdlock(&m_rwlock);
}	

int XMutexRW::WriteLock()
{
	return pthread_rwlock_wrlock(&m_rwlock);
}	

int XMutexRW::UnLock()
{
	return pthread_rwlock_unlock(&m_rwlock);
}
