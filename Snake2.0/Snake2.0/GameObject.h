//게임에 사용되는 Obejct들의 부모가 되는 클래스 정의.

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "stdafx.h"

class GameObject {
public:
	GameObject(int x, int y);
	~GameObject() { };
	const std::string& GetCategory() const { return category; }
	const Point& GetPosition() const { return position; }
	virtual void Init() { };

protected:
	Point position;		//Object의 좌표
	std::string category;		//Object의 카테고리

};

#endif GAMEOBJECT_H