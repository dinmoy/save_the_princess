#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include "console.h"

#pragma warning (disable : 4996)

#define ESC 27
#define MAXENEMY 10
#define MAXBALL 10

int bx, by;
int bullet_is_fired;
int Score;

struct Player
{
	int x;
	int y;
};

struct Enemy
{
	BOOL exist;
	int Type;
	int x, y;
	int cal;
	int nFrame;
	int nStay;
} Enemy[MAXENEMY];

struct Ball
{
	BOOL exist;
	int x, y;
	int nFrame;
	int nStay;
} Ball[MAXBALL];

const char* arEnemy[] = { " ;:^:; "," zZWZz ", " oO@Oo ", " <-=-> " };

void main()
{
	int ch;
	int i, j;
	BOOL BulletFound;

	srand((unsigned)time(NULL));
	system("cls");
	CursorView(0);

	struct Player player;
	player.x = 60;
	player.y = 60;
	bx = -1;
	Score = 0;

	while (1) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			if (player.x > 6)
				player.x--;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			if (player.x < 72)
				player.x++;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (player.y < 72)
				player.y++;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (player.y > 6)
				player.y--;
		}


		if (kbhit())
		{
			ch = getch();
			if (ch == 0xE0 || ch == 0)
			{
				getch();
			}
			else
			{
				switch (ch)
				{
				case ' ':
					if (bx == -1)
					{
						bx = player.x;
						by = 23;
					}
					break;
				case ESC:
					goto end;
				}
			}
		}

		if (rand() % 50 == 0)
		{
			for (i = 0; i < MAXENEMY && Enemy[i].exist == TRUE; i++) { ; }
			if (i != MAXENEMY)
			{
				if ((rand() % 2) + 1 == 1)
				{
					Enemy[i].x = 5;
					Enemy[i].cal = 1;
				}
				else
				{
					Enemy[i].x = 75;
					Enemy[i].cal = -1;
				}

				for (;;)
				{
					Enemy[i].y = rand() % 10 + 1;
					for (BulletFound = FALSE, j = 0; j < MAXENEMY; j++)
					{
						if (Enemy[j].exist == TRUE && Enemy[j].y == Enemy[i].y)
						{
							BulletFound = TRUE;
							break;
						}
					}
					if (BulletFound == FALSE)
					{
						break;
					}
				}
				Enemy[i].nFrame = Enemy[i].nStay = rand() % 6 + 1;
				Enemy[i].Type = rand() % (sizeof(arEnemy) / sizeof(arEnemy[0]));
				Enemy[i].exist = TRUE;
			}
		}

	   // 아군 총알 이동 및 출력
    if (bx != -1) {
        gotoxy(bx, by);
        putch(' ');
		
        if (by == 0) {
            bx = -1;
        } else {
            by--;
			gotoxy(bx, by);
			putch('i');
        }
    }

		for (i = 0; i < MAXENEMY; i++)
		{
			if (Enemy[i].x == 120) Enemy[i].exist = FALSE;

			if (Enemy[i].exist == FALSE)
				continue;

			if (Enemy[i].y == by && abs(Enemy[i].x - bx) <= 2)
			{
				gotoxy(bx, by); putch(' ');
				bx = -1;
				Enemy[i].exist = FALSE;
				gotoxy(Enemy[i].x - 3, Enemy[i].y);
				puts("       ");
				Score += 7 - Enemy[i].nFrame;
				break;
			}
		}

		for (i = 0; i < MAXBALL; i++)
		{
			if (Ball[i].exist == FALSE)
				continue;

			if (--Ball[i].nStay == 0)
			{
				Ball[i].nStay = Ball[i].nFrame;
				gotoxy(Ball[i].x, Ball[i].y); putch(' ');

				if (Ball[i].y >= 23)
				{
					Ball[i].exist = FALSE;
				}
				else
				{
					Ball[i].y++;
					gotoxy(Ball[i].x, Ball[i].y); putch('*');
				}
			}
		}

		for (i = 0; i < MAXBALL; i++)
		{
			if (Ball[i].exist == FALSE)
				continue;
			if (Ball[i].y == 23 && abs(Ball[i].x - player.x) <= 2)
			{
				gotoxy(player.x - 3, 21); puts("   .   ");
				gotoxy(player.x - 3, 22); puts(" .  . .");
				gotoxy(player.x - 3, 23); puts("..:V:..");
				Sleep(1000);

				goto end;
			}
		}

		for (i = 0; i < MAXENEMY; i++)
		{
			if (Enemy[i].exist == FALSE)
				continue;
			if (--Enemy[i].nStay == 0)
			{
				Enemy[i].nStay = Enemy[i].nFrame;
				if (Enemy[i].x >= 76 || Enemy[i].x <= 4)
				{
					Enemy[i].exist = FALSE;
					gotoxy(Enemy[i].x - 3, Enemy[i].y);
					puts("       ");
				}
				else
				{
					Enemy[i].x += Enemy[i].cal;
					gotoxy(Enemy[i].x - 3, Enemy[i].y);
					puts(arEnemy[Enemy[i].Type]);

					// 총알 발사
					if (rand() % 20 == 0)
					{
						for (j = 0; j < MAXBALL && Ball[j].exist == TRUE; j++) { ; }
						if (j != MAXBALL)
						{
							Ball[j].x = Enemy[i].x + 2;
							Ball[j].y = Enemy[i].y + 1;
							Ball[j].nFrame = Ball[j].nStay = Enemy[i].nFrame * 6;
							Ball[j].exist = TRUE;
						}
					}
				}
			}
		}

		// 파이터 및 점수 출력
		gotoxy(player.x - 3, 23);
		puts(" ☆ ");
		gotoxy(0, 24);
		printf("점수=%d", Score);

		// 초당 10프레임
		Sleep(40);
	}

end:
	system("cls");
	gotoxy(30, 10);
	printf("==========================GAMEOVER==========================\n\n");
	gotoxy(58, 15);
	printf("점수=%d\n\n\n\n\n\n\n\n\n\n\n\n", Score);
	CursorView(0);
	getchar();
}

