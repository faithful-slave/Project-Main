#include <iostream>
#include "Reaction_Intro.h"
#include "Utils.h"
#include "Menu.h"
#include "MenuScreen.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int Rreturnnum = 0;

void showReactionIntro()
{
#define y 5
#define x 20
    // REACTION MENU출력
    gotoXY(x, y + 0); printf("/$$$$$$$  /$$$$$$$$  /$$$$$$   /$$$$$$  /$$$$$$$$ /$$$$$$  /$$$$$$   /$$   /$$");
    gotoXY(x, y + 1); printf("| $$__  $$| $$_____/ /$$__  $$ /$$__  $$|__  $$__/|_  $$_/ /$$__  $$| $$$ | $$");
    gotoXY(x, y + 2); printf("| $$  \\ $$| $$      | $$  \\ $$| $$  \\__/   | $$     | $$  | $$  \\ $$| $$$$| $$");
    gotoXY(x, y + 3); printf("| $$$$$$$/| $$$$$   | $$$$$$$$| $$         | $$     | $$  | $$  | $$| $$ $$ $$");
    gotoXY(x, y + 4); printf("| $$__  $$| $$__/   | $$__  $$| $$         | $$     | $$  | $$  | $$| $$  $$$$");
    gotoXY(x, y + 5); printf("| $$  \\ $$| $$      | $$  | $$| $$    $$   | $$     | $$  | $$  | $$| $$\\  $$$");
    gotoXY(x, y + 6); printf("| $$  | $$| $$$$$$$$| $$  | $$|  $$$$$$/   | $$    /$$$$$$|  $$$$$$/| $$ \\  $$");
    gotoXY(x, y + 7); printf("|__/  |__/|________/|__/  |__/ \\______/    |__/   |______/ \\______/ |__/  \\__/");
#define x 37
    gotoXY(x, y + 9); printf("  /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$");
    gotoXY(x, y + 10); printf(" /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/");
    gotoXY(x, y + 11); printf("| $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$      ");
    gotoXY(x, y + 12); printf("| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$   ");
    gotoXY(x, y + 13); printf("| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/   ");
    gotoXY(x, y + 14); printf("| $$  \\ $$| $$  | $$| $$\\  $ | $$| $$      ");
    gotoXY(x, y + 15); printf("|  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$");
    gotoXY(x, y + 16); printf(" \\______/ |__/  |__/|__/     |__/|________/");


    const char* Reaction_Menu[] = { "게임 시작하기", "게임 선택으로 돌아가기" };
    int selected = menu(Reaction_Menu, 2, 35, 25, 37, 27);

    if (selected == 0)
    {
        printf("\n");
        gotoXY(47, 5);
        printf("[ 게임을 시작하는 중입니다 ]");
        Sleep(500);
        printf("\n");
    }
    else if (selected == 1)
    {
        printf("\n");
        gotoXY(47, 5);
        printf("게임 선택 화면으로 돌아갑니다\n");
        Rreturnnum = 1;
    }

}