#pragma once
#include "Common.h"

enum class GridCellType {
	Wall,
	Floor,
	Robot,
	Camera,
	Door,
	Interactable,
	None
};

struct GridCell {
	GridCellType CellType;
	bool Visible;
	GridCell() {
		CellType = GridCellType::None;
		Visible = false;
	}
	GridCell(GridCellType Type, bool _Visibility) {
		CellType = Type;
		Visible = _Visibility;
	}
};

class Grid {
private:
	vector<GridCell> Data;
	int GridWidth;
	int GridHeight;
public:
	Grid(int _GridWidth, int _GridHeight);

	GridCell& GetCell(int x, int y);
	GridCell& GetCell(int idx);
	void SetCell(int x, int y, GridCell Cell);
	void SetCell(int idx, GridCell Cell);
	void SetVisibility(int x, int y, bool Visible);
	int DataLen();
};