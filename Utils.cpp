#include <stdio.h>
#include <windows.h>
#include "Utils.h"
#define ANSI_POS_OFFSET_X 1
#define ANSI_POS_OFFSET_Y 1

#define TEXT_C_RED 31
#define TEXT_C_BLUE 34
#define TEXT_C_WHITE 37
#define TEXT_C_CHENG 36 //청록
#define TEXT_C_WHITE 37 //하양

void clearScreen() {
    printf("\x1b[2J");
}

void gotoXY(int _x, int _y) {
    printf("\x1b[%d;%dH", _y + ANSI_POS_OFFSET_Y, _x + ANSI_POS_OFFSET_X);
}

void colorChange(int _colorNum) {
    printf("\x1b[%dm", _colorNum);
}

void colorEnd() {
    printf("\x1b[0m");
}

void DoProgress(const char* label, int step, int total, int x, int y)
{
    const int pwidth = 72;

    int width = pwidth - strlen(label);
    int pos = (step * width) / total;

    int percent = (step * 100) / total;
    gotoXY(x, y);
    printf("%s[", label);

    for (int i = 0; i < pos; i++)
        printf("\x1b[48;2;255;80;80m \x1b[0m");
    
    printf("% *c", width - pos + 1, ']');
    printf(" %3d%% 완료됨\r", percent);
}