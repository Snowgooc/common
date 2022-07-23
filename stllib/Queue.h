// /*****************************************************************************
// *  @copyright   
// *  @file        Queue.h
// *  @brief       顺序表类
// *  @note
// *  
// *  @author      Snowgooc
// *  @version     1.0.0
// *  @date        2022-06-26
// *  
// *----------------------------------------------------------------------------
// *  Remark         : Description
// *----------------------------------------------------------------------------
// *  Change History :
// *  <Date>     | <Version> | <Author>       | <Description>
// *----------------------------------------------------------------------------
// *  
// *****************************************************************************/
// #ifndef _STL_LIB_QUEUE_H_
// #define _STL_LIB_QUEUE_H_

// #include <stdio.h>
// #include <stdlib.h>
// #include "include/def/ComTypedef.h"


// namespace com_stl {


// #define QUEUE_DEFAULT_LEN          255

// typedef struct QUEUE_NODE {
//     void            *data;              // 数据
//     QUEUE_NODE      *next;              // 下一个节点
// }QUEUE_NODE;


// class Queue
// {
// protected:
//     uint32_c            length = 0;                             // 长度
//     uint32_c            capacity = QUEUE_DEFAULT_LEN;          // 容量
//     QUEUE_NODE          *top = nullptr;                       // 顺序表

// public:
//     SeqList(uint32_c size = QUEUE_DEFAULT_LEN);                    // 根据容量构造
//     SeqList(ET e[], uint32_c n, uint32_c size = QUEUE_DEFAULT_LEN);// 顺序表按长度构造
//     SeqList(const SeqList<ET> &sl);                             // 复制构造
//     SeqList(SeqList<ET> &&sl);                                  // 移动复制构造
//     virtual ~SeqList();                                         // 析构
//     SeqList<ET>& operator=(const SeqList<ET> &sl);              // 赋值运算符
//     SeqList<ET>& operator=(SeqList<ET> &&sl);                   // 移动赋值运算符
//     ET& operator[](const uint32_c i);                           // 下标运算符

// public:
//     void clear();                                               // 清除数据
//     bool empty() const;                                       // 是否为空
//     uint32_c size() const;                                 // 获取长度
//     uint32_c getCapacity() const;                               // 获取容量
//     ET& at(uint32_c i) const;                                   // 按下标读元素
//     const ET* getElem(uint32_c i) const;                        // 按位置读元素
//     bool setElem(const ET &e, const uint32_c i);                // 按位置修改元素
//     bool delElem(const uint32_c i);                          // 删除该位置元素
//     bool insert(const ET &e);                                   // 插入元素
//     bool insert(const ET &e, const uint32_c i);                 // 按位置插入元素

// };


// }

// #endif /* _STL_LIB_QUEUE_H_ */
