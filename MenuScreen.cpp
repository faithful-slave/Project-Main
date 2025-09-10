#include <iostream>
#include "MenuScreen.h"
#include "Utils.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Menu.h"
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
    const char* mainMenu[] = { "반응 속도 테스트 게임", "타자 게임"};
    int selected = menu(mainMenu, 2, 38, 20, 39, 22);
    menunum = selected;
    system("cls");
    
}

