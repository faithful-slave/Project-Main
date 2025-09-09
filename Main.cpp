#include "MainScreen.h"
#include "MenuScreen.h"
#include "Typing_Intro.h"
#include "Typing_Game_Screen.h"
#include "Reaction_Test_Game.h"
#include <Windows.h>

int main()
{
    showMainScreen();
    while (1)  // 무한 루프 시작
    {
        system("cls");
        showMenuScreen();

        if (menunum == 0)
        {
            system("cls");
            showReactionGame();
            break;
        }

        else if (menunum == 1)
        {
            system("cls");
            showTypingIntro();

            if (returnnum == 1)
            {
                system("cls");
                continue;  // continue로 루프 재시작하여 다시 메인메뉴로 돌아감
            }
            if (returnnum == 2)
			{
				system("cls");
                showTypingGame();  //타이핑 게임 실행
			}
            else
            {
                system("cls");
                showTypingGame();  //타이핑 게임 실행
                break;
            }
        }
    }

    return 0;
}