#include <stdio.h>
#include <windows.h>

void init3();
void ruleDraw();

void init3() {
    system("mode con:cols=120 lines=30 | title Save the Princess");
}

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

        return 0;
    }