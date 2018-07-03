#pragma once
#include "TetrisObject.h"

class Jocker : public TetrisObject{
	Point body;
	int serial;
	Board &board;
	int score;
	const Color color = LIGHTGREEN;
	const Signs sign = JOCKER_SIGN;
public:
	//Constructor:
	Jocker(Board &b) : board(b) {}

	//inline Functions:
	void reNew(ShapeType _type, int _serial) override;
	void setSerial(int _serial) { serial = _serial; }
	Color getColor() { return color; }
	int getScore() override { return score; }
	bool isAbleToMove(int x, int y) {
		return (board.getSerial(body.getY() + y, body.getX() + x) != EDGE);
	}

	//cpp Functions:
	bool move (Keys dir) override;
	void printPrevPoint();
	void endUse() override;
};
