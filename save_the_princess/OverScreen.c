#include<stdio.h>
#include <windows.h>
#include <conio.h>
// "console.h"

//키보드값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

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
void init1() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}

//제목 출력 함수  \n");
void TitleDraw1()
{
    printf("\n\n");
    printf("\t\t\t\t\t     _______  _______  __   __  _______      \n");
    printf("\t\t\t\t\t    |       ||   _   ||  |_|  ||       |     \n");
    printf("\t\t\t\t\t    |    ___||  |_|  ||       ||    ___|     \n");
    printf("\t\t\t\t\t    |   | __ |       ||       ||   |___      \n");
    printf("\t\t\t\t\t    |   ||  ||       ||       ||    ___|     \n");
    printf("\t\t\t\t\t    |   |_| ||   _   || ||_|| ||   |___      \n");
    printf("\t\t\t\t\t    |_______||__| |__||_|   |_||_______|     \n\n\n");
    printf("\t\t\t\t\t  _______  __   __  _______  ______      __  \n");
    printf("\t\t\t\t\t |       ||  | |  ||       ||    _ |    |  | \n");
    printf("\t\t\t\t\t |   _   ||  |_|  ||    ___||   | ||    |  | \n");
    printf("\t\t\t\t\t |  | |  ||       ||   |___ |   |_||_   |  | \n");
    printf("\t\t\t\t\t |  |_|  ||       ||    ___||    __  |  |__| \n");
    printf("\t\t\t\t\t |_______|  |___|  |_______||___|  |_|  |__| \n");

}

//메뉴 출력 함수 & 메뉴 선택기능 함수
int menuDraw1() {
    int x = 55;
    int y = 40;
    gotoxy(x - 2, y + 1);
    printf("> 다시 돌아가기");
    gotoxy(x, y + 2);
    printf("    종 료    ");

    while (1) { //무한 반복
        int n = keyControl1();
        switch (n) {
        case UP: {
            if (y > 26) {
                gotoxy(x - 2, y);
                printf(" "); //원래 위치 지우기
                gotoxy(x - 2, --y);
                printf(">");//다시그리기

            }
            break;
        }
        case DOWN: {    //입력된 키의 값이 DOWN인 경우
            if (y < 27) {
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
int keyControl1() {
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