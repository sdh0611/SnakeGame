#include "stdafx.h"
#include "GameManager.h"
#include "Snake.h"
#include "Apple.h"

GameManager::GameManager() {

	run = true;


}

GameManager::~GameManager() {


}

void GameManager::Exec() {

	while (run) {
		Init();
		//std::thread obstacle
		while (!dead) {
			Update();

		}		
		End();
	}

}

void GameManager::Init() {
		
	srand(time(NULL));
	HideCursor();
	
	player = new Snake(WIDTH / 2, HEIGHT / 2);
	apple = new Apple(rand() % WIDTH + 1, rand() % HEIGHT + 1);

	isAppleGen = false;
	dead = false;
	totalScore = 0;
	highScore = 0;

	RenderMap();
	player->RenderSnake();
	
}

void GameManager::Update() {
	
	PrintUI();
	apple->RenderApple();
	PlayerControl();
	IsCollsion();
}
 
void GameManager::End() {

	if(highScore < totalScore)
		highScore = totalScore;

	delete player;
	delete apple;

	system("cls");
}

void GameManager::PlayerControl() {

	if (KEY_DOWN(VK_DOWN)) {
		player->Move(Direction::DOWN);
	}
	else if (KEY_DOWN(VK_UP)) {
		player->Move(Direction::UP);
	}
	else if (KEY_DOWN(VK_RIGHT)) {
		player->Move(Direction::RIGHT);
	}
	else if (KEY_DOWN(VK_LEFT)) {
		player->Move(Direction::LEFT);
	}
	else {
		player->MoveIdle();
	}

	_sleep(150);

}

void GameManager::RenderMap() {

	for (int i = 0; i < WIDTH+1; i++) {
		GotoXy(i, 0);
		puts("¢Ì");
		GotoXy(i, HEIGHT);
		puts("¢Ì");
	}

	for (int i = 1; i < HEIGHT; i++) {
		GotoXy(0, i);
		puts("¢Ì");
		GotoXy(WIDTH, i);
		puts("¢Ì");
	}

}

void GameManager::IsCollsion() {

	if (player->GetPosition().x == apple->GetPosition().x 
		&& player->GetPosition().y == apple->GetPosition().y) {
		totalScore += 10;
		player->GetApple();
		isAppleGen = true;
		apple->SetPosition(rand() % (WIDTH-1) + 1, rand() % (HEIGHT-1) + 1);
	}

	

	if (player->GetPosition().x > WIDTH - 1 || player->GetPosition().x < 1
		|| player->GetPosition().y > HEIGHT - 1 || player->GetPosition().y < 1) {
		dead = true;
	}

	if (player->IsBitten()) {
		dead = true;
	}

}

void GameManager::PrintUI() {

	GotoXy(WIDTH + 2, HEIGHT / 2 - 3);
	printf("Score : %d", totalScore);

}