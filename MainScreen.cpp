#include <iostream>
#include "MainScreen.h"
#include "Utils.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>


// ───────────────[made by 재경]─────────────── /
void showMainScreen() {
    char input;
    {
        // TEAM 3 출력
        clearScreen();
        gotoXY(32, 14);
        printf("/$$$$$$$$                                       /$$$$$$");
        gotoXY(32, 15);
        printf("|__  $$__/                                      /$$__  $$");
        gotoXY(32, 16);
        printf("   | $$   /$$$$$$   /$$$$$$  /$$$$$$/$$$$       |__/  \\ $$");
        gotoXY(32, 17);
        printf("   | $$  /$$__  $$ |____  $$| $$_  $$_  $$         /$$$$$/");
        gotoXY(32, 18);
        printf("   | $$ | $$$$$$$$  /$$$$$$$| $$ \\ $$ \\ $$        |___  $$");
        gotoXY(32, 19);
        printf("   | $$ | $$_____/ /$$__  $$| $$ | $$ | $$       /$$  \\ $$");
        gotoXY(32, 20);
        printf("   | $$ |  $$$$$$$|  $$$$$$$| $$ | $$ | $$      |  $$$$$$/");
        gotoXY(32, 21);
        printf("   |__/  \\_______/ \\_______/|__/ |__/ |__/       \\______/");
        // GAME START 출력
        gotoXY(12, 5);
        colorChange(TEXT_C_RED);
        printf(" /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$        /$$$$$$  /$$$$$$$$ /$$$$$$  /$$$$$$$  /$$$$$$$$");
        gotoXY(12, 6);
        colorChange(TEXT_C_RED);
        printf("/$$__  $$ /$$__  $$| $$$    /$$$| $$_____/       /$$__  $$|__  $$__//$$__  $$| $$__  $$|__  $$__/");
        gotoXY(12, 7);
        colorChange(TEXT_C_RED);
        printf("| $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$            | $$  \\__/   | $$  | $$  \\ $$| $$  \\ $$   | $$   ");
        gotoXY(12, 8);
        colorChange(TEXT_C_WHITE);
        printf("| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$         |  $$$$$$    | $$  | $$$$$$$$| $$$$$$$/   | $$   ");
        gotoXY(12, 9);
        colorChange(TEXT_C_WHITE);
        printf("| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/          \\____  $$   | $$  | $$__  $$| $$__  $$   | $$   ");
        gotoXY(12, 10);
        colorChange(TEXT_C_BLUE);
        printf("| $$  \\ $$| $$  | $$| $$\\  $ | $$| $$             /$$  \\ $$   | $$  | $$  | $$| $$  \\ $$   | $$   ");
        gotoXY(12, 11);
        colorChange(TEXT_C_BLUE);
        printf("|  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$      |  $$$$$$/   | $$  | $$  | $$| $$  | $$   | $$   ");
        gotoXY(12, 12);
        colorChange(TEXT_C_BLUE);
        printf(" \\______/ |__/  |__/|__/     |__/|________/       \\______/    |__/  |__/  |__/|__/  |__/   |__/  ");
    }
    colorChange(TEXT_C_WHITE);

    gotoXY(45, 23);
    printf("  게임을 시작하는 중입니다");
    colorEnd();

    // ───────────────[made by 수범]─────────────── //
    Sleep(1000);                     // 1초 대기
    int total = 100;                 // 진행바의 총 완료량 지정
    srand(time(NULL));               // 현재 시간을 시드로 사용하여 난수 생성기를 초기화
    int sleeptime = rand() % 20;     // 0~19사이의 난수를 생성
    for (int i = 0; i <= total; i++) // 진행바의 총 완료량만큼 반복
    {
        DoProgress("진행도 : ", i,  total, 18, 25); //// 진행바 이름, 완료량, 최종 완료량, 진행바의 위치, 지정하여 함수 실행
        Sleep(sleeptime); // 랜덤 시간 만큼 대기
    }
    Sleep(500); // 0.5초 대기
    gotoXY(18, 25); printf("\r\33[2K"); // 줄 청소
    gotoXY(45, 23); printf("\r\33[2K"); // 줄 청소

    gotoXY(55, 23);
    printf(" 시작!");
    Sleep(700); // 0.7초 대기
    
    system("cls"); // 콘솔 청소
}