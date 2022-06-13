/***********************************************************
 **文件名:      LinkList.h
 **功能描述:    单链表类
 **创建日期:    2022-06-11
 **作者:       
 **版本:        0.1
 **---------------------------------------------------------
 ***********************************************************/
#ifndef _STL_LIB_LINKLIST_H_
#define _STL_LIB_LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "include/def/ComTypedef.h"



template<class ET>
struct LL_NODE
{
    ET              data;
    LL_NODE<ET>     *next = nullptr;
};


template <class ET>
class LinkList
{
public:
    // 构造
    LinkList();

    // 复制构造函数
    LinkList(const LinkList<ET> &ll);

    // 析构
    virtual ~LinkList();

    // 赋值运算符重载
    LinkList<ET>& operator =(const LinkList<ET> &ll);

public:
    // 清除数据
    void clear();

    // 是否为空
    bool isEmpty() const;

    // 获取长度
    uint32_c getLength() const;

    // 按位置读元素
    bool getElem(uint32_c i, ET &e) const;

    // 按位置修改元素
    bool setElem(const ET &e, uint32_c i);

    // 删除该位置元素
    bool deleteElem(uint32_c i);

    // 插入元素
    bool insert(const ET &e);

    // 按位置插入元素
    bool insert(const ET &e, uint32_c i);

protected:
    uint32_c            length = 0;                     // 长度
    LL_NODE<ET>         *head = nullptr;                // 单链表头

};



#endif /* _STL_LIB_LINKLIST_H_ */
