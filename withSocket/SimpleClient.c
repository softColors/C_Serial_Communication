//-----------------------------------------------------------------------------
// PROGRAMMER   : cucudas0127
// REVISION     : 2020.11.05
// DESCRIPTS    : Simple Socket Client Code 
// Environment ----------------------------------------------------------------
// OS : ubuntu 18.04
//-----------------------------------------------------------------------------
#include "SimpleClient.h"


#define C_FAIL    -1
#define C_SUCCESS 0

#define MAX_RX_BUF_SIZE  128

// Server's Host Address 
struct sockaddr_in	    HostAddr;                   



typedef struct ServerInfo
{
    char ip[20];
    int  port;
    int  sock_fd;
}server;

ServerInfo server;
//-----------------------------------------------------------------------------
// DESCRIPTS  : Create & Open Socket 
//-----------------------------------------------------------------------------
int OpenSocket_Client(char *ip_addr,int ip_port)
{
    int socket_fd;
    int itmp;
    int vOpt = 1;       // OptVal = TRUE

    // Create TCP/IP Socket & Init
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);           

    if(socket_fd < 0)    return C_FAIL;

    bzero(&HostAddr, sizeof(struct sockaddr_in));

    HostAddr.sin_family      = AF_INET;
    HostAddr.sin_addr.s_addr = inet_addr(ip_addr);
    HostAddr.sin_port        = htons(ip_port);

    itmp = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &vOpt, sizeof(vOpt));

    if(itmp != 0)  return C_FAIL;  
    
    itmp =connect(socket_fd, (struct sockaddr  *)&HostAddr, sizeof(HostAddr));
    if(itmp != 0 ) return C_FAIL;


    // Open Success
    return socket_fd;

}

//-----------------------------------------------------------------------------
// DESCRIPTS  :Send data to server 
//-----------------------------------------------------------------------------
int SendData(int sock_fd, char *tx_buf,int tx_len)
{
    int itmp; 

    // Send Packet
    itmp = send(sock_fd, tx_buf, tx_len, MSG_NOSIGNAL);

    // Check Tx Status
    if(itmp < 0)  return C_FAIL;   
    else          return C_SUCCESS; 
}


//-----------------------------------------------------------------------------
// DESCRIPTS  :Recive data, dodnt wait for data to be received
//-----------------------------------------------------------------------------
int RecivedData_NoWait(int sock_fd, char *rx_buf, int rx_buf_size)
{
    int  	    nData;
    int	      st_socket_size = sizeof(struct sockaddr_in);
    struct    timeval  timeOut;
    fd_set  	readFds ;
    char buf[128];

    memset(rx_buf, 0, rx_buf_size);

    // Set 1ms Timeout counter
    // Just wait 1 msecond and exit
    timeOut.tv_sec  = 0;
    timeOut.tv_usec = 1000;   

    FD_ZERO(&readFds);
    FD_SET(sock_fd, &readFds);


    // if Recivedata Exist
    if(select(sock_fd+1, &readFds, NULL, NULL, &timeOut) > 0) 
    {
        nData = recvfrom(sock_fd, rx_buf, rx_buf_size, 0,
                        (struct sockaddr *)&HostAddr, &st_socket_size);
        return C_SUCCESS;
    }  
    else return C_FAIL;


}

//-----------------------------------------------------------------------------
// Function descripts : Read Buffer,wait for data to be recieved
//-----------------------------------------------------------------------------
void RecivedData_Wait(int sock_fd, char *rx_buf, int rx_buf_size)
{
    if(sock_fd > 0)   read(sock_fd, rx_buf, rx_buf_size);
    
}

//-----------------------------------------------------------------------------
// DESCRIPTS  :Close the Socket
//-----------------------------------------------------------------------------
void CloseSocket(int sock_fd)
{
    if(sock_fd > 0 )              
        close(sock_fd);
}


//-----------------------------------------------------------------------------
// DESCRIPTS  :Init Socket
//-----------------------------------------------------------------------------
# define MIN_IP_ADDR_LEN 7
int Init_Socket(char *ip_addr,int ip_len ,int ip_port)
{
    
    //check config error
    if(ip_addr==NULL) { printf("Sever ip config is empty!\n"); return C_FAIL;}
    if(ip_len < MIN_IP_ADDR_LEN) { printf("Wrong server ip!\n"); return C_FAIL;}
    if(ip_len < 0) { printf("Wrong server port!\n"); return C_FAIL;}
    
    //init gloval variable
    strncpy(server.ip,ip_addr,ip_len);
    server.port = ip_port;
     
    // Socket Open
    sock_fd = OpenSocket_Client(server.ip,server.port);
    if(sock_fd == C_FAIL) { printf("Socket open Error!\n"); return C_FAIL;}
    
    //register socket file discripter
    server.sock_fd = sock_fd;
    return C_SUCCESS;

}
    

//-----------------------------------------------------------------------------
// DESCRIPTS  :Management Socket
//-----------------------------------------------------------------------------
void  Socket_TaskManager(void)
{

    char  rx_buf[MAX_RX_BUF_SIZE] = {0,};
    int   itmp;


    itmp = RecivedData_NoWait(server.sock_fd,rx_buf, MAX_RX_BUF_SIZE);
    if(itmp ==C_SUCCESS)   printf("RxData : %s",rx_buf);
    else                   return ;

}
