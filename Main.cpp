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
    showMainScreen();  // 메인 화면 출력

    while (1)  // 메인 루프 시작
    {
        system("cls");

        // 메뉴 화면 조건 (각 게임에서 돌아온 상태가 아닐 때)
        if (Rreturnnum != 3 && Treturnnum != 3 && Rreturnnum != 4 && Treturnnum != 4)
        {
            showMenuScreen();  // 메뉴 화면 출력
        }

        // 반응 속도 게임 직접 실행 요청
        else if (Rreturnnum == 3)
        {
            system("cls");
            Rreturnnum = 0;
            showReactionGame();
        }

        // 타이핑 게임 직접 실행 요청
        else if (Treturnnum == 3)
        {
            system("cls");
            Treturnnum = 0;
            showTypingGame();
        }

        // 반응 속도 게임 인트로 요청
        if (Rreturnnum == 4)
        {
            system("cls");
            Rreturnnum = 0;
            menunum = 5;
            showReactionIntro();
        }

        // 타이핑 게임 인트로 요청
        if (Treturnnum == 4)
        {
            system("cls");
            Treturnnum = 0;
            menunum = 6;
            showTypingIntro();
        }

        // 반응 속도 게임 선택 시
        if (menunum == 0 || menunum == 5)
        {
            system("cls");

            // 메뉴에서 선택한 경우 인트로 먼저 실행
            if (menunum == 0)
                showReactionIntro();

            // 메뉴로 돌아가기 요청
            if (Rreturnnum == 1)
            {
                system("cls");
                Rreturnnum = 0;
                continue;  // 루프 재시작 (메뉴로)
            }

            // 게임 실행 요청
            if (Rreturnnum == 0)
            {
                system("cls");
                Rreturnnum = 0;
                showReactionGame();
            }
        }

        // 타자 게임 선택 시
        else if (menunum == 1 || menunum == 6)
        {
            system("cls");

            // 메뉴에서 선택한 경우 인트로 먼저 실행
            if (menunum == 1)
                showTypingIntro();

            // 메뉴로 돌아가기 요청
            if (Treturnnum == 1)
            {
                system("cls");
                Treturnnum = 0;
                continue;  // 루프 재시작 (메뉴로)
            }

            // 게임 실행 요청
            if (Treturnnum == 0)
            {
                system("cls");
                Treturnnum = 0;
                showTypingGame();
            }
        }

        // 기타 예외적인 재요청 처리 (인트로)
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
