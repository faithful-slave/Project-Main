#include "MainScreen.h"
#include "MenuScreen.h"
#include "Typing_Intro.h"

int main()
{
    //��¼���
    //showMainScreen();     // 1. ��Ʈ�� ȭ�� ���
    showMenuScreen();     // 2. �޴� ȭ�� & ���� ���� ȭ�� ���
    if (menunum == 0)
    {
        showTypingIntro();
    }
    else if (menunum == 1)
    {

    }


    return 0;
}