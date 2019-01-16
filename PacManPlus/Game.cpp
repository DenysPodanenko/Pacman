#include "Game.h"

Game::Game()
:scene(), pacman()
{
}

Game::Game(const std::string& mapPath)
{
	scene = Scene(mapPath);
	pacman = Pacman(3, 0, scene.getPacmanPos());
	shadow = (scene.getShadowPos());
	speede = (scene.getSpeedePos());

}

Game::~Game()
{
}

void Game::restart()
{
	shadow.setPos(shadow.getStartPos());
	speede.setPos(speede.getStartPos());
	pacman.setPos(pacman.getStartPos());
}

void Game::go()
{
	while (pacman.getLives() > 0)
	{
		system("CLS");
		std::cout << "Score : " << pacman.getScore() << "    " << pacman.getStatus() << std::endl;
		scene.drawScene(pacman.getStatus());
		pacman.move(scene);
		shadow.move(scene, scene.getPacmanPos());
		if (shadow.getPacmanCach())
		{
			pacman.setLives(pacman.getLives() - 1);
			restart();
		}
	}

	//gameover();
}