#include "MainScreen.h"
#include "MenuScreen.h"
#include "Typing_Intro.h"
#include "Typing_Game_Screen.h"
#include "Reaction_Test_Game.h"
#include "Reaction_Intro.h"
#include <Windows.h>

// ������������������������������[made by ����]������������������������������ //

int main()
{
    showMainScreen();  // ���� ȭ�� ���

    while (1)  // ���� ���� ����
    {
        system("cls");

        // �޴� ȭ�� ���� (�� ���ӿ��� ���ƿ� ���°� �ƴ� ��)
        if (Rreturnnum != 3 && Treturnnum != 3 && Rreturnnum != 4 && Treturnnum != 4)
        {
            showMenuScreen();  // �޴� ȭ�� ���
        }

        // ���� �ӵ� ���� ���� ���� ��û
        else if (Rreturnnum == 3)
        {
            system("cls");
            Rreturnnum = 0;
            showReactionGame();
        }

        // Ÿ���� ���� ���� ���� ��û
        else if (Treturnnum == 3)
        {
            system("cls");
            Treturnnum = 0;
            showTypingGame();
        }

        // ���� �ӵ� ���� ��Ʈ�� ��û
        if (Rreturnnum == 4)
        {
            system("cls");
            Rreturnnum = 0;
            menunum = 5;
            showReactionIntro();
        }

        // Ÿ���� ���� ��Ʈ�� ��û
        if (Treturnnum == 4)
        {
            system("cls");
            Treturnnum = 0;
            menunum = 6;
            showTypingIntro();
        }

        // ���� �ӵ� ���� ���� ��
        if (menunum == 0 || menunum == 5)
        {
            system("cls");

            // �޴����� ������ ��� ��Ʈ�� ���� ����
            if (menunum == 0)
                showReactionIntro();

            // �޴��� ���ư��� ��û
            if (Rreturnnum == 1)
            {
                system("cls");
                Rreturnnum = 0;
                continue;  // ���� ����� (�޴���)
            }

            // ���� ���� ��û
            if (Rreturnnum == 0)
            {
                system("cls");
                Rreturnnum = 0;
                showReactionGame();
            }
        }

        // Ÿ�� ���� ���� ��
        else if (menunum == 1 || menunum == 6)
        {
            system("cls");

            // �޴����� ������ ��� ��Ʈ�� ���� ����
            if (menunum == 1)
                showTypingIntro();

            // �޴��� ���ư��� ��û
            if (Treturnnum == 1)
            {
                system("cls");
                Treturnnum = 0;
                continue;  // ���� ����� (�޴���)
            }

            // ���� ���� ��û
            if (Treturnnum == 0)
            {
                system("cls");
                Treturnnum = 0;
                showTypingGame();
            }
        }

        // ��Ÿ �������� ���û ó�� (��Ʈ��)
        if (Rreturnnum == 3)
        {
            system("cls");
            showReactionIntro();
        }

        if (Treturnnum == 3)
        {
            system("cls");
            showTypingIntro();
        }
    }

    return 0;
}
