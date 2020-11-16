
#-----------------------------------------------------------------------------
# PROGRAMMER   : cucudas0127
# REVISION     : 2020.11.03
# DESCRIPTS    : Simple Serial Communication with Queue Function.
# Environment Setting
# OS : ubuntu 18.04
#-----------------------------------------------------------------------------

# if you want using make command
# you have to install cmake
# sudo apt install make 


CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )
PROJECT("Serial Communication with Socket")

SET(  FILES 
      main.c 
      Queue.c 
      Serial.c
      SimpleClient.c
    )

ADD_EXECUTABLE( withSocket.out ${FILES})
ADD_EXECUTABLE( TestServer.out SimpleServer.c)
