#include "stdafx.h"
#include "Snake.h"

Snake::Snake(int x, int y) : GameObject(x, y) {

	Init();

}

Snake::~Snake(){ }


bool Snake::GetApple() {

	

}

bool Snake::IsBitten() {


}

void Snake::Move(const Direction direction) {

	switch (direction) {
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

}

void Snake::RenderSnake() {

	for (auto lt = body.begin(); lt != body.end(); ++lt) {
		Gotoxy(*(*lt).x, *(*lt).y, );
	}

}

void Snake::Init() {

	direction = Direction::RIGHT;
	hungry = true;
	length = 2;
	body.emplace_back(Point(position));
	body.emplace_back(Point{ position.x - 1, position.y });


}

void Snake::UpdateTails() {

	body.push_front(position);
	body.pop_back();

}

void Snake::MoveUp() {
	
	direction = Direction::UP;
	position.y--;
	UpdateTails();

}

void Snake::MoveDown() {

	direction = Direction::DOWN;
	position.y++;
	UpdateTails();

}

void Snake::MoveRight() {

	direction = Direction::RIGHT;
	position.x++;
	UpdateTails();

}

void Snake::MoveLeft() {

	direction = Direction::LEFT;
	position.x--;
	UpdateTails();

}


