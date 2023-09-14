#include "Utils.h"
#include <array>


const char* lvl1 = "(WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWFFFFFFFFFFFFFFWFFFWFFFFFFFFFFFFFFFFFFFWWFFFFFFFFFFFFFFWFFFWFFFFFFFFFFFFFFFFFFFWWFFFFFFFFFFFFFFWFFFDFFFFFFFFFIFFFFFFFFFWWWWWWWWWWWDWWWWWFFFWFFFFFFFFFFFFFFFFFFFWWFFFFFFFFFFCFFFFFFFWFFFFFFFFFFFFFFFFFFFWWEFFFFFFFFFFFFFFFFFWWWWWWWWWWWWWWWWWWWWWWFFFFFFFFFFFFFFFFFFWFFFFFFFFFFFFFFFFFFFWWWWWWWWWDWWWWWWWFFFWFFFFFFFFFFFFFFFFFFFWWFFFFFFFFFFFFFFWFFFWFFFFFFFFFFFFFFFFFFFWWFFFFFFFFFFFFFFWFFFWFFFFFFFFWWWWWWWWWWWWWFFFFFFFFFFFFFFWFFFDFFFFFFFFWFFFFFFFFFFWWFFFFFFFFFFFFFFWFFFWFFFFFFFFWFFFFFFFFFFWWFFFFFFFFFFFFFHWFFFWFFFFFFFFWFFFFFFFFFFWWFFFFFWWWWWWWWWWFFFWFFFFFFFFWFFFFFFFFFFWWFFFFFWFFFFFFFFWFFFWFFFFFFFFWFFFFFFFFFFWWFFFFFWFFFFFFFFWFFFWFFFFFFFFWFFFFFFFFFFWWFFFFFWFFFFFFFFDFFFWFFFFFFFFWFFFFFFFFFFWWFFFFFDFFFFFFFFWFFFWWWWDWWWWWWWWWDWWWWWWWFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFFWWFFFRFWFFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFPWWFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFFWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW";

const char* lvl2 = "(WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWFFFFFFFFFFFFFFFWFFFFFFFFFFWHFFFFFFFFFFWWFFFFFFFFFFFFFFFWFFFFRFFFFFWFFFFFFFFFFFWWFFFFFFFFFFFFFFFWFFFFFFFFFFWFFFFFFFFFFFWWFFFFFFFFFFFFFFFWFFFFFFFFFFWFFFFFFFFFFFWWFFFFFFFFFFFFFFFWFFFFFFFFFFWFFFFFFFFFFFWWFFFFFFFWWWWWWWWWFFFFFFFFFFWWWWWWWDWWWWWWFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFWWFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFWWFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFWWFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFWWWWWDWWWWWWWWWWWWWWWWWDWWWWWWWWWWWWWWWWWWFFFFFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFWWEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFWWFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFWWWWDWWWWWWDWWWWFFFWWWDWWWWWWWWWWWDWWWWWWWFFFFFWFFFFFFFWFFFWFFFFFFFWFFFFFFFFFFFFWWFFFFFWFFFFFFFWFFFWFFFFFFFWFFFFFFFFFFFFWWFFFFFWFFFFFFFWFFFWFFFFFFFWFFFFFFFFFFFFWWFFFFFWFFFFFFFWFFFWFFFFFFFWWWWFFFFFFFFFWWFFFFFWFFFFFFFWFFFWFFFFFFFFFFWFFFFFFFFFWWFFFFFWFFFFFFFWFPFWFFFFFFFFFFWFFFFFFFFIWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW";

const char* lvl3 = "(WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFWWFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFIFFWWFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFWWFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFWWFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFWWFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFWWFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFWWWWWWWWWDWWWWWWWDWWWWWWFFFFFFFFFFFFFFFFWWFFFFFFFFFFFFFFFFFFFFCWFFFFFFFFFFFFFFFFWWPFFFFFFFFFFFFFFFFFFFFWFFFFFFFFWWWWWWWWWWFFFFFFFFFFFFFFFFFFFFFDFFFFFFFFWFFFFFFFWWWWDWWWWWWWWDWWWWWWFFFWFFFFFFFFWFFFFFFFWWFFFFFWFFFFFFFFFFFWFFFWWWWWWWWWWFFFFFFFWWFFFFFWFFFFFFFFFFFWFFFWFFFFFFFFFFFFFFFFWWFFFFFWFFFFFFFFFFFWFFFWFFFFFFFFFFFFFFFFWWFFFFFWFFFFFFFFFFFWFFFDFFFFFFFFFFFFFFFFWWFFFFFWHFFFFFFFFFFWFFFWFFFFFFFFFFFFFFFFWWFFFFFWWWWWFFFFFFFWFFFWWWWWWWWWWFFFFFFFWWFFFFFFFFFWFFFFFFFWFFFWFFFFFFFFWFFFFFFFWWFFFFFFFFFWFFFRFFFWFFFDFFFFFFFFWFFFFFFFWWFFFFFFFFFWFFFFFFFWFEFWFFFFFFFFWFFFFFFFWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW";

const char* getLevelData(int lvl) {
	switch (lvl) {
	case 1:return lvl1;
	case 2:return lvl2;
	case 3:return lvl3;
	}
	return nullptr;
}

ConversionResult lvlToGrid(const char* lvl) {
	if (!lvl) {
		std::cout << "NE RADI LVL BLJIN!\n";
		exit(64);
	}
	int w = lvl[0];
	int h = lvl[1];
	int playerIdx = 0;
	Grid grid(w, h);
	for (int i = 2; i < w * h + 2; i++) {
		GridCellType ty = GridCellType::None;
		switch (lvl[i]) {
		case 'W':  ty = GridCellType::Wall; break;
		case 'F':  ty = GridCellType::Floor; break;
		case 'E':  ty = GridCellType::Exit; break;
		case 'P': {
			playerIdx = i - 2; 
			ty = GridCellType::Floor;
			break;
		}
		case 'D':  ty = GridCellType::Door; break;
		case 'R':  ty = GridCellType::Robot; break;
		case 'I':  ty = GridCellType::CameraHackingStation; break;
		case 'C':  ty = GridCellType::Camera; break;
		case 'H':  ty = GridCellType::RobotHackingStation; break;
		}
		grid.SetCell(i - 2, GridCell(ty, false));
	}
	int playerY = playerIdx / w;
	int playerX = playerIdx % w;
	return ConversionResult(grid, playerX, playerY);
}