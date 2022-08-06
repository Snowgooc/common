/*****************************************************************************
*  @copyright   
*  @file        DataModel.h
*  @brief       数据模型类
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
#include "DataModel.h"



/**
 *  @brief 构造
 *  @note
 * 
 */
DataModel::DataModel()
{
    map_models.clear();
}


/**
 *  @brief 析构
 *  @note
 * 
 */
DataModel::~DataModel()
{
    cancel();
}


/**
 *  @brief 获取模型对象数
 *  @note
 * 
 *  @return 模型对象数
 * 
 */
std::size_t DataModel::size() const
{
    return map_models.size();
}


/**
 *  @brief 模型对象登记
 *  @param[in] obj              对象指针
 *  @note
 *  如果该id的对象已存在，则删除并覆盖
 * 
 *  @return void
 * 
 */
void DataModel::regist(DObject *obj)
{
    if (obj)
    {
        cancel(obj->ID());
        map_models.insert(std::make_pair(obj->ID(), obj));
    }
}


/**
 *  @brief 获取该id的模型对象
 *  @param[in] id               id
 *  @note
 * 
 *  @retval *        -- 该id的模型对象指针
 *  @retval nullptr  -- 空
 * 
 */
DObject* DataModel::get(int id)
{
    if (map_models.find(id) != map_models.end())
        return map_models[id];
    
    return nullptr;
}


/**
 *  @brief 删除该id的模型对象
 *  @param[in] id           id
 *  @note
 *  
 *  @return void
 * 
 */
void DataModel::cancel(int id)
{
    if (map_models.find(id) != map_models.end())
    {
        if (nullptr != map_models[id])
            delete map_models[id];
        map_models.erase(id);
    }
}


/**
 *  @brief 删除所有模型对象
 *  @note
 *  
 *  @return void
 * 
 */
void DataModel::cancel()
{
    for (auto it : map_models)
    {
        if (nullptr != it.second)
            delete it.second;
    }
    map_models.clear();
}


