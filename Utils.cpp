#include <stdio.h>
#include <windows.h>
#include "Utils.h"
#include <conio.h>

#define ANSI_POS_OFFSET_X 1
#define ANSI_POS_OFFSET_Y 1

#define TEXT_C_RED 31
#define TEXT_C_BLUE 34
#define TEXT_C_WHITE 37
#define TEXT_C_CHENG 36 // û��
#define TEXT_C_WHITE 37 // �Ͼ�

void clearScreen()
{
    printf("\x1b[2J");
}

// ��ǥ ����
void gotoXY(int _x, int _y) 
{
    printf("\x1b[%d;%dH", _y + ANSI_POS_OFFSET_Y, _x + ANSI_POS_OFFSET_X);
}

// �� ����
void colorChange(int _colorNum) 
{
    printf("\x1b[%dm", _colorNum);
}

// �� ����
void colorEnd() 
{
    printf("\x1b[0m");
}

// ������������������������������[made by ����]������������������������������ //

// ����� �Լ� - ���� ��Ȳ(progress bar)�� ȭ�鿡 ����ϴ� �Լ�
// label : ����� �̸�
// step  : �Ϸᷮ
// total : ���� �Ϸᷮ
// x, y  : ������� ��ġ

void DoProgress(const char* label, int step, int total, int x, int y)
{
    const int pwidth = 72; // ��ü ������� �ʺ� (���� �� ����)

    int width = pwidth - strlen(label);  // ���� ������ ���� ������� �ʺ� ���
    int pos = (step * width) / total;    // ���� ���� ���¿� ���� ĥ�ؾ� �� ������� ���� ���
    int percent = (step * 100) / total;  // ���� ���� ������ ����� ���

    gotoXY(x, y);  // ����ٰ� ǥ�õ� ��ǥ(x, y)�� Ŀ�� �̵�

    printf("%s[", label); // �� & '[' ���

    // ����� ��ŭ ���� �ִ� ��� ���� ���� ���
    for (int i = 0; i < pos; i++)  
        printf("\x1b[48;2;255;80;80m \x1b[0m"); 

    // ���� ���� �κ�(width - pos)��ŭ ������ ����� �� ']'�� ���
    printf("% *c", width - pos + 1, ']');

    // ���� �����(%)��/�� �����ʿ� ���
    printf(" %3d%% �Ϸ��", percent);
}

int trynum = 10;
void Trycount(int textX, int textY, int numX) {
    int ch;
    

    while (1) {
        // ȭ�� Ŭ����
        gotoXY(textX, textY);
        printf("���� ����Ű�� �õ� Ƚ���� ���� �� Enter Ű�� ��������.\n\n");
        gotoXY(numX, textY + 2);
        printf("\r\33[2K"); // �� û��
        gotoXY(numX, textY + 3);
        printf("\r\33[2K"); // �� û��

        gotoXY(numX, textY + 2);
        printf("���� ���� �õ� Ƚ��: [ %d ]\n", trynum);

        ch = _getch();  // Ű �Է� �ޱ�

        if (ch == 224)
        {  // Ư�� Ű(����Ű ��) ó��
            ch = _getch();  // ���� ����Ű �ڵ� �ޱ�

            if (ch == 80)
            {         // �� �Ʒ��� ȭ��ǥ
                if (trynum <= 1)        // ���� ����
                {
                    gotoXY(numX, textY + 2);
                    printf("���� ���� �õ� Ƚ��: [ %d ]\n", trynum);
                    gotoXY(numX, textY + 3);
                    printf(" 1 �̻����� �������ּ��� ");

                    Sleep(300);
                }
                else
                    trynum--;
            }
            else if (ch == 72)    // �� ���� ȭ��ǥ
                trynum++;
        }
        else if (ch == 13)
        {  // Enter Ű
            gotoXY(numX, textY - 2);
            printf("���� ���� �õ� Ƚ��: [ %d ]\n", trynum);
            gotoXY(textX, textY);
            printf("\r\33[2K"); // �� û��
            gotoXY(numX, textY + 2);
            printf("\r\33[2K"); // �� û��
            gotoXY(numX, textY + 3);
            printf("\r\33[2K"); // �� û��
            return;
        }
    }
}