#include "Shadow.h"


Shadow::Shadow()
{
}

Shadow::Shadow(std::pair<int, int> pos)
{
	this->setStartPos(pos);
	this->pos = pos;
	this->prevElem = ' ';
	this->pacmanCach = false;
}

Shadow::~Shadow()
{
}

bool Shadow::getPacmanCach() const
{
	return pacmanCach;
}

bool checkPoint(Scene& scene, std::pair<int, int> point)
{
	if (scene.getScene()[point.first][point.second] != '#' && scene.getScene()[point.first][point.second] != '-')
	{
		return true;
	}

	return false;
}

std::vector<std::pair<int, int>> Shadow::neighborPoints(Scene& scene, std::pair<int, int> currentPoint, bool& pathFind)
{
	std::vector<std::pair<int, int>> points;
	std::vector<std::pair<int, int>> directions = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

	for (int i = 0; i < 4; i++)
	{
		if (currentPoint.first != 0 && currentPoint.first != scene.getSceneHeight() && 
			currentPoint.second != 0 && currentPoint.second != scene.getSceneWidth())
		{
			std::pair<int, int> neighborPoint = std::make_pair((currentPoint.first + directions[i].first), (currentPoint.second + directions[i].second));
			if (neighborPoint == this->getPos())
			{
				pathFind = true;
			}

			if (scene.getScene()[neighborPoint.first][neighborPoint.second] != '#' && 
				scene.getScene()[neighborPoint.first][neighborPoint.second] != '-' &&
				scene.getScene()[neighborPoint.first][neighborPoint.second] != '+')
			{
				scene.changeScene(neighborPoint, '+');
				points.push_back(neighborPoint);
			}
		}
	}

	return points;
}

void Shadow::DFS(Scene& scene, std::vector<std::pair<int,int>>& points, bool& pathFind, std::pair<int,int>& stepPoint)
{
	std::vector<std::pair<int, int>> newPoints;

	
	for (std::pair<int, int> point : points)
	{
		std::vector<std::pair<int, int>> tmpVec = neighborPoints(scene, point, pathFind);
		newPoints.insert(std::end(newPoints), std::begin(tmpVec), std::end(tmpVec));
		if (pathFind)
		{
			stepPoint = point;
			break;
		}
	}
	if (!pathFind)
	{
		DFS(scene, newPoints, pathFind, stepPoint);
	}
}

std::pair<int, int> Shadow::searchStepPoint(Scene scene, const std::pair<int, int>& pacmanPos)
{
	bool pathFind = false;
	std::pair<int, int> stepPoint; 
	DFS(scene, neighborPoints(scene, pacmanPos, pathFind), pathFind, stepPoint);
	return stepPoint;
}

void Shadow::move(Scene& scene, const std::pair<int, int>& pacmanPos)
{
	std::pair<int, int> stepPoint = searchStepPoint(scene, pacmanPos);
	scene.changeScene(this->pos, prevElem);
	prevElem = scene.getScene()[stepPoint.first][stepPoint.second];
	this->pos = stepPoint;
	scene.changeScene(this->pos, 'H');
	if (pos == pacmanPos)
	{
		pacmanCach = true;
	}
}