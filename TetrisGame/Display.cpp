#include "Display.h"

void setTextColor(Color colorToSet) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)colorToSet);
}

//Taken from the class
void hideCursor() {
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
}

//The function prints a message in the bottom of the screen 
void printMessage(string str, bool needToStay) {
	setTextColor(WHITE);
	gotoxy(7, 22);
	cout << str << endl;
	if (!needToStay) {
		Sleep(300);
		gotoxy(7, 22);
		cout << "                         " << endl;
	}
}

//The function prints the first menu on the screen
void printFirstScreen() {
	//Head line
	gotoxy(8, 1);
	string str = "TETRIS";
	for (int i = 0; i < 6; i++) {
		setTextColor((Color)(i + 10));
		cout << str[i];
	}
	//Right menu
	gotoxy(INDENTATION + 15, INDENTATION + 4);
	cout << "Press 1 to start";
	gotoxy(INDENTATION + 15, INDENTATION + 6);
	cout << "Press 9 to exit";
}

//The function prints the menu on the screen
void printGameScreen() {
	//Right menu
	gotoxy(INDENTATION + 15, INDENTATION + 8);
	cout << "Press 2 to pause\\continue";
	gotoxy(INDENTATION + 15, INDENTATION + 10);
	cout << "Press 3 to speed";
	gotoxy(INDENTATION + 15, INDENTATION + 12);
	cout << "Press 4 to slow";

	printInstructions();
	//print data game
	gotoxy(6, 3);
	cout << "Score:";
	gotoxy(6, 4);
	cout << "Drops:";
}

//The function prints the instructions in the bottom of the screen
void printInstructions() {
	gotoxy(INDENTATION-2, INDENTATION + 19);
	cout << "Press the 'i' arrow to ROTATE";
	gotoxy(INDENTATION-2, INDENTATION + 20);
	cout << "Press the 'j' arrow to go LEFT";
	gotoxy(INDENTATION-2, INDENTATION + 21);
	cout << "Press the 'l' arrow to go RIGHT";
	gotoxy(INDENTATION-2, INDENTATION + 22);
	cout << "Press space to go directly to the place";
	gotoxy(INDENTATION-2, INDENTATION + 23);
	cout << "Press 's' to stop the JOCKER";
}

//The function prints the score on the screen 
void printDataGame( int score) {
	setTextColor(WHITE);
	gotoxy(14, 3);
	cout << "       ";

	gotoxy(14, 3);
	cout << score;
}