#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include "console.h"

#pragma warning (disable : 4996)

#define ESC 27
#define ENEMY_NUM 10
#define BULLET 20

struct Player {
	int speed;
	float x, y;
};

int bx, by;
int Score;

struct Enemy
{
	BOOL exist;
	int Type;
	int x, y;
	int Delta;
	int speed;
	int nStay;
}
Enemy[ENEMY_NUM];


struct Bullet
{
	BOOL exist;
	int x, y;
	int speed;
	int nStay;
}
Bull[BULLET];

const char* arEnemy[] = { " ;:^:; "," zZWZz ", " oO@Oo ", " <-=-> " };


void main()
{
	int ch;
	int i, j;
	BOOL bFound;
	int count;

	srand((unsigned)time(NULL));
	system("cls");

	struct Player player;
	player.speed = 10;      //TODO: player_speed해결하기.
	player.x = 60;
	player.y = 25;

	struct Bullet bullet;
	bullet.x = 0;
	bullet.y = 0;

	bx = -1;
	Score = 0;

	for (count = 0;; count++) {
		// 좌우 이동 처리
		if (count % 2 == 0)
		{
			while (1) {

				if (GetAsyncKeyState(VK_LEFT)) {
					player.x--;
					if (player.x < 0) {
						player.x = 0;
					}
				}

				if (GetAsyncKeyState(VK_RIGHT)) {
					player.x++;
					if (player.x > 119) {
						player.x = 119;
					}
				}
				if (GetAsyncKeyState(VK_UP)) {
					player.y--;
					if (player.y < 0) {
						player.y = 0;
					}
				}
				if (GetAsyncKeyState(VK_DOWN)) {
					player.y++;
					if (player.y > 29) {
						player.y = 29;
					}
				}

				// 적군 생성
				if (rand() % 50 == 0)
				{
					for (i = 0; i < ENEMY_NUM && Enemy[i].exist == TRUE; i++) { ; }
					if (i != ENEMY_NUM)
					{
						if ((rand() % 2) + 1 == 1)
						{
							Enemy[i].x = 5;
							Enemy[i].Delta = 1;
						}

						else
						{
							Enemy[i].x = 75;
							Enemy[i].Delta = -1;
						}

						for (;;)
						{
							Enemy[i].y = rand() % 10 + 1;
							for (bFound = FALSE, j = 0; j < ENEMY_NUM; j++)
							{
								if (Enemy[j].exist == TRUE && Enemy[j].y == Enemy[i].y)
								{
									bFound = TRUE;
									break;
								}
							}
							if (bFound == FALSE)
							{
								break;
							}
						}
						Enemy[i].speed = Enemy[i].nStay = rand() % 6 + 1;
						Enemy[i].Type = rand() % (sizeof(arEnemy) / sizeof(arEnemy[0]));
						Enemy[i].exist = TRUE;
					}
				}

				// 아군 총알 이동 및 출력
				if (bx != -1)
				{
					gotoxy(bx, by);
					putch(' ');
					if (by == 0)
					{
						bx = -1;
					}
					else
					{
						by--;
						gotoxy(bx, by);
						putch('i');
					}
				}

				// 적군과 아군 총알의 충돌 판정
				for (i = 0; i < ENEMY_NUM; i++)
				{
					if (Enemy[i].exist == FALSE)
						continue;

					if (Enemy[i].y == by && abs(Enemy[i].x - bx) <= 2)
					{
						gotoxy(bx, by); putch(' ');
						bx = -1;
						Enemy[i].exist = FALSE;
						gotoxy(Enemy[i].x - 3, Enemy[i].y);
						puts("       ");
						Score += 7 - Enemy[i].speed;
						break;
					}
				}

				// 적군 총알 이동
				for (i = 0; i < BULLET; i++)
				{
					if (Bull[i].exist == FALSE)
						continue;

					if (--Bull[i].nStay == 0)
					{
						Bull[i].nStay = Bull[i].speed;
						gotoxy(Bull[i].x, Bull[i].y); putch(' ');

						if (Bull[i].y >= 23)
						{
							Bull[i].exist = FALSE;
						}
						else
						{
							Bull[i].y++;
							gotoxy(Bull[i].x, Bull[i].y); putch('*');
						}
					}
				}

				// 적군 총알과 아군의 충돌 판정
				for (i = 0; i < BULLET; i++) {
					if (Bull[i].exist == FALSE) continue;
					if (Bull[i].y == 23 && abs(Bull[i].x - 60) <= 2) {
						gotoxy(player.x - 3, 21); puts("   .   ");
						gotoxy(player.x - 3, 22); puts(" .  . .");
						gotoxy(player.x - 3, 23); puts("..:V:..");
						Sleep(1000);

						goto end;
					}
				}

				// 적군 이동 및 출력
				for (i = 0; i < ENEMY_NUM; i++) {
					if (Enemy[i].exist == FALSE) continue;
					if (--Enemy[i].nStay == 0) {
						Enemy[i].nStay = Enemy[i].speed;
						if (Enemy[i].x >= 76 || Enemy[i].x <= 4) {
							Enemy[i].exist = FALSE;
							gotoxy(Enemy[i].x - 3, Enemy[i].y);
							puts("       ");
						}
						else
						{
							Enemy[i].x += Enemy[i].Delta;
							gotoxy(Enemy[i].x - 3, Enemy[i].y);
							puts(arEnemy[Enemy[i].Type]);
							// 총알 발사
							if (rand() % 20 == 0) {
								for (j = 0; j < BULLET && Bull[j].exist == TRUE; j++) { ; }
								if (j != BULLET) {
									Bull[j].x = Enemy[i].x + 2;
									Bull[j].y = Enemy[i].y + 1;
									Bull[j].speed = Bull[j].nStay = Enemy[i].speed * 6;
									Bull[j].exist = TRUE;
								}
							}
						}
					}
				}

				// 파이터 및 점수 출력
				gotoxy(player.x - 3, 23);
				puts(" ■ ");
				gotoxy(0, 24);
				printf("점수=%d", Score);

				// 초당 10 프레임
				Sleep(40);
			}
		end:
			system("cls");
			gotoxy(30, 10);
			printf("==========================GAMEOVER==========================\n\n");
			gotoxy(58, 15);
			printf("점수=%d\n\n\n\n\n\n\n\n\n\n\n\n", Score);
			getchar();

		}
	}
}