/*****************************************************************************
*  @copyright   
*  @file        STLConstructor.h
*  @brief       STL结构体
*  @note
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
#ifndef _INCLUDE_STRUCT_STL_CONSTRUCTOR_H_
#define _INCLUDE_STRUCT_STL_CONSTRUCTOR_H_

#include <stdio.h>
#include <stdlib.h>


namespace com_stl {


/**  @brief 单链表结构体  */
typedef struct LNode {
    void            *data;              // 数据
    LNode           *next;              // 下一个节点
} LNode;







}


#endif /* _INCLUDE_STRUCT_STL_CONSTRUCTOR_H_ */
