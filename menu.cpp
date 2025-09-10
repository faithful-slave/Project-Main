#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Utils.h"
#include "Menu.h"
//좌우 선택 메뉴 함수
// menus : 메뉴 리스트
// menuCount : 메뉴 갯수
// textX, textY : 글자의 위치
// menuX, menuY : 메뉴의 위치
// ───────────────[made by 수범]─────────────── //
int menu(const char* menus[], int menuCount, int textX, int textY, int menuX, int menuY)
{
    int currentMenuIndex = 0; // 선택된 메뉴의 인덱스
    int ch; 

    while (1)
    {
        gotoXY(textX, textY); // 글자 위치 조정
        printf("좌우 방향키로 메뉴 선택 후 Enter 키를 누르세요.\n\n");
        gotoXY(menuX, menuY); // 메뉴 갯수 및 글자 갯수에 따른 x위치 조정 바람

        // 메뉴 종류를 한 줄로 표시 (선택된 메뉴는 대괄호로 감싸 표시)
        for (int i = 0; i < menuCount; i++) // 메뉴 갯수만큼 반복
        {
            if (i == currentMenuIndex) // 선택된 메뉴인 경우
                printf("[ \x1b[38;2;255;220;120m%s\x1b[0m ]  ", menus[i]); // 노란색 대괄호로 감싸서 표시
            else // 선택된 메뉴가 아닌 경우
                printf("  \x1b[38;2;80;80;80m%s\x1b[0m    ", menus[i]); // 대괄호로 감싸지 않고 회색으로 표시
        }
        printf("\n");

        ch = _getch();

        if (ch == 224)
        {
            ch = _getch();
            if (ch == 75) // 왼쪽 화살표 키
            {
                currentMenuIndex--;
                if (currentMenuIndex < 0) // 현재메뉴인덱스가 0보다 작다면
                    currentMenuIndex = menuCount - 1; //선택된 메뉴를 메뉴의 최대 갯수 - 1로 지정
            }
            else if (ch == 77) // 오른쪽 화살표 키
            {
                currentMenuIndex++;
                if (currentMenuIndex >= menuCount) // 현재메뉴인덱스가 메뉴의 최대 갯수보다 크거나 같다면 
                    currentMenuIndex = 0; //선택된 메뉴를 0번째로 지정
            }
        }
        else if (ch == 13)  // Enter 키
        {
            system("cls"); // 콘솔 청소
            return currentMenuIndex; // 선택된 메뉴 번호 반환
        }
    }
}
