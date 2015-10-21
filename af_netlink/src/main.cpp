/* 
 * File:   main.cpp
 * Author: thanhpv
 *
 * Created on October 20, 2015, 9:58 PM
 */

#include <cstdlib>
#include <string.h>//for memset
#include <linux/inet_diag.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

#include "common.h"

#define TCPF_ALL 0xFFF
#define SOCKET_BUFFER_SIZE (getpagesize() < 8192L ? getpagesize() : 8192L)

using namespace std;

/*
 * 
 */
void showbits(unsigned int x) {
	int i;
	for (int i = (sizeof (int)*8) / 2; i >= 0; i--) {
		(x & (1 << i)) ? putchar('1') : putchar('0');
	}
	printf("\n");
}

bool parse_msg_diag(struct inet_diag_msg *diag_msg, int rtalen) {

}

bool send_msg_diag(int sockfd) {
	struct msghdr msg;
	struct nlmsghdr nlh;
	struct inet_diag_req_v2 conn_req;
	struct sockaddr_nl sa;
	struct iovec iov[4];
	int retval = 0;

	//Filter
	struct rtattr rta;
	void *filter_mem = NULL;
	int filter_len = 0;

	memset(&msg, 0, sizeof (msg));
	memset(&sa, 0, sizeof (sa));
	memset(&nlh, 0, sizeof (nlh));
	memset(&conn_req, 0, sizeof (conn_req));

	//init sockaddr_nl
	//sa.nl_pid = 0 means kernel will receive message
	sa.nl_family = AF_NETLINK;

	//Sepcify address family and protocol 
	//can be UDP, DCCP, Unix Socket
	conn_req.sdiag_family = AF_INET; //IPv4
	conn_req.sdiag_protocol = IPPROTO_TCP;

	//Filter only some states:
	//1 << TCP_SYN_RECV: left shift 1 TCP_SYN_RECV bits
	//1 >> TCP_SYN_RECV: right shift 1 TCP_SYN_RECV bits
	conn_req.idiag_states = TCPF_ALL & ~((1 << TCP_SYN_RECV) | (1 << TCP_TIME_WAIT) | (1 << TCP_CLOSE));
}

int main(int argc, char** argv) {
	showbits(~((1 << TCP_SYN_RECV) | (1 << TCP_TIME_WAIT) | (1 << TCP_CLOSE)));
	showbits(((1 << TCP_SYN_RECV) | (1 << TCP_TIME_WAIT) | (1 << TCP_CLOSE)));
	showbits(TCPF_ALL & ~((1 << TCP_SYN_RECV) | (1 << TCP_TIME_WAIT) | (1 << TCP_CLOSE)));
	send_msg_diag(9);
	return 0;
}

