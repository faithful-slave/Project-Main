#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Utils.h"

#define MAX_MENUS 5
void menu(const char* menus[], int menuCount)
{
    int currentMenuIndex = 0;
    int ch;

    //����� ��
    //const char* mainMenu[] = { "����", "����", "�ҷ�����", "����", "����" };
    //menu(mainMenu, 5);  // �޴� �迭�� ���� ����

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
}