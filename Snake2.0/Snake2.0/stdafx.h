//���� ����ϰԵǴ� �Լ��� ������ϵ��� ��Ƴ��� PCH

#ifndef STDAFX_H
#define STDAFX_H

#include <list>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>

//Ű�Է��� �ޱ� ���� ��ũ���Լ� ����
#define KEY_DOWN(vk_code) ( (GetAsyncKeyState(vk_code) & 0x8000)?1:0)
#define KEY_UP(vk_code) ( (GetAsyncKeyState(vk_code) & 0x8000)?0:1)

//���� ȭ���� �ʺ�� ���� ����
#define WIDTH 40
#define HEIGHT 28

//��ǥ�� ��Ÿ���� ���� Point ����ü
struct Point {
	int x;
	int y;
	bool operator==(const Point& other);
};

//������ ��Ÿ���� ���� Enum Class
enum class Direction{ 
	UP=0, DOWN, LEFT, RIGHT 
};


void GotoXy(int x, int y);
void HideCursor();

#endif