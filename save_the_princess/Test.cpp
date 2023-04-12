#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#pragma warning (disable : 4996)

#define ESC 27
#define MAXENEMY 10
#define MAXBALL 20

int fx;
int bx, by;
int Score;

void gotoxy(int x, int y)
{
    COORD Pos = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void CursorView(char show)//커서숨기기
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}


struct tag_Enemy
{
    BOOL exist;
    int Type;
    int x, y;
    int Delta;
    int nFrame;
    int nStay;
}
Enemy[MAXENEMY];


struct tag_Ball
{
    BOOL exist;
    int x, y;
    int nFrame;
    int nStay;
}
Ball[MAXBALL];

const char* arEnemy[] = { " ;:^:; "," zZWZz ", " oO@Oo ", " <-=-> " };

BOOL IsKeyDown(int Key)
{
    return ((GetAsyncKeyState(Key) & 0x8000) != 0);
}


void main()
{
    int ch;
    int i, j;
    BOOL bFound;
    int count;

    srand((unsigned)time(NULL));
    system("cls");
    CursorView(0);//커서 숨기기

    fx = 60;
    bx = -1;
    Score = 0;

    for (count = 0;; count++) {
        // 좌우 이동 처리
        if (count % 2 == 0)
        {
            if (IsKeyDown(VK_LEFT))
            {
                if (fx > 6)
                    fx--;
            }
            if (IsKeyDown(VK_RIGHT))
            {
                if (fx < 72)
                    fx++;
            }
        }

        // 키 입력 처리
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
                    for (bFound = FALSE, j = 0; j < MAXENEMY; j++)
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
                    Enemy[i].x += Enemy[i].Delta;
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
        puts(" <<A>> ");
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