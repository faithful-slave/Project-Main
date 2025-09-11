#pragma once
#ifndef UTILS_H
#define UTILS_H

void clearScreen();
void gotoXY(int _x, int _y);
void colorChange(int _colorNum);
void colorEnd();

void DoProgress(const char* label, int step, int total, int x, int y);

void Trycount(int textX, int textY, int numX);
extern int trynum;
#define ANSI_POS_OFFSET_X 1
#define ANSI_POS_OFFSET_Y 1

#define TEXT_C_RED 31
#define TEXT_C_BLUE 34
#define TEXT_C_WHITE 37
#define TEXT_C_CHENG 36 
#define TEXT_C_WHITE 37 
#endif