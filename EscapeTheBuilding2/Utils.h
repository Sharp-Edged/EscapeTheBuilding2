#pragma once
#include <vector>
#include <string>
#include "Grid.h"

struct ConversionResult {
	Grid grid;
	int playerX;
	int playerY;

	ConversionResult(Grid grid, int playerX, int playerY) : grid(grid), playerX(playerX), playerY(playerY) {}
};

ConversionResult levelToGrid(int levelID);
