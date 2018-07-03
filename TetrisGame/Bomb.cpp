#include "Bomb.h"

//The function moves the bomb according to the given direction
bool Bomb::move(Keys dir ) {

	switch (dir) {
	case LEFT:
		if (isAbleToMove(-1,0)) {
			body.draw(EMPTY);
			body.move(-1, 0);
			return true;
		}	
		else if (needToExplode(-1, 0)) {
			explode(-1, 0);
			return false;
		}
		break;
	case RIGHT:
		if (isAbleToMove(1,0)) {
			body.draw(EMPTY);
			body.move(1, 0);
			return true;
		}
		else if (needToExplode(1, 0)) {
			explode(1, 0);
			return false;
		}
		break;
	case DOWN:
		if (isAbleToMove(0,1)) {
			body.draw(EMPTY);
			body.move(0, 1);
			return true;
		}
		else if (needToExplode(0, 1)) {
			explode(0, 1);
			return false;
		}
		break;
	case DIRECT:
		while (isAbleToMove(0, 1)) {
			body.draw(EMPTY);
			body.move(0, 1);
			score += 2;
		}
	}
	return true;
}

//The function checks if the bomb need to explode- touch the ground or moving into existing shapes
bool Bomb::needToExplode(int x, int y) {
	//If the bomb arrive to the bottom
	if (x == 0 && y == 1 && board.getSerial(body.getY() + y, body.getX() + x) == EDGE)
		return true;
	return (board.getSerial(body.getY() +y, body.getX() +x) != EDGE);
}

//The function makes an explosion when needed
void Bomb::explode(int x, int y) {
	int topLeftCol, topLeftRow;

	//Locate the bomb before exploding the 9X9 square around it
	body.updatePoint(x, y);
	topLeftCol = body.getX() - INDENTATION - 1;
	topLeftRow = body.getY() - INDENTATION - 1;
	
	updateExplosion(board, topLeftRow, topLeftCol);
}

//The function updated the board(boardCells values) after an explosion
void Bomb::updateExplosion(Board & board, int firstRow, int firstCol) {
	printExplosion(board, firstRow, firstCol);//Effect
	Sleep(200);

	for (int i = firstRow; i < 3 + firstRow; i++)
		for (int j = firstCol; j < 3 + firstCol; j++)
			if (board.getSerialByRowCol(i, j ) != -1 && i<ROW+1) {
				if (board.getSerialByRowCol(i , j) != 0)
					score-=50;//Updated the score -50 for each brick that was exploded
				board.set(Point(j+ INDENTATION,i+ INDENTATION, EMPTY), 0, WHITE);
				gotoxy(j + INDENTATION, i + INDENTATION);
				cout << (char)EMPTY;
			}
}

//The function prints an explosion effect
void Bomb::printExplosion(Board & board, int firstRow, int firstCol) {
	setTextColor(LIGHTRED);
	for (int i = firstRow; i < 3 + firstRow; i++)
		for (int j = firstCol; j < 3 + firstCol; j++)
			if (board.getSerialByRowCol(i, j) != EDGE && i < ROW + 1) {
				gotoxy(j+INDENTATION, i+INDENTATION);
				cout << (char)EFFECT_BOMB;
			}
	printMessage("OHH NO!!");
}

//The function updates the board after the explosion
void Bomb::endUse() {
	board.updateBoard();
}
