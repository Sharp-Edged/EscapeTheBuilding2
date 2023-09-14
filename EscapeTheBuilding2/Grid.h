#pragma once
#include "Common.h"

enum class GridCellType {
	Wall,
	Floor,
	Robot,
	Camera,
	Door,
	RobotHackingStation,
	CameraHackingStation,
	Exit,
	Error,
	None
};

struct GridCell {
	GridCellType CellType;
	GridCell() {
		CellType = GridCellType::None;
	}
	GridCell(GridCellType Type) {
		CellType = Type;
	}
};

class Grid {
private:
	vector<GridCell> Data;
public:
	int GridWidth;
	int GridHeight;

	Grid(int _GridWidth, int _GridHeight);

	GridCell& GetCell(int x, int y);
	GridCell& GetCell(int idx);
	void SetCell(int x, int y, GridCell Cell);
	void SetCell(int idx, GridCell Cell);
	int DataLen();
};