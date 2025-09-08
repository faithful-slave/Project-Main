#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Utils.h"

#define MAX_MENUS 5
void menu(const char* menus[], int menuCount)
{
    int currentMenuIndex = 0;
    int ch;

    //사용할 때
    //const char* mainMenu[] = { "시작", "설정", "불러오기", "도움말", "종료" };
    //menu(mainMenu, 5);  // 메뉴 배열과 갯수 전달

    while (1)
    {
        gotoXY(40, 20);
        printf("좌우 방향키로 메뉴 선택 후 Enter 키를 누르세요.\n\n");

        gotoXY(50, 22);  // 메뉴 갯수 및 글자 갯수에 따른 x위치 조정 바람

        // 메뉴 종류를 한 줄로 표시 (선택된 메뉴는 대괄호로 감싸 표시)
        for (int i = 0; i < MAX_MENUS; i++)
        {
            if (i == currentMenuIndex) // 만약 currentMenuIndex와 i가 같다면(선택 하였다면)
                printf("[ \x1b[38;2;255;220;120m%s\x1b[0m ]  ", menus[i]); //괄호 표시

            else
                printf("  \x1b[38;2;80;80;80m%s\x1b[0m    ", menus[i]); // 괄호 없이 회색으로 표시
        }
        printf("\n");

        ch = _getch(); // 키입력

        if (ch == 224)
        {  // 방향키 입력 시작
            ch = _getch();

            if (ch == 75) // 만약 왼쪽 키 입력이라면
            {
                currentMenuIndex--;  // 1빼기
                if (currentMenuIndex < 0) // 만약 currentMenuIndex이 0보다 작다면
                    currentMenuIndex = MAX_MENUS - 1; //최대 메뉴의 갯수에서 1을 빼서 currentMenuIndex저장
            }
            else if (ch == 77)  // 만약 오른쪽 키 입력이라면
            {
                currentMenuIndex++; // 1더하기
                if (currentMenuIndex >= MAX_MENUS) // 만약 currentMenuIndex이 최대 메뉴 갯수보다 크거나 같다면
                    currentMenuIndex = 0; // 0번째로 초기화(1번째 메뉴로 이동)
            }
        }
        else if (ch == 13)  // Enter 키
        {
            system("cls");
            break;  // 선택 완료 후 종료
        }
    }
}