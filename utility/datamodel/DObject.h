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
#ifndef _UTILITY_DATAMODEL_DOBJECT_H_
#define _UTILITY_DATAMODEL_DOBJECT_H_

#include <stdio.h>



class DObject
{
protected:
    int                         id = 0;                         // id
    void                        *data = nullptr;                // 绑定的数据
    
public:
    DObject(int id, void *data = nullptr);                      // 构造
    virtual ~DObject();                                         // 析构

    int ID() const;                                             // 获取id
    void* Data() const;                                         // 获取绑定的数据

};



#endif /* _UTILITY_DATAMODEL_DOBJECT_H_ */
