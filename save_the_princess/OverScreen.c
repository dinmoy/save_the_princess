#include<stdio.h>
#include <windows.h>
#include <conio.h>
//#include "console.h"

//Ű���尪
#define UP 72
#define DOWN 80
#define SUBMIT 13
#define LEFT 2
#define RIGHT 3

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
    int y = 20;
    int menuIndex = 0;
    char menuItems[2][20] = { "���ư���","��   ��" };

    while (1) {
        // �޴� ������ ���
        for (int i = 0; i < 2; i++) {
            gotoxy(x, y + i);
            if (i == menuIndex) printf("> %s", menuItems[i]);
            else printf("  %s", menuItems[i]);
        }

        // �Է� ó��
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
                exit(0);
            }
        }
        }
    }
}

int keyControl1() {
    int temp = _getch();

    // �̼��� ��ġ ������ ���� �߰� �ڵ�
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