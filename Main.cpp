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
    //showReactionIntro();
    
    showMainScreen();
    while (1)  // ���� ���� ����
    {
        system("cls");
        if (Rreturnnum != 3 && Treturnnum != 3)
            showMenuScreen(); // �޴� ����
        else if (Rreturnnum == 3)
		{
			system("cls");
            Rreturnnum = 0;
			showReactionGame();
			
		}
		else if (Treturnnum == 3)
		{
			system("cls");
            Treturnnum = 0;
			showTypingGame();
			
		}

        if (menunum == 0)  // �����ӵ� �׽�Ʈ ���� ����
        {
            system("cls");
            showReactionIntro(); // ���� �ӵ� �׽�Ʈ ���� ����
            if (Rreturnnum == 1)
            {
                system("cls"); 
                Rreturnnum = 0;
                continue;  // continue�� ���� ������Ͽ� �ٽ� ���θ޴��� ���ư� 
            }
            if (Rreturnnum == 0)
            {
                system("cls"); 
                Rreturnnum = 0;
                showReactionGame();  // ���� �ӵ� �׽�Ʈ ���� ����
            }
            
        }

        else if (menunum == 1) // Ÿ�� ���� ����
        {
            system("cls");
            showTypingIntro(); // Ÿ���� ��Ʈ�� ����
            
           if (Treturnnum == 1) //�޴���
            {
                system("cls");		
                Treturnnum = 0;
                continue;  // continue�� ���� ������Ͽ� �ٽ� ���θ޴��� ���ư�
                
            }
            if (Treturnnum == 0) // Ÿ���� ���� ����
			{
				system("cls");
                Treturnnum = 0;
                showTypingGame();  // Ÿ���� ���� ����
			}
            
        }
        if (Rreturnnum == 3)
        {
            system("cls");
            showReactionIntro();  // ���� ���� ����
        }

        if (Treturnnum == 3)
        {
            system("cls");
            showTypingIntro();  // Ÿ���� ���� ����
        }
        
    }

    return 0;
}