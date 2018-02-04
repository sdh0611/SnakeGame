// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"
#include <list>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>

#define KEY_DOWN(vk_code) ( (GetAsyncKeyState(vk_code) & 0x8000)?1:0)
#define KEY_UP(vk_code) ( (GetAsyncKeyState(vk_code) & 0x8000)?0:1)

#define WIDTH 30
#define HEIGHT 20

struct Point {
	int x;
	int y;
	bool operator==(const Point& other);
};

enum class Direction{ 
	UP=0, DOWN, LEFT, RIGHT 
};


void GotoXy(int x, int y);
void HideCursor();


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
