#include <iostream>
#include "Typing_Intro.h"
#include "Utils.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define x 10
#define y 8
#define p 24
void showTypingIntro()
{
    char input;
    {
        //타자 게임 출력
        colorChange(TEXT_C_CHENG);
        gotoXY(x, y+1);  printf("/$$$$$$$$ /$$     /$$ /$$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$          /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$\n");
        gotoXY(x, y+2);  printf("|__  $$__/|  $$   /$$/| $$__  $$|_  $$_/| $$$ | $$ /$$__  $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/\n");
        gotoXY(x, y+3);  printf("   | $$    \\  $$ /$$/ | $$  \\ $$  | $$  | $$$$| $$| $$  \\__/      | $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$      \n");
        gotoXY(x, y+4);  printf("   | $$     \\  $$$$/  | $$$$$$$/  | $$  | $$ $$ $$| $$ /$$$$      | $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$   \n");
        gotoXY(x, y+5);  printf("   | $$      \\  $$/   | $$____/   | $$  | $$  $$$$| $$|_  $$      | $$|_  $$| $$__  $$| $$  $$$| $$| $$__/   \n");
        gotoXY(x, y+6);  printf("   | $$       | $$    | $$        | $$  | $$\\  $$$| $$  \\ $$      | $$  \\ $$| $$  | $$| $$\\  $ | $$| $$      \n");
        gotoXY(x, y+7);  printf("   | $$       | $$    | $$       /$$$$$$| $$ \\  $$|  $$$$$$/      |  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$\n");
        gotoXY(x, y+8);  printf("   |__/       |__/    |__/      |______/|__/  \\__/ \\______/        \\______/ |__/  |__/|__/     |__/|________/\n");
        colorChange(TEXT_C_WHITE);
#define MAX_MENUS 3 //최대 메뉴 갯수 지정

        char menus[MAX_MENUS][30] = //메뉴 배열 지정
        {
            "게임 시작하기",
            "게임 설명",
            "게임 선택으로 돌아가기"
        };
        char menus2[MAX_MENUS][30] = //메뉴 배열 지정
        {
            "게임 시작하기",
            "게임 메인으로 돌아가기",
        };

        int currentMenuIndex = 0;  // 현재 선택된 메뉴 인덱스
        int ch;

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

        if (currentMenuIndex == 0)
        {
            printf("\n");

            gotoXY(47, 5);
            printf("[ 게임을 시작하는 중 입니다 ]");
            Sleep(3000);

            printf("\n");
        }
        if (currentMenuIndex == 1)
        {
            printf("게임 설명");
            Sleep(3000);
        }
        if (currentMenuIndex == 2)
        {

        }
        system("cls");
    }
}