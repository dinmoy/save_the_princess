#include<stdio.h>
#include <windows.h>
#include <conio.h>
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
int menuDraw();     //메뉴 출력&선택 함수 
int keyControl();   //화살표 선택하는 거


//main함수 
int main()
{
    init();
    TitleDraw();
    menuDraw();
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
    printf("\t\t\t                _______  _______  __   __  _______                 \n");
    printf("\t\t\t               |       ||   _   ||  | |  ||       |                \n");
    printf("\t\t\t               |  _____||  |_|  ||  |_|  ||    ___|                \n");
    printf("\t\t\t               | |_____ |       ||       ||   |___                 \n");
    printf("\t\t\t               |_____  ||       ||       ||    ___|                \n");
    printf("\t\t\t                _____| ||   _   | |     | |   |___                 \n");
    printf("\t\t\t               |_______||__| |__|  |___|  |_______|                \n\n");
    printf("\t\t\t                     _______  __   __  _______                     \n");
    printf("\t\t\t                    |       ||  | |  ||       |                    \n");
    printf("\t\t\t                    |_     _||  |_|  ||    ___|                    \n");
    printf("\t\t\t                      |   |  |       ||   |___                     \n");
    printf("\t\t\t                      |   |  |       ||    ___|                    \n");
    printf("\t\t\t                      |   |  |   _   ||   |___                     \n");
    printf("\t\t\t                      |___|  |__| |__||_______|                    \n\n\n");
    printf("\t\t\t      _______  ______    ___   __    _  _______  _______  _______  \n");
    printf("\t\t\t     |       ||    _ |  |   | |  |  | ||       ||       ||       | \n");
    printf("\t\t\t     |    _  ||   | ||  |   | |   |_| ||       ||    ___||  _____| \n");
    printf("\t\t\t     |   |_| ||   |_||_ |   | |       ||       ||   |___ | |_____  \n");
    printf("\t\t\t     |    ___||    __  ||   | |  _    ||      _||    ___||_____  | \n");
    printf("\t\t\t     |   |    |   |  | ||   | | | |   ||     |_ |   |___  _____| | \n");
    printf("\t\t\t     |___|    |___|  |_||___| |_|  |__||_______||_______||_______| \n");
}

//메뉴 출력 함수 & 메뉴 선택기능 함수
int menuDraw() {
    int x = 55;
    int y = 25;
    gotoxy(x - 2, y + 1);
    printf("> 게 임 시 작");
    gotoxy(x, y + 2);
    printf("게 임 정 보");
    gotoxy(x, y + 3);
    printf("    종 료    ");

    while (1) { //무한 반복
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 25) {
                gotoxy(x - 2, y);
                printf(" "); //원래 위치 지우기
                gotoxy(x - 2, --y);
                printf(">");//다시그리기

            }
            break;
        }
        case DOWN: {    //입력된 키의 값이 DOWN인 경우
            if (y < 28) {
                gotoxy(x - 2, y);
                printf(" "); //원래 위치 지우기
                gotoxy(x - 2, ++y);
                printf(">");//다시그리기
            }
            break;
        }
        case SUBMIT: {
            return y - 25;
        }
        }
    }
}
////위,아래 ,왼,우 키값 지정 함수 
int keyControl() {
    char temp = _getch();

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    //스페이스
    else if (temp == ' ') {
        return SUBMIT;
    }
}