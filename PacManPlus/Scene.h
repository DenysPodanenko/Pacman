#pragma once

#include<iostream>
#include<vector>
#include<string>

class Scene
{
private:
	std::vector<std::string> scene;
	int sceneWidth;
	int sceneHeight;

public:
	Scene();
	Scene(const std::vector<std::string> scene);
	Scene(const std::string mapPath);

	void drawScene(const bool& status);
	std::vector<std::string> getScene();
	void createScene(const std::vector<std::string> scene);
	std::pair<int, int> getPacmanPos();
	std::pair<int, int> getShadowPos();
	std::pair<int, int> getSpeedePos();
	void changeScene(const int& y, const int& x, const char& newElement);
	void changeScene(const std::pair<int, int>& point, const char& newElement);
	int getSceneWidth();
	int getSceneHeight();
};

