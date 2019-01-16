#pragma once

#include "Scene.h"

class Pacman
{
private:
	int lives;
	int score;
	bool status;
	std::pair<int, int> pos;
	std::pair<int, int> oldPos;
	std::pair<int, int> startPos;
	char direction;
	char oldDirection;
	int stepCounter;

	void setStatus(const bool status);
	void makeStep(Scene& scene, const int& xNew, const int& yNew);
	void changeDirection();
public:
	Pacman();
	Pacman(const int lives, const int score, const std::pair<int, int> pos);

	void setLives(const int lives);
	int getLives() const;
	int getScore() const;
	bool getStatus() const;
	void setPos(const std::pair<int, int> pos);
	void setPos(const int x, const int y);
	std::pair<int, int> getPos() const;
	void setStartPos(std::pair<int, int> startPos);
	std::pair<int, int> getStartPos() const;
	void setDirection(const char direction);
	char getDirection() const;
	void move(Scene& scene);
};

