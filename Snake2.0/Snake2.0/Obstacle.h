#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Obstacle :public GameObject {
public:
	Obstacle(int x, int y);
	~Obstacle();
	void Init() override;

private:


};