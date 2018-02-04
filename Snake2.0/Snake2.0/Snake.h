#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Snake : public GameObject {
public:
	Snake(int x, int y);
	~Snake();

public:
	void GetApple();
	bool IsBitten();
	void Move(const Direction direction);
	void MoveIdle();
	void RenderSnake();
	virtual void Init() override;

private:
	void EraseTail();
	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();

private:
	int length;
	bool hungry;
	Direction direction;
	std::list<Point> body;
	

};