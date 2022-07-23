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
#include "SimpThread.h"
#include <unistd.h>



/**  
 *  @brief  构造
 *  @note
 *  
 *  
 */
SimpThread::SimpThread()
{
    this->states = _stop;
    this->thr = nullptr;
}


/**  
 *  @brief  析构
 *  @note
 *  
 *  
 */
SimpThread::~SimpThread()
{
    if (nullptr != this->thr)
        delete this->thr;
    this->thr = nullptr;
}


/**  
 *  @brief  启动线程
 *  @note
 *  
 *  @retval true        -- 成功
 *  @retval false       -- 失败
 *  
 * 
 */
bool SimpThread::start()
{
    if (nullptr != this->thr || _running == this->states)
        return true;
    this->thr = new std::thread(&SimpThread::thread_fun, this);
    if (nullptr == this->thr)
        return false;
    this->thr->detach();
    return true;
}


/**  
 *  @brief  关闭线程
 *  @note
 *  
 *  @retval true        -- 成功
 *  @retval false       -- 失败
 *  
 *  
 */
bool SimpThread::stop()
{
    if (nullptr == this->thr || _stop == this->states)
        return true;
    this->states = _stopping;
    while (_stop != this->states)
    {
        usleep(10);
    }
    return true;
}


/**  
 *  @brief  线程入口函数
 *  @note
 *  
 *  @return
 *  void
 * 
 */
void SimpThread::thread_fun()
{
    if (nullptr == this->thr)
        return;
    this->states = _running;
    while (_running == this->states)
    {
        this->run();
    }
    this->states = _stop;
}

