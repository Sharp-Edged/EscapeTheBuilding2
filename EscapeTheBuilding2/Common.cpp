#include "Common.h"

void TerminalUtility::PrintCentered(int row, std::string text) {
	int offset = (WIDTH - text.size()) / 2;
	terminal_print(offset, row, text.c_str());
}