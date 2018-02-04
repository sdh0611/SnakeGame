// stdafx.cpp : ǥ�� ���� ���ϸ� ��� �ִ� �ҽ� �����Դϴ�.
// Tetris2.0.pch�� �̸� �����ϵ� ����� �˴ϴ�.
// stdafx.obj���� �̸� �����ϵ� ���� ������ ���Ե˴ϴ�.

#include "stdafx.h"

bool Point::operator== (const Point& other) {

	if (other.x == this->x && other.y == this->y)
		return true;

	return false;
}

void GotoXy(int x, int y) {

	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void HideCursor() {

	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	info.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

}

// TODO: �ʿ��� �߰� �����
// �� ������ �ƴ� STDAFX.H���� �����մϴ�.
