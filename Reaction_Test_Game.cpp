#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Reaction_Test_Game.h"
#include "Utils.h"
#include "Menu.h"
#include "Reaction_Intro.h"

#define TRIALS 2
// ───────────────[made by 수범]─────────────── //
// 반응속도 테스트 메뉴 만들기
void print_grade(ULONGLONG ms) {
    if (ms <= 180) {
        printf("\x1b[38;5;212m등급: 매우빠름 ★★★★★ (대단히 빠름!)\x1b[0m\n");
    }
    else if (ms <= 250) {
        printf("\x1b[38;5;221m등급: 빠름 ★★★★☆ (빠른 반응)\x1b[0m\n");
    }
    else if (ms <= 350) {
        printf("\x1b[38;5;120m등급: 우수 ★★★☆☆ (좋은 반응 속도)\x1b[0m\n");
    }
    else if (ms <= 500) {
        printf("\x1b[38;5;159m등급: 보통 ★★☆☆☆ (평균적인 속도)\x1b[0m\n");
    }
    else if (ms <= 800) {
        printf("\x1b[38;5;75m등급: 느림 ★☆☆☆☆ (느린 편)\x1b[0m\n");
    }
    else {
        printf("\x1b[38;5;246m등급: 매우느림 ☆☆☆☆☆ (연습 필요!)\x1b[0m\n");
    }
}

void showReactionGame()
{

    srand((unsigned int)time(NULL));
    ULONGLONG total_time = 0;
    ULONGLONG times[TRIALS];

    printf("< 반응 속도 테스트 - 총 %d회 >\n\n", TRIALS);
    Sleep(1000);
    printf("'\x1b[1;31m지금!\x1b[0m'이라는 글자가 나타나면 아무 키나 누르세요!\n");
    Sleep(3000);

    for (int i = 0; i < TRIALS; ++i)
    {
        system("cls");
        printf("[시도 %d/%d]\n", i + 1, TRIALS);

        int randomsleeptime = 1000 + rand() % 9000;
        printf("준비하세요...\n");
        Sleep(randomsleeptime);

        // (예비 누름 방지)
        while (_kbhit()) 
        {
            _getch();
        }
        Beep(1200, 100);
        printf("\n\x1b[1;31m지금!\x1b[0m\n");

        ULONGLONG start_time = GetTickCount64();

        while (1)
        {
            if (_kbhit())
            {
                _getch();
                ULONGLONG end_time = GetTickCount64();
                system("cls");

                printf("[시도 %d/%d]\n", i + 1, TRIALS);
                printf("\n");
                ULONGLONG elapsed_ms = end_time - start_time;
                times[i] = elapsed_ms;
                total_time += elapsed_ms;

                printf("\x1b[1;33m당신의 반응 속도는 \x1b[1;32m%llums\x1b[1;37m입니다.\x1b[0m\n", elapsed_ms);
                print_grade(elapsed_ms);
                Sleep(2000);
                break;
            }
            Sleep(0);
        }
    }

    int min = times[0];
    int max = times[0];

    for (int i = 1; i < TRIALS; i++) 
    {
        if (times[i] < min) 
            min = times[i];
        if (times[i] > max) 
            max = times[i];
    }

    // 평균 결과 출력
    // ───────────────[made by 은혁 & 재경 & 수범]─────────────── //
    system("cls");
    printf("============= 결과 요약 =============\n\n");
    for (int i = 0; i < TRIALS; ++i)
    {
        if (min == times[i])
            printf("   시도 %d: \x1b[38;2;118;255;118m%llums (가장 빠른 속도)\x1b[0m\n", i + 1, times[i]);
        else if (max == times[i])
            printf("   시도 %d: \x1b[38;2;255;157;183m%llums (가장 느린 속도)\x1b[0m\n", i + 1, times[i]);
        else
            printf("   시도 %d: %llums\n", i + 1, times[i]);
    }
    ULONGLONG avg = total_time / TRIALS;
    printf("\n     평균 반응 속도: \x1b[1;32m%llums\x1b[0m\n", avg);

    printf("\n=====================================\n     ");
    print_grade(avg);
    // ────────────────────────────────────────────────────────── //
    const char* Reaction_Menu[] = { "게임 선택으로 돌아가기", "게임 끝내기"};
    int selected = menu(Reaction_Menu, 2, 35, 25, 37, 27);

    if (selected == 0)
    {
        printf("게임 선택 화면으로 돌아갑니다\n");
    }
    else if (selected == 1)
    {
        system("cls");
        printf("\n");
        gotoXY(40, 5);
        printf("[ 플레이 해 주셔서 감사합니다 ]");
        printf("\n\n\n");
        Sleep(2000);
        exit(0);
    }
}