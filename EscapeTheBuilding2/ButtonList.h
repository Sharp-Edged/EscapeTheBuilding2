#pragma once
#include <string>
#include <functional>
#include <vector>

#include "BearLibTerminal.h"
#include "Common.h"

class ButtonList {
private:
	struct Button {
		std::string text;
		std::function<void()> func;
		Button(std::string _text, std::function<void()> _func) : text(_text), func(_func) {}
	};

	std::vector<Button> buttons;

	int selectedButton = 0;
	int firstRow;
	int buttonSpacing;
	int buttonAlignment;
public:
	ButtonList(int _firstRow, int _buttonSpacing, int _buttonAlignment);
	void AddButton(std::string name, std::function<void()> func);
	void SelectButton(int button);
	void Display();
	bool HandleKey(int key);
};