#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include "console.h"

//키보드값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

//함수 정의 
void TitleDraw();   //제목 출력
void init();        //콘솔창 크기함수 
//oid printGameInstructions(); // 게임 방법 화면 출력 함수
int menuDraw();     //메뉴 출력&선택 함수 
int keyControl();   //화살표 선택하는 거


//main함수 
int main()
{
    init();
    TitleDraw();
    menuDraw();
    //printGameInstructions(); // 게임 방법 화면 출력 함수
    //while (1) {
    //    TitleDraw(); //화면 출력
    //    int menuCode = menuDraw();
    //    if (menuCode == 0) {
    //        //게임 시작으로 이동
    //    }
    //    else if (menuCode == 2) {
    //        //게임 정보로 이동
    //        infoDraw();
    //    }
    //    else if (menuCode == 4){
    //        return 0;
    //    }
    //    system("cls");
    //}
    return 0;
}
//콘솔 화면 지정 함수 
void init() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}

//제목 출력 함수  \n");
void TitleDraw()
{
    textcolor(14);
    printf("\n\n");
    printf("\t    _______  _______  __   __  _______      _______  ______    ___   __    _  _______  _______  _______       \n");
    printf("\t   |       ||   _   ||  | |  ||       |    |       ||    _ |  |   | |  |  | ||       ||       ||       |      \n");
    printf("\t   |  _____||  |_|  ||  |_|  ||    ___|    |    _  ||   | ||  |   | |   |_| ||       ||    ___||  _____|      \n");
    printf("\t   | |_____ |       ||       ||   |___     |   |_| ||   |_||_ |   | |       ||       ||   |___ | |_____       \n");
    printf("\t   |_____  ||       ||       ||    ___|    |    ___||    __  ||   | |  _    ||      _||    ___||_____  |      \n");
    printf("\t    _____| ||   _   | |     | |   |___     |   |    |   |  | ||   | | | |   ||     |_ |   |___  _____| |      \n");
    printf("\t   |_______||__| |__|  |___|  |_______|    |___|    |___|  |_||___| |_|  |__||_______||_______||_______|      \n");
    printf("\n\n\n");

    printf("\t        $$$$$$$ \n");
    printf("\t       $$ $$$$$$\t   $$                                                             \n");
    printf("\t       $$$$$$$$$\t  $$$$         |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|                \n");
    printf("\t$      $$$      \t   $$          |     ___       ___       ___     |                \n");
    printf("\t$$     $$$$$$$  \t               |    |   |     |   |     |   |    |                \n");
    printf("\t$$$   $$$$$     \t               |   |     |   |     |   |     |   |                \n");
    printf("\t $$  $$$$$$$$$$ \t               -----------------------------------                \n");
    printf("\t $$$$$$$$$$$    \t   |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|    \n");
    printf("\t  $$$$$$$$$$    \t   |     ____       ____       ____     ____       ____      |    \n");
    printf("\t    $$$$$$$$    \t   |    |    |     |    |     |    |   |    |     |    |     |    \n");
    printf("\t     $$$$$$     \t   |   |      |   |      |   |      | |      |   |      |    |    \n");
    printf("\t\t                   -----------------------------------------------------------                \n");
}

//메뉴 출력 함수 & 메뉴 선택기능 함수
int menuDraw() {
    int x = 55;
    int y = 26;
    int menuIndex = 0;
    char menuItems[3][20] = { "게 임 시 작", "게 임 정 보", "    종 료    " };

    while (1) {
        // 메뉴 아이템 출력
        for (int i = 0; i < 3; i++) {
            gotoxy(x, y + i);
            if (i == menuIndex) printf("> %s", menuItems[i]);
            else printf("  %s", menuItems[i]);
        }

        // 입력 처리
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
            else if (menuIndex == 2) {
                exit(0);
            }
        }
        }
    }
}


////위,아래 ,왼,우 키값 지정 함수 
int keyControl() {
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

