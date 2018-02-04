// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
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


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
