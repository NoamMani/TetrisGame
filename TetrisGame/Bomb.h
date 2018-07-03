#pragma once
#include "TetrisObject.h"

class Bomb : public TetrisObject {
	Point body;
	Board &board;
	int score;
	const Color color = LIGHTRED;
	const Signs sign = BOMB_SIGN;
public:
	//Constructor:
	Bomb(Board &board) : board(board) {}

	//inline Functions:
	int getScore() override { return score; }
	void reNew(ShapeType _type, int _serial) override {
		setTextColor(color);
		body = Point(10, 5, sign);
		score = 0;
	}
	bool isAbleToMove(int x, int y) {
		return (board.getSerial(body.getY() + y, body.getX() + x) == 0);
	}
	Color getColor() { return color; }

	//cpp Functions:
	bool move(Keys dir) override;
	bool needToExplode(int x, int y);
	void explode(int x, int y);
	void updateExplosion(Board & board, int firstRow, int firstCol);
	void printExplosion(Board & board, int firstRow, int firstCol);
	void endUse() override;
};