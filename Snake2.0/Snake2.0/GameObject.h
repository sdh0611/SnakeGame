#pragma once
#include "stdafx.h"

class GameObject {
public:
	GameObject(int x, int y);
	~GameObject() { };
	int GetX() { return position.x; }
	int GetY() { return position.y; }
	virtual void Init();

protected:
	Point position;

};