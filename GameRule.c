#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void ruleDraw();  //���� ���
void init3();        //�ܼ�â ũ���Լ� 
int rulemenu();     //�޴� ���&���� �Լ� 
int G_keyControl();   //ȭ��ǥ �����ϴ� ��


int GameRule()
{
    init3();
    ruleDraw();
    rulemenu();
    return 0;
}
   
void init3() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}


void ruleDraw() {
    
    int x = 5,y= 5;
    gotoxy(x, y++); printf("\t\t\t===================================================================");
    gotoxy(x, y++); printf("\t\t\t                    ��������! ���ָ� ���Ͽ���!��                   ");
    gotoxy(x, y++); printf("\t\t\t===================================================================");
    gotoxy(x, y++); printf("\t\t\t                                                                   ");
    gotoxy(x, y++); printf("\t\t\t\t\t          [���� ��� ��]                                   ");
    gotoxy(x, y++);
    gotoxy(x, y++); printf("\t\t\t- ȭ�鿡 ��Ÿ���� ������ ����ġ��, ��ź�� ������!                  ");
    gotoxy(x, y++); printf("\t\t\t- �÷��̾�� �� �� �� �� Ű�� ����Ͽ� ������ �� �ֽ��ϴ�.         "); ;
    gotoxy(x, y++); printf("\t\t\t- �����̽� �ٸ� ����Ͽ� �Ѿ��� �߻��� �� �ֽ��ϴ�.                ");
    gotoxy(x, y++); printf("\t\t\t- ���� ������ ������ ��� �̼ǿ� �����մϴ�.                       ");
    gotoxy(x, y++); printf("\t\t\t- �÷��̾��� ����� 1���Դϴ�.                                     ");
    gotoxy(x, y++); printf("\t\t\t- ���� ���϶� ���� ������ 5���� �ö󰩴ϴ�.                        ");
    gotoxy(x, y++); printf("\t\t\t- ������ 50���� �Ǹ� �̼��� �����ϰ� �˴ϴ�.  ");
    gotoxy(x, y++); 
    gotoxy(x, y++); printf("\t\t\t\t\t          [�� ���۹� ��]");
    gotoxy(x, y++); printf("\t\t\t- ��: �������� �̵�                                       ^ _ ^ ");
    gotoxy(x, y++); printf("\t\t\t- ��: ���������� �̵�                                    ( o.o )");
    gotoxy(x, y++); printf("\t\t\t- �����̽� ��: �Ѿ� �߻�                                  > ^ < ");
    gotoxy(x, y++); printf("\t\t\t                                                        *-|   |-*");
    gotoxy(x, y++); printf("\t\t\t===================================================================");

}

int rulemenu() {
    textcolor(7);
    int x = 55;
    int y = 26;
    int menuIndex = 0;
    char menuItems[2][20] = { "��   ��","���ư���" };

    while (1) {
        
        for (int i = 0; i < 2; i++) {
            gotoxy(x, y + i);
            if (i == menuIndex) printf("> %s", menuItems[i]);
            else printf("  %s", menuItems[i]);
        }
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


int G_keyControl() {
    int temp = _getch();

    if (temp == 0xE0 || temp == 0)
    {
        temp = _getch();
    }

    switch (temp) {
    case 72: 
        return UP;
    case 80: 
        return DOWN;
    case 75:
        return LEFT;
    case 77: 
        return RIGHT;
    case 13: 
        return SUBMIT;
    default:
        return 0;
    }
}