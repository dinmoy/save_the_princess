#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include "console.h"

#pragma warning (disable : 4996)

//esc �ƽ�Ű �ڵ�
#define ESC 27
//�ִ� �� ��
#define MAXENEMY 10
//�ִ� �Ѿ� ��
#define MAXBALL 10

//�÷��̾� x,y
int fx;
int fy;
//�Ѿ� x,y
int bx, by;
//����
int Score;

//�� ����ü
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

//�� ���
const char* arEnemy[] = { " ;:^:; "," zZWZz ", " oO@Oo ", " <-=-> " };



void main()
{
    int ch;
    int i, j;
    BOOL BulletFound;


    srand((unsigned)time(NULL));
    system("cls");
    CursorView(0);//Ŀ�� �����

    fx = 60;
    fy = 60;
    bx = -1;
    Score = 0;

    while (1) {
        // �¿� �̵� ó��
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

        // Ű �Է� ó��-- �Ѿ˹߻�� ����(���ݴ� �ڵ� �м�����)
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

        // ���� ����
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

                //while�� �ٲ���!
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

        // �Ʊ� �Ѿ� �̵� �� ���
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


        // ������ �Ʊ� �Ѿ��� �浹 ����
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

        // ���� �Ѿ� �̵�
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

        // ���� �Ѿ˰� �Ʊ��� �浹 ����
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

        // ���� �̵� �� ���
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
                    // �Ѿ� �߻�
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

        // ������ �� ���� ���
        gotoxy(fx - 3, 23);
        puts(" �� ");
        gotoxy(0, 24);
        printf("����=%d", Score);

        // �ʴ� 10 ������
        Sleep(40);
    }
end:
    system("cls");
    gotoxy(30, 10);
    printf("==========================GAMEOVER==========================\n\n");
    gotoxy(58, 15);
    printf("����=%d\n\n\n\n\n\n\n\n\n\n\n\n", Score);
    CursorView(0);
    getchar();

}