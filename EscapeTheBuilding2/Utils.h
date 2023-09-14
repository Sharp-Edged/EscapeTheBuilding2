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

namespace GridHelpers {
	static GridCellType CharToCellType(char c) {
		switch (c) {
		case 'W':  return GridCellType::Wall;
		case 'F':  return GridCellType::Floor;
		case 'E':  return GridCellType::Exit;
		case 'P':  return GridCellType::Floor;
		case 'D':  return GridCellType::Door;
		case 'R':  return GridCellType::Robot;
		case 'I':  return GridCellType::CameraHackingStation;
		case 'C':  return GridCellType::Camera;
		case 'H':  return GridCellType::RobotHackingStation;
		default:
			return GridCellType::Error;
		}
	}

	static char CellTypeToChar(GridCellType t) {
		switch (t) {
		case GridCellType::Wall: return 'W';
		case GridCellType::Floor: return 'F';
		case GridCellType::Door: return 'D';
		case GridCellType::Camera: return 'C';
		case GridCellType::Robot: return 'R';
		case GridCellType::CameraHackingStation: return 'H';
		case GridCellType::RobotHackingStation: return 'K';
		case GridCellType::Exit: return 'E';
		default:
			return '.'; // TODO: ??
		}
	}
}


