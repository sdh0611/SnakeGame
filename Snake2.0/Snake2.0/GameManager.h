#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "stdafx.h"

//Class 전방선언
class Snake;
class Apple;

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
	void IsCollsion();
	void SpeedManager();
	void PrintUI();
	void PrintLOGO();
	void PrintTitle();
	bool IsContinue();

private:
	bool run;
	bool dead;
	int gameSpeed;
	int totalScore;
	int highScore;
	int scoreWeight;
	Snake* player;
	Apple* apple;

};

#endif