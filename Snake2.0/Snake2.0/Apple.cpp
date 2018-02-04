#include "stdafx.h"
#include "Apple.h"

Apple::Apple(int x, int y) :GameObject(x, y) {

	Init();

}

Apple::~Apple() {

}

//Apple의 속성 초기화
void Apple::Init() {

	category = "apple";

}

//Apple을 화면상에 출력하기 위한 메소드.
void Apple::RenderApple() {

	GotoXy(position.x, position.y);
	puts("＠");

}

//Apple의 위치를 변경함.
void Apple::SetPosition(int x, int y) {

	position = { x, y };

}