#include "Pacman.h"
#include <conio.h>

Pacman::Pacman()
:lives(), score(), status(), pos(), oldPos(), startPos(), stepCounter()
{
}

Pacman::Pacman(const int lives, const int score, const std::pair<int, int> pos)
: lives(lives), score(score), status(false), pos(pos), startPos(pos), oldPos(), stepCounter(0)
{
}

int Pacman::getLives() const 
{
	return lives;
}

int Pacman::getScore() const
{
	return score;
}

bool Pacman::getStatus() const
{
	return status;
}

void Pacman::setLives(const int lives)
{
	this->lives = lives;
}

void Pacman::setStatus(const bool status)
{
	this->status = status;
}

void Pacman::setPos(const std::pair<int, int> pos)
{
	this->pos = pos;
}

void Pacman::setPos(const int x, const int y)
{
	this->pos = std::make_pair(y, x);
}

std::pair<int, int> Pacman::getPos() const
{
	return pos;
}

void Pacman::setStartPos(std::pair<int, int> startPos)
{
	this->startPos = startPos;
}

std::pair<int, int> Pacman::getStartPos() const
{
	return startPos;
}

void Pacman::setDirection(const char direction)
{
	this->direction = direction;
}

char Pacman::getDirection() const
{
	return direction;
}

void Pacman::changeDirection()
{
	if (_kbhit()) {
		direction = tolower(_getch());
	}
}

void Pacman::makeStep(Scene& scene, const int& yNew, const int& xNew)
{
	scene.changeScene(oldPos, ' ');

	if (scene.getScene()[yNew][xNew] == '$')
	{
		score++;
	}
	if (scene.getScene()[yNew][xNew] == '0')
	{
		setStatus(true);
		stepCounter = 0;
	}
	setPos(std::make_pair(yNew, xNew));
	scene.changeScene(pos, '*');
}

void Pacman::move(Scene& scene)
{
	oldPos = pos;
	oldDirection = direction;
	changeDirection();

	switch (direction)
	{
	case'a':
		if (oldPos.second - 1 < 0)
		{
			makeStep(scene, oldPos.first, (scene.getSceneWidth() - 1));
		}
		else if (scene.getScene()[oldPos.first][oldPos.second - 1] == '#' || scene.getScene()[oldPos.first][oldPos.second - 1] == '-')
		{
			direction = oldDirection;
		}
		else 
		{
			makeStep(scene, oldPos.first, (oldPos.second - 1));
		}
		break;
	case'w':
		if (oldPos.first - 1 < 0)
		{
			makeStep(scene, (scene.getSceneHeight() - 1), oldPos.second);
		}
		else if (scene.getScene()[oldPos.first - 1][oldPos.second] == '#' || scene.getScene()[oldPos.first - 1][oldPos.second] == '-')
		{
			direction = oldDirection;
		}
		else
		{
			makeStep(scene, (oldPos.first - 1), oldPos.second);
		}
		break;
	case'd':
		if (oldPos.second + 1 > (scene.getSceneWidth() - 1))
		{
			makeStep(scene, oldPos.first, 0);
		}
		else if (scene.getScene()[oldPos.first][oldPos.second + 1] == '#' || scene.getScene()[oldPos.first][oldPos.second + 1] == '-')
		{
			direction = oldDirection;
		}
		else
		{
			makeStep(scene, oldPos.first, (oldPos.second + 1));
		}
		break;
	case's':
		if (oldPos.first + 1 > (scene.getSceneHeight()-1))
		{
			makeStep(scene, 0, oldPos.second);

		}
		else if (scene.getScene()[oldPos.first + 1][oldPos.second] == '#' || scene.getScene()[oldPos.first + 1][oldPos.second] == '-')
		{
			direction = oldDirection;
		}
		else
		{
			makeStep(scene, (oldPos.first + 1), oldPos.second);
		}
		break;
	default:
		break;
	}
	if (status)
	{
		stepCounter++;
		if (stepCounter == 70)
		{
			stepCounter = 0;
			status = false;
		}
	}
}