#include <stdio.h>
#include <windows.h>
#define ANSI_POS_OFFSET_X 1
#define ANSI_POS_OFFSET_Y 1

#define TEXT_C_RED 31
#define TEXT_C_BLUE 34
#define TEXT_C_WHITE 37

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
