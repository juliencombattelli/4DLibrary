/*
* 4DLibrary.cpp
* This file is a part of 4DLibrary
* Copyright (c) 2015 juliencombattelli, SRTH
*/

#include "4DLibrary.hpp"

4DLibrary::4DLibrary(PinName tx, PinName rx, PinName reset) : serial(tx, rx), rst(reset)
{
	clear_rx_buffer();
}

/*
* private function
*/

void 4DLibrary::clear_rx_buffer()
{
	while(serial.readable())
	{
		serial.getc();
	}
}

void 4DLibrary::write_commande(unsigned char* cmd, unsigned char size)
{
	for(unsigned char i = 0; i < size; i++)
	{
		while (!serial.writeable());
		serial.putc(cmd[i]);
	}
}

void 4DLibrary::read_commande(unsigned char* cmd, unsigned char size)
{
	for(unsigned char i = 0; i < size; i++)
	{
		while (!serial.readable());
		cmd[i] = serial.getc();
	}
}
