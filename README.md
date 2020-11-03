# C_Serial_Communication


Serial Communication using C language ( RS-232, RS-485, USB,...,)

## Basic code
it is basic code for serial communication, when only one device is connected.   
The compiler should use **gcc**.

You may have to enter command if program doesn't work even though it is connected to the device.   
```
chmod 777 {Enter your serial port like '/dev/ttyS1'}
```
## withQueue
In this code, the receive buffer is made up of a queue.
This code's the Read function reads and exits the serial buffer only once without waiting for input.   
This method prevents system delay, but it also makes it difficult to find the beginning and end of the received signal.
Therefore, the receive buffer must consist of a queue.


## Multi Drop Mode code
