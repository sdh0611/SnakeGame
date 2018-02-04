#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Apple :public GameObject {
public:
	Apple(int x, int y);
	~Apple();
	void Init() override;
	void RenderApple();
	void SetPosition(int x, int y);

private:



};