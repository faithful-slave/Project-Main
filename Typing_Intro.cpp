#include <iostream>
#include "Typing_Intro.h"
#include "Utils.h"
#include "Menu.h"
#include "MenuScreen.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define x 5
#define y 8
#define p 24
int Treturnnum = 0;
void showTypingIntro()
{
    char input;
    {    // ───────────────[made by 재경]─────────────── //
        //타자 게임 출력
        colorChange(TEXT_C_CHENG);
        gotoXY(x, y + 1);  printf("/$$$$$$$$ /$$     /$$ /$$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$          /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$\n");
        gotoXY(x, y + 2);  printf("|__  $$__/|  $$   /$$/| $$__  $$|_  $$_/| $$$ | $$ /$$__  $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/\n");
        gotoXY(x, y + 3);  printf("   | $$    \\  $$ /$$/ | $$  \\ $$  | $$  | $$$$| $$| $$  \\__/      | $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$      \n");
        gotoXY(x, y + 4);  printf("   | $$     \\  $$$$/  | $$$$$$$/  | $$  | $$ $$ $$| $$ /$$$$      | $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$   \n");
        gotoXY(x, y + 5);  printf("   | $$      \\  $$/   | $$____/   | $$  | $$  $$$$| $$|_  $$      | $$|_  $$| $$__  $$| $$  $$$| $$| $$__/   \n");
        gotoXY(x, y + 6);  printf("   | $$       | $$    | $$        | $$  | $$\\  $$$| $$  \\ $$      | $$  \\ $$| $$  | $$| $$\\  $ | $$| $$      \n");
        gotoXY(x, y + 7);  printf("   | $$       | $$    | $$       /$$$$$$| $$ \\  $$|  $$$$$$/      |  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$\n");
        gotoXY(x, y + 8);  printf("   |__/       |__/    |__/      |______/|__/  \\__/ \\______/        \\______/ |__/  |__/|__/     |__/|________/\n");
        colorChange(TEXT_C_WHITE);
        // ───────────────[made by 수범]─────────────── //

        const char* Typing_Menu[] = { "게임 시작하기", "게임 설명", "게임 선택으로 돌아가기" };
        int selected = menu(Typing_Menu, 3, 35, 20, 30, 22);
        //gotoXY(40, 20);//gotoXY(50, 22);
        if (selected == 0)
        {
            printf("\n");
            gotoXY(47, 5);
            printf("[ 게임을 시작하는 중입니다 ]");
            Sleep(500);
            printf("\n");
        }
            
        else if (selected == 1)
        {    
            // ───────────────[made by 재경 ]─────────────── //
            #define p 13
            #define y 5
            gotoXY(p, y + 0); printf("==========================================게임설명=============================================\n");
            gotoXY(p, y + 1); printf("|                                                                                             |\n");
            gotoXY(p, y + 2); printf("|                              난이도(Easy ~ Crazy)를 선택하고                                |\n");
            gotoXY(p, y + 3); printf("|                            화면에 출력된 문장을 그대로 입력합니다.                          |\n");
            gotoXY(p, y + 4); printf("|                                                                                             |\n");
            gotoXY(p, y + 5); printf("|             10번 입력이 끝나면 오타, 점수, 걸린 시간, 타자 속도가 자동으로 표시되며         |\n");
            gotoXY(p, y + 6); printf("|                            틀린 글자는 시각적으로 확인할 수 있습니다.                       |\n");
            gotoXY(p, y + 7); printf("|                                                                                             |\n");
            gotoXY(p, y + 8); printf("|                           정확도와 속도를 기반으로 점수가 계산되며                          |\n");
            gotoXY(p, y + 9); printf("|                     반복 플레이를 통해 타자 실력을 향상시킬 수 있습니다.                    |\n");
            gotoXY(p, y + 10); printf("|                                                                                             |\n");
            gotoXY(p, y + 11); printf("===============================================================================================\n");
            
            // ───────────────[made by 수범]─────────────── //
            const char* Typing_Menu[] = { "게임 시작하기", "게임 선택으로 돌아가기" };
            int selected2 = menu(Typing_Menu, 2, 38, 20, 38, 22);
            if (selected2 == 0)
            {
                printf("\n");
                gotoXY(47, 5);
                printf("[ 게임을 시작하는 중입니다 ]");
                Sleep(500);
                printf("\n");
            }
            else if (selected2 == 1)
			{
                printf("게임 선택 화면으로 돌아갑니다\n");
                Treturnnum = 1;
			}
        }
        else if (selected == 2)
        {
            printf("게임 선택 화면으로 돌아갑니다\n");
            Treturnnum = 1;
        }


    }
}
