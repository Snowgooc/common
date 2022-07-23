/*****************************************************************************
*  @copyright   
*  @file        SeqList.h
*  @brief       顺序表类
*  @note
*  
*  @author      Snowgooc
*  @version     1.0.0
*  @date        2022-06-26
*  
*----------------------------------------------------------------------------
*  Remark         : Description
*----------------------------------------------------------------------------
*  Change History :
*  <Date>     | <Version> | <Author>       | <Description>
*----------------------------------------------------------------------------
*  
*****************************************************************************/
#ifndef _STL_LIB_SEQLIST_H_
#define _STL_LIB_SEQLIST_H_

#include <string.h>
#include "include/def/ComTypedef.h"


namespace com_stl {


#define SEQ_DEF_SIZE          255


template <typename ET>
class SeqList
{
protected:
    uint32_c            length = 0;                             // 长度
    uint32_c            capacity = 0;                           // 容量
    ET                  *elems = nullptr;                       // 顺序表

public:
    SeqList(uint32_c size = SEQ_DEF_SIZE);                      // 根据容量构造
    SeqList(const SeqList<ET> &sl);                             // 复制构造
    SeqList(SeqList<ET> &&sl);                                  // 移动复制构造
    virtual ~SeqList();                                         // 析构
    SeqList<ET>& operator=(const SeqList<ET> &sl);              // 赋值运算符
    SeqList<ET>& operator=(SeqList<ET> &&sl);                   // 移动赋值运算符
    ET& operator[](const uint32_c i);                           // 下标运算符

public:
    void clear();                                               // 清除数据
    bool empty() const;                                         // 是否为空
    uint32_c size() const;                                      // 获取长度
    uint32_c getCapacity() const;                                  // 获取容量
    ET& at(uint32_c i) const;                                   // 按下标读元素
    const ET* getElem(uint32_c i) const;                        // 按位置读元素
    bool setElem(const ET &e, const uint32_c i);                // 按位置修改元素
    bool delElem(const uint32_c i);                             // 删除该位置元素
    bool insert(const ET &e);                                   // 插入元素
    bool insert(const ET &e, const uint32_c i);                 // 按位置插入元素

};


/**  
 *  @brief  根据容量构造
 *  @param[in] size             顺序表长度(默认为255)
 *  @note
 *  默认size为255
 *  
 */
template <typename ET>
SeqList<ET>::SeqList(uint32_c size)
{
    this->length = 0;
    this->capacity = size;
    this->elems = new ET[size];
}


/**  
 *  @brief  复制构造
 *  @param[in] sl           顺序表对象
 *  @note
 *  
 *  
 */
template <typename ET>
SeqList<ET>::SeqList(const SeqList<ET> &sl)
{
    this->length = sl.length;
    this->capacity = sl.capacity;
    this->elems = new ET[sl.capacity];
    ::memcpy(this->elems, sl.elems, sizeof(ET) *  sl.length);
}


/**  
 *  @brief  移动复制构造
 *  @param[in] sl           顺序表对象
 *  @note
 *  
 *  
 */
template <typename ET>
SeqList<ET>::SeqList(SeqList<ET> &&sl)
{
    this->length = sl.length;
    this->capacity = sl.capacity;
    this->elems = sl.elems;
    sl.elems = nullptr;
    sl.length = 0;
    sl.capacity = 0;
}


/**  
 *  @brief  析构
 *  @note
 *  
 *  
 */
template <typename ET>
SeqList<ET>::~SeqList()
{
    DEL_ARRAY(this->elems);
}


/**  
 *  @brief  赋值运算符
 *  @param[in] sl           顺序表对象
 *  @note
 *                          
 *  @return 
 *  对象自身
 *  
 */
template <typename ET>
SeqList<ET>& SeqList<ET>::operator=(const SeqList<ET> &sl)
{
    this->length = sl.length;
    this->capacity = sl.capacity;
    DEL_ARRAY(this->elems);
    this->elems = new ET[sl.capacity];
    ::memcpy(this->elems, sl.elems, sizeof(ET) *  sl.length);
    return *this;
}


/**  
 *  @brief  移动赋值运算符
 *  @param[in] sl           顺序表对象
 *  @note
 *                          
 *  @return 
 *  对象自身
 *  
 */
template <typename ET>
SeqList<ET>& SeqList<ET>::operator=(SeqList<ET> &&sl)
{
    this->length = sl.length;
    this->capacity = sl.capacity;
    DEL_ARRAY(this->elems);
    this->elems = sl.elems;
    sl.elems = nullptr;
    sl.length = 0;
    sl.capacity = 0;
    return *this;
}


/**  
 *  @brief  下标运算符
 *  @param[in] i           下标
 *  @note
 *                          
 *  @return 
 *  指向该元素的引用
 *  
 */
template <typename ET>
ET& SeqList<ET>::operator[](const uint32_c i)
{
    return at(i);
}


/**  
 *  @brief  清除数据
 *  @note
 *  
 *  @return
 *  void
 *  
 */
template <typename ET>
void SeqList<ET>::clear()
{
    this->length = 0;
}


/**  
 *  @brief  是否为空
 *  @note
 *  
 *  @retval true    -- 为空
 *  @retval false   -- 不为空
 *  
 */
template <typename ET>
bool SeqList<ET>::empty() const
{
    return (0 == this->length);
}


/**  
 *  @brief  获取长度
 *  @note
 *  
 *  @return 
 *  长度
 *  
 */
template <typename ET>
uint32_c SeqList<ET>::size() const
{
    return this->length;
}


/**  
 *  @brief  获取容量
 *  @note
 *  
 *  @return 
 *  容量
 *  
 */
template <typename ET>
uint32_c SeqList<ET>::getCapacity() const
{
    return this->capacity;
}


/**  
 *  @brief  按下标读元素
 *  @param[in] i            下标
 *  @note
 *  
 *  @warning 需判断i是否越界
 *  @return 
 *  指向该元素的引用
 *  
 */
template <typename ET>
ET& SeqList<ET>::at(uint32_c i) const
{
    return this->elems[i];
}


/**  
 *  @brief  按位置读元素
 *  @param[in] i           位置
 *  @note
 *  
 *  @retval nullptr -- 获取失败
 *  @retval const*  -- 指向该元素常量的指针
 *  
 */
template <typename ET>
const ET* SeqList<ET>::getElem(uint32_c i) const
{
    if (0 == i || i > this->length)
        return nullptr;
    return &at(i - 1);
}


/**  
 *  @brief  按位置修改元素
 *  @param[in] e           数据源
 *  @param[in] i           位置
 *  @note
 *  
 *  @retval true    -- 修改成功
 *  @retval false   -- 修改失败
 *  
 */
template <typename ET>
bool SeqList<ET>::setElem(const ET &e, const uint32_c i)
{
    if (0 == i || i > this->length) 
        return false;
    ::memcpy(&this->elems[i - 1], &e, sizeof(ET));
    return true;
}


/**  
 *  @brief  删除该位置元素
 *  @param[in] i           位置
 *  @note
 *  
 *  @retval true    -- 删除成功
 *  @retval false   -- 删除失败
 *  
 */
template <typename ET>
bool SeqList<ET>::delElem(uint32_c i)
{
    if (0 == i || i > this->length)
        return false;
    // 将数据往前移
    for (uint32_c j = i; j < this->length; j++)
        ::memcpy(&this->elems[j - 1], &this->elems[j], sizeof(ET));
    --this->length;
    return true;
}


/**  
 *  @brief  插入元素
 *  @param[in] e           数据源
 *  @note
 *  
 *  @retval true    -- 插入成功
 *  @retval false   -- 插入失败
 *  
 */
template <typename ET>
bool SeqList<ET>::insert(const ET &e)
{
    return insert(e, this->length + 1);
}


/**  
 *  @brief  按位置插入元素
 *  @param[in] e           数据源
 *  @param[in] i           位置
 *  @note
 *  
 *  @retval true    -- 插入成功
 *  @retval false   -- 插入失败
 *  
 */
template <typename ET>
bool SeqList<ET>::insert(const ET &e, const uint32_c i)
{
    if (0 == i || i > this->length + 1 || i > this->capacity) 
        return false;
    // 将数据往后移
    for (uint32_c j = this->length + 1; j > i ; j--)
        this->elems[j - 1] = this->elems[j - 2]; 
    this->elems[i - 1] = e;
    ++length;
    return true;
}


}


#endif /* _STL_LIB_SEQLIST_H_ */
