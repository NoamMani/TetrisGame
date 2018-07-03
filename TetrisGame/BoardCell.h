#pragma once
#include "Display.h"
#include "ShapesSigns.h"

class BoardCell {
	int serial;
	Signs sign;
	bool isUpdated;
	int row, col;
	Color color;

public:
	//Constructor:
	BoardCell() :serial(0), sign(EMPTY), color(WHITE), isUpdated(false) {};

	//inline Functions:
	void set(int _serial, Signs _sign, Color _color) {
		serial = _serial;
		color = _color;
		sign = _sign;
	}

	void setRowCol(int row, int col) {
		this->row = row;
		this->col = col;
	}

	void setStatus(bool status) { this->isUpdated = status; }
	int getSerial() {  return serial; }
	int getRow() { return row; }
	int getCol() { return col; }
	Signs getSign() { return sign; }
	int getColor() { return color; }
	bool getStatus() { return isUpdated; }
};