/*
* 4DLibrary.cpp
* This file is a part of 4DLibrary
* Copyright (c) 2015 juliencombattelli, SRTH
*/

#include "4DLibrary.hpp"

4DLibrary::4DLibrary(PinName tx, PinName rx, PinName reset) : serial(tx, rx), rst(reset)
{

}

