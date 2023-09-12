#pragma once
#include <array>

class Player {
private:
	std::array<int, 2> Coords;
	int Health;

public:
	Player(int _Health);
	int GetX();
	int GetY();
	std::array<int, 2> GetCoords();
	void SetX(int x);
	void SetY(int y);
	void SetCoords(std::array<int, 2> _Coords);
};
