#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Utils.h"
#include "Menu.h"
//좌우 선택 메뉴 함수
int menu(const char* menus[], int menuCount, int textX, int textY, int menuX, int menuY)
{
    int currentMenuIndex = 0;
    int ch;

    while (1)
    {
        gotoXY(textX, textY);
        printf("좌우 방향키로 메뉴 선택 후 Enter 키를 누르세요.\n\n");
        gotoXY(menuX, menuY); // 메뉴 갯수 및 글자 갯수에 따른 x위치 조정 바람

        // 메뉴 종류를 한 줄로 표시 (선택된 메뉴는 대괄호로 감싸 표시)
        for (int i = 0; i < menuCount; i++)
        {
            if (i == currentMenuIndex)
                printf("[ \x1b[38;2;255;220;120m%s\x1b[0m ]  ", menus[i]);
            else
                printf("  \x1b[38;2;80;80;80m%s\x1b[0m    ", menus[i]);
        }
        printf("\n");

        ch = _getch();

        if (ch == 224)
        {
            ch = _getch();

            if (ch == 75) // 왼쪽 키
            {
                currentMenuIndex--;
                if (currentMenuIndex < 0)
                    currentMenuIndex = menuCount - 1;
            }
            else if (ch == 77) // 오른쪽 키
            {
                currentMenuIndex++;
                if (currentMenuIndex >= menuCount)
                    currentMenuIndex = 0;
            }
        }
        else if (ch == 13)  // Enter 키
        {
            system("cls");
            return currentMenuIndex; // 선택된 메뉴 번호 반환
        }
    }
}
