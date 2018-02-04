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

	//�ܼ�Ŀ���� �����.
	HideCursor();

	//�ΰ� ���
	PrintLOGO();

	//Ÿ��Ʋȭ�� ���. Enter�� ������ ������ ���۵ȴ�
	while (!run) {
		PrintTitle();
		if (KEY_DOWN(VK_RETURN)) 
			run = true;
		
	}

	//���� ����
	while (run) {
		//GameManager�� �Ӽ� �ʱ�ȭ.
		Init();

		//���� �� ���� �÷��� ����.
		//���� �ʾ��� ��� ��� ������ ������.
		while (!dead) {
			//���� �� �÷��� ��Ȳ ������Ʈ
			Update();
		}		

		//�װ� �� �� GameObject���� �����ϰ�, �ٽ� �� ������ �����.
		End();
	}

}

//GameManager�� �Ӽ��� �ʱ�ȭ. 
//������ �絵�� �� ��� �ٽ� ȣ��Ǳ⵵ �Ѵ�.
void GameManager::Init() {
		
	system("cls");
	srand(time(NULL));
	
	player = new Snake(WIDTH / 2, HEIGHT / 2);
	apple = new Apple(rand() % (WIDTH-1) + 1, rand() % (HEIGHT-1) + 1);

	dead = false;
	totalScore = 0;		//�� ���� �ʱ�ȭ
	scoreWeight = 10;	//���� ����ġ �ʱ�ȭ
	gameSpeed = 7;		//���� ���ǵ� �ʱ�ȭ

	RenderMap();
	player->RenderSnake();
	
}

//���� �� �÷��� ��Ȳ�� ������Ʈ�ϴ� �޼ҵ�.
void GameManager::Update() {
	
	PrintUI();
	apple->RenderApple();
	PlayerControl();
	IsCollsion();

}
 
//Player�� ���� �� Object�� �����ϰ� �ٽ� �� �� ���� �����
void GameManager::End() {

	if(highScore < totalScore)
		highScore = totalScore;

	delete player;
	delete apple;

	//�ٽ� �÷����� ���� ���.
	while (!IsContinue());

}

//Ű �Է��� �����Ѵ�.
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

//�� ���
void GameManager::RenderMap() {

	//���� �� ���
	for (int i = 0; i < WIDTH+1; i++) {
		GotoXy(i, 0);		puts("��");
		GotoXy(i, HEIGHT);		puts("��");
	}

	//���� �� ���
	for (int i = 1; i < HEIGHT; i++) {
		GotoXy(0, i);		puts("��");
		GotoXy(WIDTH, i);		puts("��");
	}

}

//�浹 �˻�
void GameManager::IsCollsion() {

	//Snake�� Apple�� �����Ͽ����� �˻��Ѵ�.
	if (player->GetPosition().x == apple->GetPosition().x 
		&& player->GetPosition().y == apple->GetPosition().y) {

		totalScore += scoreWeight;
		if (highScore < totalScore)
			highScore = totalScore;

		//���ھ� ���� �� ���ǵ� ����
		SpeedManager();

		player->GetApple();
		apple->SetPosition(rand() % (WIDTH-1) + 1, rand() % (HEIGHT-1) + 1);
	}

	//Snake�� �������� �������� �˻�
	if (player->GetPosition().x > WIDTH - 1 || player->GetPosition().x < 1
		|| player->GetPosition().y > HEIGHT - 1 || player->GetPosition().y < 1) {
		dead = true;
	}

	//Snake�� �ڽ��� ���� �浹�Ͽ����� �˻�
	if (player->IsBitten()) {
		dead = true;
	}

}

//���� ���ǵ� ����
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

//���� �� UI ���
void GameManager::PrintUI() {

	GotoXy(WIDTH + 2, HEIGHT / 2 - 3);		printf("HighScore : %d", highScore);
	GotoXy(WIDTH + 2, HEIGHT / 2 - 2); 	printf("Score : %d", totalScore);

	GotoXy(WIDTH + 2+2, HEIGHT / 2 + 1);	   	  puts("��");
	GotoXy(WIDTH + 2+1, HEIGHT / 2 + 2);		puts("��  ��");
	GotoXy(WIDTH + 2+2, HEIGHT / 2 + 3);		  puts("��");
}

//�ΰ� ���
void GameManager::PrintLOGO() {

	GotoXy(WIDTH / 2-3, HEIGHT / 2);
	puts("- Made by SDH -");
	Sleep(2000);
	system("cls");
	Sleep(500);
}

//Ÿ��Ʋ ȭ�� ���
void GameManager::PrintTitle() {

	RenderMap();
	GotoXy(WIDTH / 2 - 4, HEIGHT / 2 - 1);
	puts("Welcome SnakeGame !");
	GotoXy(WIDTH / 2 - 5, HEIGHT / 2 + 1);
	puts("<Press Enter to start>");

}

//������ �ٽ� �Ұ��� ���.
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