#pragma once
#include "BearLibTerminal.h"
#include "Common.h"
#include "ButtonList.h"
#include "Grid.h"
#include "Player.h"

enum class GameState {
	MainMenu,
	Game,
	Settings,
	Quit
};

class Game {
private:
	Grid& Level;
	Player player;
public:
	GameState gameState;

	Game(Grid& _Level);
	void OpenMainMenu();
	void ShowMainMenu();
	void MainLoop();
	void MovePlayer(int CharCode);
	void IlluminateMap();
};