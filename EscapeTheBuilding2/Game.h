#pragma once
#include "BearLibTerminal.h"
#include "Common.h"
#include "Grid.h"
#include "Player.h"

class Game {
private:
	Grid& Level;
	Player player;
public:
	Game(Grid& _Level);
	void ShowMainMenu();
	void MainLoop();
	void MovePlayer(int CharCode);
	void IlluminateMap();
};