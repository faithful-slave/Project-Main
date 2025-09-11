#include "MainScreen.h"
#include "MenuScreen.h"
#include "Typing_Intro.h"
#include "Typing_Game_Screen.h"
#include "Reaction_Test_Game.h"
#include "Reaction_Intro.h"
#include <Windows.h>
// ───────────────[made by 수범]─────────────── //

int main()
{
    //showReactionIntro();
    
    showMainScreen();
    while (1)  // 무한 루프 시작
    {
        system("cls");
        if (Rreturnnum != 3 && Treturnnum != 3)
            showMenuScreen(); // 메뉴 실행
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

        if (menunum == 0)  // 반응속도 테스트 게임 선택
        {
            system("cls");
            showReactionIntro(); // 반응 속도 테스트 게임 실행
            if (Rreturnnum == 1)
            {
                system("cls"); 
                Rreturnnum = 0;
                continue;  // continue로 루프 재시작하여 다시 메인메뉴로 돌아감 
            }
            if (Rreturnnum == 0)
            {
                system("cls"); 
                Rreturnnum = 0;
                showReactionGame();  // 반응 속도 테스트 게임 실행
            }
            
        }

        else if (menunum == 1) // 타자 게임 선택
        {
            system("cls");
            showTypingIntro(); // 타이핑 인트로 실행
            
           if (Treturnnum == 1) //메뉴로
            {
                system("cls");		
                Treturnnum = 0;
                continue;  // continue로 루프 재시작하여 다시 메인메뉴로 돌아감
                
            }
            if (Treturnnum == 0) // 타이핑 게임 실행
			{
				system("cls");
                Treturnnum = 0;
                showTypingGame();  // 타이핑 게임 실행
			}
            
        }
        if (Rreturnnum == 3)
        {
            system("cls");
            showReactionIntro();  // 반응 게임 실행
        }

        if (Treturnnum == 3)
        {
            system("cls");
            showTypingIntro();  // 타이핑 게임 실행
        }
        
    }

    return 0;
}