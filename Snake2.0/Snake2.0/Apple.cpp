#include "stdafx.h"
#include "Apple.h"

Apple::Apple(int x, int y) :GameObject(x, y) {

	Init();

}

Apple::~Apple() {

}

//Apple�� �Ӽ� �ʱ�ȭ
void Apple::Init() {

	category = "apple";

}

//Apple�� ȭ��� ����ϱ� ���� �޼ҵ�.
void Apple::RenderApple() {

	GotoXy(position.x, position.y);
	puts("��");

}

//Apple�� ��ġ�� ������.
void Apple::SetPosition(int x, int y) {

	position = { x, y };

}