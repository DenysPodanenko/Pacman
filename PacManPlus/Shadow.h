#pragma once
#include "Enemy.h"
class Shadow :
	public Enemy
{
private:
	char prevElem;

	bool checkPoint(Scene& scene, std::pair<int, int> point);
	bool pacmanCach;
	std::vector<std::pair<int, int>> neighborPoints(Scene& scene, std::pair<int, int> currentPoint, bool& pathFind);
	void DFS(Scene& scene, std::vector<std::pair<int, int>>& points, bool& pathFind, std::pair<int, int>& stepPoint);

public:
	Shadow();
	Shadow(std::pair<int, int> pos);
	~Shadow();

	bool getPacmanCach() const;
	std::pair<int, int> searchStepPoint(Scene scene, const std::pair<int, int>& pacmanPos);
	void move(Scene& scene, const std::pair<int, int>& pacmanPos) override;
};

