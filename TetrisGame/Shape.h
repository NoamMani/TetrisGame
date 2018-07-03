#pragma once
#include "ShapeFactory.h"
#include "TetrisObject.h"

class Shape : public ShapeFactory {
	Board &board;
	int score=0;

public:
	//Constructor:
	Shape(Board &b) : board(b) {};

	//inline Functions:
	int getScore() override {
		int temp = score;
		score = 0;
		return temp;
	}

	//CPP Functions:
	bool move(Keys dir) override;
	bool isAbleToMove(int x, int y);
	void makeAmove(int x, int y, bool needRotate = false);
	void rotate();
	void swapSigns(Point &a, Point &board, Point &c, Point &d);
	bool isLastColEmpty();
	void moveNextCol();
	void rotateBack();
	bool isLastRowEmpty();
	void moveNextRow();
	bool isAbleToRotate();
	void endUse() override;
};