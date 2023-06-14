#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>


#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void OverDraw();   
void init1();         
int Overmenu();      
int O_keyControl();   
 
int Over()
{
    PlaySound(TEXT("Overbgm.wav"), NULL, SND_ASYNC | SND_LOOP);
    while (1)
    {
        init1();
        OverDraw();
        Overmenu();
        Sleep(1000);
    }
}

void init1() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}


void OverDraw()
{
    int x = 5, y = 3;
    
    gotoxy(x, y++); printf("\t\t     _______  _______  __   __  _______         _______  __   __  _______  ______      __ ");
    gotoxy(x, y++); printf("\t\t    |       ||   _   ||  |_|  ||       |       |       ||  | |  ||       ||    _ |    |  |");
    gotoxy(x, y++); printf("\t\t    |    ___||  |_|  ||       ||    ___|       |   _   ||  |_|  ||    ___||   | ||    |  |");
    gotoxy(x, y++); printf("\t\t    |   | __ |       ||       ||   |___        |  | |  ||       ||   |___ |   |_||_   |  |");
    gotoxy(x, y++); printf("\t\t    |   ||  ||       ||       ||    ___|       |  |_|  ||       ||    ___||    __  |  |__|");
    gotoxy(x, y++); printf("\t\t    |   |_| ||   _   || ||_|| ||   |___        |_______|  |___|  |_______||___|  |_|  |__|");
    gotoxy(x, y++); printf("\t\t    |_______||__| |__||_|   |_||_______|                                                  ");
    gotoxy(x, y++);
    gotoxy(x, y++);
    gotoxy(x, y++);
    gotoxy(x, y++); printf("\t       $$$$$$$$$$$                    |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|                 ");
    gotoxy(x, y++); printf("\t     $$$$$$$$$$$$$$$                  |     ___       ___       ___     |                 ");
    gotoxy(x, y++); printf("\t   $$$$$$$$$$$$$$$$$$$                |    |   |     |   |     |   |    |                 ");
    gotoxy(x, y++); printf("\t   $$   $  $$$$$  $ $$                |   |     |   |     |   |     |   |                 ");
    gotoxy(x, y++); printf("\t   $$ $    $$$$$ $  $$                -----------------------------------                 ");
    gotoxy(x, y++); printf("\t    $$$$$$$$$$$$$$$$$       |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|   ");
    gotoxy(x, y++); printf("\t     $$$$$$$$$$$$$$$        |     ____       ____       ____     ____       ____      |   ");
    gotoxy(x, y++); printf("\t      $$$$      $$$         |    |    |     |    |     |    |   |    |     |    |     |   ");
    gotoxy(x, y++); printf("\t       $$$      $$          |   |      |   |      |   |      | |      |   |      |    |   ");
    gotoxy(x, y++); printf("\t        $$$$$$$$$$          -----------------------------------------------------------   ");
}


int Overmenu() {
    textcolor(7);
    int x = 57;
    int y = 26;
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
        int n = O_keyControl();
        switch (n) {
        case SUBMIT: {
            if (menuIndex == 0) {
                return main();
            }
        }
        }
    }
}



int O_keyControl() {
    int temp = _getch();


    if (temp == 0xE0 || temp == 0)
    {
        temp = _getch();
    }

    switch (temp) {
    case 72: 
        return UP;
    case 80: 
        return DOWN;
    case 75: 
        return LEFT;
    case 77: 
        return RIGHT;
    case 13: 
        return SUBMIT;
    default:
        return 0;
    }
}