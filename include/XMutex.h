/*************************************************************************
	> File Name: Xmutex.h
	> Author: xuhuichi
	> Desc:  
	> Created Time: 2017年02月03日 星期五 15时04分38秒
 ************************************************************************/
#ifndef _XMUTEX_H_
#define _XMUTEX_H_
#include <pthread.h>
#include <iostream>
class XCond;
class XMutex
{
public:
	XMutex();
	~XMutex();
	int Lock();
	int UnLock();
private:
	pthread_mutex_t m_mutex;
	friend class XCond;
};

class XAutoLocker
{
public:
	XAutoLocker(XMutex * pXMutex):m_pXMutex(pXMutex)
	{
		//std::cout << "lock" << std::endl;
		if(NULL != m_pXMutex) m_pXMutex->Lock();
	}
	~XAutoLocker()
	{
		//std::cout << "unlock" << std::endl;
		if(NULL != m_pXMutex) m_pXMutex->UnLock();
	}
private:
	XMutex * m_pXMutex;

};
#endif // _XMUTEX_H_
