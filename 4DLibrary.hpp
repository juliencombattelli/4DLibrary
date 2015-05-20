/*
* uLCD_4DLibrary.hpp
* This file is a part of uLCD_4DLibrary
* Copyright (c) 2015 juliencombattelli, SRTH
*/

#include "mbed.h"

namespace Color
{
	enum
	{
		ALICEBLUE			= 0xF7DF,
		ANTIQUEWHITE	    = 0xFF5A,
		AQUA         		= 0x07FF,
		AQUAMARINE   		= 0x7FFA,
		AZURE         		= 0xF7FF,
		BEIGE        		= 0xF7BB,
		BISQUE        		= 0xFF38,
		BLACK         		= 0x0000,
		BLANCHEDALMOND 		= 0xFF59,
		BLUE         		= 0x001F,
		BLUEVIOLET     		= 0x895C,
		BROWN       	  	= 0xA145,
		BURLYWOOD     		= 0xDDD0,
		CADETBLUE     		= 0x5CF4,
		CHARTREUSE     		= 0x7FE0,
		CHOCOLATE     		= 0xD343,
		CORAL         		= 0xFBEA,
		CORNFLOWERBLUE 		= 0x64BD,
		CORNSILK       	 	= 0xFFDB,
		CRIMSON         	= 0xD8A7,
		CYAN        	 	= 0x07FF,
		DARKBLUE       		= 0x0011,
		DARKCYAN    	    = 0x0451,
		DARKGOLDENROD   	= 0xBC21,
		DARKGRAY       		= 0xAD55,
		DARKGREEN     		= 0x0320,
		DARKKHAKI     		= 0xBDAD,
		DARKMAGENTA     	= 0x8811,
		DARKOLIVEGREEN  	= 0x5345,
		DARKORANGE     		= 0xFC60,
		DARKORCHID     		= 0x9999,
		DARKRED         	= 0x8800,
		DARKSALMON      	= 0xECAF,
		DARKSEAGREEN    	= 0x8DF1,
		DARKSLATEBLUE   	= 0x49F1,
		DARKSLATEGRAY   	= 0x2A69,
		DARKTURQUOISE   	= 0x067A,
		DARKVIOLET     		= 0x901A,
		DEEPPINK        	= 0xF8B2,
		DEEPSKYBLUE    		= 0x05FF,
		DIMGRAY         	= 0x6B4D,
		DODGERBLUE     		= 0x1C9F,
		FIREBRICK     		= 0xB104,
		FLORALWHITE     	= 0xFFDE,
		FORESTGREEN     	= 0x2444,
		FUCHSIA         	= 0xF81F,
		GAINSBORO     		= 0xDEFB,
		GHOSTWHITE     		= 0xFFDF,
		GOLD        	 	= 0xFEA0,
		GOLDENROD    	 	= 0xDD24,
		GRAY        	 	= 0x8410,
		GREEN        	 	= 0x0400,
		GREENYELLOW   	  	= 0xAFE5,
		HONEYDEW      		= 0xF7FE,
		HOTPINK       		= 0xFB56,
		INDIANRED     		= 0xCAEB,
		INDIGO         		= 0x4810,
		IVORY         		= 0xFFFE,
		KHAKI         		= 0xF731,
		LAVENDER        	= 0xE73F,
		LAVENDERBLUSH   	= 0xFF9E,
		LAWNGREEN     		= 0x7FE0,
		LEMONCHIFFON    	= 0xFFD9,
		LIGHTBLUE       	= 0xAEDC,
		LIGHTCORAL     		= 0xF410,
		LIGHTCYAN     		= 0xE7FF,
		LIGHTGOLD       	= 0xFFDA,
		LIGHTGREEN     		= 0x9772,
		LIGHTGREY     		= 0xD69A,
		LIGHTPINK     		= 0xFDB8,
		LIGHTSALMON     	= 0xFD0F,
		LIGHTSEAGREEN   	= 0x2595,
		LIGHTSKYBLUE    	= 0x867F,
		LIGHTSLATEGRAY  	= 0x7453,
		LIGHTSTEELBLUE  	= 0xB63B,
		LIGHTYELLOW     	= 0xFFFC,
		LIME         		= 0x07E0,
		LIMEGREEN     		= 0x3666,
		LINEN         		= 0xFF9C,
		MAGENTA         	= 0xF81F,
		MAROON         		= 0x8000,
		MEDIUMAQUAMARINE	= 0x6675,
		MEDIUMBLUE     		= 0x0019,
		MEDIUMORCHID    	= 0xBABA,
		MEDIUMPURPLE    	= 0x939B,
		MEDIUMSEAGREEN  	= 0x3D8E,
		MEDIUMSLATEBLUE 	= 0x7B5D,
		MEDIUMSPRINGGREEN 	= 0x07D3,
		MEDIUMTURQUOISE 	= 0x4E99,
		MEDIUMVIOLETRED 	= 0xC0B0,
		MIDNIGHTBLUE     	= 0x18CE,
		MINTCREAM     		= 0xF7FF,
		MISTYROSE     		= 0xFF3C,
		MOCCASIN         	= 0xFF36,
		NAVAJOWHITE     	= 0xFEF5,
		NAVY         		= 0x0010,
		OLDLACE         	= 0xFFBC,
		OLIVE         		= 0x8400,
		OLIVEDRAB     		= 0x6C64,
		ORANGE         		= 0xFD20,
		ORANGERED     		= 0xFA20,
		ORCHID         		= 0xDB9A,
		PALEGOLDENROD    	= 0xEF55,
		PALEGREEN     		= 0x9FD3,
		PALETURQUOISE     	= 0xAF7D,
		PALEVIOLETRED     	= 0xDB92,
		PAPAYAWHIP     		= 0xFF7A,
		PEACHPUFF     		= 0xFED7,
		PERU         		= 0xCC27,
		PINK         		= 0xFE19,
		PLUM         		= 0xDD1B,
		POWDERBLUE     		= 0xB71C,
		PURPLE         		= 0x8010,
		RED         		= 0xF800,
		ROSYBROWN     		= 0xBC71,
		ROYALBLUE     		= 0x435C,
		SADDLEBROWN     	= 0x8A22,
		SALMON         		= 0xFC0E,
		SANDYBROWN     		= 0xF52C,
		SEAGREEN         	= 0x2C4A,
		SEASHELL         	= 0xFFBD,
		SIENNA         		= 0xA285,
		SILVER         		= 0xC618,
		SKYBLUE         	= 0x867D,
		SLATEBLUE     		= 0x6AD9,
		SLATEGRAY     		= 0x7412,
		SNOW         		= 0xFFDF,
		SPRINGGREEN     	= 0x07EF,
		STEELBLUE     		= 0x4416,
		TAN         		= 0xD5B1,
		TEAL         		= 0x0410,
		THISTLE         	= 0xDDFB,
		TOMATO         		= 0xFB08,
		TURQUOISE     		= 0x471A,
		VIOLET         		= 0xEC1D,
		WHEAT         		= 0xF6F6,
		WHITE         		= 0xFFFF,
		WHITESMOKE     		= 0xF7BE,
		YELLOW         		= 0xFFE0,
		YELLOWGREEN     	= 0x9E66
	};
}

class uLCD_4DLibrary
{
private :
	
	Serial m_serial;
	DigitalOut m_rst;
	
	void clear_rx_buffer();
	
	void write_commande(uint8_t* cmd, uint16_t size);
	
	void read_commande(uint8_t* cmd, uint16_t size);
	
	/*media function*/
	uint16_t media_flush();

	/*UART function*/
	uint8_t code_baud_rate(uint32_t baud_rate);
	
public : 
	
	/*Constructors*/
	uLCD_4DLibrary(PinName tx, PinName rx, PinName reset);
	
	/*txt function*/
	uint8_t txt_move_cursor(uint16_t line, uint16_t column);
	
	uint8_t txt_put_char(uint8_t caractere);
	
	uint8_t txt_put_str(const int8_t* str);
	
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
	
	uint16_t txt_attributes(bool bold, bool italic, bool inverse, bool underline); //txt_y_gap command is required to be at least 2 for the underline to be visible
	
	uint16_t txt_wrap(uint16_t wrap_pixel);
	
	/*graphics function*/
	
	uint8_t gfx_clear_screen();
	
	uint8_t gfx_change_color(uint16_t old_color, uint16_t new_color);
	
	uint8_t gfx_draw_circle(uint16_t center_x, uint16_t center_y, uint16_t radius, uint16_t colour);
	
	uint8_t gfx_draw_filled_circle(uint16_t center_x, uint16_t center_y, uint16_t radius, uint16_t colour);
	
	uint8_t gfx_draw_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour);
	
	uint8_t gfx_draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour);
	
	uint8_t gfx_draw_filled_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour);

	uint8_t gfx_draw_polyline(uint16_t n, uint16_t* x_array, uint16_t* y_array, uint16_t colour);

	uint8_t gfx_draw_polygon(uint16_t n, uint16_t* x_array, uint16_t* y_array, uint16_t colour);

	uint8_t gfx_draw_filled_polygon(uint16_t n, uint16_t* x_array, uint16_t* y_array, uint16_t colour);
	
	uint8_t gfx_draw_triangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t colour);
	
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
	
	/*UART function*/
	uint16_t uart_set_baud_rate(uint32_t baud_rate);
	
	/* timer function*/
	uint16_t timer_sleep_systeme(uint16_t units); // 1 unit = approximatly 1 second
	
	/* file function*/
	uint16_t file_last_error();
	
	uint16_t file_file_count(uint8_t* file_name);
	
	uint16_t file_file_count_and_display(uint8_t* file_name);
	
	uint16_t file_find_first_file_and_display(uint8_t* file_name);
	
	uint16_t file_find_first_file_and_report(uint8_t* file_name_search, uint8_t* file_name_found);
	
	uint16_t file_find_next_file_and_display();
	
	uint16_t file_find_next_file_and_report(uint8_t* file_name_found);
	
	uint16_t file_file_exist(uint8_t* file_name);
	
	uint16_t file_open_file(uint8_t* file_name, uint8_t mode); // return handle /!\ keep it for closing file or other
	
	uint16_t file_close_file(uint16_t handle); // use the opening handle
	
	uint16_t file_read_file(uint16_t size, uint16_t handle, uint8_t* read_file); // use the opening handle
	
	uint16_t file_file_seek(uint16_t handle, uint32_t byte_position); // use the opening handle
	
	uint16_t file_file_index(uint16_t handle, uint32_t record_size, uint16_t records_number); // use the opening handle
	
	uint32_t file_file_index(uint16_t handle); // use the opening handle
	
	uint16_t file_write_file(uint16_t size, uint16_t handle, uint8_t* write_file); // use the opening handle
	
	uint32_t file_file_size(uint16_t handle); // use the opening handle
	
	uint16_t file_display_image(uint16_t handle, uint16_t x, uint16_t y); // use the opening handle
	
	uint16_t file_screen_capture(uint16_t handle, uint16_t x, uint16_t y, uint16_t width, uint16_t height); // use the opening handle
	
	uint16_t file_write_char_to_file(uint16_t handle, uint8_t charactere); // use the opening handle
	
	uint8_t file_read_char_to_file(uint16_t handle); // use the opening handle
	
	uint16_t file_write_word_to_file(uint16_t handle, uint16_t word); // use the opening handle
	
	uint16_t file_read_word_to_file(uint16_t handle); // use the opening handle
};

