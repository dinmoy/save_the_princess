#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>

//Ű���尪
#define UP 72
#define DOWN 80
#define SUBMIT 13
#define LEFT 2
#define RIGHT 3

//�Լ� ���� 
void TitleDraw2();   //���� ���
void init2();        //�ܼ�â ũ���Լ� 
int menuDraw2();     //�޴� ���&���� �Լ� 
int keyControl2();   //ȭ��ǥ �����ϴ� ��

//main�Լ� 
int Success()
{
    init2();
    TitleDraw2();
    menuDraw2();
    return 0;
}
//�ܼ� ȭ�� ���� �Լ� 
void init2() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}

//���� ��� �Լ�  \n");
void TitleDraw2()
{
    printf("\t\t\t __   __  ___   _______  _______  ___   _______  __    _	        \n");
    printf("\t\t\t|  |_|  ||   | |       ||       ||   | |       ||  |  | |         \n");
    printf("\t\t\t|       ||   | |  _____ || _____||   | |   _   ||   |_| |         \n");
    printf("\t\t\t|       ||   | | |_____ | |_____ |   | |  | |  ||       |         \n");
    printf("\t\t\t|       ||   | |_____ || _____  ||   | |  |_|  ||  _    |         \n");
    printf("\t\t\t| ||_|| ||   |  _____| | _____| ||   | |       || | |   |         \n");
    printf("\t\t\t|_|   |_||___| |_______||_______||___| |_______||_|  |__|         \n");
    printf("\t\t\t _______  __   __  _______  _______  _______  _______  _______    \n");
    printf("\t\t\t|       ||  | |  ||       ||       ||       ||       ||       |   \n");
    printf("\t\t\t|  _____||  | |  ||       ||       ||    ___ || _____|| _____|    \n");
    printf("\t\t\t| |_____ |  |_|  ||       ||       ||   |___ | |_____| |_____	|   \n");
    printf("\t\t\t| _____ ||       ||      _||      _|| _____ || _____ |	  | |   \n");
    printf("\t\t\t  _____|||       ||     |_ |     |_ |   |___   _____|| _____| |	\n");
    printf("\t\t\t|_______||_______||_______||_______||_______||_______||_______|	\n");

}

//�޴� ��� �Լ� & �޴� ���ñ�� �Լ�
int menuDraw2() {
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
                return main(); // ���ư��⸦ �����ϸ� FirstScreen() �Լ��� �̵�
            }
            else if (menuIndex == 1) {
                exit(0); // ���Ḧ �����ϸ� ���α׷��� ����
            }
        }
        }
    }
}

int keyControl2() {
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