//����ڰ� �����ؾ� �� Apple Object�� �Ӽ��� ������ ������ Ŭ����.

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