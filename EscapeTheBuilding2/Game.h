#pragma once
#include "BearLibTerminal.h"
#include "Common.h"
#include "ButtonList.h"

enum class GameState {
	MainMenu,
	Game,
	Settings,
	Quit
};

class Game {
private:
	
public:
	GameState gameState;

	Game();
	void OpenMainMenu();
};