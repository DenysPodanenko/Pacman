#include "Speede.h"


Speede::Speede()
{
}

Speede::Speede(std::pair<int, int> pos)
{
	this->setStartPos(pos);
	this->pos = pos;
}

Speede::~Speede()
{
}

void Speede::move(Scene& scene, const std::pair<int, int>& pacmanPos)
{

}