#include "stdafx.h"
#include "GameManager.h"
#include "Snake.h"
#include "Apple.h"

GameManager::GameManager() {

	run = false;
	highScore = 0;

}

GameManager::~GameManager() {


}

void GameManager::Exec() {

	//콘솔커서를 지운다.
	HideCursor();

	//로고 출력
	PrintLOGO();

	//타이틀화면 출력. Enter를 누르면 게임이 시작된다
	while (!run) {
		PrintTitle();
		if (KEY_DOWN(VK_RETURN)) 
			run = true;
		
	}

	//게임 시작
	while (run) {
		//GameManager의 속성 초기화.
		Init();

		//게임 내 실제 플레이 루프.
		//죽지 않았을 경우 계속 루프를 돌린다.
		while (!dead) {
			//게임 내 플레이 현황 업데이트
			Update();
		}		

		//죽고 난 후 GameObject들을 정리하고, 다시 할 것인지 물어본다.
		End();
	}

}

//GameManager의 속성을 초기화. 
//게임을 재도전 할 경우 다시 호출되기도 한다.
void GameManager::Init() {
		
	system("cls");
	srand(time(NULL));
	
	player = new Snake(WIDTH / 2, HEIGHT / 2);
	apple = new Apple(rand() % (WIDTH-1) + 1, rand() % (HEIGHT-1) + 1);

	dead = false;
	totalScore = 0;		//총 점수 초기화
	scoreWeight = 10;	//점수 가중치 초기화
	gameSpeed = 7;		//게임 스피드 초기화

	RenderMap();
	player->RenderSnake();
	
}

//게임 내 플레이 현황을 업데이트하는 메소드.
void GameManager::Update() {
	
	PrintUI();
	apple->RenderApple();
	PlayerControl();
	IsCollsion();

}
 
//Player가 죽은 뒤 Object를 정리하고 다시 할 것 인지 물어본다
void GameManager::End() {

	if(highScore < totalScore)
		highScore = totalScore;

	delete player;
	delete apple;

	//다시 플레이할 건지 물어봄.
	while (!IsContinue());

}

//키 입력을 감지한다.
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

	Sleep(1000/gameSpeed);

}

//맵 출력
void GameManager::RenderMap() {

	//가로 벽 출력
	for (int i = 0; i < WIDTH+1; i++) {
		GotoXy(i, 0);		puts("▩");
		GotoXy(i, HEIGHT);		puts("▩");
	}

	//세로 벽 출력
	for (int i = 1; i < HEIGHT; i++) {
		GotoXy(0, i);		puts("▩");
		GotoXy(WIDTH, i);		puts("▩");
	}

}

//충돌 검사
void GameManager::IsCollsion() {

	//Snake가 Apple을 습득하였는지 검사한다.
	if (player->GetPosition().x == apple->GetPosition().x 
		&& player->GetPosition().y == apple->GetPosition().y) {

		totalScore += scoreWeight;
		if (highScore < totalScore)
			highScore = totalScore;

		//스코어 점검 후 스피드 조정
		SpeedManager();

		player->GetApple();
		apple->SetPosition(rand() % (WIDTH-1) + 1, rand() % (HEIGHT-1) + 1);
	}

	//Snake가 벽밖으로 나갔는지 검사
	if (player->GetPosition().x > WIDTH - 1 || player->GetPosition().x < 1
		|| player->GetPosition().y > HEIGHT - 1 || player->GetPosition().y < 1) {
		dead = true;
	}

	//Snake가 자신의 몸과 충돌하였는지 검사
	if (player->IsBitten()) {
		dead = true;
	}

}

//게임 스피드 조절
void GameManager::SpeedManager() {

	if (totalScore == 100) {
		scoreWeight = 20;
		gameSpeed += 2;
	}
	if (totalScore == 300) {
		scoreWeight = 30;
		gameSpeed += 2;
	}
	if (totalScore == 750) {
		scoreWeight = 35;
		++gameSpeed;
	}
	if (totalScore == 1240) {
		scoreWeight = 40;
		++gameSpeed;
	}

}

//게임 내 UI 출력
void GameManager::PrintUI() {

	GotoXy(WIDTH + 2, HEIGHT / 2 - 3);		printf("HighScore : %d", highScore);
	GotoXy(WIDTH + 2, HEIGHT / 2 - 2); 	printf("Score : %d", totalScore);

	GotoXy(WIDTH + 2+2, HEIGHT / 2 + 1);	   	  puts("▲");
	GotoXy(WIDTH + 2+1, HEIGHT / 2 + 2);		puts("◀  ▶");
	GotoXy(WIDTH + 2+2, HEIGHT / 2 + 3);		  puts("▼");
}

//로고 출력
void GameManager::PrintLOGO() {

	GotoXy(WIDTH / 2-3, HEIGHT / 2);
	puts("- Made by SDH -");
	Sleep(2000);
	system("cls");
	Sleep(500);
}

//타이틀 화면 출력
void GameManager::PrintTitle() {

	RenderMap();
	GotoXy(WIDTH / 2 - 4, HEIGHT / 2 - 1);
	puts("Welcome SnakeGame !");
	GotoXy(WIDTH / 2 - 5, HEIGHT / 2 + 1);
	puts("<Press Enter to start>");

}

//게임을 다시 할건지 물어봄.
bool GameManager::IsContinue() {

	GotoXy(WIDTH/2 + 2-4, HEIGHT / 2-1);		puts("You Dead...");
	GotoXy(WIDTH/2 + 2-11, HEIGHT / 2+1);		puts("<If you want to restart, press Enter>");
	GotoXy(WIDTH/2 + 2-11, HEIGHT / 2+2);		puts("<If you want to exit game, press ESC>");

	if (KEY_DOWN(VK_RETURN)) {
		return true;
	}
	else if (KEY_DOWN(VK_ESCAPE)) {
		run = false;
		return true;
	}

	return false;

}