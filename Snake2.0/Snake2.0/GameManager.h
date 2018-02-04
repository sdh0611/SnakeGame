#pragma once
#include "stdafx.h"

class Snake;
class Apple;
class Obstacle;

class GameManager {
public:
	GameManager();
	~GameManager();
	void Exec();

private:
	void Init();
	void Update();
	void End();

private:
	void PlayerControl();
	void RenderMap();
	void ObstcleGen();
	void IsCollsion();
	void PrintUI();

private:
	bool run;
	bool dead;
	bool isAppleGen;
	int totalScore;
	int highScore;
	Snake* player;
	Apple* apple;

};