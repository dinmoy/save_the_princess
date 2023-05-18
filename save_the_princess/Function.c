#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>

#pragma warning (disable : 4996)

//esc 아스키 코드
#define ESC 27
//최대 적 수
#define MAXENEMY 20
//최대 총알 수
#define MAXBULLET 10

//점수
int Score;
struct Player {
    int x, y;
};

//적 구조체
struct Enemy
{
    BOOL exist;
    //적의 종류
    int Type;
    int x, y;
    //적이 좌우로 움직일 때 사용하는 변수
    int movementcal;

    //적의 움직임 애니메이션을 표현하기 위한 변수
    int nFrame;
    int nStay;
}
Enemy[MAXENEMY];


struct Bullet
{
    BOOL exist;
    int x, y;
    int nFrame;
    int nStay;
}
Bullet[MAXBULLET];

//적 모양
const char* Type_Enemy[] = { " ;:^:; "," zZWZz ", " oO@Oo ", " <-=-> " };


void drawscreen() {
    textcolor(14);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■                                                                        ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}
void Function()
{

    int ch;
    int i, j;
    BOOL BulletFound;


    srand((unsigned)time(NULL));
    system("cls");
    //CursorView(0);//커서 숨기기

    struct Player player;
    player.x = 60;
    player.y = 60;

    struct Bullet bullet;
    bullet.x = -1;
    bullet.y = 0;
    Score = 0;
    drawscreen();

    while (1) {

        // 좌우 이동 처리
        if (GetAsyncKeyState(VK_LEFT))
        {
            if (player.x > 6)
                player.x--;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            if (player.x < 72)
                player.x++;
        }
        if (GetAsyncKeyState(VK_UP))
        {
            if (player.y < 72)
                player.y++;
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            if (player.y > 6)
                player.x--;
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
                case ' ': // Space
                    if (bullet.x == -1)
                    {
                        bullet.x = player.x;
                        bullet.y = 23;
                    }
                    break;
                case ESC:
                    goto end;
                }
            }
        }

        // 아군 총알 이동 및 출력
        if (bullet.x != -1)
        {
            gotoxy(bullet.x, bullet.y);
            putch('  ');
            bullet.y--;
            if (bullet.y <= 2) { // y 좌표가 0 이하일 때 총알 삭제
                gotoxy(bullet.x, bullet.y);
                putch(' ');
                bullet.x = -1;
                bullet.y = -1;
            }
            else {
                gotoxy(bullet.x, bullet.y);
                putch('i');
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
                    Enemy[i].x = 7;
                    Enemy[i].y = 30;
                    Enemy[i].movementcal = 1;
                }

                else
                {
                    Enemy[i].x = 70;
                    Enemy[i].movementcal = -1;
                }

                //while로 바꾸장!
                for (;;) {
                    Enemy[i].y = rand() % 15 + 2;
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
                Enemy[i].Type = rand() % (sizeof(Type_Enemy) / sizeof(Type_Enemy[0])); //random(sizeof(Type_Enemy) / sizeof(Type_Enemy[0]));
                Enemy[i].exist = TRUE;
            }
        }


        // 적군과 아군 총알의 충돌 판정
        for (i = 0; i < MAXENEMY; i++)
        {
            if (Enemy[i].x == 120) Enemy[i].exist = FALSE;

            if (Enemy[i].exist == FALSE)
                continue;

            if (Enemy[i].y == bullet.y && abs(Enemy[i].x - bullet.x) <= 2)
            {
                gotoxy(bullet.x, bullet.y); putch(' ');
                bullet.x = -1;
                Enemy[i].exist = FALSE;
                gotoxy(Enemy[i].x - 3, Enemy[i].y);
                puts("       ");
                Score += Enemy[i].nFrame;
                break;
            }
        }

        // 적군 총알 이동
        for (i = 0; i < MAXBULLET; i++)
        {
            if (Bullet[i].exist == FALSE)
                continue;

            if (--Bullet[i].nStay == 0)
            {
                Bullet[i].nStay = Bullet[i].nFrame;
                gotoxy(Bullet[i].x, Bullet[i].y); putch(' ');

                if (Bullet[i].y >= 23)
                {
                    Bullet[i].exist = FALSE;
                }
                else
                {
                    Bullet[i].y++;
                    gotoxy(Bullet[i].x, Bullet[i].y); putch('*');
                }
            }

        }

        // 적군 총알과 아군의 충돌 판정
        for (i = 0; i < MAXBULLET; i++) {
            if (Bullet[i].exist == FALSE) continue;
            if (Bullet[i].y == 23 && abs(Bullet[i].x - player.x) <= 2) {
                gotoxy(player.x - 3, 21); puts("   .   ");
                gotoxy(player.x - 3, 22); puts(" .  . .");
                gotoxy(player.x - 3, 23); puts("..:V:..");
                Sleep(1000);

                goto end;
            }
        }

        // 적군 이동 및 출력
        for (i = 0; i < MAXENEMY; i++) {
            if (Enemy[i].exist == FALSE) continue;
            if (--Enemy[i].nStay == 0) {
                Enemy[i].nStay = Enemy[i].nFrame;
                if (Enemy[i].x >= 69 || Enemy[i].x <= 6) {
                    Enemy[i].exist = FALSE;
                    gotoxy(Enemy[i].x - 3, Enemy[i].y);
                    puts("       ");
                }
                else
                {
                    Enemy[i].x += Enemy[i].movementcal;
                    gotoxy(Enemy[i].x - 3, Enemy[i].y);
                    puts(Type_Enemy[Enemy[i].Type]);
                    // 총알 발사
                    if (rand() % 20 == 0) {
                        for (j = 0; j < MAXBULLET && Bullet[j].exist == TRUE; j++) { ; }
                        if (j != MAXBULLET) {
                            Bullet[j].x = Enemy[i].x + 2;
                            Bullet[j].y = Enemy[i].y + 1;
                            Bullet[j].nFrame = Bullet[j].nStay = Enemy[i].nFrame * 6;
                            Bullet[j].exist = TRUE;
                        }
                    }
                }
            }
        }



        // 파이터 및 점수 출력
        CursorView(0);
        gotoxy(player.x - 3, 23);
        puts(" ☆ ");
        gotoxy(67, 2);
        printf("점수: %d", Score);

        gotoxy(85, 7);
        printf("♣작전명! 공주를 구하라♣");
        gotoxy(85, 11);
        printf("★플레이어 이동 방법★");
        gotoxy(85, 13);
        printf("↑ ↓ ← →를 이용하여 이동");
        gotoxy(85, 15);
        printf("스페이스바 ==> 공격");

        // 초당 10 프레임
        Sleep(40);
    }
end:
    /*system("cls");
    gotoxy(30, 10);
    printf("==========================GAMEOVER==========================\n\n");
    gotoxy(58, 15);
    printf("점수=%d\n\n\n\n\n\n\n\n\n\n\n\n", Score);
    CursorView(0);
    getchar();*/
    textcolor(15);
    Over();

}