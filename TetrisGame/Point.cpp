#include "Point.h"

void Point::draw(Signs c) {
	gotoxy(x, y);
	cout << (char)c;
	cout.flush();
}

void Point::move(int dirX, int dirY) {
	updatePoint(dirX, dirY);
	if (ch != EMPTY)
		draw(ch);
}
