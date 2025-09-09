#include <iostream>
#include "MainScreen.h"
#include "Utils.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>


// ───────────────[made by 재경]─────────────── /
void showMainScreen() {
    char input;
    {
        // TEAM 3 출력
        clearScreen();
        gotoXY(32, 14);
        printf("/$$$$$$$$                                       /$$$$$$");
        gotoXY(32, 15);
        printf("|__  $$__/                                      /$$__  $$");
        gotoXY(32, 16);
        printf("   | $$   /$$$$$$   /$$$$$$  /$$$$$$/$$$$       |__/  \\ $$");
        gotoXY(32, 17);
        printf("   | $$  /$$__  $$ |____  $$| $$_  $$_  $$         /$$$$$/");
        gotoXY(32, 18);
        printf("   | $$ | $$$$$$$$  /$$$$$$$| $$ \\ $$ \\ $$        |___  $$");
        gotoXY(32, 19);
        printf("   | $$ | $$_____/ /$$__  $$| $$ | $$ | $$       /$$  \\ $$");
        gotoXY(32, 20);
        printf("   | $$ |  $$$$$$$|  $$$$$$$| $$ | $$ | $$      |  $$$$$$/");
        gotoXY(32, 21);
        printf("   |__/  \\_______/ \\_______/|__/ |__/ |__/       \\______/");
        // GAME START 출력
        gotoXY(12, 5);
        colorChange(TEXT_C_RED);
        printf(" /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$        /$$$$$$  /$$$$$$$$ /$$$$$$  /$$$$$$$  /$$$$$$$$");
        gotoXY(12, 6);
        colorChange(TEXT_C_RED);
        printf("/$$__  $$ /$$__  $$| $$$    /$$$| $$_____/       /$$__  $$|__  $$__//$$__  $$| $$__  $$|__  $$__/");
        gotoXY(12, 7);
        colorChange(TEXT_C_RED);
        printf("| $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$            | $$  \\__/   | $$  | $$  \\ $$| $$  \\ $$   | $$   ");
        gotoXY(12, 8);
        colorChange(TEXT_C_WHITE);
        printf("| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$         |  $$$$$$    | $$  | $$$$$$$$| $$$$$$$/   | $$   ");
        gotoXY(12, 9);
        colorChange(TEXT_C_WHITE);
        printf("| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/          \\____  $$   | $$  | $$__  $$| $$__  $$   | $$   ");
        gotoXY(12, 10);
        colorChange(TEXT_C_BLUE);
        printf("| $$  \\ $$| $$  | $$| $$\\  $ | $$| $$             /$$  \\ $$   | $$  | $$  | $$| $$  \\ $$   | $$   ");
        gotoXY(12, 11);
        colorChange(TEXT_C_BLUE);
        printf("|  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$      |  $$$$$$/   | $$  | $$  | $$| $$  | $$   | $$   ");
        gotoXY(12, 12);
        colorChange(TEXT_C_BLUE);
        printf(" \\______/ |__/  |__/|__/     |__/|________/       \\______/    |__/  |__/  |__/|__/  |__/   |__/  ");
    }
    colorChange(TEXT_C_WHITE);

    gotoXY(45, 23);
    printf("  게임을 시작하는 중입니다");
    colorEnd();

    Sleep(1000);
    int total = 100;
    srand(time(NULL));
    int last = rand() % 20;
    for (int i = 0; i <= total; i++) 
    {
        DoProgress("진행도 : ", i,  total, 18, 25);
        Sleep(last); 
    }
    Sleep(500);
    gotoXY(18, 25); printf("\r\33[2K");
    gotoXY(45, 23); printf("\r\33[2K");

    gotoXY(55, 23);
    printf(" 시작!");
    Sleep(700);
    
    system("cls");
}