#include "MainScreen.h"
#include "MenuScreen.h"
#include "Typing_Intro.h"
#include "Typing_Game_Screen.h"
#include "Reaction_Test_Game.h"
#include <Windows.h>
// ������������������������������[made by ����]������������������������������ //
int main()
{
    showMainScreen();
    while (1)  // ���� ���� ����
    {
        system("cls");
        showMenuScreen(); //�޴� ����

        if (menunum == 0)
        {
            system("cls");
            showReactionGame(); //���� �ӵ� �׽�Ʈ ���� ����
            break;
        }

        else if (menunum == 1)
        {
            system("cls");
            showTypingIntro(); //Ÿ���� ��Ʈ�� ����

            if (returnnum == 1)
            {
                system("cls");
                continue;  // continue�� ���� ������Ͽ� �ٽ� ���θ޴��� ���ư�
            }
            if (returnnum == 2)
			{
				system("cls");
                showTypingGame();  //Ÿ���� ���� ����
			}
            else
            {
                system("cls");
                showTypingGame();  //Ÿ���� ���� ����
                break;
            }
        }
    }

    return 0;
}