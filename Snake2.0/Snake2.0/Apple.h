//사용자가 습득해야 할 Apple Object의 속성과 동작을 정의한 클래스.

#ifndef APPLE_H
#define APPLE_H

#include "stdafx.h"
#include "GameObject.h"

class Apple :public GameObject {
public:
	Apple(int x, int y);
	~Apple();
	void Init() override;
	void RenderApple();
	void SetPosition(int x, int y);

};

#endif