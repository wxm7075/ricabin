//! @file net_thread.h
#ifndef _NET_THREAD_H_
#define _NET_THREAD_H_

#include "hc_thread.h"

class net_messenger;
class ireactor;

//! @class net_thread
//! @brief 网络处理线程
//!
//! 此线程负责网络数据的收发, 网络通道超时检查, 将待发送数据放入各网络通道的待发送队列
class net_thread : public threadc
{
public:
    //! 构造函数
    //! @param net_messenger 网络管理器
    //! @param reactor 反应器
    net_thread(net_messenger* nm, ireactor* nrc);
    virtual ~net_thread();

public:
    //! 启动线程
    int start();
    //! 停止线程
    int stop();
    //! 线程函数
    virtual int svc();

private:
    //! 运行状态
    volatile bool m_is_run_;
    //! 停止通知
    volatile bool m_notify_stop_;
    //! 网络管理器
    net_messenger* m_net_messenger_;
    //! 反应器
    ireactor* m_reactor_;
};


#endif // _NET_THREAD_H_
