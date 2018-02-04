// stdafx.cpp : 표준 포함 파일만 들어 있는 소스 파일입니다.
// Tetris2.0.pch는 미리 컴파일된 헤더가 됩니다.
// stdafx.obj에는 미리 컴파일된 형식 정보가 포함됩니다.

#include "stdafx.h"

bool Point::operator=(const Point& other) {

	if (other.x == this->x && other.y == this->y)
		return true;

	return false;
}

void GotoXy(int x, int y) {

	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

// TODO: 필요한 추가 헤더는
// 이 파일이 아닌 STDAFX.H에서 참조합니다.
