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
        //Ÿ�� ���� ���
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
#define MAX_MENUS 3 //�ִ� �޴� ���� ����

        char menus[MAX_MENUS][30] = //�޴� �迭 ����
        {
            "���� �����ϱ�",
            "���� ����",
            "���� �������� ���ư���"
        };
        char menus2[MAX_MENUS][30] = //�޴� �迭 ����
        {
            "���� �����ϱ�",
            "���� �������� ���ư���",
        };

        int currentMenuIndex = 0;  // ���� ���õ� �޴� �ε���
        int ch;

        while (1)
        {
            gotoXY(40, 20);
            printf("�¿� ����Ű�� �޴� ���� �� Enter Ű�� ��������.\n\n");

            gotoXY(50, 22);  // �޴� ���� �� ���� ������ ���� x��ġ ���� �ٶ�

            // �޴� ������ �� �ٷ� ǥ�� (���õ� �޴��� ���ȣ�� ���� ǥ��)
            for (int i = 0; i < MAX_MENUS; i++)
            {
                if (i == currentMenuIndex) // ���� currentMenuIndex�� i�� ���ٸ�(���� �Ͽ��ٸ�)
                    printf("[ \x1b[38;2;255;220;120m%s\x1b[0m ]  ", menus[i]); //��ȣ ǥ��

                else
                    printf("  \x1b[38;2;80;80;80m%s\x1b[0m    ", menus[i]); // ��ȣ ���� ȸ������ ǥ��
            }
            printf("\n");

            ch = _getch(); // Ű�Է�

            if (ch == 224)
            {  // ����Ű �Է� ����
                ch = _getch();

                if (ch == 75) // ���� ���� Ű �Է��̶��
                {
                    currentMenuIndex--;  // 1����
                    if (currentMenuIndex < 0) // ���� currentMenuIndex�� 0���� �۴ٸ�
                        currentMenuIndex = MAX_MENUS - 1; //�ִ� �޴��� �������� 1�� ���� currentMenuIndex����
                }
                else if (ch == 77)  // ���� ������ Ű �Է��̶��
                {
                    currentMenuIndex++; // 1���ϱ�
                    if (currentMenuIndex >= MAX_MENUS) // ���� currentMenuIndex�� �ִ� �޴� �������� ũ�ų� ���ٸ�
                        currentMenuIndex = 0; // 0��°�� �ʱ�ȭ(1��° �޴��� �̵�)
                }
            }
            else if (ch == 13)  // Enter Ű
            {
                system("cls");
                break;  // ���� �Ϸ� �� ����
            }
        }

        if (currentMenuIndex == 0)
        {
            printf("\n");

            gotoXY(47, 5);
            printf("[ ������ �����ϴ� �� �Դϴ� ]");
            Sleep(3000);

            printf("\n");
        }
        if (currentMenuIndex == 1)
        {
            printf("���� ����");
            Sleep(3000);
        }
        if (currentMenuIndex == 2)
        {

        }
        system("cls");
    }
}