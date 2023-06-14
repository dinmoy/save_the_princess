#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include "console.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

//키보드값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

//함수 정의 
void TitleDraw();   
void init();
int menuDraw();      
int keyControl();  



int main()
{
    PlaySound(TEXT("Waterfall.wav"), NULL, SND_ASYNC | SND_LOOP);
    while (1)
    {
        init();
        TitleDraw();
        menuDraw();
        Sleep(1000);
    }
    
     //일반 재생


    return 0;
}


void init() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}

void TitleDraw()
{
    int x = 5, y = 3;
    textcolor(14);
 
    gotoxy(x, y++); printf("\t    _______  _______  __   __  _______      _______  ______    ___   __    _  _______  _______  _______ ");
    gotoxy(x, y++); printf("\t   |       ||   _   ||  | |  ||       |    |       ||    _ |  |   | |  |  | ||       ||       ||       |");
    gotoxy(x, y++); printf("\t   |  _____||  |_|  ||  |_|  ||    ___|    |    _  ||   | ||  |   | |   |_| ||       ||    ___||  _____|");
    gotoxy(x, y++); printf("\t   | |_____ |       ||       ||   |___     |   |_| ||   |_||_ |   | |       ||       ||   |___ | |_____ ");
    gotoxy(x, y++); printf("\t   |_____  ||       ||       ||    ___|    |    ___||    __  ||   | |  _    ||      _||    ___||_____  |");
    gotoxy(x, y++); printf("\t    _____| ||   _   | |     | |   |___     |   |    |   |  | ||   | | | |   ||     |_ |   |___  _____| |");
    gotoxy(x, y++); printf("\t   |_______||__| |__|  |___|  |_______|    |___|    |___|  |_||___| |_|  |__||_______||_______||_______|");
    gotoxy(x, y++);
    gotoxy(x, y++);
    gotoxy(x, y++);
    gotoxy(x, y++); printf("\t        $$$$$$$ \t                                |▶                                ");
    gotoxy(x, y++); printf("\t       $$ $$$$$$\t   $$                           |                                  ");
    gotoxy(x, y++); printf("\t       $$$$$$$$$\t  $$$$         -----------------------------------                 ");
    gotoxy(x, y++); printf("\t$      $$$      \t   $$          |     ___       ___       ___     |                 ");
    gotoxy(x, y++); printf("\t$$     $$$$$$$  \t               |    |   |     |   |     |   |    |                $$");
    gotoxy(x, y++); printf("\t$$$   $$$$$     \t               |   |     |   |     |   |     |   |               $$$$");
    gotoxy(x, y++); printf("\t $$  $$$$$$$$$$ \t               -----------------------------------                $$");
    gotoxy(x, y++); printf("\t $$$$$$$$$$$    \t   |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|    ");
    gotoxy(x, y++); printf("\t  $$$$$$$$$$    \t   |     ____       ____       ____     ____       ____      |    ");
    gotoxy(x, y++); printf("\t    $$$$$$$$    \t   |    |    |     |    |     |    |   |    |     |    |     |    ");
    gotoxy(x, y++); printf("\t     $$$$$$     \t   |   |      |   |      |   |      | |      |   |      |    |    ");
    gotoxy(x, y++); printf("\t\t                   -----------------------------------------------------------    ");
}

int menuDraw() {
    textcolor(7);
    int x = 55;
    int y = 26;
    int menuIndex = 0;
    char menuItems[2][20] = { "게 임 시 작", "게 임 정 보"};

    while (1) {
       
        for (int i = 0; i < 2; i++) {
            gotoxy(x, y + i);
            if (i == menuIndex) printf("> %s", menuItems[i]);
            else printf("  %s", menuItems[i]);
        }

        int n = keyControl();
        switch (n) {
        case UP: {
            if (menuIndex > 0) menuIndex--;
            break;
        }
        case DOWN: {
            if (menuIndex < 2) menuIndex++;
            break;
        }
        case SUBMIT: {
            if (menuIndex == 0) {
                return Function();
            }
            else if (menuIndex == 1) {
                GameRule();

            }
          }
        }
    }
}


int keyControl() {
    int temp = _getch();

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