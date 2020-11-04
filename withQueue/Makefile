
#-----------------------------------------------------------------------------
# PROGRAMMER   : cucudas0127
# REVISION     : 2020.11.03
# DESCRIPTS    : Simple Serial Communication with Queue Function.
# Environment Setting
# OS : ubuntu 18.04
#-----------------------------------------------------------------------------

# if you want using make command
# you have to install make
# sudo apt-get install make 


CC = gcc
CFLAGS=-o -c
OBJS=main.o Queue.o
TARGET=withQueue.out

all: $(TARGET)

clean:		
	rm *.o   
	rm $(TARGET)  

$(TARGET): $(OBJS)
	$(CC) $(TARGET) $(OBJS)


main.o: main.c 
Queue.o: Queue.c


 