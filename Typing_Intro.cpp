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
        //Ÿ�� ���� ���
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


        const char* Typing_Menu[] = { "���� �����ϱ�", "���� ����", "���� �������� ���ư���" };
        int selected = menu(Typing_Menu, 3, 40, 20, 50, 22);
        //gotoXY(40, 20);//gotoXY(50, 22);
        if (selected == 0)
        {
            printf("\n");
            gotoXY(47, 5);
            printf("[ ������ �����ϴ� �� �Դϴ� ]");
            Sleep(3000);
            printf("\n");
        }
            
        else if (selected == 1)
        {
            printf("���� ����");
            const char* Typing_Menu[] = { "���� �����ϱ�", "���� �������� ���ư���" };
            int selected2 = menu(Typing_Menu, 2, 40, 20, 50, 22);
            if (selected2 == 0)
            {
                printf("\n");
                gotoXY(47, 5);
                printf("[ ������ �����ϴ� �� �Դϴ� ]");
                returnnum = 2;
                Sleep(2000);
                printf("\n");
            }
            else if (selected2 == 1)
			{
                printf("���� ���� ȭ������ ���ư��ϴ�\n");
                Sleep(2000);
                returnnum = 1;
			}
            Sleep(3000);
        }
        else if (selected == 2)
        {
            printf("���� ���� ȭ������ ���ư��ϴ�\n");
            Sleep(2000);
            returnnum = 1;

        }


    }
}
