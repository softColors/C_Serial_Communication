
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
    // Config Serial Port
    char* port_name = "/dev/ttyS3";

    // Config Send Packet
    char  send_packet[MAX_TX_BUF_SIZE] = {0x01,0x02,0x03};
    int   send_packet_len = 3;

    // if you want changing rx_buf size 
    // you can config {MAX_RX_BUF_SIZE} in header.h
    // Default rxbuf size : 128
    //================================================

    SRL_



}