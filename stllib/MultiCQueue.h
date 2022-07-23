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
#ifndef _STL_LIB_MULTICQUEUE_H_
#define _STL_LIB_MULTICQUEUE_H_

#include "stllib/CQueue.h"

using namespace com_stl;


namespace com_stl {


class MultiCQueue
{
protected:
    CQueue              *dataCQue = nullptr;                    // 数据队列
    CQueue              *multiCQue = nullptr;                   // 资源队列

public:
    MultiCQueue(uint32_c size = CQUEUE_DEF_LEN);                // 构造
    virtual ~MultiCQueue();                                     // 析构
    MultiCQueue(const MultiCQueue &sl) = delete;                // 禁用复制构造
    MultiCQueue(MultiCQueue &&sl) = delete;                     // 禁用移动复制构造
    MultiCQueue& operator=(const MultiCQueue &sl) = delete;     // 禁用赋值运算符
    MultiCQueue& operator=(MultiCQueue &&sl) = delete;          // 禁用移动赋值运算符

public:
    bool push(void *data);                                      // 写入数据
    void* pop();                                                // 弹出数据
    bool put(void *res);                                        // 放入资源
    void* get();                                                // 获取资源


};


}


#endif /* _STL_LIB_MULTICQUEUE_H_ */
