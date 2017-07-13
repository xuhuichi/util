/*************************************************************************
	> File Name: XThread.h
	> Author: xuhuichi
	> Desc:  
	> Created Time: 2017年02月04日 星期六 08时38分46秒
 ************************************************************************/
#ifndef _XTHREAD_H_
#define _XTHREAD_H_

#include <pthread.h>

class XThread
{
public:
	XThread();
	~XThread();
	/*Desc: 设置线程分离，需在Start函数之前调用
	 */
	void SetDetach();
	void Start();
	void Join();
	virtual void Entry() =0;
	static void * _Entry(void * pThread);
private:
	pthread_t m_pid;
	pthread_attr_t m_threadAttr;
	bool m_isDetach;
};


#endif // _XTHREAD_H_
