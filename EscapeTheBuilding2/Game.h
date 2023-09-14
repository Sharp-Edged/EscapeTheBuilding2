#pragma once
#include "BearLibTerminal.h"
#include "Common.h"
#include "ButtonList.h"
#include "Grid.h"
#include "Player.h"
#include "Inventory.h"

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
	bool inventoryOpen;

public:
	GameState gameState;

	Game(Grid& _Level);
	
	void OpenMainMenu();
	void OpenSettings();
    void StartGame();
	void DrawMap();
	void SetPlayerCoords(int x, int y);
	
	void DisplayStatusBar();

	void MovePlayer(int CharCode);
};