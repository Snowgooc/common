/*****************************************************************************
*  @copyright   
*  @file        SeqList.cpp
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
#include "SeqList.h"
#include <string.h>



/**  
 *  @brief  根据容量构造
 *  @param[in] size             顺序表长度
 *  @note
 *  
 *  @return
 *  
 */
template <class ET>
SeqList<ET>::SeqList(uint32_c size)
{
    this->length = 0;
    this->maxLength = size;
    this->elems = new ET[size];
}


/**  
 *  @brief  顺序表按长度构造
 *  @param[in] e[]          拷贝源顺序表
 *  @param[in] n            拷贝源顺序表的长度
 *  @param[in] size         顺序表容量
 *  @note
 *  
 *  @return
 *  
 */
template <class ET>
SeqList<ET>::SeqList(ET e[], uint32_c n, uint32_c size)
{
    this->length = n;
    this->maxLength = size;
    this->elems = new ET[size];
    memcpy(this->elems, e, sizeof(ET) *  n);
}


/**  
 *  @brief  复制构造
 *  @param[in] sl           顺序表对象
 *  @note
 *  
 *  @return
 *  
 */
template <class ET>
SeqList<ET>::SeqList(const SeqList<ET> &sl)
{
    this->length = sl.length;
    this->maxLength = sl.maxLength;
    this->elems = new ET[sl.maxLength];
    memcpy(this->elems, sl.elems, sizeof(ET) *  sl.length);
}


/**  
 *  @brief  移动复制构造
 *  @param[in] sl           顺序表对象
 *  @note
 *  
 *  @return
 *  
 */
template <class ET>
SeqList<ET>::SeqList(SeqList<ET> &&sl)
{
    this->length = sl.length;
    this->maxLength = sl.maxLength;
    this->elems = sl.elems;
    sl.elems = nullptr;
    sl.length = 0;
    sl.maxLength = 0;
}


/**  
 *  @brief  析构
 *  @param[in]
 *  @note
 *  
 *  @return
 *  
 */
template <class ET>
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
template <class ET>
SeqList<ET>& SeqList<ET>::operator=(const SeqList<ET> &sl)
{
    this->length = sl.length;
    this->maxLength = sl.maxLength;
    DEL_ARRAY(this->elems);
    this->elems = new ET[sl.maxLength];
    memcpy(this->elems, sl.elems, sizeof(ET) *  sl.length);
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
template <class ET>
SeqList<ET>& SeqList<ET>::operator=(SeqList<ET> &&sl)
{
    this->length = sl.length;
    this->maxLength = sl.maxLength;
    DEL_ARRAY(this->elems);
    this->elems = sl.elems;
    sl.elems = nullptr;
    sl.length = 0;
    sl.maxLength = 0;
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
template <class ET>
ET& SeqList<ET>::operator[](const uint32_c i)
{
    return at(i);
}


/**  
 *  @brief  清除数据
 *  @param[in]
 *  @note
 *  
 *  @return
 *  
 */
template <class ET>
void SeqList<ET>::clear()
{
    length = 0;
}


/**  
 *  @brief  是否为空
 *  @param[in]
 *  @note
 *  
 *  @retval true    -- 为空
 *  @retval false   -- 不为空
 *  
 */
template <class ET>
bool SeqList<ET>::isEmpty() const
{
    return (0 == length);
}


/**  
 *  @brief  获取长度
 *  @param[in]
 *  @note
 *  
 *  @return 
 *  长度
 *  
 */
template <class ET>
uint32_c SeqList<ET>::getLength() const
{
    return length;
}


/**  
 *  @brief  获取容量
 *  @param[in]
 *  @note
 *  
 *  @return 
 *  容量
 *  
 */
template <class ET>
uint32_c SeqList<ET>::getCapacity() const
{
    return maxLength;
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
template <class ET>
ET& SeqList<ET>::at(uint32_c i) const
{
    return elems[i];
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
template <class ET>
const ET* SeqList<ET>::getElem(uint32_c i) const
{
    if (0 == i || i > length)
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
template <class ET>
bool SeqList<ET>::setElem(const ET &e, const uint32_c i)
{
    if (0 == i || i > length) 
        return false;
    memcpy(&elems[i - 1], &e, sizeof(ET));
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
template <class ET>
bool SeqList<ET>::deleteElem(uint32_c i)
{
    if (0 == i || i > length)
        return false;
    // 将数据往前移
    for (uint32_c j = i; j < length; j++)
        memcpy(&elems[j - 1], &elems[j], sizeof(ET));
    --length;
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
template <class ET>
bool SeqList<ET>::insert(const ET &e)
{
    return insert(e, length + 1);
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
template <class ET>
bool SeqList<ET>::insert(const ET &e, const uint32_c i)
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


