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


// typedef struct Node {
//     void            *data;              // 数据
//     Node            *next;              // 下一个节点
// } Node;


// class LinkList
// {
// protected:
//     uint32_c            length = 0;                             // 长度
//     Node                *head = nullptr;                        // 头节点
//     Node                *tail = nullptr;                        // 尾节点

// public:
//     LinkList();                                                 // 构造
//     LinkList(const LinkList &ll);                               // 复制构造
//     LinkList(LinkList &&ll);                                    // 移动复制构造
//     virtual ~LinkList();                                        // 析构
//     LinkList& operator=(const LinkList &ll);                    // 赋值运算符
//     LinkList& operator=(LinkList &&ll);                         // 移动赋值运算符
//     void* operator[](const uint32_c i);                         // 下标运算符

// public:
//     void clear();                                               // 清除数据
//     bool empty() const;                                       // 是否为空
//     uint32_c size() const;                                 // 获取长度
//     void* at(uint32_c i) const;                                 // 按下标读元素
//     const void* getElem(uint32_c i) const;                      // 按位置读元素
//     bool delElem(const uint32_c i);                          // 删除该位置元素
//     bool insert(const void *e);                                 // 插入元素
//     bool insert(const void *e, const uint32_c i);               // 按位置插入元素

// };


// }

// #endif /* _STL_LIB_QUEUE_H_ */
