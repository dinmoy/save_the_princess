#include <stdio.h>
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
void printGameInstructions(); // 게임 방법 화면 출력 함수
int menuDraw();     //메뉴 출력&선택 함수 
int keyControl();   //화살표 선택하는 거


//main함수 
int main()
{
    init();
    TitleDraw();
    menuDraw();
    printGameInstructions(); // 게임 방법 화면 출력 함수
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
    int y = 26;
    int menuIndex = 0;
    char menuItems[3][20] = { "게 임 시 작", "게 임 정 보", "    종 료    " };

    while (1) {
        // 메뉴 아이템 출력
        for (int i = 0; i < 3; i++) {
            gotoxy(x, y + i);
            if (i == menuIndex) printf("> %s", menuItems[i]);
            else printf("  %s", menuItems[i]);
        }

        // 입력 처리
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
                printGameInstructions();

            }
            else if (menuIndex == 2) {
                exit(0);
            }
        }
        }
    }
}


////위,아래 ,왼,우 키값 지정 함수 
int keyControl() {
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

void printGameInstructions() {
    LPCWSTR message = L"상하좌우 키를 나타내어 플레이어를 움직이며 공격은 스페이스바 입니다.";
    MessageBoxW(NULL, message, L"알림", MB_OK);
}