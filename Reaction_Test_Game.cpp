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
// ������������������������������[made by ����]������������������������������ //
// �����ӵ� �׽�Ʈ �޴� �����
void print_grade(ULONGLONG ms) {
    if (ms <= 180) {
        printf("\x1b[38;5;212m���: �ſ���� �ڡڡڡڡ� (����� ����!)\x1b[0m\n");
    }
    else if (ms <= 250) {
        printf("\x1b[38;5;221m���: ���� �ڡڡڡڡ� (���� ����)\x1b[0m\n");
    }
    else if (ms <= 350) {
        printf("\x1b[38;5;120m���: ��� �ڡڡڡ١� (���� ���� �ӵ�)\x1b[0m\n");
    }
    else if (ms <= 500) {
        printf("\x1b[38;5;159m���: ���� �ڡڡ١١� (������� �ӵ�)\x1b[0m\n");
    }
    else if (ms <= 800) {
        printf("\x1b[38;5;75m���: ���� �ڡ١١١� (���� ��)\x1b[0m\n");
    }
    else {
        printf("\x1b[38;5;246m���: �ſ���� �١١١١� (���� �ʿ�!)\x1b[0m\n");
    }
}

void showReactionGame()
{

    srand((unsigned int)time(NULL));
    ULONGLONG total_time = 0;
    ULONGLONG times[TRIALS];

    printf("< ���� �ӵ� �׽�Ʈ - �� %dȸ >\n\n", TRIALS);
    Sleep(1000);
    printf("'\x1b[1;31m����!\x1b[0m'�̶�� ���ڰ� ��Ÿ���� �ƹ� Ű�� ��������!\n");
    Sleep(3000);

    for (int i = 0; i < TRIALS; ++i)
    {
        system("cls");
        printf("[�õ� %d/%d]\n", i + 1, TRIALS);

        int randomsleeptime = 1000 + rand() % 9000;
        printf("�غ��ϼ���...\n");
        Sleep(randomsleeptime);

        // (���� ���� ����)
        while (_kbhit()) 
        {
            _getch();
        }
        Beep(1200, 100);
        printf("\n\x1b[1;31m����!\x1b[0m\n");

        ULONGLONG start_time = GetTickCount64();

        while (1)
        {
            if (_kbhit())
            {
                _getch();
                ULONGLONG end_time = GetTickCount64();
                system("cls");

                printf("[�õ� %d/%d]\n", i + 1, TRIALS);
                printf("\n");
                ULONGLONG elapsed_ms = end_time - start_time;
                times[i] = elapsed_ms;
                total_time += elapsed_ms;

                printf("\x1b[1;33m����� ���� �ӵ��� \x1b[1;32m%llums\x1b[1;37m�Դϴ�.\x1b[0m\n", elapsed_ms);
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

    // ��� ��� ���
    // ������������������������������[made by ���� & ��� & ����]������������������������������ //
    system("cls");
    printf("============= ��� ��� =============\n\n");
    for (int i = 0; i < TRIALS; ++i)
    {
        if (min == times[i])
            printf("   �õ� %d: \x1b[38;2;118;255;118m%llums (���� ���� �ӵ�)\x1b[0m\n", i + 1, times[i]);
        else if (max == times[i])
            printf("   �õ� %d: \x1b[38;2;255;157;183m%llums (���� ���� �ӵ�)\x1b[0m\n", i + 1, times[i]);
        else
            printf("   �õ� %d: %llums\n", i + 1, times[i]);
    }
    ULONGLONG avg = total_time / TRIALS;
    printf("\n     ��� ���� �ӵ�: \x1b[1;32m%llums\x1b[0m\n", avg);

    printf("\n=====================================\n     ");
    print_grade(avg);
    // �������������������������������������������������������������������������������������������������������������������� //
    const char* Reaction_Menu[] = { "���� �������� ���ư���", "���� ������"};
    int selected = menu(Reaction_Menu, 2, 35, 25, 37, 27);

    if (selected == 0)
    {
        printf("���� ���� ȭ������ ���ư��ϴ�\n");
    }
    else if (selected == 1)
    {
        system("cls");
        printf("\n");
        gotoXY(40, 5);
        printf("[ �÷��� �� �ּż� �����մϴ� ]");
        printf("\n\n\n");
        Sleep(2000);
        exit(0);
    }
}