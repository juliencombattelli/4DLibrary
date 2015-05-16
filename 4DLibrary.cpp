/*
* 4DLibrary.cpp
* This file is a part of 4DLibrary
* Copyright (c) 2015 juliencombattelli, SRTH
*/

#include "4DLibrary.hpp"

4DLibrary::4DLibrary(PinName tx, PinName rx, PinName reset) : m_serial(tx, rx), m_rst(reset)
{
	clear_rx_buffer();
}

/*
* private function
*/

void 4DLibrary::clear_rx_buffer()
{
	while(m_serial.readable())
	{
		m_serial.getc();
	}
}

void 4DLibrary::write_commande(uint8_t* cmd, uint16_t size)
{
	for(uint8_t i = 0; i < size; i++)
	{
		while (!m_serial.writeable());
		m_serial.putc(cmd[i]);
	}
}

void 4DLibrary::read_commande(uint8_t* cmd, uint16_t size)
{
	for(uint8_t i = 0; i < size; i++)
	{
		while (!m_serial.readable());
		cmd[i] = m_serial.getc();
	}
}

/*
* public function
*/

	/*txt function*/
uint8_t 4DLibrary::txt_move_cursor(uint16_t line, uint16_t column)
{
	uint8_t cmd[6];
	cmd[0] = 0xFF;
	cmd[1] = 0xE9;
	cmd[2] = (uint8_t)(line >> 8);
	cmd[3] = (uint8_t)line;
	cmd[4] = (uint8_t)(column >> 8);
	cmd[5] = (uint8_t)column;
	
	write_commande(cmd, 6);
	read_commande(cmd, 1);
	if(cmd[0] = 0x06)
		return 0;
	else
		return 1;
}

uint8_t 4DLibrary::txt_put_char(uint8_t caractere)
{
	uint8_t cmd[4];
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

uint8_t 4DLibrary::txt_put_str(uint8_t* str)
{
	uint16_t size = strlen((uint8_t*)str);
	uint8_t cmd[3];
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

uint16_t 4DLibrary::txt_char_width(uint8_t car)
{
	uint8_t cmd[3];
	cmd[0] = 0x00;
	cmd[1] = 0x1E;
	cmd[2] = car;
	
	write_commande(cmd, 3);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // refert to datasheet
	}
	else
		return ( 0xFFFF ); // impossible value -> error
}

uint16_t 4DLibrary::txt_char_height(uint8_t car)
{
	uint8_t cmd[3];
	cmd[0] = 0x00;
	cmd[1] = 0x1D;
	cmd[2] = car;
	
	write_commande(cmd, 3);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // refert to datasheet
	}
	else
		return ( 0xFFFF ); // impossible value -> error
}

uint16_t 4DLibrary::txt_foreground_color(uint16_t color)
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xE7;
	cmd[2] = (uint8_t)(color >> 8);
	cmd[3] = (uint8_t)color;
	
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous color
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_background_color(uint16_t color)
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xE6;
	cmd[2] = (uint8_t)(color >> 8);
	cmd[3] = (uint8_t)color;
	
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous color
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_set_font(uint8_t font)
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xE5;
	cmd[2] = 0x00;
	if(font > 0 && font < 4)
		cmd[3] = font - 1; // adaptation for font id
	else
		return( 0x0xFFFE ); // invalid font
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous font
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_width_multiplier(uint8_t multiplier)
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xE4;
	cmd[2] = 0x00;
	if(font >= 1 && font <= 16)
		cmd[3] = multiplier; 
	else
		return( 0xFFFE ); // invalid multiplier
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous multiplier
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_height_multiplier(uint8_t multiplier)
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xE3;
	cmd[2] = 0x00;
	if(font >= 1 && font <= 16)
		cmd[3] = multiplier; 
	else
		return( 0xFFFE ); // invalid multiplier
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous multiplier
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_x_gap(uint8_t pixel_count)
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xE2;
	cmd[2] = 0x00;
	if(font >= 0 && font <= 32)
		cmd[3] = pixel_count; 
	else
		return( 0xFFFE ); // invalid multiplier
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous x_gap
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_y_gap(uint8_t pixel_count)
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xE1;
	cmd[2] = 0x00;
	if(font >= 1 && font <= 32)
		cmd[3] = pixel_count; 
	else
		return( 0xFFFE ); // invalid multiplier
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous y_gap
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_bold(bool bold)
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xDE;
	cmd[2] = 0x00;
	if(bold == false)
		cmd[3] = 0x00; 
	else
		cmd[3] = 0x01;
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous bold mode
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_inverse(bool inverse)
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xDC;
	cmd[2] = 0x00;
	if(inverse == false)
		cmd[3] = 0x00; 
	else
		cmd[3] = 0x01;
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous inverse mode
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_italic(bool italic)
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xDD;
	cmd[2] = 0x00;
	if(italic == false)
		cmd[3] = 0x00; 
	else
		cmd[3] = 0x01;
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous italic mode
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_opacity(bool opaque)
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xDF;
	cmd[2] = 0x00;
	if(opaque == false)
		cmd[3] = 0x00; //transparent
	else
		cmd[3] = 0x01; //opaque
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous opacity mode
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_underline(bool underline) //txt_y_gap command is required to be at least 2 for the underline to be visible
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xDB;
	cmd[2] = 0x00;
	if(underline == false)
		cmd[3] = 0x00;
	else
		cmd[3] = 0x01;
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous underline mode
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_attributes(bool bold, bool italic, bool inverse, bool underline) //txt_y_gap command is required to be at least 2 for the underline to be visible
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xDA;
	cmd[2] = 0x00;
	cmd[3] = 0x00
	if(bold == true)
		cmd[3] = cmd[3] | (0x01 << 4);
	if(italic == true)
		cmd[3] = cmd[3] | (0x01 << 5);
	if(inverse == true)
		cmd[3] = cmd[3] | (0x01 << 6);
	if(underline == true)
		cmd[3] = cmd[3] | (0x01 << 7);
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous attributes mode
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::txt_wrap(uint16_t wrap_pixel)
{
	uint8_t cmd[4];
	cmd[0] = 0xFF;
	cmd[1] = 0xD9;
	cmd[2] = (uint8_t)(wrap_pixel>>8);
	cmd[3] = (uint8_t)wrap_pixel; 
		
	write_commande(cmd, 4);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		return( (uint16_t)(cmd[1]<<8) || cmd[2]); // previous wrap pixel
	}
	else
		return 0xFFFF; // error
}

	/*graphics function*/

uint8_t 4DLibrary::gfx_clear_screen()
{
	uint8_t cmd[2];
	cmd[0] = 0xFF;
	cmd[1] = 0xCD;
	
	write_commande(cmd, 2);
	read_commande(cmd, 1);
	if(cmd[0] = 0x06)
		return 0;
	else
		return 1;
}	

uint8_t 4DLibrary::gfx_change_color(uint16_t old_color, uint16_t new_color)
{
	uint8_t cmd[6];
	cmd[0] = 0xFF;
	cmd[1] = 0xFE;
	cmd[2] = uint8_t(old_color >> 8);
	cmd[3] = uint8_t(old_color);
	cmd[4] = uint8_t(new_color >> 8);
	cmd[5] = uint8_t(new_color);
	
	write_commande(cmd, 6);
	read_commande(cmd, 1);
	if(cmd[0] = 0x06)
		return 0;
	else
		return 1;
}

uint8_t 4DLibrary::gfx_draw_circle(uint16_t center_x, uint16_t center_y, uint16_t radius, uint16_t colour)
{
	uint8_t cmd[10];
	cmd[0] = 0xFF;
	cmd[1] = 0xC3;
	cmd[2] = uint8_t(center_x >> 8);
	cmd[3] = uint8_t(center_x);
	cmd[4] = uint8_t(center_y >> 8);
	cmd[5] = uint8_t(center_y);
	cmd[6] = uint8_t(radius >> 8);
	cmd[7] = uint8_t(radius);
	cmd[8] = uint8_t(colour >> 8);
	cmd[9] = uint8_t(colour);
	
	write_commande(cmd, 10);
	read_commande(cmd, 1);
	if(cmd[0] = 0x06)
		return 0;
	else
		return 1;
}

uint8_t 4DLibrary::gfx_draw_filled_circle(uint16_t center_x, uint16_t center_y, uint16_t radius, uint16_t colour)
{
	uint8_t cmd[10];
	cmd[0] = 0xFF;
	cmd[1] = 0xC2;
	cmd[2] = uint8_t(center_x >> 8);
	cmd[3] = uint8_t(center_x);
	cmd[4] = uint8_t(center_y >> 8);
	cmd[5] = uint8_t(center_y);
	cmd[6] = uint8_t(radius >> 8);
	cmd[7] = uint8_t(radius);
	cmd[8] = uint8_t(colour >> 8);
	cmd[9] = uint8_t(colour);
	
	write_commande(cmd, 10);
	read_commande(cmd, 1);
	if(cmd[0] = 0x06)
		return 0;
	else
		return 1;
}

uint8_t 4DLibrary::gfx_draw_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour)
{
	uint8_t cmd[12];
	cmd[0] = 0xFF;
	cmd[1] = 0xC8;
	cmd[2] = uint8_t(x1 >> 8);
	cmd[3] = uint8_t(x1);
	cmd[4] = uint8_t(y1 >> 8);
	cmd[5] = uint8_t(y1);
	cmd[6] = uint8_t(x2 >> 8);
	cmd[7] = uint8_t(x2);
	cmd[8] = uint8_t(y2 >> 8);
	cmd[9] = uint8_t(y2);
	cmd[10] = uint8_t(colour >> 8);
	cmd[11] = uint8_t(colour);
	
	write_commande(cmd, 10);
	read_commande(cmd, 1);
	if(cmd[0] = 0x06)
		return 0;
	else
		return 1;
}

uint8_t 4DLibrary::gfx_draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour)
{
	uint8_t cmd[12];
	cmd[0] = 0xFF;
	cmd[1] = 0xC5;
	cmd[2] = uint8_t(x1 >> 8);
	cmd[3] = uint8_t(x1);
	cmd[4] = uint8_t(y1 >> 8);
	cmd[5] = uint8_t(y1);
	cmd[6] = uint8_t(x2 >> 8);
	cmd[7] = uint8_t(x2);
	cmd[8] = uint8_t(y2 >> 8);
	cmd[9] = uint8_t(y2);
	cmd[10] = uint8_t(colour >> 8);
	cmd[11] = uint8_t(colour);
	
	write_commande(cmd, 10);
	read_commande(cmd, 1);
	if(cmd[0] = 0x06)
		return 0;
	else
		return 1;
}
	
	/*media function*/
uint16_t 4DLibrary::media_init()
{
	uint8_t cmd[3];
	cmd[0] = 0xFF;
	cmd[1] = 0x89; 
		
	write_commande(cmd, 2);
	read_commande(cmd, 3);
	if(cmd[0] = 0x06)
	{
		if(cmd[3] == 0x01)
			return( 0x00 );
		else
			return( 0xFFFE); // no card is presentor not able to initialise.
	}
	else
		return 0xFFFF; // error
}

uint16_t 4DLibrary::media_set_addr(uint32_t addr)
{
	uint8_t cmd[6];
	cmd[0] = 0xFF;
	cmd[1] = 0x93; 
	cmd[2] = (uint8_t)(addr >> 24);
	cmd[3] = (uint8_t)(addr >> 16);
	cmd[4] = (uint8_t)(addr >> 8);
	cmd[5] = (uint8_t)addr;
	
	write_commande(cmd, 6);
	read_commande(cmd, 1);
	if(cmd[0] = 0x06)
			return( 0x00 );
	else
		return( 0xFFFF ); // error
}

uint16_t 4DLibrary::media_set_sector(uint32_t sector)
{
	uint8_t cmd[6];
	cmd[0] = 0xFF;
	cmd[1] = 0x92; 
	cmd[2] = (uint8_t)(sector >> 24);
	cmd[3] = (uint8_t)(sector >> 16);
	cmd[4] = (uint8_t)(sector >> 8);
	cmd[5] = (uint8_t)sector;
	
	write_commande(cmd, 6);
	read_commande(cmd, 1);
	if(cmd[0] = 0x06)
			return( 0x00 );
	else
		return( 0xFFFF ); // error
}