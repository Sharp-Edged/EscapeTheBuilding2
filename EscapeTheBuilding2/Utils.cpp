#include "Utils.h"
#include "Common.h"


vector<string> levels = { 
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
	"WFFFFFFFFFFFFFFWFFFWFFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFFFFFFFFWFFFWFFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFFFFFFFFWFFFDFFFFFFFFFIFFFFFFFFFW"
	"WWWWWWWWWWDWWWWWFFFWFFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFFFFCFFFFFFFWFFFFFFFFFFFFFFFFFFFW"
	"WEFFFFFFFFFFFFFFFFFWWWWWWWWWWWWWWWWWWWWW"
	"WFFFFFFFFFFFFFFFFFFWFFFFFFFFFFFFFFFFFFFW"
	"WWWWWWWWDWWWWWWWFFFWFFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFFFFFFFFWFFFWFFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFFFFFFFFWFFFWFFFFFFFFWWWWWWWWWWWW"
	"WFFFFFFFFFFFFFFWFFFDFFFFFFFFWFFFFFFFFFFW"
	"WFFFFFFFFFFFFFFWFFFWFFFFFFFFWFFFFFFFFFFW"
	"WFFFFFFFFFFFFFHWFFFWFFFFFFFFWFFFFFFFFFFW"
	"WFFFFFWWWWWWWWWWFFFWFFFFFFFFWFFFFFFFFFFW"
	"WFFFFFWFFFFFFFFWFFFWFFFFFFFFWFFFFFFFFFFW"
	"WFFFFFWFFFFFFFFWFFFWFFFFFFFFWFFFFFFFFFFW"
	"WFFFFFWFFFFFFFFDFFFWFFFFFFFFWFFFFFFFFFFW"
	"WFFFFFDFFFFFFFFWFFFWWWWDWWWWWWWWWDWWWWWW"
	"WFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFFW"
	"WFFFRFWFFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFPW"
	"WFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFFW"
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
	, 
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
	"WFFFFFFFFFFFFFFFWFFFFFFFFFFWHFFFFFFFFFFW"
	"WFFFFFFFFFFFFFFFWFFFFRFFFFFWFFFFFFFFFFFW"
	"WFFFFFFFFFFFFFFFWFFFFFFFFFFWFFFFFFFFFFFW"
	"WFFFFFFFFFFFFFFFWFFFFFFFFFFWFFFFFFFFFFFW"
	"WFFFFFFFFFFFFFFFWFFFFFFFFFFWFFFFFFFFFFFW"
	"WFFFFFFFWWWWWWWWWFFFFFFFFFFWWWWWWWDWWWWW"
	"WFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFWFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFW"
	"WWWWDWWWWWWWWWWWWWWWWWDWWWWWWWWWWWWWWWWW"
	"WFFFFFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFW"
	"WEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFW"
	"WWWDWWWWWWDWWWWFFFWWWDWWWWWWWWWWWDWWWWWW"
	"WFFFFFWFFFFFFFWFFFWFFFFFFFWFFFFFFFFFFFFW"
	"WFFFFFWFFFFFFFWFFFWFFFFFFFWFFFFFFFFFFFFW"
	"WFFFFFWFFFFFFFWFFFWFFFFFFFWFFFFFFFFFFFFW"
	"WFFFFFWFFFFFFFWFFFWFFFFFFFWWWWFFFFFFFFFW"
	"WFFFFFWFFFFFFFWFFFWFFFFFFFFFFWFFFFFFFFFW"
	"WFFFFFWFFFFFFFWFPFWFFFFFFFFFFWFFFFFFFFIW"
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
	, 
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
	"WFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFIFFW"
	"WFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFW"
	"WFFFFFFFFFFWFFFFFFFFWFFFFFFFFFFFFFFFFFFW"
	"WWWWWWWWDWWWWWWWDWWWWWWFFFFFFFFFFFFFFFFW"
	"WFFFFFFFFFFFFFFFFFFFFCWFFFFFFFFFFFFFFFFW"
	"WPFFFFFFFFFFFFFFFFFFFFWFFFFFFFFWWWWWWWWW"
	"WFFFFFFFFFFFFFFFFFFFFFDFFFFFFFFWFFFFFFFW"
	"WWWDWWWWWWWWDWWWWWWFFFWFFFFFFFFWFFFFFFFW"
	"WFFFFFWFFFFFFFFFFFWFFFWWWWWWWWWWFFFFFFFW"
	"WFFFFFWFFFFFFFFFFFWFFFWFFFFFFFFFFFFFFFFW"
	"WFFFFFWFFFFFFFFFFFWFFFWFFFFFFFFFFFFFFFFW"
	"WFFFFFWFFFFFFFFFFFWFFFDFFFFFFFFFFFFFFFFW"
	"WFFFFFWHFFFFFFFFFFWFFFWFFFFFFFFFFFFFFFFW"
	"WFFFFFWWWWWFFFFFFFWFFFWWWWWWWWWWFFFFFFFW"
	"WFFFFFFFFFWFFFFFFFWFFFWFFFFFFFFWFFFFFFFW"
	"WFFFFFFFFFWFFFRFFFWFFFDFFFFFFFFWFFFFFFFW"
	"WFFFFFFFFFWFFFFFFFWFEFWFFFFFFFFWFFFFFFFW"
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
};

ConversionResult levelToGrid(int levelID) {
	if (levelID < 0 || levelID >(int) levels.size()) {
		cout << "KURWA!\n";
		exit(64);
	}

	int w = 40; // TODO: La numera magica
	int h = 23;
	int playerIdx = 0;
	
	string level = levels[levelID];

	Grid grid(w, h);
	for (int i = 0; i < w * h; i++) {
		GridCellType cellType = GridHelpers::CharToCellType(level[i]);

		// TODO: Dirty?
		if (level[i] == 'P') {
			playerIdx = i;
		}

		grid.SetCell(i % w, i / w, GridCell(cellType));
	}
	int playerY = playerIdx / w;
	int playerX = playerIdx % w;
	return ConversionResult(grid, playerX, playerY);
}