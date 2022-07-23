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
#include "CQueue.h"


using namespace com_stl;



/**  
 *  @brief  构造
 *  @param[in]  size            长度(默认为255)
 *  @note
 *  
 *  
 */
CQueue::CQueue(uint32_c size)
{
    this->dfront = new LNode;
    this->drear = this->dfront;
    this->cfront = new LNode;
    this->crear = this->cfront;
    for (uint32_c i = 0; i < size; i++)
    {
        cpush(new LNode);
    }
}


/**  
 *  @brief  析构
 *  @note
 *  
 *  
 */
CQueue::~CQueue()
{
    LNode *tmp = dpop();
    while (tmp)
    {
        DEL_PTR(tmp);
        tmp = dpop();
    }
    DEL_PTR(this->dfront);
    this->drear = nullptr;

    tmp = cpop();
    while (tmp)
    {
        DEL_PTR(tmp);
        tmp = cpop();
    }
    DEL_PTR(this->cfront);
    this->crear = nullptr;
}


/**  
 *  @brief  清除数据
 *  @note
 *  
 *  @return
 *  void
 *  
 */
void CQueue::clear()
{
    LNode *tmp = dpop();
    while (tmp)
    {
        cpush(tmp);
        tmp = dpop();
    }
}


/**  
 *  @brief  是否为空
 *  @note
 *  
 *  @retval true    -- 为空
 *  @retval false   -- 非空
 *  
 */
bool CQueue::empty() const
{
    return (this->drear == this->dfront);
}


/**  
 *  @brief  获取长度
 *  @note
 *  
 *  @return
 *  长度
 *  
 */
uint32_c CQueue::size() const
{
    return this->length;
}


/**  
 *  @brief  获取可用容量
 *  @note
 *  
 *  @return
 *  可用容量
 *  
 */
uint32_c CQueue::getCapacity() const
{
    return this->capacity;
}


/**  
 *  @brief  插入元素
 *  @param[in]  data            节点
 *  @note
 *  
 *  @retval true    -- 成功
 *  @retval false   -- 失败
 *  
 */
bool CQueue::push(void *data)
{
    if (data)
    {
        LNode *tmp = cpop();
        if (nullptr == tmp)
        {
            tmp = new LNode;
            if (nullptr == tmp)
                return false;
        }
        tmp->data = data;
        return dpush(tmp);
    }
    return false;
}


/**  
 *  @brief  读取头元素
 *  @note
 *  
 *  @retval void*   -- 读取成功
 *  @retval NULL    -- 读取失败
 *  
 */
void* CQueue::front()
{
    if (!empty())
    {
        LNode *tmp = this->dfront->next;
        return tmp->data;
    }
    return nullptr;
}


/**  
 *  @brief  弹出头元素并返回
 *  @note
 *  
 *  @retval void*   -- 读取成功
 *  @retval NULL    -- 读取失败
 *  
 */
void* CQueue::pop()
{
    LNode *tmp = dpop();
    if (tmp)
    {
        void *dat = tmp->data;
        cpush(tmp);
        return dat;
    }
    return nullptr;
}


/**  
 *  @brief  插入节点到数据队列
 *  @param[in] node             节点
 *  @note
 *  
 *  @retval true    -- 成功
 *  @retval false   -- 失败
 *  
 */
bool CQueue::dpush(LNode *node)
{
    if (node)
    {
        node->next = nullptr;
        this->drear->next = node;
        this->drear = node;
        ++this->length;
        return true;
    }
    return false;
}


/**  
 *  @brief  从数据队列弹出一个节点并返回
 *  @note
 *  
 *  @retval LNode*  -- 取成功
 *  @retval NULL    -- 取失败
 *  
 */
LNode* CQueue::dpop()
{
    if (!empty())
    {
        LNode *tmp = this->dfront->next;
        this->dfront->next = tmp->next;
        if (tmp == this->drear)
            this->drear = this->dfront;
        tmp->next = nullptr;
        --this->length;
        return tmp;
    }
    return nullptr;
}


/**  
 *  @brief  插入节点到回收队列
 *  @param[in] node             节点
 *  @note
 *  
 *  @retval true    -- 成功
 *  @retval false   -- 失败
 *  
 */
bool CQueue::cpush(LNode *node)
{
    if (node)
    {
        node->next = nullptr;
        this->crear->next = node;
        this->crear = node;
        ++this->capacity;
        return true;
    }
    return false;
}


/**  
 *  @brief  从回收队列弹出一个节点并返回
 *  @note
 *  
 *  @retval LNode*  -- 取成功
 *  @retval NULL    -- 取失败
 *  
 */
LNode* CQueue::cpop()
{
    if (this->crear != this->cfront)
    {
        LNode *tmp = this->cfront->next;
        this->cfront->next = tmp->next;
        if (tmp == this->crear)
            this->crear = this->cfront;
        tmp->next = nullptr;
        --this->capacity;
        return tmp;
    }
    return nullptr;
}
