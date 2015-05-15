/*
* 4DLibrary.hpp
* This file is a part of 4DLibrary
* Copyright (c) 2015 juliencombattelli, SRTH
*/

#include "mbed.h"

class 4DLibrary
{
private :
	
	Serial serial;
	DigitalOut rst;
	
	void clear_rx_buffer();
	
	void write_commande(unsigned char* cmd, unsigned int size);
	
	void read_commande(unsigned char* cmd, unsigned int size);
	
public : 
	
	/*txt function*/
	unsigned char txt_move_cursor(unsigned int line, unsigned int column);
	
	unsigned char txt_put_char(unsigned char caractere);
	
	unsigned char txt_put_str(unsigned char* str);
	
	unsigned int txt_char_width(unsigned char car);
	
	unsigned int txt_char_height(unsigned char car);
	
	unsigned int txt_foreground_color(unsigned int color);
	
	unsigned int txt_background_color(unsigned int color);
	
	unsigned int txt_set_font(unsigned char font);
	
	unsigned int txt_width_multiplier(unsigned char multiplier);
	
	unsigned int txt_height_multiplier(unsigned char multiplier);
	
	unsigned int txt_x_gap(unsigned char pixel_count);
	
	unsigned int txt_y_gap(unsigned char pixel_count);
	
	unsigned int txt_bold(bool bold);
	
	unsigned int txt_inverse(bool inverse);
	
	unsigned int txt_italic(bool italic);
	
	unsigned int txt_opacity(bool opaque);
	
	unsigned int txt_underline(bool underline); //txt_y_gap command is required to be at least 2 for the underline to be visible
	
	unsigned int txt_attributes(bool bold, bool italic, bool inverse, bool underline) //txt_y_gap command is required to be at least 2 for the underline to be visible
	
	unsigned int txt_wrap(unsigned int wrap_pixel);
	
	/*graphics function*/
	
	
	/*media function*/
	unsigned int media_init();
	
	unsigned int media_set_addr(uint32_t addr);
	
	unsigned int media_set_sector(uint32_t sector);
	
};

