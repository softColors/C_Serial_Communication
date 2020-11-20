
//-----------------------------------------------------------------------------
// PROGRAMMER   : cucudas0127
// REVISION     : 2020.11.05
// DESCRIPTS    : Simple Serial Communication and Send Server
// Environment Setting
// OS : ubuntu 18.04
//-----------------------------------------------------------------------------


#include "header.h"

// Global variables (STATIC)
//-----------------------------------------------------------------------------
//=============================================================================








void main(void)
{

    //---------------------Config--------------------
    // Enter Server IP 
    char* server_addr = "127.0.0.1";
    int   server_port = 8600;
  
    char send_data[MAX_SOCKET_TX_LEN];
  
    //-------------------
    // Config Serial Port
    char* port_name = "/dev/ttyS3";

    // Config Send Packet
    char  send_packet[MAX_SERIAL_Tx_LEN] = {0x01,0x02,0x03};
    int   send_packet_len = 3;


    // if you want changing rx_buf size 
    // you can config {MAX_RX_BUF_SIZE} in header.h
    // Default rxbuf size : 128
    //================================================
    int itmp, check; 
    int com_fd,sock_fd ; 
    char serial_rx_buf[MAX_RX_BUF_SIZE];

    // Init System
    sock_fd = CLT_Init(server_addr,strlen(server_addr),server_port);
    com_fd  = SRL_Init(port_name);

    if(sock_fd !=C_FAIL && com_fd !=C_FAIL) 
    {
        for(itmp = 0; itmp < 5 ; itmp ++)
        {
        // Send Packet to sensor
        check = SRL_SendPacket(com_fd,send_packet,send_packet_len);
        if(check ==C_SUCCESS) 
            printf("Send Serial Packet Success..\n");
        
        //Recive Packet from sensor
        check = SRL_TaskManager(com_fd, serial_rx_buf,MAX_RX_BUF_SIZE);

        // Send serial data to server
        if(check == TRUE)
            CLT_SendData(sock_fd, serial_rx_buf, strlen(serial_rx_buf));

        //delay
        sleep(2);

        }
    }

    


    // Colse serial port
    itmp = SRL_Finalize(com_fd);
    //if(itmp ==C_SUCCESS ) printf("Serial Port Close Success..\n");

    // Socket Close
    CLT_CloseSocket(sock_fd);
}