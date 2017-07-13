/*************************************************************************
	> File Name: XThread.cpp
	> Author: xuhuichi
	> Desc:  
	> Created Time: 2017年02月04日 星期六 08时44分09秒
 ************************************************************************/
#include "XThread.h"

XThread::XThread()
{
	pthread_attr_init(&m_threadAttr);
	m_isDetach = false;
}

XThread::~XThread()
{

}
void XThread::SetDetach()
{
	pthread_attr_setdetachstate(&m_threadAttr,PTHREAD_CREATE_DETACHED);
	m_isDetach = true;
}
void XThread::Start()
{
	pthread_create(&m_pid, &m_threadAttr, _Entry, (void *)this);
}
void * XThread::_Entry(void * pThread)
{
	XThread * pThis = (XThread*)pThread;
	pThis->Entry();
}

void XThread::Join()
{
	if(!m_isDetach) pthread_join(m_pid, NULL);
}
