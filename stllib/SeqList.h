/***********************************************************
 **文件名:      SeqList.h
 **功能描述:    顺序表类
 **创建日期:    2022-06-05
 **作者:       
 **版本:        0.1
 **---------------------------------------------------------
 ***********************************************************/
#ifndef _STL_LIB_SEQLIST_H_
#define _STL_LIB_SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "include/def/ComTypedef.h"


#define SL_MAX_LEN          65535


template <class ET>
class SeqList
{
public:
    // 根据长度构造顺序表
    SeqList(uint32_c size = SL_MAX_LEN);

    // 将顺序表按长度复制到新的顺序表
    SeqList(ET e[], uint32_c n, uint32_c size = SL_MAX_LEN);

    // 复制构造函数
    SeqList(const SeqList<ET> &sl);

    // 析构
    virtual ~SeqList();

    // 赋值运算符重载
    SeqList<ET>& operator =(const SeqList<ET> &sl);

public:
    // 清除数据
    void clear();

    // 是否为空
    bool isEmpty() const;

    // 获取长度
    uint32_c getLength() const;

    // 获取容量
    uint32_c getCapacity() const;

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
    uint32_c            maxLength = SL_MAX_LEN;         // 最大长度
    ET                  *elems = nullptr;               // 顺序表

};


#endif /* _STL_LIB_SEQLIST_H_ */
