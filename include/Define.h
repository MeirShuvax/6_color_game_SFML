#pragma once

//=============================================================//
//The size of this is only allowed to be a size divisible by 20//
//this is a size (in pixel) of the RECTANGEL from the HEXAGONALS//
 const int RECTANGEL_HEXAGONALS = 600;
//=============================================================//
const int PIXEL_SIZE = 10;
const int COLOR_KEY_SIZE = RECTANGEL_HEXAGONALS/20;
const int INFORMATION_DISPLAY = RECTANGEL_HEXAGONALS/6;
const int RECTANGEL_SIDE = INFORMATION_DISPLAY/2;
//const int SIZE_HEXAGONALS = WINDOW_WIDTH / 30;
const double RADIUS = 11.54701;
const int SUM_HEXAGONALS = RECTANGEL_HEXAGONALS / 20;
const int WINDOW_HEIGHT = (RADIUS * 1.5) * SUM_HEXAGONALS + INFORMATION_DISPLAY * 2 ;
const int WINDOW_WIDTH = RECTANGEL_HEXAGONALS +  RECTANGEL_SIDE*2;
const char WELCOM[] = "Please select a game algorithm";
const std::string VICTORY = "                     \n   You Won!!!  \n                    ";
const std::string LOST = "                     \n   You lost!!!  \n                    ";



enum Sign
{
	PLAYER = 'p',
	COMPUTER = 'c',
    EMPTY = 'N'
};

enum Algoritem
{
	NUL,
	RANDOM ,
	GREEDY ,
	SMART
};



