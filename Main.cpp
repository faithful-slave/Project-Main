#include "MainScreen.h"
#include "MenuScreen.h"
#include "Typing_Intro.h"

int main()
{
    //출력순서
    //showMainScreen();     // 1. 인트로 화면 출력
    showMenuScreen();     // 2. 메뉴 화면 & 게임 선택 화면 출력
    if (menunum == 0)
    {
        showTypingIntro();
    }
    else if (menunum == 1)
    {

    }


    return 0;
}