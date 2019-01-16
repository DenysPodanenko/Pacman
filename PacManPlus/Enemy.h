#pragma once

#include "Scene.h"

class Enemy
{
protected:
	std::pair<int, int> startPos;
	std::pair<int, int> pos;

public:
	virtual ~Enemy() {}

	void setPos(std::pair<int, int> pos);
	std::pair<int, int> getPos();
	void setStartPos(std::pair<int, int> startPos);
	std::pair<int, int> getStartPos();
	virtual void move(Scene& scene, const std::pair<int, int>& pacmanPos) = 0;
};

