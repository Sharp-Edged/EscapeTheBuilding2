#include "Grid.h"
#include <iostream>

Grid::Grid(int _GridWidth, int _GridHeight) {
	GridWidth = _GridWidth;
	GridHeight = _GridHeight;
	Data.resize(GridWidth * GridHeight, GridCell(GridCellType::Floor));
}

bool Grid::InBounds(int x, int y) {
	return 0 <= x && x < GridWidth && 0 <= y && y < GridHeight;
}

GridCell& Grid::GetCell(int x, int y) {
	int idx = y * GridWidth + x;
	if (idx >= Data.size()) {
		std::cout << "Index to large\n";
		throw std::exception();
	}
	return Data[idx];
}

GridCell& Grid::GetCell(int idx) {
	if (idx >= Data.size()) {
		std::cout << "Index to large\n";
		throw std::exception();
	}
	return Data[idx];
}

void Grid::SetCell(int x, int y, GridCell Cell) {
	int idx = y * GridWidth + x;
	if (idx >= Data.size()) {
		std::cout << "Index to large\n";
		throw std::exception();
	}
	Data[idx] = Cell;
}

void Grid::SetCell(int idx, GridCell Cell) {
	if (idx >= Data.size()) {
		std::cout << "Index to large\n";
		throw std::exception();
	}
	Data[idx] = Cell;
}

int Grid::DataLen() {
	return Data.size();
}

bool Grid::IsWall(int x, int y) {
	return InBounds(x, y) && GetCell(x, y).CellType == GridCellType::Wall;
}

bool Grid::IsDoor(int x, int y) {
	return InBounds(x, y) && GetCell(x, y).CellType == GridCellType::Door;
}

int Grid::GetWallCharacter(int x, int y) {
	vector<bool> adjWalls = {	IsWall(x, y - 1) || IsDoor(x, y - 1), 
								IsWall(x + 1, y) || IsDoor(x + 1, y),
								IsWall(x, y + 1) || IsDoor(x, y + 1),
								IsWall(x - 1, y) || IsDoor(x - 1, y)
	};

	if (adjWalls == vector<bool>{0, 1, 0, 1}) return 0x2500; // '─'
	if (adjWalls == vector<bool>{1, 0, 1, 0}) return 0x2502; // '│'

	if (adjWalls == vector<bool>{0, 0, 1, 1}) return 0x2510; // '┐'
	if (adjWalls == vector<bool>{1, 1, 0, 0}) return 0x2514; // '└'
	if (adjWalls == vector<bool>{1, 0, 0, 1}) return 0x2518; // '┘'
	if (adjWalls == vector<bool>{0, 1, 1, 0}) return 0x250C; // '┌'

	if (adjWalls == vector<bool>{1, 1, 1, 0}) return 0x251C; // '├'
	if (adjWalls == vector<bool>{1, 0, 1, 1}) return 0x2524; // '┤'
	if (adjWalls == vector<bool>{0, 1, 1, 1}) return 0x252C; // '┬'
	if (adjWalls == vector<bool>{1, 1, 0, 1}) return 0x2534; // '┴'
	if (adjWalls == vector<bool>{1, 1, 1, 1}) return 0x253C; // '┼'

	return 'x';
}