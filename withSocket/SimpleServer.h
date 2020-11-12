//-----------------------------------------------------------------------------
// PROGRAMMER   : cucudas0127
// REVISION     : 2020.11.10
// DESCRIPTS    : Simple Socket Server Code  
// Environment ----------------------------------------------------------------
// OS : ubuntu 18.04
//-----------------------------------------------------------------------------
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>         // O_WRONLY
#include <unistd.h>        // write(), close()
#include <netinet/in.h>

int SendData(int sock_fd, char *tx_buf,int tx_len);
void RecivedData_Wait(int sock_fd, char *rx_buf, int rx_buf_size);
int RecivedData_NoWait(int sock_fd, char *rx_buf, int rx_buf_size);
int OpenSocket_Server(struct sockaddr_in st_server, int ip_port);
int AcceptClient(int sock_fd);



