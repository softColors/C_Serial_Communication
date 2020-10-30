#include<stdio.h>


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
//                      ↓
#define SRL_C_BAUDRATE B19200


void main()
{

    printf("hello World");
    printf("what ever\n");

}