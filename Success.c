#include <stdio.h>
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
void SuccessDraw();   //제목 출력
void init2();        //콘솔창 크기함수 
int Successmenu();     //메뉴 출력&선택 함수 
int S_keyControl();   //화살표 선택하는 거

//main함수 
int Success()
{
    init2();
    SuccessDraw();
    Successmenu();
    return 0;
}
//콘솔 화면 지정 함수 
void init2() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}

//제목 출력 함수  \n");
void SuccessDraw()
{
    printf("\t\t\t\t  __   __  ___   _______  _______  ___   _______  __    _	\n");
    printf("\t\t\t\t |  |_|  ||   | |       ||       ||   | |       ||  |  | | \n");
    printf("\t\t\t\t |       ||   | |  _____ || _____||   | |   _   ||   |_| | \n");
    printf("\t\t\t\t |       ||   | | |_____ | |_____ |   | |  | |  ||       | \n");
    printf("\t\t\t\t |       ||   | |_____ || _____  ||   | |  |_|  ||  _    | \n");
    printf("\t\t\t\t | ||_|| ||   |  _____| | _____| ||   | |       || | |   | \n");
    printf("\t\t\t\t |_|   |_||___| |_______||_______||___| |_______||_|  |__| \n");
    printf("\t\t\t\t _______  __   __  _______  _______  _______  _______  _______\n");
    printf("\t\t\t\t|       ||  | |  ||       ||       ||       ||       ||       |\n");
    printf("\t\t\t\t|  _____||  | |  ||       ||       ||    ___||  _____||  _____|\n");
    printf("\t\t\t\t| |_____ |  |_|  ||       ||       ||   |___ | |_____ | |_____ \n");
    printf("\t\t\t\t| _____ ||       ||      _||      _||   _____|| _____|| ____  |\n");
    printf("\t\t\t\t  _____|||       ||     |_ |     |_ |   |___  _____| | _____| |	\n");
    printf("\t\t\t\t|_______||_______||_______||_______||_______||_______||_______|	\n\n\n");

    
    printf("\t   $$$    $$$     \t\t      |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|                \n");
    printf("\t  $$$$$  $$$$$    \t\t      |     ___       ___       ___     |                \n");
    printf("\t $$$$$$$$$$$$$$$  \t\t      |    |   |     |   |     |   |    |                \n");
    printf("\t$$$$$$$$$$$$$$$$$ \t\t      |   |     |   |     |   |     |   |                \n");
    printf("\t $$$$$$$$$$$$$$   \t\t      -----------------------------------                \n");
    printf("\t  $$$$$$$$$$$     \t|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-| \n");
    printf("\t    $$$$$$$       \t|     ____       ____       ____     ____       ____      | \n");
    printf("\t      $$$$        \t|    |    |     |    |     |    |   |    |     |    |     | \n");
    printf("\t       $$         \t|    |    |     |    |     |    |   |    |     |    |     | \n");
    printf("\t                \t -----------------------------------------------------------  \n");
}//메뉴 출력 함수 & 메뉴 선택기능 함수
int Successmenu() {
    int x = 55;
    int y = 28;
    int menuIndex = 0;
    char menuItems[2][20] = { "돌아가기","종   료" };

    while (1) {
        // 메뉴 아이템 출력
        for (int i = 0; i < 2; i++) {
            gotoxy(x, y + i);
            if (i == menuIndex) printf("> %s", menuItems[i]);
            else printf("  %s", menuItems[i]);
        }

        // 입력 처리
        int n = S_keyControl();
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
                 main(); // 돌아가기를 선택하면 FirstScreen() 함수로 이동
            }
            else if (menuIndex == 1) {
                exit(0); // 종료를 선택하면 프로그램을 종료
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
