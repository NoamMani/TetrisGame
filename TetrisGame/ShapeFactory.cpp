#include "ShapeFactory.h"

//The function restart the data members for a new use
void ShapeFactory::reNew(ShapeType _type, int _serial) {
	serial = _serial;
	shouldRotate = true;
	//Setting the body points to the start position
	for (int i = 0; i < BODY_SIZE; i++)
		for (int j = 0; j < BODY_SIZE; j++)
			body[i][j] = Point(j + 9, i + 3);
	//Setting the shape to the body matrix
	switch (_type) {
	case LINE:
		body[3][0].setChar(SHAPE_SIGN);
		body[3][1].setChar(SHAPE_SIGN);
		body[3][2].setChar(SHAPE_SIGN);
		body[3][3].setChar(SHAPE_SIGN);
		break;
	case SQUARE:
		shouldRotate = false;
		body[2][1].setChar(SHAPE_SIGN);
		body[2][2].setChar(SHAPE_SIGN);
		body[3][1].setChar(SHAPE_SIGN);
		body[3][2].setChar(SHAPE_SIGN);
		break;
	case Z:
		body[2][1].setChar(SHAPE_SIGN);
		body[2][2].setChar(SHAPE_SIGN);
		body[3][2].setChar(SHAPE_SIGN);
		body[3][3].setChar(SHAPE_SIGN);
		break;
	case PLUS:
		body[3][1].setChar(SHAPE_SIGN);
		body[2][2].setChar(SHAPE_SIGN);
		body[3][2].setChar(SHAPE_SIGN);
		body[3][3].setChar(SHAPE_SIGN);
		break;
	case L:
		body[2][1].setChar(SHAPE_SIGN);
		body[3][1].setChar(SHAPE_SIGN);
		body[3][2].setChar(SHAPE_SIGN);
		body[3][3].setChar(SHAPE_SIGN);
		break;
	}
	randomColor();
	setTextColor(color);
	printShape(0, 0);
}

//The function draw a color for the shape
void ShapeFactory::randomColor() {
	Color random = (Color)((rand() % 6) + 9);
	while (color == random)
		random = (Color)((rand() % 6) + 9);
	this->color = random;
}

//The function prints the shape on the board
void ShapeFactory::printShape(int x, int y) {
	for (int i = 0; i < BODY_SIZE; i++)
		for (int j = 0; j < BODY_SIZE; j++)
			body[i][j].move(x, y);
}
