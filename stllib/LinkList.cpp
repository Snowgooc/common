/***********************************************************
 **文件名:      LinkList.h
 **功能描述:    单链表类
 **创建日期:    2022-06-11
 **作者:       
 **版本:        0.1
 **---------------------------------------------------------
 ***********************************************************/
#include "LinkList.h"
#include <string.h>
#include <assert.h>


/***********************************************************
 **函数名:      LinkList
 **输入:        
 **输出:        
 **函数功能:    构造
 **作者:        
 **日期:        2022-06-11
 **版本:        0.1
 ***********************************************************/
template <class ET>
LinkList<ET>::LinkList()
{
    this->length = 0;
    this->head = new LL_NODE<ET>;
    assert(this->head);
}

/***********************************************************
 **函数名:      LinkList
 **输入:        const LinkList<ET> &ll -- 拷贝源
 **输出:        
 **函数功能:    复制构造函数
 **作者:        
 **日期:        2022-06-11
 **版本:        0.1
 ***********************************************************/
template <class ET>
LinkList<ET>::LinkList(const LinkList<ET> &ll)
{
    this->length = 0;
    this->head = new LL_NODE<ET>;
    assert(this->head);
    // 数据拷贝
    LL_NODE<ET> *lp = ll.head->next;
    LL_NODE<ET> *hp = this->head;
    while (lp)
    {
        hp->next = new LL_NODE<ET>;         // 将新结点链接到末尾
        assert(hp->next);
        memcpy(&hp->next->data, &lp->data, sizeof(hp->next->data));
        hp->next->next = nullptr;
        hp = hp->next; 
        ++this->length;                             // 长度+1
        lp = lp->next; 
    }
}

/***********************************************************
 **函数名:      ~LinkList
 **输入:        
 **输出:        
 **函数功能:    析构
 **作者:        
 **日期:        2022-06-11
 **版本:        0.1
 ***********************************************************/
template <class ET>
LinkList<ET>::~LinkList()
{
    LL_NODE<ET> *p = this->head->next;
    while (p)
    {
        LL_NODE<ET> *temp = p;
        p = p->next;
        DEL_PTR(temp)
    }
    DEL_PTR(this->head)
}

/***********************************************************
 **函数名:      operator =
 **输入:        const LinkList<ET> &ll -- 数据源
 **输出:        
 **函数功能:    赋值运算符重载
 **作者:        
 **日期:        2022-06-11
 **版本:        0.1
 ***********************************************************/
template <class ET>
LinkList<ET>& LinkList<ET>::operator =(const LinkList<ET> &ll)
{
    // 数据拷贝
    LL_NODE<ET> *p = ll.head->next;
    while (p)
    {
        this->rear->next = new LL_NODE<ET>;         // 将新结点链接到末尾
        assert(this->rear->next);
        memcpy(&this->rear->next->data, &p->data, sizeof(this->rear->next->data));
        this->rear->next->next = nullptr;   
        ++this->length;                             // 长度+1
        p = p->next; 
    }
    return *this;
}

/***********************************************************
 **函数名:      clear
 **输入:        
 **输出:        
 **函数功能:    清除数据
 **作者:        
 **日期:        2022-06-11
 **版本:        0.1
 ***********************************************************/
template <class ET>
void LinkList<ET>::clear()
{
    LL_NODE<ET> *p = this->head->next;
    while (p)
    {
        LL_NODE<ET> *temp = p;
        p = p->next;
        DEL_PTR(temp)
    }
    length = 0;
    head->next = nullptr;
    rear = this->head;
}

/***********************************************************
 **函数名:      isEmpty
 **输入:        
 **输出:        
 **函数功能:    是否为空
 **作者:        
 **日期:        2022-06-11
 **版本:        0.1
 ***********************************************************/
template <class ET>
bool LinkList<ET>::isEmpty() const
{
    return (nullptr == head->next)
}

/***********************************************************
 **函数名:      getLength
 **输入:        
 **输出:        
 **函数功能:    获取长度
 **作者:        
 **日期:        2022-06-11
 **版本:        0.1
 ***********************************************************/
template <class ET>
uint32_c LinkList<ET>::getLength() const
{
    return length;
}

/***********************************************************
 **函数名:      getLength
 **输入:        uint32_c i -- 位置
 **输入(输出):  ET &e -- 读取到的元素值
 **输出:        bool -- true 成功; false 失败
 **函数功能:    按位置读元素
 **作者:        
 **日期:        2022-06-11
 **版本:        0.1
 ***********************************************************/
template <class ET>
bool LinkList<ET>::getElem(uint32_c i, ET &e) const
{
    if (0 == i || i > length)
        return false;
    LL_NODE<ET> *p = head->next;
    for (uint32_c j = 1; j < i; j++)
        p = p->next;
    memccpy(&e, &p->data, sizeof(e));
    return true;
}

/***********************************************************
 **函数名:      setElem
 **输入:        const ET &e -- 数据源
 **输入:        uint32_c i -- 位置
 **输出:        bool -- true 成功; false 失败
 **函数功能:    按位置修改元素
 **作者:        
 **日期:        2022-06-11
 **版本:        0.1
 ***********************************************************/
template <class ET>
bool LinkList<ET>::setElem(const ET &e, uint32_c i)
{
    if (0 == i || i > length)
        return false;
    LL_NODE<ET> *p = head->next;
    for (uint32_c j = 1; j < i; j++)
        p = p->next;
    memccpy(&p->data, &e, sizeof(p->data));
    return true;
}

/***********************************************************
 **函数名:      deleteElem
 **输入:        uint32_c i -- 位置
 **输出:        bool -- true 成功; false 失败
 **函数功能:    删除该位置元素
 **作者:        
 **日期:        2022-06-11
 **版本:        0.1
 ***********************************************************/
template <class ET>
bool LinkList<ET>::deleteElem(uint32_c i)
{
    if (0 == i || i > length)
        return false;
    LL_NODE<ET> *p = head->next;
    for (uint32_c j = 1; j < i; j++)
        p = p->next;
    memccpy(&p->data, &e, sizeof(p->data));
    return true;
}

// 插入元素
template <class ET>
bool LinkList<ET>::insert(const ET &e)
{

}

// 按位置插入元素
template <class ET>
bool LinkList<ET>::insert(const ET &e, uint32_c i)
{

}

