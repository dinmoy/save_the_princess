#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>


//키보드값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

//함수 정의 
void OverDraw();   //제목 출력
void init1();        //콘솔창 크기함수 
int Overmenu();     //메뉴 출력&선택 함수 
int O_keyControl();   //화살표 선택하는 거


//main함수 
int Over()
{
    init1();
    OverDraw();
    Overmenu();
    return 0;
}
//콘솔 화면 지정 함수 
void init1() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}

//제목 출력 함수  \n");
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

//메뉴 출력 함수 & 메뉴 선택기능 함수
int Overmenu() {
    int x = 55;
    int y = 26;
    int menuIndex = 0;
    char menuItems[3][20] = { "돌아가기","종    료" };

    while (1) {
        // 메뉴 아이템 출력
        for (int i = 0; i < 2; i++) {
            gotoxy(x, y + i);
            if (i == menuIndex) printf("> %s", menuItems[i]);
            else printf("  %s", menuItems[i]);
        }

        // 입력 처리
        int n = O_keyControl();
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
                return main();
            }
            else if (menuIndex == 1) {
                exit(0);

            }
        }
        }
    }
}


////위,아래 ,왼,우 키값 지정 함수 
int O_keyControl() {
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