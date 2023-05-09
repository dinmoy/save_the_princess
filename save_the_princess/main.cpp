#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include "console.h"

#pragma warning (disable : 4996)

//esc 아스키 코드
#define ESC 27
//최대 적 수
#define MAXENEMY 10
//최대 총알 수
#define MAXBALL 10

//플레이어 x,y
int fx;
int fy;
//총알 x,y
int bx, by;
//점수
int Score;

//적 구조체
struct Enemy
{
    BOOL exist;
    int Type;
    int x, y;
    int cal;
    int nFrame;
    int nStay;
}
Enemy[MAXENEMY];


struct Ball
{
    BOOL exist;
    int x, y;
    int nFrame;
    int nStay;
}
Ball[MAXBALL];

//적 모양
const char* arEnemy[] = { " ;:^:; "," zZWZz ", " oO@Oo ", " <-=-> " };



void main()
{
    int ch;
    int i, j;
    BOOL BulletFound;


    srand((unsigned)time(NULL));
    system("cls");
    CursorView(0);//커서 숨기기

    fx = 60;
    fy = 60;
    bx = -1;
    Score = 0;

    while (1) {
        // 좌우 이동 처리
        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
            if (fx > 6)
                fx--;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
            if (fx < 72)
                fx++;
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            if (fy < 72)
                fy++;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            if (fy > 6)
                fx--;
        }

        // 키 입력 처리-- 총알발사랑 종료(조금더 코드 분석하자)
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
                case ' '://Space
                    if (bx == -1)
                    {
                        bx = fx;
                        by = 23;
                    }
                    break;
                case ESC:
                    goto end;
                }
            }
        }

        // 적군 생성
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

                //while로 바꾸장!
                for (;;) {
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
                Enemy[i].Type = rand() % (sizeof(arEnemy) / sizeof(arEnemy[0])); //random(sizeof(arEnemy) / sizeof(arEnemy[0]));
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

        // 적군 총알 이동
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

        // 적군 총알과 아군의 충돌 판정
        for (i = 0; i < MAXBALL; i++) {
            if (Ball[i].exist == FALSE) continue;
            if (Ball[i].y == 23 && abs(Ball[i].x - fx) <= 2) {
                gotoxy(fx - 3, 21); puts("   .   ");
                gotoxy(fx - 3, 22); puts(" .  . .");
                gotoxy(fx - 3, 23); puts("..:V:..");
                Sleep(1000);

                goto end;
            }
        }

        // 적군 이동 및 출력
        for (i = 0; i < MAXENEMY; i++) {
            if (Enemy[i].exist == FALSE) continue;
            if (--Enemy[i].nStay == 0) {
                Enemy[i].nStay = Enemy[i].nFrame;
                if (Enemy[i].x >= 76 || Enemy[i].x <= 4) {
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
                    if (rand() % 20 == 0) {
                        for (j = 0; j < MAXBALL && Ball[j].exist == TRUE; j++) { ; }
                        if (j != MAXBALL) {
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
        gotoxy(fx - 3, 23);
        puts(" ☆ ");
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
    CursorView(0);
    getchar();

}