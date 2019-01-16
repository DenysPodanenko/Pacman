#pragma once

#include "Pacman.h"
#include "Scene.h"
#include "Speede.h"
#include "Shadow.h"

class Game
{
private:
	Scene scene;
	Pacman pacman;
	Speede speede;
	Shadow shadow;

public:
	Game();
	Game(const std::string& mapPath);
	~Game();

	void go();
	void restart();
	void gameover();
	void gameWin();
};

