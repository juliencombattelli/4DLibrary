/*
* 4DLibrary.hpp
* This file is a part of 4DLibrary
* Copyright (c) 2015 juliencombattelli, SRTH
*/

#include "mbed.h"

class 4DLibrary
{
private :
	
	Serial m_serial;
	DigitalOut m_rst;
	
	void clear_rx_buffer();
	
	void write_commande(uint8_t* cmd, uint16_t size);
	
	void read_commande(uint8_t* cmd, uint16_t size);
	
	/*media function*/
uint16_t 4DLibrary::media_flush();
	
public : 
	
	/*txt function*/
	uint8_t txt_move_cursor(uint16_t line, uint16_t column);
	
	uint8_t txt_put_char(uint8_t caractere);
	
	uint8_t txt_put_str(uint8_t* str);
	
	uint16_t txt_char_width(uint8_t car);
	
	uint16_t txt_char_height(uint8_t car);
	
	uint16_t txt_foreground_color(uint16_t color);
	
	uint16_t txt_background_color(uint16_t color);
	
	uint16_t txt_set_font(uint8_t font);
	
	uint16_t txt_width_multiplier(uint8_t multiplier);
	
	uint16_t txt_height_multiplier(uint8_t multiplier);
	
	uint16_t txt_x_gap(uint8_t pixel_count);
	
	uint16_t txt_y_gap(uint8_t pixel_count);
	
	uint16_t txt_bold(bool bold);
	
	uint16_t txt_inverse(bool inverse);
	
	uint16_t txt_italic(bool italic);
	
	uint16_t txt_opacity(bool opaque);
	
	uint16_t txt_underline(bool underline); //txt_y_gap command is required to be at least 2 for the underline to be visible
	
	uint16_t txt_attributes(bool bold, bool italic, bool inverse, bool underline) //txt_y_gap command is required to be at least 2 for the underline to be visible
	
	uint16_t txt_wrap(uint16_t wrap_pixel);
	
	/*graphics function*/
	
	uint8_t gfx_clear_screen();
	
	uint8_t gfx_change_color(uint16_t old_color, uint16_t new_color);
	
	/*media function*/
	uint16_t media_init();
	
	uint16_t media_set_addr(uint32_t addr);
	
	uint16_t media_set_sector(uint32_t sector);
	
	uint16_t media_read_sector(uint8_t* sector); // sector must be a 512 areas map / set sector before
	
	uint16_t media_write_sector(uint8_t* sector); // sector must be a 512 areas map / set sector before
	
	uint16_t media_read_byte(); // set addr before
	
	uint16_t media_read_word(); // set addr before
	
	uint16_t media_write_byte(uint8_t byte); // set addr before
	
	uint16_t media_write_word(uint16_t word); // set addr before
	
	uint16_t media_display_image(uint16_t x, uint16_t y); // set addr or sector before
	
	uint16_t media_display_video(uint16_t x, uint16_t y); // set addr or sector before
	
	uint16_t media_display_video_frame(uint16_t x, uint16_t y, uint16_t frame_number); // set addr or sector before
	
};

