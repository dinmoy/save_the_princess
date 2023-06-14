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

void ruleDraw();  //제목 출력
void init3();        //콘솔창 크기함수 
int rulemenu();     //메뉴 출력&선택 함수 
int G_keyControl();   //화살표 선택하는 거


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
    gotoxy(x, y++); printf("\t\t\t                    ♣작전명! 공주를 구하여라!♣                   ");
    gotoxy(x, y++); printf("\t\t\t===================================================================");
    gotoxy(x, y++); printf("\t\t\t                                                                   ");
    gotoxy(x, y++); printf("\t\t\t\t\t          [게임 방법 ☆]                                   ");
    gotoxy(x, y++);
    gotoxy(x, y++); printf("\t\t\t- 화면에 나타나는 적들을 물리치고, 폭탄을 피하자!                  ");
    gotoxy(x, y++); printf("\t\t\t- 플레이어는 ↑ ↓ ← → 키를 사용하여 움직일 수 있습니다.         "); ;
    gotoxy(x, y++); printf("\t\t\t- 스페이스 바를 사용하여 총알을 발사할 수 있습니다.                ");
    gotoxy(x, y++); printf("\t\t\t- 적에 공격을 받으면 즉시 미션에 실패합니다.                       ");
    gotoxy(x, y++); printf("\t\t\t- 플레이어의 목숨은 1개입니다.                                     ");
    gotoxy(x, y++); printf("\t\t\t- 적을 죽일때 마다 점수는 5점씩 올라갑니다.                        ");
    gotoxy(x, y++); printf("\t\t\t- 점수가 50점이 되면 미션을 성공하게 됩니다.  ");
    gotoxy(x, y++); 
    gotoxy(x, y++); printf("\t\t\t\t\t          [☆ 조작법 ☆]");
    gotoxy(x, y++); printf("\t\t\t- ←: 왼쪽으로 이동                                       ^ _ ^ ");
    gotoxy(x, y++); printf("\t\t\t- →: 오른쪽으로 이동                                    ( o.o )");
    gotoxy(x, y++); printf("\t\t\t- 스페이스 바: 총알 발사                                  > ^ < ");
    gotoxy(x, y++); printf("\t\t\t                                                        *-|   |-*");
    gotoxy(x, y++); printf("\t\t\t===================================================================");

}

int rulemenu() {
    textcolor(7);
    int x = 55;
    int y = 26;
    int menuIndex = 0;
    char menuItems[2][20] = { "다   음","돌아가기" };

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