#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>


//키보드값
#define UP 72
#define DOWN 80
#define SUBMIT 13
#define LEFT 2
#define RIGHT 3

//함수 정의 
void TitleDraw1();   //제목 출력
void init1();        //콘솔창 크기함수 
int menuDraw1();     //메뉴 출력&선택 함수 
int keyControl1();   //화살표 선택하는 거

//main함수 
int Over()
{
    init1();
    TitleDraw1();
    menuDraw1();
    return 0;
}
//콘솔 화면 지정 함수 
void init1() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}

//제목 출력 함수  \n");
void TitleDraw1()
{
    printf("\n\n");
    printf("\t     _______  _______  __   __  _______         _______  __   __  _______  ______      __       \n");
    printf("\t    |       ||   _   ||  |_|  ||       |       |       ||  | |  ||       ||    _ |    |  |      \n");
    printf("\t    |    ___||  |_|  ||       ||    ___|       |   _   ||  |_|  ||    ___||   | ||    |  |      \n");
    printf("\t    |   | __ |       ||       ||   |___        |  | |  ||       ||   |___ |   |_||_   |  |      \n");
    printf("\t    |   ||  ||       ||       ||    ___|       |  |_|  ||       ||    ___||    __  |  |__|      \n");
    printf("\t    |   |_| ||   _   || ||_|| ||   |___        |_______|  |___|  |_______||___|  |_|  |__|      \n");
    printf("\t    |_______||__| |__||_|   |_||_______|                                                      \n\n\n");
    printf("\t                                                                                              \n");

    printf("\t       $$$$$$$$$$$                    |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|                                         \n");
    printf("\t     $$$$$$$$$$$$$$$                  |     ___       ___       ___     |                                         \n");
    printf("\t   $$$$$$$$$$$$$$$$$$$                |    |   |     |   |     |   |    |                                         \n");
    printf("\t   $$   $  $$$$$  $ $$                |   |     |   |     |   |     |   |                                         \n");
    printf("\t   $$ $    $$$$$ $  $$                -----------------------------------                                         \n");
    printf("\t    $$$$$$$$$$$$$$$$$         |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|                                           \n");
    printf("\t     $$$$$$$$$$$$$$$          |     ____       ____       ____     ____       ____      |                                           \n");
    printf("\t      $$$$      $$$           |    |    |     |    |     |    |   |    |     |    |     |                                           \n");
    printf("\t       $$$      $$            |   |      |   |      |   |      | |      |   |      |    |                                           \n");
    printf("\t        $$$$$$$$$$            -----------------------------------------------------------                                           \n");
    printf("\t                                                                         \n");


}

//메뉴 출력 함수 & 메뉴 선택기능 함수
int menuDraw1() {
    int x = 55;
    int y = 20;
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
        int n = keyControl1();
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
                return main(); // 돌아가기를 선택하면 FirstScreen() 함수로 이동
            }
            else if (menuIndex == 1) {
                exit(0); // 종료를 선택하면 프로그램을 종료
            }
        }
        }
    }
}

int keyControl1() {
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
    case ' ': // Space
        return SUBMIT;
    default:
        return 0;
    }
}