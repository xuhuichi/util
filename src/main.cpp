/*************************************************************************
	> File Name: main.cpp
	> Author: xuhuichi
	> Desc:  
	> Created Time: 2017年02月04日 星期六 10时45分39秒
 ************************************************************************/
#include <stdint.h>
#include <iostream>
#include <list>
#include <unistd.h>
#include <atomic>
#include "XCond.h"
#include "XMutex.h"
#include "XThread.h"
class XQueue
{
public:
	XQueue():m_deCount(0){}
	void Enqueue(int value);
	void Dequeue(int & value);
private:
	bool IsEmpty();
	volatile int32_t m_deCount;
//	std::atomic<int> m_deCount;
private:
	std::list<int> m_queue;
	XCond m_cond;
	XMutex m_mutex;
};
bool XQueue::IsEmpty()
{
	XAutoLocker locker(&m_mutex);
	return (0 ==m_queue.size()) ;
}
void XQueue::Enqueue(int value)
{
	XAutoLocker locker(&m_mutex);
	m_queue.push_back(value);
	if(m_deCount) m_cond.Broadcast();
}
void XQueue::Dequeue(int & value)
{
	XAutoLocker locker(&m_mutex);
	__sync_fetch_and_add(&m_deCount, 1);
//	++m_deCount;
	while(m_queue.empty())
	{
		m_cond.Wait(&m_mutex, 0);
		__sync_fetch_and_sub(&m_deCount, 1);
	//	--m_deCount;
	}
	value = m_queue.front();
	m_queue.pop_front();

}

XQueue g_queue;

class TaskThread : public XThread
{
public:
	virtual void Entry();
};
void TaskThread::Entry()
{
	while(true)
	{
		int i = -1;
		g_queue.Dequeue(i);
		std::cout <<pthread_self() <<  " i=" << i << std::endl;
	}

}

int32_t main(int32_t argc, char * argv[])
{
	std::cout << "test" << std::endl;
	TaskThread td,td2;
	td.Start();
	for(int i = 0; i < 10; ++i)
	{
		std::cout << "enqueue=" << i << std::endl;
		g_queue.Enqueue(i);
		usleep(10);
	}
	std::cout << "for end" << std::endl; 
	std::cout << "for end" << std::endl; 
	std::cout << "for end" << std::endl; 
	td.Join();
}
