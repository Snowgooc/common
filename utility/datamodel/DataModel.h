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
#ifndef _UTILITY_DATAMODEL_DATAMODEL_H_
#define _UTILITY_DATAMODEL_DATAMODEL_H_

#include <stdio.h>
#include <map>
#include <memory>
#include <string>
#include "DObject.h"


class DataModel
{
protected:
    std::map<int, DObject *>    map_models;                     // 模型对象列表
    
public:
    DataModel();                                                // 构造
    virtual ~DataModel();                                       // 析构

    std::size_t size() const;                                   // 获取模型对象数
    virtual DObject* create(int id, void *data = nullptr) = 0;  // 创建一个模型对象
    void regist(DObject *obj);                                  // 模型对象登记
    DObject* get(int id);                                       // 获取该id的模型对象
    void cancel(int id);                                        // 删除该id的模型对象
    void cancel();                                              // 删除所有模型对象

};



/**
 *  @brief 定义该type模型
 *  @note
 * 
 */
#define DEF_DATAMODEL(type) \
class type##DataModel : public DataModel \
{ \
public: \
    static DataModel* getInstance() \
    { \
        static std::unique_ptr<DataModel> instance; \
        if (nullptr == instance.get()) \
            instance.reset(new type##DataModel()); \
        return instance.get(); \
    } \
    virtual DObject* create(int id, void *data = nullptr) \
    { \
        DObject *tmp = new type(id, data); \
        if (nullptr == tmp) \
            return nullptr; \
        regist(tmp); \
        return tmp; \
    } \
};



/**
 *  @brief 获取该type模型的单例
 *  @note
 * 
 */
#define GET_DATAMODEL(type) type##DataModel::getInstance()
























#endif /* _UTILITY_DATAMODEL_DATAMODEL_H_ */
