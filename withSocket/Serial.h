//-----------------------------------------------------------------------------
// PROGRAMMER   : cucudas0127
// REVISION     : 2020.11.03
// DESCRIPTS    : Simple Serial Communication with Queue Function.
// Environment Setting
// OS : ubuntu 18.04
//-----------------------------------------------------------------------------

#ifndef _SERIAL_H_
#define _SERIAL_H_


//  Serial Communication baud rate
/*
    choose your sensors(or board) baud rate and set Vlaue
    |Baud Rate  | Value    | 
    |―――――――――――|――――――――――|
    |115200     | B115200  |
    |57600      | B57600   |
    |38400      | B38400   |
    |19200      | B19200   |
    |9600       | B9600    |
    |4800       | B4800    |
    |2400       | B2400    |
*/

//   Put your Baud Rate Value Right Here
//                       ↓
#define BAUDRATE        B19200


// Global variables (STATIC)
//-----------------------------------------------------------------------------
#define MAX_RX_BUF_SIZE  128
#define MAX_TX_BUF_SIZE  128


int SRL_Init(char *port_name);
int SRL_SendPacket(int com_fd, char* send_packet, int packet_len);
int SRL_Finalize(int comfd);
int SRL_TaskManager(int  com_fd, char* buf, int buf_size);

#endif