/*****************************************************************************
*  @copyright   
*  @file        ComTypedef.h
*  @brief       通用数据类型
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
#ifndef _INCLUDE_DEF_COMTYPEDEF_H_
#define _INCLUDE_DEF_COMTYPEDEF_H_

#include <stdio.h>
#include <stdlib.h>



#define DEL_PTR(p)              if (nullptr != p) { delete p; p = nullptr;}
#define DEL_ARRAY(p)            if (nullptr != p) { delete []p; p = nullptr;}



typedef char                    int8_c;
typedef unsigned char           uint8_c;
typedef short                   int16_c;
typedef unsigned short          uint16_c;
typedef int                     int32_c;
typedef unsigned int            uint32_c;
typedef long long               int64_c;
typedef unsigned long long      uint64_c;





#endif /* _INCLUDE_DEF_COMTYPEDEF_H_ */
