//-----------------------------------------------------------------------------
// PROGRAMMER   : cucudas0127
// REVISION     : 2020.11.05
// DESCRIPTS    : Simple Socket Client Code 
// Environment ----------------------------------------------------------------
// OS : ubuntu 18.04
//-----------------------------------------------------------------------------

#ifndef _SIMPLECLIENT_H_
#define _SIMPLECLIENT_H_


#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>         // O_WRONLY
#include <unistd.h>        // write(), close()


int  CLT_OpenSocket_Client(char *ip_addr,int ip_port);
int  CLT_SendData(int sock_fd, char *tx_buf,int tx_len);
int  CLT_RecivedData_NoWait(int sock_fd, char *rx_buf, int rx_buf_size);
void CLT_RecivedData_Wait(int sock_fd, char *rx_buf, int rx_buf_size);
void CLT_CloseSocket(int sock_fd);
int  CLT_Init(char *ip_addr,int ip_len ,int ip_port); 
void CLT_TaskManager(int sock_fd);

#endif