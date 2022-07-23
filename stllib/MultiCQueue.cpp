/*****************************************************************************
*  @copyright   
*  @file        MultiCQueue.h
*  @brief       资源复用队列
*  @note
*  采用双CQueue实现
* 
*  @author      Snowgooc
*  @version     1.0.0
*  @date        2022-07-09
*  
*----------------------------------------------------------------------------
*  Remark         : Description
*----------------------------------------------------------------------------
*  Change History :
*  <Date>     | <Version> | <Author>       | <Description>
*----------------------------------------------------------------------------
*  
*****************************************************************************/
#include "MultiCQueue.h"


using namespace com_stl;



/**  
 *  @brief  构造
 *  @note
 *  默认size为255
 *  
 */
MultiCQueue::MultiCQueue(uint32_c size)
{
    this->dataCQue = new CQueue(size);
    this->multiCQue = new CQueue(size);
}


/**  
 *  @brief  析构
 *  @note
 *  
 *  
 */
MultiCQueue::~MultiCQueue()
{
    DEL_PTR(this->dataCQue);
    DEL_PTR(this->multiCQue);
}


/**  
 *  @brief  写入数据
 *  @param[in] data             数据的指针
 *  @note
 *  
 *  @retval true        -- 成功
 *  @retval false       -- 失败
 *  
 * 
 */
bool MultiCQueue::push(void *data)
{
    if (nullptr == data || nullptr == this->dataCQue)
        return false;
    return this->dataCQue->push(data);
}


/**  
 *  @brief  弹出数据
 *  @note
 *  
 *  @retval void*       -- 数据
 *  @retval NULL        -- 读失败
 *  
 * 
 */
void* MultiCQueue::pop()
{
    if (nullptr == this->dataCQue)
        return nullptr;
    return this->dataCQue->pop();
}


/**  
 *  @brief  放入资源
 *  @param[in] res              资源的指针
 *  @note
 *  
 *  @retval true        -- 成功
 *  @retval false       -- 失败
 *  
 * 
 */
bool MultiCQueue::put(void *res)
{
    if (nullptr == res || nullptr == this->multiCQue)
        return false;
    return this->multiCQue->push(res);
}


/**  
 *  @brief  获取资源
 *  @note
 *  
 *  @retval void*       -- 资源
 *  @retval NULL        -- 读失败
 *  
 * 
 */
void* MultiCQueue::get()
{
    if (nullptr == this->multiCQue)
        return nullptr;
    return this->multiCQue->pop();
}
