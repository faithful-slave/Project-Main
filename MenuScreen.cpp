#include <iostream>
#include "MenuScreen.h"
#include "Utils.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
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

#define MAX_MENUS 2 //�ִ� �޴� ���� ����

    char menus[MAX_MENUS][30] = //�޴� �迭 ����
    {
        "���� �ӵ� �׽�Ʈ ����",
        "Ÿ�� ����",
    };

    int currentMenuIndex = 0;  // ���� ���õ� �޴� �ε���
    int ch;

    while (1) 
    {
        gotoXY(26, 20);
        printf("�¿� ����Ű�� �޴� ���� �� Enter Ű�� ���� ���ϴ� ������ �����ϼ���.\n\n");

        gotoXY(39, 22);  // �޴� ���� �� ���� ������ ���� x��ġ ���� �ٶ�

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
            printf("[%s] ���� �̵� ���Դϴ�!\n", menus[currentMenuIndex]); //�޴� currentMenuIndex��°�� �̵�
            printf("%d", currentMenuIndex);
            break;  // ���� �Ϸ� �� ����
        }
    }
    menunum = currentMenuIndex;
    Sleep(900);
}

