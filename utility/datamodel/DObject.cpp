/*****************************************************************************
*  @copyright   
*  @file        DObject.h
*  @brief       数据模型父类
*  @note
*  
*  @author      Snowgooc
*  @version     1.0.0
*  @date        2022-07-30
*  
*----------------------------------------------------------------------------
*  Remark         : Description
*----------------------------------------------------------------------------
*  Change History :
*  <Date>     | <Version> | <Author>       | <Description>
*----------------------------------------------------------------------------
*  
*****************************************************************************/
#include "DObject.h"



/**
 *  @brief 构造
 *  @param[in] id               id
 *  @param[in] data             绑定数据
 *  @note
 * 
 */
DObject::DObject(int id, void *data)
{
    this->id = id;
    if (nullptr != data)
        this->data = data;
}


/**
 *  @brief 析构
 *  @note
 * 
 */
DObject::~DObject()
{

}


/**
 *  @brief 获取id
 *  @note
 * 
 *  @return id
 * 
 */
int DObject::ID() const
{
    return id;
}


/**
 *  @brief 获取绑定的数据
 *  @note
 * 
 *  @retval void*       -- 绑定的数据指针
 *  @retval NULL        -- 空
 * 
 */
void* DObject::Data() const
{
    return data;
}