
#-----------------------------------------------------------------------------
# PROGRAMMER   : cucudas0127
# REVISION     : 2020.11.03
# DESCRIPTS    : Simple Serial Communication with Queue Function.
# Environment Setting
# OS : ubuntu 18.04
#-----------------------------------------------------------------------------

# if you want using make command
# you have to install cmake
# sudo apt install cmake 

CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )
PROJECT("Serial Communication with Queue")
MESSAGE ( ${CMAKE_PROJECT_NAME} )

SET(  FILES 
      main.c 
      Queue.c 
    )

ADD_EXECUTABLE( withQueue.out ${FILES})
