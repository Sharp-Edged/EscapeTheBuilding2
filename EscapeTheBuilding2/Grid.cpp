#include "Grid.h"
#include <iostream>

Grid::Grid(int _GridWidth, int _GridHeight) {
	GridWidth = _GridWidth;
	GridHeight = _GridHeight;
	Data.resize(GridWidth * GridHeight, GridCell(GridCellType::Floor));
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