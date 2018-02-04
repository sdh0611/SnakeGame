//���ӿ� ���Ǵ� Obejct���� �θ� �Ǵ� Ŭ���� ����.

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
	Point position;		//Object�� ��ǥ
	std::string category;		//Object�� ī�װ�

};

#endif GAMEOBJECT_H