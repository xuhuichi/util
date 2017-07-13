/*************************************************************************
	> File Name: XMutexRW.h
	> Author: xuhuichi
	> Desc:  
	> Created Time: 2017年02月03日 星期五 16时37分50秒
 ************************************************************************/
#ifndef _XMUTEXRW_H_
#define _XMUTEXRW_H_
#include <pthread.h>
class XMutexRW
{
public:
	XMutexRW();
	~XMutexRW();
	inline int ReadLock();
	inline int WriteLock();
	inline int UnLock();	
private:
	pthread_rwlock_t m_rwlock;
};

class XAutoReadLocker
{
public:
	XAutoReadLocker(XMutexRW * pMutexRw):m_pXMutexRw(pMutexRw)
	{
		if(NULL != m_pXMutexRw) m_pXMutexRw->ReadLock();
	}
	~XAutoReadLocker()
	{
		if(NULL != m_pXMutexRw) m_pXMutexRw->UnLock();
	}
private:
	XMutexRW * m_pXMutexRw;
};

class XAutoWriteLocker
{
public:
	XAutoWriteLocker(XMutexRW * pMutexRw):m_pXMutexRw(pMutexRw)
	{
		if(NULL != m_pXMutexRw) m_pXMutexRw->WriteLock();
	}
	~XAutoWriteLocker()
	{
		if(NULL != m_pXMutexRw) m_pXMutexRw->UnLock();
	}
private:
	XMutexRW * m_pXMutexRw;
};

#endif
