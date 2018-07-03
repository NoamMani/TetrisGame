#include "Shape.h"

//G-E-N-E-R-I-C MOVE
//The function moves the shape in a genric way- it doesnt metter whats the type!
bool Shape::move(Keys dir) {
	switch (dir) {
	case LEFT:
		if (isAbleToMove(-1, 0))
			makeAmove(-1, 0);
		return true;
	case RIGHT:
		if (isAbleToMove(1, 0))
			makeAmove(1, 0);
		return true;
	case DOWN:
		if (isAbleToMove(0, 1)) {
			makeAmove(0, 1);
			return true;
		}
		else
			return false;
	case ROTATE:
		if (shouldRotate)
			makeAmove(0, 0, isAbleToRotate());
		return true;
	case DIRECT:
		while (isAbleToMove(0, 1)) {
			makeAmove(0, 1);
			score += 2;
		}
		return false;
	}

}

//The function checks if the shape is able to move in wanted direction
bool Shape::isAbleToMove(int x, int y) {
	int i, j;
	Point temp;
	for (i = 0; i < BODY_SIZE; i++)
		for (j = 0; j < BODY_SIZE; j++)
		{
			temp = body[i][j];
			if (board.getSerial(temp.getY() + y, temp.getX() + x) != 0 && temp.getChar() != EMPTY)
				return false;
		}
	return true;
}

//The function moves the shape as needed
void Shape::makeAmove(int x, int y, bool needToRotate) {
	int i, j;

	for (i = 0; i < BODY_SIZE; i++)
		for (j = 0; j < BODY_SIZE; j++)
			if (body[i][j].getChar() != EMPTY)
				body[i][j].draw(EMPTY);

	if (needToRotate)
		rotate();

	printShape(x, y);
}

//G-E-N-E-R-I-C ROTATE
//The function rotate the shape in a genric way- it doesnt metter whats the type!
void Shape::rotate() {
	//Rotate the body (matrix 4X4) in 90 degrees with the clock direction
	for (int i = 0; i < BODY_SIZE / 2; i++)
		for (int j = 0; j < (BODY_SIZE + 1) / 2; j++)
			//Swap the body cells in the correct order
			swapSigns(body[i][j], body[BODY_SIZE - 1 - j][i], body[BODY_SIZE - 1 - i][BODY_SIZE - 1 - j], body[j][BODY_SIZE - 1 - i]);
	//Placing the shape in the matrix (right)
	while (isLastColEmpty())
		moveNextCol();
}

//The function rotate the body (matrix 4X4) in 90 degrees by sawping the given cells
void Shape::swapSigns(Point &a, Point &b, Point &c, Point &d) {
	//Swap the signs in the points (a->b, b->c, c->d, d->a)
	Signs temp = a.getChar();
	a.setChar(b.getChar());
	b.setChar(c.getChar());
	c.setChar(d.getChar());
	d.setChar(temp);
}

bool Shape::isLastColEmpty() {
	//Check if the shape can move right in the matrix
	for (int i = 0; i < BODY_SIZE; i++)
		if (body[i][3].getChar() != EMPTY)
			return false;
	return true;
}

void Shape::moveNextCol() {
	//Coping the shape right (only one step)
	for (int c = 2; c >= 0; c--)
		for (int r = 0; r < BODY_SIZE; r++)
			body[r][c + 1].setChar(body[r][c].getChar());
	for (int r = 0; r < BODY_SIZE; r++)
		body[r][0].setChar(EMPTY);
}

void Shape::rotateBack() {
	//Rotate the body (matrix 4X4) in 90 degrees againt the clock direction
	for (int i = 0; i < BODY_SIZE / 2; i++)
		for (int j = 0; j < (BODY_SIZE + 1) / 2; j++)
			//Swap the body cells in the correct order
			swapSigns(body[j][BODY_SIZE - 1 - i], body[BODY_SIZE - 1 - i][BODY_SIZE - 1 - j], body[BODY_SIZE - 1 - j][i], body[i][j]);
	while (isLastRowEmpty())
		moveNextRow();
}

bool Shape::isLastRowEmpty() {
	//Check if the shape can move down in the matrix
	for (int i = 0; i < BODY_SIZE; i++)
		if (body[3][i].getChar() != EMPTY)
			return false;
	return true;
}

void Shape::moveNextRow() {
	//Coping the shape down (only one step)
	for (int r = 2; r >= 0; r--)
		for (int c = 0; c < BODY_SIZE; c++)
			body[r + 1][c].setChar(body[r][c].getChar());
	for (int c = 0; c < BODY_SIZE; c++)
		body[0][c].setChar(EMPTY);
}

//The function checks if the shape can rotate
bool Shape::isAbleToRotate() {
	Point temp;
	rotate();//Rotate the shape for checking
	for (int i = 0; i < BODY_SIZE; i++)
		for (int j = 0; j < BODY_SIZE; j++) {
			temp = body[i][j];
			if (board.getSerial(temp.getY(), temp.getX()) != 0 && temp.getChar() != EMPTY) {
				rotateBack(); //Back to Normal shpae- Can't rotate
				return false;
			}
		}
	rotateBack(); // Back to Normal shpae- can rotate
	return true;
}

//Update the shape on the board
void Shape::endUse() {
	//Set the shape to the main board
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j < BODY_SIZE; j++)
			if (body[i][j].getChar() != EMPTY)
				board.set(body[i][j], this->serial, this->color);
}
