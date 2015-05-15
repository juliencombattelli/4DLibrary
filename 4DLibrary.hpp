/*
* 4DLibrary.hpp
* This file is a part of 4DLibrary
* Copyright (c) 2015 juliencombattelli, SRTH
*/

#include "mbed.h"

class 4DLibrary
{
private :

	void clear_rx_buffer();
	
	void write_commande(unsigned char* cmd, unsigned char size);
	
	void read_commande(unsigned char* cmd, unsigned char size);
	
public : 
	
	/*
	* txt function
	*/
	unsigned char txt_move_cursor(unsigned int line, unsigned int column);
	
	unsigned char txt_put_char(unsigned char caractere);
	
	unsigned char txt_put_str(unsigned char* str);
	
	unsigned int txt_char_width(unsigned char car);
	
	unsigned int txt_char_height(unsigned char car);
	
	unsigned int txt_foreground_color(unsigned int color);
	
	unsigned int txt_background_color(unsigned int color);
	
	unsigned int txt_set_font(unsigned char font);

};

