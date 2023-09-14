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

	bool InBounds(int x, int y);

	GridCell& GetCell(int x, int y);
	GridCell& GetCell(int idx);

	void SetCell(int x, int y, GridCell Cell);
	void SetCell(int idx, GridCell Cell);

	bool IsWall(int x, int y);
	bool IsDoor(int x, int y);
	int GetWallCharacter(int x, int y);

	int DataLen();
};