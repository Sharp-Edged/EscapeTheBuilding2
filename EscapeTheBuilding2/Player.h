#pragma once
#include "Common.h"

class Player {
private:
	Point coords;
	int health;

public:
	Player(int _health, int _x, int _y);
	int GetX();
	int GetY();
	Point GetCoords();
	
	void SetX(int x);
	void SetY(int y);
	void SetCoords(Point _Coords);
};
