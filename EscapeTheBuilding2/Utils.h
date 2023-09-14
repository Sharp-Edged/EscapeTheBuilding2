#pragma once
#include <vector>
#include <string>
#include "Grid.h"

const char* getLevelData(int lvl);


struct ConversionResult {
	Grid grid;
	int playerX;
	int playerY;

	ConversionResult(Grid grid, int playerX, int playerY) : grid(grid), playerX(playerX), playerY(playerY) {}
};

ConversionResult lvlToGrid(const char* lvl);
