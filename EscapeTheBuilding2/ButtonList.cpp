#include "ButtonList.h"

ButtonList::ButtonList(int _firstRow, int _buttonSpacing, int _buttonAlignment) {
	firstRow = _firstRow;
	buttonSpacing = _buttonSpacing;
	buttonAlignment = _buttonAlignment;
}

void ButtonList::AddButton(std::string name, std::function<void()> func) {
	buttons.emplace_back(name, func);
}

void ButtonList::SelectButton(int button) {
	selectedButton = button;
}

void ButtonList::Display() {
	int currentRow = firstRow;
	for (int i = 0; i < (int)buttons.size(); i++) {
		if (selectedButton == i) { terminal_color("orange"); }
		
		terminal_print_ext(0, currentRow, WIDTH, 1, buttonAlignment, buttons[i].text.c_str());

		terminal_color("white");
		
		currentRow += buttonSpacing;
	}
}

bool ButtonList::HandleKey(int key) {
	if (key == TK_UP || key == TK_W) {
		selectedButton = (selectedButton - 1 + buttons.size()) % buttons.size();
	}
	else if (key == TK_DOWN || key == TK_S) {
		selectedButton = (selectedButton + 1) % buttons.size();
	}
	else if (key == TK_ENTER) {
		buttons[selectedButton].func();
		return 1;
	}
	return 0;
}