#pragma once
#include "Board.h"
#include "Keys.h"

class TetrisObject {
public:
	virtual bool move(Keys dir)=0;
	virtual int getScore()=0;
	virtual void endUse()=0;
	virtual void reNew(ShapeType _type, int _serial) = 0;
	virtual Color getColor() = 0;
};
