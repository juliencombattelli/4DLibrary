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

};

