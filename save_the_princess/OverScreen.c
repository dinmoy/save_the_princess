#include<stdio.h>
#include <windows.h>
#include <conio.h>
// "console.h"

//Ű���尪
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

//�Լ� ���� 
void TitleDraw1();   //���� ���
void init1();        //�ܼ�â ũ���Լ� 
int menuDraw1();     //�޴� ���&���� �Լ� 
int keyControl1();   //ȭ��ǥ �����ϴ� ��

//main�Լ� 
int Over()
{
    init1();
    TitleDraw1();
    menuDraw1();
    //while (1) {
    //    TitleDraw(); //ȭ�� ���
    //    int menuCode = menuDraw();
    //    if (menuCode == 0) {
    //        //���� �������� �̵�
    //    }
    //    else if (menuCode == 2) {
    //        //���� ������ �̵�
    //        infoDraw();
    //    }
    //    else if (menuCode == 4){
    //        return 0;
    //    }
    //    system("cls");
    //}
    return 0;
}
//�ܼ� ȭ�� ���� �Լ� 
void init1() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}

//���� ��� �Լ�  \n");
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

//�޴� ��� �Լ� & �޴� ���ñ�� �Լ�
int menuDraw1() {
    int x = 55;
    int y = 40;
    gotoxy(x - 2, y + 1);
    printf("> �ٽ� ���ư���");
    gotoxy(x, y + 2);
    printf("    �� ��    ");

    while (1) { //���� �ݺ�
        int n = keyControl1();
        switch (n) {
        case UP: {
            if (y > 26) {
                gotoxy(x - 2, y);
                printf(" "); //���� ��ġ �����
                gotoxy(x - 2, --y);
                printf(">");//�ٽñ׸���

            }
            break;
        }
        case DOWN: {    //�Էµ� Ű�� ���� DOWN�� ���
            if (y < 27) {
                gotoxy(x - 2, y);
                printf(" "); //���� ��ġ �����
                gotoxy(x - 2, ++y);
                printf(">");//�ٽñ׸���
            }
            break;
        }
        case SUBMIT: {
            return y - 25;
        }
        }
    }
}
////��,�Ʒ� ,��,�� Ű�� ���� �Լ� 
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
    //�����̽�
    else if (temp == ' ') {
        return SUBMIT;
    }
}