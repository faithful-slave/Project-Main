#include <iostream>
#include "Typing_Intro.h"
#include "Utils.h"
#include "Menu.h"
#include "MenuScreen.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define x 5
#define y 8
#define p 24
int Treturnnum = 0;
void showTypingIntro()
{
    char input;
    {    // ������������������������������[made by ���]������������������������������ //
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
        // ������������������������������[made by ����]������������������������������ //

        const char* Typing_Menu[] = { "���� �����ϱ�", "���� ����", "���� �������� ���ư���" };
        int selected = menu(Typing_Menu, 3, 35, 20, 30, 22);
        //gotoXY(40, 20);//gotoXY(50, 22);
        if (selected == 0)
        {
            printf("\n");
            gotoXY(47, 5);
            printf("[ ������ �����ϴ� ���Դϴ� ]");
            Sleep(500);
            printf("\n");
        }
            
        else if (selected == 1)
        {    
            // ������������������������������[made by ��� ]������������������������������ //
            #define p 13
            #define y 5
            gotoXY(p, y + 0); printf("==========================================���Ӽ���=============================================\n");
            gotoXY(p, y + 1); printf("|                                                                                             |\n");
            gotoXY(p, y + 2); printf("|                              ���̵�(Easy ~ Crazy)�� �����ϰ�                                |\n");
            gotoXY(p, y + 3); printf("|                            ȭ�鿡 ��µ� ������ �״�� �Է��մϴ�.                          |\n");
            gotoXY(p, y + 4); printf("|                                                                                             |\n");
            gotoXY(p, y + 5); printf("|             10�� �Է��� ������ ��Ÿ, ����, �ɸ� �ð�, Ÿ�� �ӵ��� �ڵ����� ǥ�õǸ�         |\n");
            gotoXY(p, y + 6); printf("|                            Ʋ�� ���ڴ� �ð������� Ȯ���� �� �ֽ��ϴ�.                       |\n");
            gotoXY(p, y + 7); printf("|                                                                                             |\n");
            gotoXY(p, y + 8); printf("|                           ��Ȯ���� �ӵ��� ������� ������ ���Ǹ�                          |\n");
            gotoXY(p, y + 9); printf("|                     �ݺ� �÷��̸� ���� Ÿ�� �Ƿ��� ����ų �� �ֽ��ϴ�.                    |\n");
            gotoXY(p, y + 10); printf("|                                                                                             |\n");
            gotoXY(p, y + 11); printf("===============================================================================================\n");
            
            // ������������������������������[made by ����]������������������������������ //
            const char* Typing_Menu[] = { "���� �����ϱ�", "���� �������� ���ư���" };
            int selected2 = menu(Typing_Menu, 2, 38, 20, 38, 22);
            if (selected2 == 0)
            {
                printf("\n");
                gotoXY(47, 5);
                printf("[ ������ �����ϴ� ���Դϴ� ]");
                Sleep(500);
                printf("\n");
            }
            else if (selected2 == 1)
			{
                printf("���� ���� ȭ������ ���ư��ϴ�\n");
                Treturnnum = 1;
			}
        }
        else if (selected == 2)
        {
            printf("���� ���� ȭ������ ���ư��ϴ�\n");
            Treturnnum = 1;
        }


    }
}
