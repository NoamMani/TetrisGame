#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "gotoxy.h"

enum Display{ INDENTATION = 5 };

enum Color {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGREY = 7,
	DARKGREY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};

//cpp Functions:
void setTextColor(Color color);
void hideCursor();
void printMessage(string str, bool needToStay=false);
void printFirstScreen();
void printGameScreen();
void printInstructions();
void printDataGame(int score);