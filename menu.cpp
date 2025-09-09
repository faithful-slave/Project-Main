#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Utils.h"
#include "Menu.h"
//�¿� ���� �޴� �Լ�
int menu(const char* menus[], int menuCount, int textX, int textY, int menuX, int menuY)
{
    int currentMenuIndex = 0;
    int ch;

    while (1)
    {
        gotoXY(textX, textY);
        printf("�¿� ����Ű�� �޴� ���� �� Enter Ű�� ��������.\n\n");
        gotoXY(menuX, menuY); // �޴� ���� �� ���� ������ ���� x��ġ ���� �ٶ�

        // �޴� ������ �� �ٷ� ǥ�� (���õ� �޴��� ���ȣ�� ���� ǥ��)
        for (int i = 0; i < menuCount; i++)
        {
            if (i == currentMenuIndex)
                printf("[ \x1b[38;2;255;220;120m%s\x1b[0m ]  ", menus[i]);
            else
                printf("  \x1b[38;2;80;80;80m%s\x1b[0m    ", menus[i]);
        }
        printf("\n");

        ch = _getch();

        if (ch == 224)
        {
            ch = _getch();

            if (ch == 75) // ���� Ű
            {
                currentMenuIndex--;
                if (currentMenuIndex < 0)
                    currentMenuIndex = menuCount - 1;
            }
            else if (ch == 77) // ������ Ű
            {
                currentMenuIndex++;
                if (currentMenuIndex >= menuCount)
                    currentMenuIndex = 0;
            }
        }
        else if (ch == 13)  // Enter Ű
        {
            system("cls");
            return currentMenuIndex; // ���õ� �޴� ��ȣ ��ȯ
        }
    }
}
