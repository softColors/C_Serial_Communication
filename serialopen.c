int Open_SerialPort(char *portname, int baudrate, int datalen, int )
{
	int tty_fd;
	struct termios newtio;



	tty_fd = open(PortName[port_num], O_RDWR | O_NOCTTY);
	if(tty_fd < 0)
	{
		LOG_Error_Handler(ERR_CODE_OPEN_SERIAL,port_num ,PortName[port_num],0);
        return FAIL;
	}
	memset( &newtio, 0, sizeof(newtio));

	//newtio.c_cflag = B115200 | CS8 | CLOCAL | CREAD | CRTSCTS;
	//newtio.c_iflag = IGNPAR;

    newtio.c_cflag = CLOCAL | CREAD | CRTSCTS;


	switch(Cnfg.Port[port_num].Srl.Baudrate)
	{
		case 1  : 
			newtio.c_cflag |= B115200;
			printf("## Port %d, Baudrate B115200\n",port_num);

			break;
		case 2  :
			newtio.c_cflag |= B57600;//INPCK
			printf("## Port %d, Baudrate B57600\n",port_num);

			break;
		case 3  : 
			newtio.c_cflag |= B38400; 
			printf("## Port %d, Baudrate B38400\n",port_num);

			break;
		case 4  : 
			newtio.c_cflag |= B19200; 
			printf("## Port %d, Baudrate B19200\n",port_num);

			break;
		case 5  : 
			newtio.c_cflag |= B9600; 
			printf("## Port %d, Baudrate B9600\n",port_num);

			break;
		case 6  : 
			newtio.c_cflag |= B4800; 
			printf("## Port %d, Baudrate B4800\n",port_num);

			break;
		case 7  : 
			newtio.c_cflag |= B1200; 
			printf("## Port %d, Baudrate B1200\n",port_num);
			break;
		default :

			LOG_Error_Handler(ERR_CODE_BAUDRATE_SERIAL,port_num,PortName[port_num],0);
			close(tty_fd);
			return FAIL;
	}

	newtio.c_cflag &= ~CSIZE;

	// Data Len
	switch(Cnfg.Port[port_num].Srl.DataLen)
	{
		case 1  : // Data Len 8
			newtio.c_cflag |= CS8;
			printf("## Port %d, DataLen CS8\n",port_num);
			break;
		case 2  :/// Data Len 7
			newtio.c_cflag |= CS7;//INPCK
			printf("## Port %d, DataLen CS7\n",port_num);
			break;
		case 3  : // Data Len 6
			newtio.c_cflag |= CS6; // Error
			printf("## Port %d, DataLen CS6\n",port_num);
			break;
		case 4  : // Data Len 5
			newtio.c_cflag |= CS5; // Error
			printf("## Port %d, DataLen CS5\n",port_num);
			break;
		default :
			LOG_Error_Handler(ERR_CODE_DATALEN_SERIAL,port_num,0,0);
			close(tty_fd);
			return FAIL;

	}



	// StopBit
	switch(Cnfg.Port[port_num].Srl.Stop)
	{
		case 1  : //  Set 1 stop bits
			printf("## Port %d, Stop bit 1\n",port_num);
			newtio.c_cflag &= ~CSTOPB ;//INPCK

			break;
		
		case 2  : //  Set two stop bits, rather than one.
			newtio.c_cflag |= CSTOPB ;//INPCK
			printf("## Port %d, Stop bit 2\n",port_num);

			break;
		
		default :

			LOG_Error_Handler(ERR_CODE_STOPBIT_SERIAL,port_num,0,0);
			close(tty_fd);
			return FAIL;
	}

	// Config Parity
	switch(Cnfg.Port[port_num].Srl.Parity)
	{
		case 1  : // Parity Bit None
			//newtio.c_iflag &= ~PARENB;
			//newtio.c_iflag &= ~CSTOPB;
			// newtio.c_iflag &= ~CSIZE;
			// options.c_cflag &= ~PARENB;
            // options.c_iflag &= ~INPCK;
			newtio.c_iflag |= IGNPAR;
			printf("## Port %d, Parity bit None\n",port_num);

			break;
		case 2  :// Parity Bit Even
			newtio.c_cflag |= PARENB;
			newtio.c_cflag &= ~PARODD;
	        newtio.c_iflag |= (INPCK | ISTRIP);
			printf("## Port %d, Parity bit Even\n",port_num);

			break;
		case 3  : // Parity Bit Odd
			newtio.c_cflag |= PARENB;
			newtio.c_cflag |= PARODD;
	        newtio.c_iflag |= (INPCK | ISTRIP);
			printf("## Port %d, Parity bit ODD\n",port_num);

			break;
		default :
			LOG_Error_Handler(ERR_CODE_PARITY_SERIAL,port_num,0,0);
			close(tty_fd);
			return FAIL;

	}

	newtio.c_oflag = 0;

	//set input mode (non-canonical, no echo,.....)
	newtio.c_lflag     = 0;     // LF recive filter unused
	newtio.c_cc[VTIME] = 0;     // inter charater timer unused
	newtio.c_cc[VMIN]  = 0;     // blocking read until 1 character arrives

	tcflush( tty_fd, TCIFLUSH );
	tcsetattr( tty_fd, TCSANOW, &newtio );
	printf( " >> Serial Port %d Opened [%s]\r\n", port_num,PortName[port_num]);

	// Serial Q  Init
	return tty_fd;
}

