#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Utils.h"
#include "Menu.h"
//�¿� ���� �޴� �Լ�
// menus : �޴� ����Ʈ
// menuCount : �޴� ����
// textX, textY : ������ ��ġ
// menuX, menuY : �޴��� ��ġ
// ������������������������������[made by ����]������������������������������ //
int menu(const char* menus[], int menuCount, int textX, int textY, int menuX, int menuY)
{
    int currentMenuIndex = 0; // ���õ� �޴��� �ε���
    int ch; 

    while (1)
    {
        gotoXY(textX, textY); // ���� ��ġ ����
        printf("�¿� ����Ű�� �޴� ���� �� Enter Ű�� ��������.\n\n");
        gotoXY(menuX, menuY); // �޴� ���� �� ���� ������ ���� x��ġ ���� �ٶ�

        // �޴� ������ �� �ٷ� ǥ�� (���õ� �޴��� ���ȣ�� ���� ǥ��)
        for (int i = 0; i < menuCount; i++) // �޴� ������ŭ �ݺ�
        {
            if (i == currentMenuIndex) // ���õ� �޴��� ���
                printf("[ \x1b[38;2;255;220;120m%s\x1b[0m ]  ", menus[i]); // ����� ���ȣ�� ���μ� ǥ��
            else // ���õ� �޴��� �ƴ� ���
                printf("  \x1b[38;2;80;80;80m%s\x1b[0m    ", menus[i]); // ���ȣ�� ������ �ʰ� ȸ������ ǥ��
        }
        printf("\n");

        ch = _getch();

        if (ch == 224)
        {
            ch = _getch();
            if (ch == 75) // ���� ȭ��ǥ Ű
            {
                currentMenuIndex--;
                if (currentMenuIndex < 0) // ����޴��ε����� 0���� �۴ٸ�
                    currentMenuIndex = menuCount - 1; //���õ� �޴��� �޴��� �ִ� ���� - 1�� ����
            }
            else if (ch == 77) // ������ ȭ��ǥ Ű
            {
                currentMenuIndex++;
                if (currentMenuIndex >= menuCount) // ����޴��ε����� �޴��� �ִ� �������� ũ�ų� ���ٸ� 
                    currentMenuIndex = 0; //���õ� �޴��� 0��°�� ����
            }
        }
        else if (ch == 13)  // Enter Ű
        {
            system("cls"); // �ܼ� û��
            return currentMenuIndex; // ���õ� �޴� ��ȣ ��ȯ
        }
    }
}
