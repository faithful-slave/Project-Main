#include <stdio.h>
#include <windows.h>
#include "Utils.h"
#include <conio.h>

#define ANSI_POS_OFFSET_X 1
#define ANSI_POS_OFFSET_Y 1

#define TEXT_C_RED 31
#define TEXT_C_BLUE 34
#define TEXT_C_WHITE 37
#define TEXT_C_CHENG 36 // 청록
#define TEXT_C_WHITE 37 // 하양

void clearScreen()
{
    printf("\x1b[2J");
}

// 좌표 지정
void gotoXY(int _x, int _y) 
{
    printf("\x1b[%d;%dH", _y + ANSI_POS_OFFSET_Y, _x + ANSI_POS_OFFSET_X);
}

// 색 변경
void colorChange(int _colorNum) 
{
    printf("\x1b[%dm", _colorNum);
}

// 색 삭제
void colorEnd() 
{
    printf("\x1b[0m");
}

// ───────────────[made by 수범]─────────────── //

// 진행바 함수 - 진행 상황(progress bar)을 화면에 출력하는 함수
// label : 진행바 이름
// step  : 완료량
// total : 최종 완료량
// x, y  : 진행바의 위치

void DoProgress(const char* label, int step, int total, int x, int y)
{
    const int pwidth = 72; // 전체 진행바의 너비 (문자 수 기준)

    int width = pwidth - strlen(label);  // 라벨을 제외한 실제 진행바의 너비 계산
    int pos = (step * width) / total;    // 현재 진행 상태에 따라 칠해야 할 진행바의 길이 계산
    int percent = (step * 100) / total;  // 현재 진행 상태의 백분율 계산

    gotoXY(x, y);  // 진행바가 표시될 좌표(x, y)로 커서 이동

    printf("%s[", label); // 라벨 & '[' 출력

    // 진행된 만큼 색상 있는 배경 공백 문자 출력
    for (int i = 0; i < pos; i++)  
        printf("\x1b[48;2;255;80;80m \x1b[0m"); 

    // 남은 진행 부분(width - pos)만큼 공백을 출력한 후 ']'를 출력
    printf("% *c", width - pos + 1, ']');

    // 현재 진행률(%)을/를 오른쪽에 출력
    printf(" %3d%% 완료됨", percent);
}

int trynum = 10;
void Trycount(int textX, int textY, int numX) {
    int ch;
    

    while (1) {
        // 화면 클리어
        gotoXY(textX, textY);
        printf("상하 방향키로 시도 횟수를 설정 후 Enter 키를 누르세요.\n\n");
        gotoXY(numX, textY + 2);
        printf("\r\33[2K"); // 줄 청소
        gotoXY(numX, textY + 3);
        printf("\r\33[2K"); // 줄 청소

        gotoXY(numX, textY + 2);
        printf("현재 게임 시도 횟수: [ %d ]\n", trynum);

        ch = _getch();  // 키 입력 받기

        if (ch == 224)
        {  // 특수 키(방향키 등) 처리
            ch = _getch();  // 실제 방향키 코드 받기

            if (ch == 80)
            {         // ↓ 아레쪽 화살표
                if (trynum <= 1)        // 음수 방지
                {
                    gotoXY(numX, textY + 2);
                    printf("현재 게임 시도 횟수: [ %d ]\n", trynum);
                    gotoXY(numX, textY + 3);
                    printf(" 1 이상으로 선택해주세요 ");

                    Sleep(300);
                }
                else
                    trynum--;
            }
            else if (ch == 72)    // ↑ 위쪽 화살표
                trynum++;
        }
        else if (ch == 13)
        {  // Enter 키
            gotoXY(numX, textY - 2);
            printf("현재 게임 시도 횟수: [ %d ]\n", trynum);
            gotoXY(textX, textY);
            printf("\r\33[2K"); // 줄 청소
            gotoXY(numX, textY + 2);
            printf("\r\33[2K"); // 줄 청소
            gotoXY(numX, textY + 3);
            printf("\r\33[2K"); // 줄 청소
            return;
        }
    }
}