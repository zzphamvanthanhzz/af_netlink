/* 
 * File:   common.h
 * Author: thanhpv
 *
 * Created on October 20, 2015, 11:33 PM
 */

#ifndef COMMON_H
#define	COMMON_H


//Kernel TCP states. /include/net/tcp_states.h
//11 TCP states
enum{
    TCP_ESTABLISHED = 1,
    TCP_SYN_SENT,
    TCP_SYN_RECV,
    TCP_FIN_WAIT1,
    TCP_FIN_WAIT2,
    TCP_TIME_WAIT,
    TCP_CLOSE,
    TCP_CLOSE_WAIT,
    TCP_LAST_ACK,
    TCP_LISTEN,
    TCP_CLOSING 
};



#endif	/* COMMON_H */

