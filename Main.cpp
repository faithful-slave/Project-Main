#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define ANSI_POS_OFFSET_X 1
#define ANSI_POS_OFFSET_Y 1

#define TEXT_C_RED 31
#define TEXT_C_BLUE 34
#define TEXT_C_WHITE 37


void clearScreen() {
    printf("\x1b[2J");
}
void gotoXY(int _x, int _y) {
    printf("\x1b[%d;%dH", _y + ANSI_POS_OFFSET_Y, _x + ANSI_POS_OFFSET_X);
}
void colorChange(int _colorNum) {
    printf("\x1b[%dm", _colorNum);
}
int main() {
    char input;
    {
        // TEAM 3 출력
        clearScreen();
        gotoXY(32, 13);
        printf("/$$$$$$$$                                       /$$$$$$");
        gotoXY(32, 14);
        printf("|__  $$__/                                      /$$__  $$");
        gotoXY(32, 15);
        printf("   | $$   /$$$$$$   /$$$$$$  /$$$$$$/$$$$       |__/  \\ $$");
        gotoXY(32, 16);
        printf("   | $$  /$$__  $$ |____  $$| $$_  $$_  $$         /$$$$$/");
        gotoXY(32, 17);
        printf("   | $$ | $$$$$$$$  /$$$$$$$| $$ \\ $$ \\ $$        |___  $$");
        gotoXY(32, 18);
        printf("   | $$ | $$_____/ /$$__  $$| $$ | $$ | $$       /$$  \\ $$");
        gotoXY(32, 19);
        printf("   | $$ |  $$$$$$$|  $$$$$$$| $$ | $$ | $$      |  $$$$$$/");
        gotoXY(32, 20);
        printf("   |__/  \\_______/ \\_______/|__/ |__/ |__/       \\______/");
        // GMAE STAR 출력
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

    gotoXY(45, 22);
    printf("게임을 시작하는 중입니다");
    colorEnd();

    for (int i = 0; i < 3; i++)
    {
        gotoXY(45, 23);
        printf("  잠시만 기다려주세요");
        printf("\x1b[2K\r");    gotoXY(45, 23);
        printf("  잠시만 기다려주세요.");
        Sleep(1000);//1초 멈춤
        printf("\x1b[2K\r");    gotoXY(45, 23);
        printf("  잠시만 기다려주세요..");
        Sleep(1000);//1초 멈춤
        printf("\x1b[2K\r");    gotoXY(45, 23);
        printf("  잠시만 기다려주세요...");
        Sleep(1000);//1초 멈춤
    }

    gotoXY(36, 11);

    Sleep(1000);//3초 멈춤
    system("cls");

    return 0;
}