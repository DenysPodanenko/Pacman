#include "Scene.h"
#include <windows.h>
#include <fstream>

Scene::Scene()
:scene()
{
}

Scene::Scene(const std::vector<std::string> scene)
:scene(scene)
{
}

Scene::Scene(const std::string mapPath)
{
	std::ifstream map("map.txt");

	if (map.is_open())
	{
		std::string line;
		int maxWidth = 0;
		while (getline(map, line))
		{
			scene.push_back(line);
			if (line.length() > maxWidth)
			{
				maxWidth = line.length();
			}
		}
		map.close();
		sceneHeight = scene.size();
		sceneWidth = maxWidth;
	}
}

std::vector<std::string> Scene::getScene()
{
	return scene;
}

void Scene::createScene(const std::vector<std::string> scene)
{
	this->scene = scene;
}

void Scene::drawScene(const bool& status)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	for (std::string line : scene)
	{
		for (char c : line)
		{
			switch (c)
			{
			case'#':
				SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
				std::cout << '#';
				break;
			case'$':
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				std::cout << '$';
				break;
			case'@':
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
				std::cout << '@';
				break;
			case'*':
				if (status)
				{
					SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);
				}
				else
				{
					SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
				std::cout << c;
				break;
			default:
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				std::cout << c;
				break;
			}
		}
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::cout << std::endl;
	}
}

std::pair<int,int> Scene::getPacmanPos()
{
	for (int i = 0; i < scene.size();i++)
	{
		for (int j = 0; j < scene[i].length();j++)
		{
			if (scene[i][j] == '*')
			{
				return std::make_pair(i, j);
			}
		}
	}
}

std::pair<int, int> Scene::getShadowPos()
{
	for (int i = 0; i < scene.size(); i++)
	{
		for (int j = 0; j < scene[i].length(); j++)
		{
			if (scene[i][j] == 'H')
			{
				return std::make_pair(i, j);
			}
		}
	}
}

std::pair<int, int> Scene::getSpeedePos()
{
	for (int i = 0; i < scene.size(); i++)
	{
		for (int j = 0; j < scene[i].length(); j++)
		{
			if (scene[i][j] == 'P')
			{
				return std::make_pair(i, j);
			}
		}
	}
}

void Scene::changeScene(const int& y, const int& x, const char& newElement)
{
	scene[y][x] = newElement;
}

void Scene::changeScene(const std::pair<int, int>& point, const char& newElement)
{
	scene[point.first][point.second] = newElement;
}

int Scene::getSceneHeight()
{
	return sceneHeight;
}

int Scene::getSceneWidth()
{
	return sceneWidth;
}