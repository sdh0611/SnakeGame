//자주 사용하게되는 함수와 헤더파일들을 모아놓은 PCH

#ifndef STDAFX_H
#define STDAFX_H

#include <list>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>

//키입력을 받기 위한 매크로함수 정의
#define KEY_DOWN(vk_code) ( (GetAsyncKeyState(vk_code) & 0x8000)?1:0)
#define KEY_UP(vk_code) ( (GetAsyncKeyState(vk_code) & 0x8000)?0:1)

//게임 화면의 너비와 높이 정의
#define WIDTH 40
#define HEIGHT 28

//좌표를 나타내기 위한 Point 구조체
struct Point {
	int x;
	int y;
	bool operator==(const Point& other);
};

//방향을 나타내기 위한 Enum Class
enum class Direction{ 
	UP=0, DOWN, LEFT, RIGHT 
};


void GotoXy(int x, int y);
void HideCursor();

#endif