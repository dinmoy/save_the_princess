#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include "console.h"

#define ESC 27
#define MAXENEMY 10
#define BULLET 20


struct Enemy
{
	BOOL exist;
	int Type;
	int x, y;
	int Delta;
	int nFrame;
	int nStay;
}
Enemy[MAXENEMY];

struct Player {
	int speed;
	float x, y;
	int life;
};

struct Bullet {
	int x, y;
	int is_fired;   //발사 여부
};

void main() {

	int count;
	struct Player player;
	player.speed = 10;      //TODO: player_speed해결하기.
	player.x = 60;
	player.y = 25;
	player.life = 3;

	struct Bullet bullet;
	bullet.is_fired = 0;
	bullet.x = 0;
	bullet.y = 0;

	srand((unsigned)time(NULL));
	CursorView(0);//커서 숨기기

	for (count = 0;; count++) {
		if (count % 2 == 0) {
			
			Clearscreen();
			if (IsKeyDown(VK_LEFT))
			{
				player.x--;
				if (player.x > 6)
					player.x = 0;
			}
			if (IsKeyDown(VK_RIGHT))
			{
				player.x++;
				if (player.x < 72)
					player.x = 72;
			}
			if (IsKeyDown(VK_UP))
			{
				player.y--;
				if (player.y < 0)
					player.y = 0;
			}
			if (IsKeyDown(VK_DOWN))
			{
				player.y++;
				if (player.y > 29)
					player.y = 29;
			}
			if (IsKeyDown(VK_SPACE)) {
				if (GetAsyncKeyState(VK_SPACE)) {
					bullet.x = player.x;
					bullet.y = player.y - 1;
					bullet.is_fired = 1;   //화살이 발사 될때
				}
			}
		}
		if (bullet.is_fired)   //화살 발사 여부
		{
			gotoxy(bullet.x, bullet.y);
			printf("▲");
			bullet.y--;
			if (bullet.y < 0) {
				bullet.is_fired = 0;
			}
		}
		gotoxy(player.x, player.y);
		printf("■");

	}

	system("pause");
}

