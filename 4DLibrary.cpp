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

/*
* public function
*/

unsigned char 4DLibrary::txt_move_cursor(unsigned int line, unsigned int column)
{
	unsigned char cmd[6];
	cmd[0] = 0xFF;
	cmd[1] = 0xE9;
	cmd[2] = (unsigned char)(line >> 8);
	cmd[3] = (unsigned char)line;
	cmd[4] = (unsigned char)(column >> 8);
	cmd[5] = (unsigned char)column;
	
	write_commande(cmd, 6);
	read_commande(cmd, 1);
	if(cmd[0] = 0x06)
		return 0;
	else
		return 1;
}

unsigned char 4DLibrary::txt_put_char(unsigned char caractere)
{
	unsigned char cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xFE;
	cmd[2] = 0x00;
	cmd[3] = caractere;
	
	write_commande(cmd, 4);
	read_commande(cmd, 1);
	if(cmd[0] = 0x06)
		return 0;
	else
		return 1;
}

unsigned char 4DLibrary::txt_put_str(unsigned char* str)
{
	unsigned int size = strlen((unsigned char*)str);
	unsigned char cmd[3];
	cmd[0] = 0x00;
	cmd[1] = 0x18;
	cmd[2] = 0x00;
	
	write_commande(cmd, 2);
	write_commande(str, size);
	write_commande(&(cmd[2]), 1);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		if( ((cmd[1]<<8) || cmd[2]) == size)
			return 0;
		else
			return 2;
	}
	else
		return 1;
}

unsigned int 4DLibrary::txt_char_width(unsigned char car)
{
	unsigned char cmd[3];
	cmd[0] = 0x00;
	cmd[1] = 0x1E;
	cmd[2] = car;
	
	write_commande(cmd, 3);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (unsigned int)(cmd[1]<<8) || cmd[2]); // refert to datasheet
	}
	else
		return 0; // impossible value -> error
}

unsigned int 4DLibrary::txt_char_height(unsigned char car)
{
	unsigned char cmd[3];
	cmd[0] = 0x00;
	cmd[1] = 0x1D;
	cmd[2] = car;
	
	write_commande(cmd, 3);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (unsigned int)(cmd[1]<<8) || cmd[2]); // refert to datasheet
	}
	else
		return 0; // impossible value -> error
}

unsigned int 4DLibrary::txt_foreground_color(unsigned int color)
{
	unsigned char cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xE7;
	cmd[2] = (unsigned char)(color >> 8);
	cmd[3] = (unsigned char)color;
	
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (unsigned int)(cmd[1]<<8) || cmd[2]); // previous color
	}
	else
		return 0xFFFF; // error
}

unsigned int 4DLibrary::txt_background_color(unsigned int color)
{
	unsigned char cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xE6;
	cmd[2] = (unsigned char)(color >> 8);
	cmd[3] = (unsigned char)color;
	
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (unsigned int)(cmd[1]<<8) || cmd[2]); // previous color
	}
	else
		return 0xFFFF; // error
}

unsigned int 4DLibrary::txt_set_font(unsigned char font)
{
	unsigned char cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xE5;
	cmd[2] = 0x00;
	if(font > 0 && font < 4)
		cmd[3] = font - 1; // adaptation for font id
	else
		return( 0x00 ); // invalid font
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (unsigned int)(cmd[1]<<8) || cmd[2]); // previous font
	}
	else
		return 0xFFFF; // error
}