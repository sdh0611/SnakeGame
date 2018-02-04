#include "stdafx.h"
#include "Snake.h"

Snake::Snake(int x, int y) : GameObject(x, y) {

	Init();

}

Snake::~Snake(){ }

//Apple을 습득했을 때의 행동.
//hungry 변수를 false로 초기화 하고, 길이를 증가시킨다.
void Snake::GetApple() {

	hungry = false;
	++length;
}

//뱀이 자신의 몸과 충돌했는지 검사하는 메소드.
bool Snake::IsBitten() {

	auto lt = body.begin();

	for (++lt; lt != body.end(); ++lt) 
		if (position == *lt) 
			return true;
	
	return false;

}

//뱀의 움직임에 대해 정의해놓은 메소드.
//진행방향의 반대방향으로는 움직이지 못하게 해놓음
//사과를 습득하지 않은 경우 맨끝부분을 지우고,
//사과를 습득한 경우 그대로 냅둔다.
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

//키입력을 하지 않고있을 때의 동작을 정의한 메소드.
//Move()와 거의 동일하다.
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

//뱀을 화면에 출력하기 위한 메소드.
void Snake::RenderSnake() {

	auto lt = body.begin();
	
	//머리 Render
	GotoXy(lt->x, lt->y);
	puts("●");

	//꼬리 Render
	for (++lt; lt != body.end(); ++lt) {
		GotoXy(lt->x, lt->y);
		puts("○");
	}

}

//뱀의 속성들을 출력한다.
void Snake::Init() {

	direction = Direction::RIGHT;		//뱀의 처음 진행방향 정의(오른쪽)
	hungry = true;	
	length = 2;		//뱀의 길이 : 2
	category = "snake";
	body.push_back(position);
	body.emplace_back(Point{ position.x - 1, position.y });

}

//뱀의 끝부분을 지운다.
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


