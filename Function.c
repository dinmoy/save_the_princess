#include <stdio.h> u
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>

#pragma warning (disable : 4996)

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

#define ESC 27
#define MAXENEMY 4
#define MAXBALL 10

void SuccessDraw();   //제목 출력
void init2();        //콘솔창 크기함수 
int Successmenu();     //메뉴 출력&선택 함수 
int S_keyControl();   //화살표 선택하는 거

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
    int Frame;
    int Stay;
}
Enemy[MAXENEMY];


struct Bullet
{
    BOOL exist;
    int x, y;
    int Frame;
    int Stay;
}
Bullet[MAXBALL];

const char* Type_Enemy[] = { " ◈◈◈ ", " ●__● ", " ⊙o⊙ ", " ＠＠＠ " };

void textcolor(int colorNum) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void drawscreen() {
    textcolor(14);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ ┌──────────────────────────────────┐\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■                                                                        ■ │                                  │\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ └──────────────────────────────────┘\n");
}


void Function()
{

    int ch;
    int i, j;
    BOOL BulletFound;


    srand((unsigned)time(NULL));
    system("cls");
    

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
        int available = -1;
        for (int i = 0; i < MAXENEMY; i++) {
            if (Enemy[i].exist == FALSE) {
                available = i;
                break;
            }
        }

        if (available != -1) {
            int position=0;
            int newX, newY;

            do {
                position= 0;
                if ((rand() % 2) + 1 == 1) {
                    newX = 7;
                    Enemy[available].movementcal = 1;
                }
                else {
                    newX = 70;
                    Enemy[available].movementcal = -1;
                }
                newY = rand() % 10 + 2;

                for (int j = 0; j < MAXENEMY; j++) {
                    if (Enemy[j].exist && (Enemy[j].x == newX && Enemy[j].y == newY)) {
                        position = 1;
                        break;
                    }
                }
            } while (position);

            Enemy[available].x = newX;
            Enemy[available].y = newY;
            Enemy[available].Frame = Enemy[available].Stay = rand() % 6 + 1;
            Enemy[available].Type = rand() % (sizeof(Type_Enemy) / sizeof(Type_Enemy[0]));
            Enemy[available].exist = TRUE;
        }


        // 적군과 아군 총알의 충돌 판정
        for (i = 0; i < MAXENEMY; i++)
        {
            if (Enemy[i].x > 120|| Enemy[i].y <=2) Enemy[i].exist = FALSE;

            if (Enemy[i].exist == FALSE)
                continue;

            if (Enemy[i].y == bullet.y && abs(Enemy[i].x - bullet.x) <= 2)
            {
                gotoxy(bullet.x, bullet.y); putch(' ');
                bullet.x = -1;
                Enemy[i].exist = FALSE;
                gotoxy(Enemy[i].x - 3, Enemy[i].y);
                puts("       ");
                Score += 5;
                if (Score == 50) Success();
                break;

            }

        }

        // 적군 총알 이동
        for (i = 0; i < MAXBALL; i++)
        {
            if (Bullet[i].exist == FALSE)
                continue;

            if (--Bullet[i].Stay == 0)
            {
                Bullet[i].Stay = Bullet[i].Frame;
                gotoxy(Bullet[i].x, Bullet[i].y); putch(' ');

                if (Bullet[i].y >= 23)
                {
                    Bullet[i].exist = FALSE;
                }
                else
                {
                    Bullet[i].y++;
                    gotoxy(Bullet[i].x, Bullet[i].y); putch('●');
                }
            }

        }

        // 적군 총알과 아군의 충돌 판정
        for (i = 0; i < MAXBALL; i++) {
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
            if (--Enemy[i].Stay == 0) {
                Enemy[i].Stay = Enemy[i].Frame;
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
                        for (j = 0; j < MAXBALL && Bullet[j].exist == TRUE; j++) { ; }
                        if (j != MAXBALL) {
                            Bullet[j].x = Enemy[i].x + 2;
                            Bullet[j].y = Enemy[i].y + 1;
                            Bullet[j].Frame = Bullet[j].Stay = Enemy[i].Frame * 6;
                            Bullet[j].exist = TRUE;
                        }
                    }
                }
            }
        }



        // 파이터 및 점수 출력
        CursorView(0);
        gotoxy(player.x - 3, 23);
        puts(" ★ ");
        gotoxy(67, 2);
        printf("점수: %d", Score);

        gotoxy(82, 4);
        printf("♣작전명! 공주를 구하여라~♣");

        gotoxy(80, 7);
        printf("=============미션!===============\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t적을 공격하여 공주를 지켜내라!");
       
        gotoxy(80, 11);
        printf("해당키를 사용하여 적을 공격하라!");

        printf("\n");

        gotoxy(80, 15);
        printf("\t\t오른쪽 : →");

        gotoxy(80, 17);
        printf("\t\t왼쪽   : ← \n");

        gotoxy(80, 19);
        printf("\t\t공격   : SPACE\n\n");


        // 초당 10 프레임
        Sleep(40);
    }
end:
    textcolor(15);
    Over();

}
//main함수 
int Success()
{
    PlaySound(TEXT("Successbgm.wav"), NULL, SND_ASYNC | SND_LOOP);
    while (1)
    {
        init2();
        SuccessDraw();
        Successmenu();
    }
}
//콘솔 화면 지정 함수 
void init2() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}

//제목 출력 함수  \n");
void SuccessDraw()
{
    int x = 5,y = 1;
    textcolor(14);
    gotoxy(x, y++); printf("\t\t\t\t  __   __  ___   _______  _______  ___   _______  __    _");
    gotoxy(x, y++); printf("\t\t\t\t |  |_|  ||   | |       ||       ||   | |       ||  |  | |");
    gotoxy(x, y++); printf("\t\t\t\t |       ||   | |  _____ || _____||   | |   _   ||   |_| |");
    gotoxy(x, y++); printf("\t\t\t\t |       ||   | | |_____ | |_____ |   | |  | |  ||       |");
    gotoxy(x, y++); printf("\t\t\t\t |       ||   | |_____ || _____  ||   | |  |_|  ||  _    |");
    gotoxy(x, y++); printf("\t\t\t\t | ||_|| ||   |  _____| | _____| ||   | |       || | |   |");
    gotoxy(x, y++); printf("\t\t\t\t |_|   |_||___| |_______||_______||___| |_______||_|  |__|");
    gotoxy(x, y++); printf("\t\t\t\t _______  __   __  _______  _______  _______  _______  _______");
    gotoxy(x, y++); printf("\t\t\t\t|       ||  | |  ||       ||       ||       ||       ||       |");
    gotoxy(x, y++); printf("\t\t\t\t|  _____||  | |  ||       ||       ||    ___||  _____||  _____|");
    gotoxy(x, y++); printf("\t\t\t\t| |_____ |  |_|  ||       ||       ||   |___ | |_____ | |_____ ");
    gotoxy(x, y++); printf("\t\t\t\t| _____ ||       ||      _||      _||   _____|| _____|| ____  |");
    gotoxy(x, y++); printf("\t\t\t\t  _____|||       ||     |_ |     |_ |   |___  _____| | _____| |");
    gotoxy(x, y++); printf("\t\t\t\t|_______||_______||_______||_______||_______||_______||_______|");
    gotoxy(x, y++);
    gotoxy(x, y++); printf("                                          \t\t\t|▶ ");
    gotoxy(x, y++); printf("                                          \t\t\t| ");
    gotoxy(x, y++); printf("\t   $$$    $$$     \t\t      ■■■■■■■■■■■■■■■■■                ");
    gotoxy(x, y++); printf("\t  $$$$$  $$$$$    \t\t      ■                              ■                ");
    gotoxy(x, y++); printf("\t $$$$$$$$$$$$$$$  \t\t      ■        점   수 : %2d          ■               ", Score);
    gotoxy(x, y++); printf("\t$$$$$$$$$$$$$$$$$ \t\t      ■                              ■                ");
    gotoxy(x, y++); printf("\t $$$$$$$$$$$$$$   \t\t      ■■■■■■■■■■■■■■■■■                ");
    gotoxy(x, y++); printf("\t  $$$$$$$$$$$     \t  |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-| ");
    gotoxy(x, y++); printf("\t    $$$$$$$       \t  |     ____       ____       ____     ____       ____      | ");
    gotoxy(x, y++); printf("\t      $$$$        \t  |    |    |     |    |     |    |   |    |     |    |     | ");
    gotoxy(x, y++); printf("\t       $$         \t  |    |    |     |    |     |    |   |    |     |    |     | ");
    gotoxy(x, y++); printf("\t                \t    ----------------------------------------------------------- ");
}//메뉴 출력 함수 & 메뉴 선택기능 함수
int Successmenu() {
    textcolor(7);
    int x = 57;
    int y = 28;
    int menuIndex = 0;
    char menuItems[1][20] = { "돌아가기"};

    while (1) {
        // 메뉴 아이템 출력
        for (int i = 0; i < 1; i++) {
            gotoxy(x, y + i);
            if (i == menuIndex) printf("> %s", menuItems[i]);
            else printf("  %s", menuItems[i]);
        }

        // 입력 처리
        int n = S_keyControl();
        switch (n) {
        case SUBMIT: {
            if (menuIndex == 0) {
                main(); // 돌아가기를 선택하면 FirstScreen() 함수로 이동
            }
        }
        }
    }
}

int S_keyControl() {
    int temp = _getch();

    // 미세한 위치 조정을 위한 추가 코드
    if (temp == 0xE0 || temp == 0)
    {
        temp = _getch();
    }

    switch (temp) {
    case 72: // VK_UP
        return UP;
    case 80: // VK_DOWN
        return DOWN;
    case 75: // VK_LEFT
        return LEFT;
    case 77: // VK_RIGHT
        return RIGHT;
    case 13: // Space
        return SUBMIT;
    default:
        return 0;
    }
}