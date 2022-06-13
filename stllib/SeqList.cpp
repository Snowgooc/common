/***********************************************************
 **文件名:      SeqList.cpp
 **功能描述:    顺序表操作类
 **创建日期:    2022-06-05
 **作者:       
 **版本:        0.1
 **---------------------------------------------------------
 ***********************************************************/
#include "SeqList.h"
#include <string.h>
#include <assert.h>


/***********************************************************
 **函数名:      SeqList
 **输入:        uint32_c size -- 顺序表长度
 **输出:        
 **函数功能:    根据长度构造
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
SeqList<ET>::SeqList(uint32_c size)
{
    this->length = 0;
    this->maxLength = size;
    this->elems = new ET[size];
    assert(this->elems);
}

/***********************************************************
 **函数名:      SeqList
 **输入:        ET e[] -- 需拷贝顺序表
 **输入:        uint32_c n -- 需拷贝顺序表的长度
 **输入:        uint32_c size -- 顺序表长度
 **输出:        
 **函数功能:    将顺序表按长度复制到新的顺序表
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
SeqList<ET>::SeqList(ET e[], uint32_c n, uint32_c size)
{
    this->length = n;
    this->maxLength = size;
    this->elems = new ET[size];
    assert(this->elems);
    memcpy(this->elems, e, sizeof(ET) * n);
}

/***********************************************************
 **函数名:      SeqList
 **输入:        const SeqList<ET> &sl -- 顺序表类
 **输出:        
 **函数功能:    复制构造函数
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
SeqList<ET>::SeqList(const SeqList<ET> &sl)
{
    this->length = sl.length;
    this->maxLength = sl.maxLength;
    this->elems = new ET[sl.maxLength];
    assert(this->elems);
    memcpy(this->elems, sl.elems, sizeof(ET) * sl.length);
}

/***********************************************************
 **函数名:      ~SeqList
 **输入:        
 **输出:        
 **函数功能:    析构
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
SeqList<ET>::~SeqList()
{
    DEL_ARRAY(this->elems)
}

/***********************************************************
 **函数名:      operator =
 **输入:        const SeqList<ET> &e -- 顺序表类对象
 **输出:        SeqList<ET>& -- 对象自身
 **函数功能:    赋值运算符重载
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
SeqList<ET>& SeqList<ET>::operator =(const SeqList<ET> &sl)
{
    this->length = sl.length;
    this->maxLength = sl.maxLength;
    // 删除旧表
    DEL_ARRAY(this->elems)
    // 再按照sl.maxLength的长度建表
    this->elems = new ET[sl.maxLength];
    assert(this->elems);
    memcpy(this->elems, sl.elems, sizeof(ET) * sl.length);
    return *this;
}

/***********************************************************
 **函数名:      clear
 **输入:        
 **输出:        
 **函数功能:    清除数据
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
void SeqList<ET>::clear()
{
    length = 0;
}

/***********************************************************
 **函数名:      isEmpty
 **输入:        
 **输出:        bool -- true 为空; false 不为空
 **函数功能:    是否为空
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
bool SeqList<ET>::isEmpty() const
{
    return (0 == length);
}

/***********************************************************
 **函数名:      getLength
 **输入:        
 **输出:        uint32_c -- 长度
 **函数功能:    获取长度
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
uint32_c SeqList<ET>::getLength() const
{
    return length;
}

/***********************************************************
 **函数名:      getCapacity
 **输入:        
 **输出:        uint32_c -- 容量
 **函数功能:    获取容量
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
uint32_c SeqList<ET>::getCapacity() const
{
    return maxLength;
}

/***********************************************************
 **函数名:      getElem
 **输入:        uint32_c i -- 位置
 **输入(输出):  ET &e -- 读取到的元素值
 **输出:        bool -- true 成功; false 是吧
 **函数功能:    按位置读元素
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
bool SeqList<ET>::getElem(uint32_c i, ET &e) const
{
    if (0 == i || i > length) 
        return false;
    e = elems[i - 1];
    return true;
}

/***********************************************************
 **函数名:      setElem
 **输入:        const ET &e -- 数据源
 **输入:        uint32_c i -- 位置
 **输出:        bool -- true 成功; false 是吧
 **函数功能:    按位置修改元素
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
bool SeqList<ET>::setElem(const ET &e, uint32_c i)
{
    if (0 == i || i > length) 
        return false;
    elems[i - 1] = e;
    return true;
}

/***********************************************************
 **函数名:      deleteElem
 **输入:        uint32_c i -- 位置
 **输出:        bool -- true 成功; false 是吧
 **函数功能:    删除该位置元素
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
bool SeqList<ET>::deleteElem(uint32_c i)
{
    if (0 == i || i > length)
        return false;
    // 将数据往前移
    for (uint32_c j = i; j < length; j++)
        elems[j - 1] = elems[j];
    --length;
    return true;
}

/***********************************************************
 **函数名:      insert
 **输入:        const ET &e -- 数据源
 **输出:        bool -- true 成功; false 是吧
 **函数功能:    插入元素
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
bool SeqList<ET>::insert(const ET &e)
{
    return insert(e, length + 1);
}

/***********************************************************
 **函数名:      insert
 **输入:        const ET &e -- 数据源
 **输入:        uint32_c i -- 位置
 **输出:        bool -- true 成功; false 是吧
 **函数功能:    按位置插入元素
 **作者:        
 **日期:        2022-06-05
 **版本:        0.1
 ***********************************************************/
template <class ET>
bool SeqList<ET>::insert(const ET &e, uint32_c i)
{
    if (0 == i || i > length + 1 || i > maxLength) 
        return false;
    // 将数据往后移
    for (uint32_c j = length + 1; j > i ; j--)
        elems[j - 1] = elems[j - 2]; 
    elems[i - 1] = e;
    ++length;
    return true;
}


