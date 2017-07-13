/*************************************************************************
	> File Name: XMutex.cpp
	> Author: xuhuichi
	> Desc:  
	> Created Time: 2017年02月03日 星期五 15时11分46秒
 ************************************************************************/
#include "XMutex.h"

XMutex::XMutex()
{
	pthread_mutex_init(&m_mutex, NULL);
}

XMutex::~XMutex()
{
	pthread_mutex_destroy(&m_mutex);
}


int  XMutex::Lock()
{
	return pthread_mutex_lock(&m_mutex);
}

int XMutex::UnLock()
{
	return 	pthread_mutex_unlock(&m_mutex);
}
