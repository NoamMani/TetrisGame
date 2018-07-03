#pragma once
#include "Board.h"
#include "TetrisObject.h"
#include <time.h>

enum { BODY_SIZE = 4 };

class ShapeFactory : public TetrisObject {
	protected:
	Point body[BODY_SIZE][BODY_SIZE];
	bool shouldRotate;
	int serial;
	Color color;

public:
	//Constructor:
	ShapeFactory() {};
	//inline Functions:
	Color getColor() { return color; }

	//cpp Function:
	void reNew(ShapeType _type, int _serial) override;
	void randomColor();
	void printShape(int x, int y);
	virtual bool move(Keys dir) override = 0;
	virtual int getScore() override = 0;
	virtual void endUse() override = 0;
};
