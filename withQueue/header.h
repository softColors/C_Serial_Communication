
//-----------------------------------------------------------------------------
// PROGRAMMER   : cucudas0127
// REVISION     : 2020.11.03
// DESCRIPTS    : Simple Serial Communication with Queue Function.
// Environment Setting
// OS : ubuntu 18.04
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

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

#define C_FAIL    -1
#define C_SUCCESS  1




#include "Queue.h"
