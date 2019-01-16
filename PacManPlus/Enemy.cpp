#include "Enemy.h"

void Enemy::setPos(std::pair<int, int> pos)
{
	this->pos = pos;
}

std::pair<int, int> Enemy::getPos()
{
	return pos;
}

void Enemy::setStartPos(std::pair<int, int> startPos)
{
	this->startPos = startPos;
}

std::pair<int, int> Enemy::getStartPos()
{
	return startPos;
}