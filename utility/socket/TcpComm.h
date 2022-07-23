/*****************************************************************************
*  @copyright   
*  @file        TcpComm.h
*  @brief       TCP通讯类
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
#ifndef _UTILITY_SOCKET_TCPCOMMUNICATION_H_
#define _UTILITY_SOCKET_TCPCOMMUNICATION_H_

#include <sys/socket.h>
#include <string.h>
#include "utility/socket/ICommAPI.h"





class ITcpFactor : public ICommAPI
{
public:
    ITcpFactor() = default;
    virtual ~ITcpFactor() = default;

    virtual bool connect(Communication_t &commt) = 0;
    virtual bool disconnect() = 0;

};




class TcpComm : public ITcpFactor
{
protected:
    bool                        init_states;
    int                         sock;
    int                         conn;
    struct sockaddr_in          servaddr;
    socklen_t                   len;
    Communication_t             comm;

public:
    TcpComm();                                                  // 构造
    virtual ~TcpComm();                                         // 析构
    TcpComm(const TcpComm &tc) = delete;                        // 禁用复制构造
    TcpComm(TcpComm &&tc) = delete;                             // 禁用移动复制构造
    TcpComm& operator=(const TcpComm &tc) = delete;             // 禁用赋值运算符
    TcpComm& operator=(TcpComm &&tc) = delete;                  // 禁用移动赋值运算符

public:
    virtual bool connect(Communication_t &commt);               // 连接
    virtual bool disconnect();                                  // 关闭连接
    virtual int recv();                                         // 接收数据
    virtual int send();                                         // 发送数据

};



#endif /* _UTILITY_SOCKET_TCPCOMMUNICATION_H_ */
