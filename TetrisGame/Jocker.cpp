#include "Jocker.h"

//The function restart the data members for a new use
void Jocker::reNew(ShapeType _type, int _serial) {
	setTextColor(color);
	body = Point(10, 6, sign);
	score = 0;
	setSerial(_serial);
}

//The function updtes the board with the jocker when it stopes
void Jocker::endUse() {
	if (board.getSerial(body.getY(), body.getX()) == 0)
		board.set(body, this->serial, this->color);
	else
		printPrevPoint();
}

//The function moves the jocker according to the given direction
bool Jocker::move(Keys dir) {

	switch (dir) {
	case LEFT:
		if (isAbleToMove(-1, 0)) {
			printPrevPoint();
			body.move(-1, 0);
			return true;
		}
		break;
	case RIGHT:
		if (isAbleToMove(1, 0)) {
			printPrevPoint();
			body.move(1, 0);
			return true;
		}
		break;
	case DOWN:
		if (isAbleToMove(0, 1)) {
			printPrevPoint();
			body.move(0, 1);
			return true;
		}
		else
			return false;
		break;
	case STOP_JOCKER:
		return false;
		break;
	case DIRECT:
		while (isAbleToMove(0, 1)) {
			printPrevPoint();
			body.move(0, 1);
			score += 2;
		}
		break;
	}
	return true;
}

//The function prints the previous point after the jocker passed it
void Jocker::printPrevPoint() {
	BoardCell temp = board.getBoardCell(body.getY() - INDENTATION, body.getX() - INDENTATION);

	setTextColor((Color)temp.getColor());
	gotoxy(body.getX(), body.getY());
	cout << (char)temp.getSign();
	gotoxy(body.getX(), body.getY());

	setTextColor(color); //Back to the Jocker's color
}