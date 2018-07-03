#pragma once
#include "Point.h"
#include "BoardCell.h"

enum Size { ROW = 15, COL = 10 };
enum BOARD { EDGE = -1 };
enum ShapeType { BOMB = 0, JOCKER, LINE, SQUARE, Z, PLUS, L };

class Board {
	BoardCell board[ROW + 2][COL + 2];

public:
	//Constructor - cpp
	Board();

	//inline Function:
	void set(Point p, int serial, Color color);

	int getSerial(int x, int y) {
		return board[x - INDENTATION][y - INDENTATION].getSerial();
	}

	int getSign(int r, int c) {
		return board[r][c].getSign();
	}

	int getSerialByRowCol(int r, int c) {
		return board[r][c].getSerial();
	}

	void swapCellDown(int r, int c);
	void printNewCells(int r, int c);
	BoardCell& getBoardCell(int r, int c) { return board[r][c]; }

	//cpp Functions:
	void findShapeRec(BoardCell &start, BoardCell * arr, int & size);
	void updateBoard();
	void moveDown(BoardCell *arr, int size);
	bool ableToMoveDown(BoardCell arr[], int size);
};