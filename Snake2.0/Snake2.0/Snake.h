//Snake.h
//Player가 플레이 할 Snake의 속성과 동작을 정의한 클래스

#ifndef SNAKE_H
#define SNAKE_H

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
	const int GetLength() const { return length; }

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

#endif SNAKE_H