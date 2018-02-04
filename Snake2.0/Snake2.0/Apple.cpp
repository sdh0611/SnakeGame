#include "stdafx.h"
#include "Apple.h"

Apple::Apple(int x, int y) :GameObject(x, y) {

	Init();

}

Apple::~Apple() {

}

void Apple::Init() {

	category = "apple";

}

void Apple::RenderApple() {

	GotoXy(position.x, position.y);
	puts("£À");

}

void Apple::SetPosition(int x, int y) {

	position = { x, y };

}