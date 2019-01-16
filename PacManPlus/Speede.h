#pragma once

#include "Enemy.h"

class Speede :
	public Enemy
{
public:
	Speede();
	Speede(std::pair<int, int> pos);
	~Speede();

	void move(Scene& scene, const std::pair<int, int>& pacmanPos) override;
};

