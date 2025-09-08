#include <iostream>
#include "MenuScreen.h"
#include "Utils.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
// ───────────────[made by 재경]─────────────── //
// ui 제작
int menunum = 0;
void showMenuScreen() 
{
    char input;
    {
        // MAIN MENU출력
        colorChange(TEXT_C_WHITE);
        gotoXY(25, 10); printf(" /$$$$$$$  /$$           /$$                                          \n");
        gotoXY(25, 11); printf("| $$__  $$|__/          | $$                                          \n");
        gotoXY(25, 12); printf("| $$  \\ $$ /$$  /$$$$$$$| $$   /$$        /$$$$$$  /$$$$$$$   /$$$$$$ \n");
        gotoXY(25, 13); printf("| $$$$$$$/| $$ /$$_____/| $$  /$$/       /$$__  $$| $$__  $$ /$$__  $$\n");
        gotoXY(25, 14); printf("| $$____/ | $$| $$      | $$$$$$/       | $$  \\ $$| $$  \\ $$| $$$$$$$$\n");
        gotoXY(25, 15); printf("| $$      | $$| $$      | $$_  $$       | $$  | $$| $$  | $$| $$_____/\n");
        gotoXY(25, 16); printf("| $$      | $$|  $$$$$$$| $$ \\  $$      |  $$$$$$/| $$  | $$|  $$$$$$$\n");
        gotoXY(25, 17); printf("|__/      |__/ \\_______/|__/  \\__/       \\______/ |__/  |__/ \\_______/\n");
    }
    colorChange(TEXT_C_WHITE);

// ───────────────[made by 수범]─────────────── //
// 키보드로 좌우 방향키를 입력받아 메뉴 선택 기능

#define MAX_MENUS 2 //최대 메뉴 갯수 지정

    char menus[MAX_MENUS][30] = //메뉴 배열 지정
    {
        "반응 속도 테스트 게임",
        "타자 게임",
    };

    int currentMenuIndex = 0;  // 현재 선택된 메뉴 인덱스
    int ch;

    while (1) 
    {
        gotoXY(26, 20);
        printf("좌우 방향키로 메뉴 선택 후 Enter 키를 눌러 원하는 게임을 선택하세요.\n\n");

        gotoXY(39, 22);  // 메뉴 갯수 및 글자 갯수에 따른 x위치 조정 바람

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
            printf("[%s] 으로 이동 중입니다!\n", menus[currentMenuIndex]); //메뉴 currentMenuIndex번째로 이동
            printf("%d", currentMenuIndex);
            break;  // 선택 완료 후 종료
        }
    }
    menunum = currentMenuIndex;
    Sleep(900);
}

