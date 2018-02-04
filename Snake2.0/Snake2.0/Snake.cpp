#include "stdafx.h"
#include "Snake.h"

Snake::Snake(int x, int y) : GameObject(x, y) {

	Init();

}

Snake::~Snake(){ }

//Apple�� �������� ���� �ൿ.
//hungry ������ false�� �ʱ�ȭ �ϰ�, ���̸� ������Ų��.
void Snake::GetApple() {

	hungry = false;
	++length;
}

//���� �ڽ��� ���� �浹�ߴ��� �˻��ϴ� �޼ҵ�.
bool Snake::IsBitten() {

	auto lt = body.begin();

	for (++lt; lt != body.end(); ++lt) 
		if (position == *lt) 
			return true;
	
	return false;

}

//���� �����ӿ� ���� �����س��� �޼ҵ�.
//��������� �ݴ�������δ� �������� ���ϰ� �س���
//����� �������� ���� ��� �ǳ��κ��� �����,
//����� ������ ��� �״�� ���д�.
void Snake::Move(const Direction direction) {

	switch (direction) {
	case Direction::DOWN:
		if (this->direction == Direction::UP) {
			MoveIdle();
			return;
		}
		MoveDown();
		break;
	case Direction::UP:
		if (this->direction == Direction::DOWN) {
			MoveIdle();
			return;
		}
		MoveUp();
		break;
	case Direction::RIGHT:
		if (this->direction == Direction::LEFT) {
			MoveIdle();
			return;
		}
		MoveRight();
		break;
	case Direction::LEFT:
		if (this->direction == Direction::RIGHT){
			MoveIdle();
			return;
		}
		MoveLeft();
		break;
	}

	RenderSnake();

	if (hungry)
		EraseTail();
	else
		hungry = true;
	
}

//Ű�Է��� ���� �ʰ����� ���� ������ ������ �޼ҵ�.
//Move()�� ���� �����ϴ�.
void Snake::MoveIdle() {

	switch (this->direction) {
	case Direction::DOWN:
		MoveDown();
		break;
	case Direction::UP:
		MoveUp();
		break;
	case Direction::RIGHT:
		MoveRight();
		break;
	case Direction::LEFT:
		MoveLeft();
		break;
	}

	RenderSnake();

	if (hungry)
		EraseTail();
	else
		hungry = true;
}

//���� ȭ�鿡 ����ϱ� ���� �޼ҵ�.
void Snake::RenderSnake() {

	auto lt = body.begin();
	
	//�Ӹ� Render
	GotoXy(lt->x, lt->y);
	puts("��");

	//���� Render
	for (++lt; lt != body.end(); ++lt) {
		GotoXy(lt->x, lt->y);
		puts("��");
	}

}

//���� �Ӽ����� ����Ѵ�.
void Snake::Init() {

	direction = Direction::RIGHT;		//���� ó�� ������� ����(������)
	hungry = true;	
	length = 2;		//���� ���� : 2
	category = "snake";
	body.push_back(position);
	body.emplace_back(Point{ position.x - 1, position.y });

}

//���� ���κ��� �����.
void Snake::EraseTail() {

	GotoXy(body.back().x, body.back().y);
	puts("  ");
	body.pop_back();

}


void Snake::MoveUp() {
	
	direction = Direction::UP;
	position.y--;
	body.push_front(position);

}

void Snake::MoveDown() {

	direction = Direction::DOWN;
	position.y++;
	body.push_front(position);

}

void Snake::MoveRight() {

	direction = Direction::RIGHT;
	position.x++;
	body.push_front(position);

}

void Snake::MoveLeft() {

	direction = Direction::LEFT;
	position.x--;
	body.push_front(position);

}


