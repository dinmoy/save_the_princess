#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>

//Ű���尪
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

//�Լ� ���� 
void ruleDraw();  //���� ���
void init3();        //�ܼ�â ũ���Լ� 
int rulemenu();     //�޴� ���&���� �Լ� 
int G_keyControl();   //ȭ��ǥ �����ϴ� ��


//main�Լ� 
int GameRule()
{
    init3();
    ruleDraw();
    rulemenu();
    return 0;
}
//�ܼ� ȭ�� ���� �Լ� 
void init3() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}

//���� ��� �Լ�  \n");
void ruleDraw() {
    
    int x = 5,y= 5;
    gotoxy(x, y++); printf("\t\t\t===================================================================");
    gotoxy(x, y++); printf("\t\t\t                    ��������! ���ָ� ���Ͽ���!��                   ");
    gotoxy(x, y++); printf("\t\t\t===================================================================");
    gotoxy(x, y++); printf("\t\t\t                                                                   ");
    gotoxy(x, y++); printf("\t\t\t�� ���� ��� ��                                                    ");
    gotoxy(x, y++); printf("\t\t\t- ȭ�鿡 ��Ÿ���� ������ ����ġ��, ��ź�� ������!                  ");
    gotoxy(x, y++); printf("\t\t\t- �÷��̾�� �� �� �� �� Ű�� ����Ͽ� ������ �� �ֽ��ϴ�.         "); ;
    gotoxy(x, y++); printf("\t\t\t- �����̽� �ٸ� ����Ͽ� �Ѿ��� �߻��� �� �ֽ��ϴ�.                ");
    gotoxy(x, y++); printf("\t\t\t- ���� ������ ������ ��� �̼ǿ� �����մϴ�.                       ");
    gotoxy(x, y++); printf("\t\t\t- �÷��̾��� ����� 1���Դϴ�.                                     ");
    gotoxy(x, y++); printf("\t\t\t- ���� ���϶� ���� ������ 5���� �ö󰩴ϴ�.                        ");
    gotoxy(x, y++); printf("\t\t\t- ������ 50���� �Ǹ� �̼��� �����ϰ� �˴ϴ�.  ");
    gotoxy(x, y++); 
    gotoxy(x, y++); printf("\t\t\t�� ���۹� ��");
    gotoxy(x, y++); printf("\t\t\t- ��: �������� �̵�                                       ^ _ ^ ");
    gotoxy(x, y++); printf("\t\t\t- ��: ���������� �̵�                                    ( o.o )");
    gotoxy(x, y++); printf("\t\t\t- �����̽� ��: �Ѿ� �߻�                                  > ^ < ");
    gotoxy(x, y++); printf("\t\t\t                                                        *-|   |-*");
    gotoxy(x, y++); printf("\t\t\t===================================================================");

}

//�޴� ��� �Լ� & �޴� ���ñ�� �Լ�
int rulemenu() {
    int x = 55;
    int y = 26;
    int menuIndex = 0;
    char menuItems[2][20] = { "��   ��","���ư���" };

    while (1) {
        // �޴� ������ ���
        for (int i = 0; i < 2; i++) {
            gotoxy(x, y + i);
            if (i == menuIndex) printf("> %s", menuItems[i]);
            else printf("  %s", menuItems[i]);
        }
        // �Է� ó��
        int n = G_keyControl();
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
                main();

            }
        }
        }
    }
}


////��,�Ʒ� ,��,�� Ű�� ���� �Լ� 
int G_keyControl() {
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
    case 13: // Space
        return SUBMIT;
    default:
        return 0;
    }
}