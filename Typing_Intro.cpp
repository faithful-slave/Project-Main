#include <iostream>
#include "Typing_Intro.h"
#include "Utils.h"
#include "Menu.h"
#include "MenuScreen.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define x 10
#define y 8
#define p 24
int returnnum = 0;
void showTypingIntro()
{
    char input;
    {
        //타자 게임 출력
        colorChange(TEXT_C_CHENG);
        gotoXY(x, y + 1);  printf("/$$$$$$$$ /$$     /$$ /$$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$          /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$\n");
        gotoXY(x, y + 2);  printf("|__  $$__/|  $$   /$$/| $$__  $$|_  $$_/| $$$ | $$ /$$__  $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/\n");
        gotoXY(x, y + 3);  printf("   | $$    \\  $$ /$$/ | $$  \\ $$  | $$  | $$$$| $$| $$  \\__/      | $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$      \n");
        gotoXY(x, y + 4);  printf("   | $$     \\  $$$$/  | $$$$$$$/  | $$  | $$ $$ $$| $$ /$$$$      | $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$   \n");
        gotoXY(x, y + 5);  printf("   | $$      \\  $$/   | $$____/   | $$  | $$  $$$$| $$|_  $$      | $$|_  $$| $$__  $$| $$  $$$| $$| $$__/   \n");
        gotoXY(x, y + 6);  printf("   | $$       | $$    | $$        | $$  | $$\\  $$$| $$  \\ $$      | $$  \\ $$| $$  | $$| $$\\  $ | $$| $$      \n");
        gotoXY(x, y + 7);  printf("   | $$       | $$    | $$       /$$$$$$| $$ \\  $$|  $$$$$$/      |  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$\n");
        gotoXY(x, y + 8);  printf("   |__/       |__/    |__/      |______/|__/  \\__/ \\______/        \\______/ |__/  |__/|__/     |__/|________/\n");
        colorChange(TEXT_C_WHITE);


        const char* Typing_Menu[] = { "게임 시작하기", "게임 설명", "게임 선택으로 돌아가기" };
        int selected = menu(Typing_Menu, 3, 40, 20, 50, 22);
        //gotoXY(40, 20);//gotoXY(50, 22);
        if (selected == 0)
        {
            printf("\n");
            gotoXY(47, 5);
            printf("[ 게임을 시작하는 중 입니다 ]");
            Sleep(3000);
            printf("\n");
        }
            
        else if (selected == 1)
        {
            printf("게임 설명");
            const char* Typing_Menu[] = { "게임 시작하기", "게임 선택으로 돌아가기" };
            int selected2 = menu(Typing_Menu, 2, 40, 20, 50, 22);
            if (selected2 == 0)
            {
                printf("\n");
                gotoXY(47, 5);
                printf("[ 게임을 시작하는 중 입니다 ]");
                returnnum = 2;
                Sleep(2000);
                printf("\n");
            }
            else if (selected2 == 1)
			{
                printf("게임 선택 화면으로 돌아갑니다\n");
                Sleep(2000);
                returnnum = 1;
			}
            Sleep(3000);
        }
        else if (selected == 2)
        {
            printf("게임 선택 화면으로 돌아갑니다\n");
            Sleep(2000);
            returnnum = 1;

        }


    }
}
