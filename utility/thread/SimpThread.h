/*****************************************************************************
*  @copyright   
*  @file        SimpThread.h
*  @brief       简易线程类
*  @note
*  
*  @author      Snowgooc
*  @version     1.0.0
*  @date        2022-07-10
*  
*----------------------------------------------------------------------------
*  Remark         : Description
*----------------------------------------------------------------------------
*  Change History :
*  <Date>     | <Version> | <Author>       | <Description>
*----------------------------------------------------------------------------
*  
*****************************************************************************/
#ifndef _UTILITY_THREAD_SIMPTHREAD_H_
#define _UTILITY_THREAD_SIMPTHREAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <thread>



class SimpThread
{
protected:
    static const int    _stop = 1;
    static const int    _running = 2;
    static const int    _stopping = 3;

    volatile int        states = _stop;                         // 状态
    std::thread         *thr = nullptr;                         // 线程指针

public:
    SimpThread();                                               // 构造
    virtual ~SimpThread();                                      // 析构
    SimpThread(const SimpThread &st) = delete;                  // 禁用复制构造
    SimpThread(SimpThread &&st) = delete;                       // 禁用移动复制构造
    SimpThread& operator=(const SimpThread &st) = delete;       // 禁用赋值运算符
    SimpThread& operator=(SimpThread &&st) = delete;            // 禁用移动赋值运算符

public:
    virtual bool start();                                       // 启动线程
    virtual bool stop();                                        // 关闭线程
    virtual void run() = 0;                                     // 线程循环体

protected:
    virtual void thread_fun();                                  // 线程入口函数


};




#endif /* _UTILITY_THREAD_SIMPTHREAD_H_ */
