#pragma once
#include "stdafx.h"

class GameObject {
public:
	GameObject(int x, int y);
	~GameObject() { };
	int GetX() const { return position.x; }
	int GetY() const { return position.y; }
	const std::string& GetCategory() const { return category; }
	const Point& GetPosition() const { return position; }
	virtual void Init() { };

protected:
	Point position;
	std::string category;

};