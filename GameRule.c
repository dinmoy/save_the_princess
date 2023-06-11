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
void ruleDraw();  //제목 출력
void init3();        //콘솔창 크기함수 
int rulemenu();     //메뉴 출력&선택 함수 
int G_keyControl();   //화살표 선택하는 거


//main함수 
int GameRule()
{
    init3();
    ruleDraw();
    rulemenu();
    return 0;
}
//콘솔 화면 지정 함수 
void init3() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}

//제목 출력 함수  \n");
void ruleDraw() {
    printf("======================================\n");
    printf("      ♣작전명! 공주를 구하여라!♣    \n");
    printf("======================================\n");
    printf("\n");
    printf("☆ 게임 방법 ☆\n");
    printf("- 화면에 나타나는 적들을 물리치고, 폭탄을 피하자!\n");
    printf("- 플레이어는 ↑ ↓ ← → 키를 사용하여 움직일 수 있습니다.\n");
    printf("- 스페이스 바를 사용하여 총알을 발사할 수 있습니다.\n");
    printf("- 적에 공격을 받으면 즉시 미션에 실패합니다.\n");
    printf("- 플레이어의 목숨은 1개입니다. \n");
    printf("- 적을 죽일때 마다 점수는 5점씩 올라갑니다.\n");
    printf("- 점수가 20점이 되면 미션을 성공하게 됩니다.\n");
    printf("\n");
    printf("☆ 조작법 ☆\n");
    printf("- ↑: 위쪽으로 이동\n");
    printf("- ↓: 아래쪽으로 이동\n");
    printf("- ←: 왼쪽으로 이동\n");
    printf("- →: 오른쪽으로 이동\n");
    printf("- 스페이스 바: 총알 발사\n");
    printf("\n");
    printf("======================================\n");

}

//메뉴 출력 함수 & 메뉴 선택기능 함수
int rulemenu() {
    int x = 55;
    int y = 26;
    int menuIndex = 0;
    char menuItems[2][20] = { "다   음","돌아가기" };

    while (1) {
        // 메뉴 아이템 출력
        for (int i = 0; i < 2; i++) {
            gotoxy(x, y + i);
            if (i == menuIndex) printf("> %s", menuItems[i]);
            else printf("  %s", menuItems[i]);
        }
        // 입력 처리
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


////위,아래 ,왼,우 키값 지정 함수 
int G_keyControl() {
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

