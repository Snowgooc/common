/*****************************************************************************
*  @copyright   
*  @file        ICommAPT.h
*  @brief       Socket通讯协议接口
*  @note
*  
*  @author      Snowgooc
*  @version     1.0.0
*  @date        2022-07-17
*  
*----------------------------------------------------------------------------
*  Remark         : Description
*----------------------------------------------------------------------------
*  Change History :
*  <Date>     | <Version> | <Author>       | <Description>
*----------------------------------------------------------------------------
*  
*****************************************************************************/
#ifndef _UTILITY_SOCKET_I_COMMAPI_H_
#define _UTILITY_SOCKET_I_COMMAPI_H_



/**
 *  @brief 协议结构体
 * 
 */
typedef struct Communication_t
{
    int             port;                       // 端口
    char            ip[32];                     // ip
    char            lacal_ip[32];               // 本地ip
} Communication_t;



/**
 *  @brief 通讯协议接口
 * 
 */
class ICommAPI
{
public:
    ICommAPI() = default;
    virtual ~ICommAPI() = default;

    virtual int recv() = 0;                     // 接收数据
    virtual int send() = 0;                     // 发送数据

};



#endif /* _UTILITY_SOCKET_I_COMMAPI_H_ */
