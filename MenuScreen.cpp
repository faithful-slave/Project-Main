#include <iostream>
#include "MenuScreen.h"
#include "Utils.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Menu.h"
// ������������������������������[made by ���]������������������������������ //
// ui ����
int menunum = 0;
void showMenuScreen() 
{
    char input;
    {
        // MAIN MENU���
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
// ������������������������������[made by ����]������������������������������ //
// Ű����� �¿� ����Ű�� �Է¹޾� �޴� ���� ���
    const char* mainMenu[] = { "���� �ӵ� �׽�Ʈ ����", "Ÿ�� ����"};
    int selected = menu(mainMenu, 2, 38, 20, 39, 22);
    menunum = selected;
    system("cls");
    
}

