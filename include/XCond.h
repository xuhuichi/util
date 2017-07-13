/*************************************************************************
	> File Name: XCond.h
	> Author: xuhuichi
	> Desc:  
	> Created Time: 2017年02月03日 星期五 15时24分24秒
 ************************************************************************/
#ifndef _XCOND_H_
#define _XCOND_H_

#include "XMutex.h"
#include <stdint.h>
class XCond
{
public:
	XCond();
	~XCond();
	void Signal();
	/*desc: 等待条件变量
 	 *param: pMutex 信号量关联的互斥锁
	 *       inTimeoutInMilSecs 超时等待时间 单位微秒 为0时一直阻塞等待
	 */
	void Wait(XMutex * pMutex, uint32_t inTimeoutInMilSecs = 0);
	/*desc: 通知所有wait的线程
 	 */
	void Broadcast();
private:
	pthread_cond_t m_cond;
};
#endif // _XCOND_H_
