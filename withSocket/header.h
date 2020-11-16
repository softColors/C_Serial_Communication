
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

#define MAX_SOCKET_TX_LEN 128
#define MAX_SOCKET_RX_LEN 128

#define MAX_SERIAL_Tx_LEN 128
#define MAX_SERIAL_Rx_LEN 128


#define C_FAIL    -1
#define C_SUCCESS  1



#include "Serial.h"
#include "Queue.h"
#include "SimpleClient.h"
