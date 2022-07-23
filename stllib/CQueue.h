/*****************************************************************************
*  @copyright   
*  @file        CQueue.h
*  @brief       容器队列
*  @note
*  分为回收队列与数据队列。且禁止容器队列对象拷贝。
* 
*  @author      Snowgooc
*  @version     1.0.0
*  @date        2022-07-03
*  
*----------------------------------------------------------------------------
*  Remark         : Description
*----------------------------------------------------------------------------
*  Change History :
*  <Date>     | <Version> | <Author>       | <Description>
*----------------------------------------------------------------------------
*  
*****************************************************************************/
#ifndef _STL_LIB_CQUEUE_H_
#define _STL_LIB_CQUEUE_H_

#include "include/def/ComTypedef.h"
#include "include/struct/STLConstructor.h"

using namespace com_stl;


namespace com_stl {


#define CQUEUE_DEF_LEN              255


class CQueue
{
protected:
    uint32_c            length = 0;                             // 长度
    uint32_c            capacity = 0;                           // 容量
    LNode               *dfront = nullptr;                      // 数据队列头
    LNode               *drear = nullptr;                       // 数据队列尾
    LNode               *cfront = nullptr;                      // 回收队列头
    LNode               *crear = nullptr;                       // 回收队列尾

public:
    CQueue(uint32_c size = CQUEUE_DEF_LEN);                     // 构造
    virtual ~CQueue();                                          // 析构
    CQueue(const CQueue &sl) = delete;                          // 禁用复制构造
    CQueue(CQueue &&sl) = delete;                               // 禁用移动复制构造
    CQueue& operator=(const CQueue &sl) = delete;               // 禁用赋值运算符
    CQueue& operator=(CQueue &&sl) = delete;                    // 禁用移动赋值运算符

public:
    void clear();                                               // 清除数据
    bool empty() const;                                         // 是否为空
    uint32_c size() const;                                      // 获取长度
    uint32_c getCapacity() const;                               // 获取可用容量
    bool push(void *data);                                      // 插入元素
    void* front();                                              // 读取头元素
    void* pop();                                                // 弹出头元素并返回

protected:
    bool dpush(LNode *node);                                    // 插入节点到数据队列
    LNode* dpop();                                              // 从数据队列弹出一个节点并返回
    bool cpush(LNode *node);                                    // 插入节点到回收队列
    LNode* cpop();                                              // 从回收队列弹出一个节点并返回

};


}

#endif /* _STL_LIB_CQUEUE_H_ */
