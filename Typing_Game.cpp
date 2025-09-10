#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#include "Utils.h"
#include "Typing_Intro.h"
#include "Typing_Game_Screen.h"
#include "Typing_Game.h"  

#define MENU_COUNT 5 // �޴� ����

// ������������������������������[made by ����]������������������������������ //
// Ÿ���� ���� ���� �Լ�
void showTypingGame()  
{
	srand((unsigned)time(NULL)); // �ð��� �̿��� ���� ����
	int reset = 0;               // �ʱ�ȭ ���� ǥ�� ����
	int difnum = 0;              // ���̵� ���
	char input[700];             // �Է� ���� �迭
	int score = 0;               // ���� ����
	int total_score = 0;         // ���� ���� �հ�
	int total_minus_count = 0;   // �� ��Ÿ ��
	double total_time = 0;       // ���� �ҿ� �ð� (��)
	double total_wpm = 0;        // ��� Ÿ�� (WPM)
	int linenum = 1;             // ���� ��ȣ

	int arr[45]; // �迭�� �ϳ� �� ���� 50�� �ݺ�
	for (int i = 0; i < 45; i++)
	{
		arr[i] = i;
	}

	char menu[MENU_COUNT][40] = 
	{
		"����",
		"����",
		"�����",
		"�ſ� �����\n",
		"���� ���� ȭ������ ������"
	};

	int selected = 0; // ���̵� �޴� ���õǾ����� Ȯ���� ���� ����
	int ch;

	//���̵� ���� �޴� ��� (����)
	while (1) 
	{
		system("cls");  // �ܼ� ȭ�� �����
		printf("���̵��� �������ּ���\n");

		// �޴� ���
		for (int i = 0; i < MENU_COUNT; i++) 
		{
			if (i == selected) // i�� ���õ� �޴��� ���
				printf("\x1b[38;2;255;220;120m�� %s\x1b[0m\n", menu[i]); // ȭ��ǥ�� �տ� ���̰� ��������� �޴� ���
			else if (i == selected && selected == 4)
			{
				printf("\x1b[38;2;255;220;120m�� %s\x1b[0m\n", menu[i]); // ȭ��ǥ�� �տ� ���̰� ��������� �޴� ���
			}
			else // ���õ��� ���� �޴��� ���
				printf("  \x1b[38;2;80;80;80m%s\x1b[0m\n", menu[i]);  // ȭ��ǥ�� ������ �ʰ� ���� ȸ������ �޴� ���
		}

		ch = _getch(); 

		// ����Ű�� �� �� _getch() �ؾ� ��
		if (ch == 224) 
		{
			ch = _getch();

			switch (ch) 
			{
			case 72: // ch�� �Է� ���� Ű�� �� �̸�
				selected--; // ���õ� �޴��� �ε����� 1 �ڷ� �̵�
				if (selected < 0) selected = MENU_COUNT - 1; // 0���� ������ �޴� ���� -1 ��ŭ �̵�
				break;
			case 80: // ch�� �Է� ���� Ű�� �� �̸�
				selected++;  // ���õ� �޴��� �ε����� 1 ������ �̵�
				if (selected >= MENU_COUNT) selected = 0; // �޴� �������� ũ�ų� ������ 0���� �̵�
				break;
			}
		}
		else if (selected == 4 && ch == 13)
		{
			system("cls");
			printf("\n");
			gotoXY(47, 5);
			printf("[ ������ �����ϰ� ���� ���� ȭ������ ���ư��ϴ� ]\n");
			Sleep(700);
			Treturnnum = 1;
			break;
		}
		else if (ch == 13) // ch�� �Է� ���� Ű�� EnterŰ �̸�
		{ 
			difnum = selected;  // ���õ� �޴��� �ε����� difnum�� ����
			printf("\n\n[%s] ���̵��� �����Ͽ����ϴ�\n", dif[difnum]);  // ���õ� ���̵� ���
			Sleep(2000); // 2�� ���
			system("cls"); // �ܼ� û��
			break;
		}
	}

	int size = 45;  // ������ ������ 45���̱⿡ �������� ����ϴ� ������ �ִ� ũ��� 45


	// ī��Ʈ�ٿ� �Լ� ����
	startCountdown(); 


	for (int i = 0; i < 2; i++)  // 10���� ���� ���
	{
		int random_num = rand() % size; // 0 ~ 45�� ���� ���� ���

		int non_overlap = arr[random_num];  
		// ���� ���ڿ� ���� ��°�� ������ ����ϱ� ���� �迭�� �������ڸ� non_overlap�� ����

		if (difnum == 0) // ���� ���̵��� 0��°��(easy)
		{
			if (linenum % 10 != 0) // �ٹ�ȣ�� 10�� ����� �ƴϸ�
			{
				printf("[ %d ] ", linenum); // �ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", easy_diffculty[non_overlap]); // �Է��ؾ� �ϴ� ������ ���� ���
				printf("�Է�: "); // :�� �پ ���
			}
			else // �ٹ�ȣ�� 10�� ����̸�
			{
				printf("[ %d ] ", linenum); // �ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", easy_diffculty[non_overlap]); // �Է��ؾ� �ϴ� ������ ���� ���
				printf("�Է� : "); // :�� �� ���
			}

			ULONGLONG start_time = GetTickCount64(); // ���� �ð�

			scanf_s(" %[^\n]s", &input, 700); // ���� ���� ���ڿ� �Է� �ޱ�

			ULONGLONG end_time = GetTickCount64(); // ���� �ð� ����
			arr[random_num] = arr[size - 1];
			size--;

			system("cls");  // �ܼ� û��
			printf("[ %d ] ", linenum); // �ٹ�ȣ ���
			printf("\x1b[1;36m%s\n\x1b[0m", easy_diffculty[non_overlap]); // �Է��ؾ� �ϴ� ���� ���

			compare(easy_diffculty[non_overlap], input); // ���� ��, ��Ÿ ���� ����

			total_score = total_score + get_count; // �� ���� �հ�
			score = get_count; // ��� ���� ���

			// �ð� ���
			ULONGLONG elapsed_ms = end_time - start_time;        // �ð� ���
			double elapsed_s = elapsed_ms / 1000.0;              // �Ǽ� ������
			total_time = total_time + elapsed_s;                 // �� �ð� ���
			double wpm = total_sentence_len / elapsed_s * 60.0;  // Ÿ�� ���
			total_wpm = total_wpm + wpm;                         // �� Ÿ�� ���
			printf("\n\n");
			// ������������������������������[made by ����]������������������������������ //
			printf(" - \x1b[38;2;255;150;175m��Ÿ\x1b[0m : \x1b[38;2;255;154;162m%d��\x1b[0m\n", minus_count);  // ��Ÿ ���� ���
			printf(" - \x1b[38;2;150;255;215m����\x1b[0m : \x1b[38;2;166;255;211m+%d��\x1b[0m\n", score);       // ��� ���� ���
			printf(" - \x1b[38;2;255;200;170m�ð�\x1b[0m : \x1b[38;2;255;201;163m%.2f��\x1b[0m\n", elapsed_s);  // �ð� ���
			printf(" - \x1b[38;2;180;190;255mŸ��\x1b[0m : \x1b[38;2;176;184;255m%.2fŸ\x1b[0m\n", wpm);        // Ÿ�� ���
			// �������������������������������������������������������������������������������������� //
			total_minus_count = total_minus_count + minus_count; // �� ��Ÿ ���� �հ�
			
			// ���� �ݺ� �� ������ �ʱ�ȭ�� ���� ���� ���� (�ʼ��� �ƴ�)
			minus_count = reset; // ��Ÿ ���� ���� ����
			score = reset;       // ��� ���� ���� ����
			elapsed_ms = 0;      // �ð� ���� ����
			elapsed_s = 0;       // �ð� ���� ����
			linenum++;           // �ٹ�ȣ +1
			Sleep(3000);         // 3�� ���
			system("cls");       // �ܼ� û��
		}

		else if (difnum == 1)  // ���� ���̵��� 1��°��(normal)
		{
			if (linenum % 10 != 0) // �ٹ�ȣ�� 10�� ����� �ƴϸ�
			{
				printf("[ %d ] ", linenum); // �ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", normal_diffculty[non_overlap]); // �Է��ؾ� �ϴ� ���� ���
				printf("�Է�: "); // :�� �پ ���
			}
			else // �ٹ�ȣ�� 10�� ����̸�
			{
				printf("[ %d ] ", linenum); // �ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", normal_diffculty[non_overlap]); // �Է��ؾ� �ϴ� ���� ���
				printf("�Է� : "); // :�� �� ���
			}

			ULONGLONG start_time = GetTickCount64(); // ���� �ð�

			scanf_s(" %[^\n]s", &input, 700); // ���� ���� ���ڿ� �Է� �ޱ�

			ULONGLONG end_time = GetTickCount64(); // ���� �ð� ����
			arr[random_num] = arr[size - 1];
			size--;

			system("cls");  // �ܼ� û��
			printf("[ %d ] ", linenum); // �ٹ�ȣ ���
			printf("\x1b[1;36m%s\n\x1b[0m", normal_diffculty[non_overlap]); // �Է��ؾ� �ϴ� ���� ���

			compare(normal_diffculty[non_overlap], input); // ���� ��, ��Ÿ ���� ����

			total_score = total_score + get_count; // �� ���� �հ�
			score = get_count; // ��� ���� ���

			// �ð� ���
			ULONGLONG elapsed_ms = end_time - start_time;       // �ð� ���
			double elapsed_s = elapsed_ms / 1000.0;             // �Ǽ� ������
			total_time = total_time + elapsed_s;                // �� �ð� ���
			double wpm = total_sentence_len / elapsed_s * 60.0; // Ÿ�� ���
			total_wpm = total_wpm + wpm;                        // �� Ÿ�� ���

			printf("\n\n");
			// ������������������������������[made by ����]������������������������������ //
			printf(" - \x1b[38;2;255;150;175m��Ÿ\x1b[0m : \x1b[38;2;255;154;162m%d��\x1b[0m\n", minus_count);  // ��Ÿ ���� ���
			printf(" - \x1b[38;2;150;255;215m����\x1b[0m : \x1b[38;2;166;255;211m+%d��\x1b[0m\n", score);       // ��� ���� ���
			printf(" - \x1b[38;2;255;200;170m�ð�\x1b[0m : \x1b[38;2;255;201;163m%.2f��\x1b[0m\n", elapsed_s);  // �ð� ���
			printf(" - \x1b[38;2;180;190;255mŸ��\x1b[0m : \x1b[38;2;176;184;255m%.2fŸ\x1b[0m\n", wpm);        // Ÿ�� ���
			// �������������������������������������������������������������������������������������� //
			total_minus_count = total_minus_count + minus_count; // �� ��Ÿ ���� �հ�

			// ���� �ݺ� �� ������ �ʱ�ȭ�� ���� ���� ���� (�ʼ��� �ƴ�)
			minus_count = reset; // ��Ÿ ���� ���� ����
			score = reset;       // ��� ���� ���� ����
			elapsed_ms = 0;      // �ð� ���� ����
			elapsed_s = 0;       // �ð� ���� ����
			linenum++;           // �ٹ�ȣ +1
			Sleep(3000);         // 3�� ���
			system("cls");       // �ܼ� û��
		}

		else if (difnum == 2)  // ���� ���̵��� 2��°��(hard)
		{
			if (linenum % 10 != 0) // �ٹ�ȣ�� 10�� ����� �ƴϸ�
			{
				printf("[ %d ] ", linenum); // �ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", hard_diffculty[non_overlap]); // �Է��ؾ� �ϴ� ���� ���
				printf("�Է�: "); // :�� �پ ���
			}
			else // �ٹ�ȣ�� 10�� ����̸�
			{
				printf("[ %d ] ", linenum); // �ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", hard_diffculty[non_overlap]); // �Է��ؾ� �ϴ� ���� ���
				printf("�Է� : "); // :�� �� ���
			}

			ULONGLONG start_time = GetTickCount64(); // ���� �ð�

			scanf_s(" %[^\n]s", &input, 700); // ���� ���� ���ڿ� �Է� �ޱ�

			ULONGLONG end_time = GetTickCount64(); // ���� �ð� ����
			arr[random_num] = arr[size - 1];
			size--;

			system("cls");  // �ܼ� û��
			printf("[ %d ] ", linenum); // �ٹ�ȣ ���
			printf("\x1b[1;36m%s\n\x1b[0m", hard_diffculty[non_overlap]); // �Է��ؾ� �ϴ� ���� ���

			compare(hard_diffculty[non_overlap], input); // ���� ��, ��Ÿ ���� ����

			total_score = total_score + get_count; // �� ���� �հ�
			score = get_count; // ��� ���� ���

			// �ð� ���
			ULONGLONG elapsed_ms = end_time - start_time;       // �ð� ���
			double elapsed_s = elapsed_ms / 1000.0;             // �Ǽ� ������
			total_time = total_time + elapsed_s;                // �� �ð� ���
			double wpm = total_sentence_len / elapsed_s * 60.0; // Ÿ�� ���
			total_wpm = total_wpm + wpm;                        // �� Ÿ�� ���

			printf("\n\n");
			// ������������������������������[made by ����]������������������������������ //
			printf(" - \x1b[38;2;255;150;175m��Ÿ\x1b[0m : \x1b[38;2;255;154;162m%d��\x1b[0m\n", minus_count);  // ��Ÿ ���� ���
			printf(" - \x1b[38;2;150;255;215m����\x1b[0m : \x1b[38;2;166;255;211m+%d��\x1b[0m\n", score);       // ��� ���� ���
			printf(" - \x1b[38;2;255;200;170m�ð�\x1b[0m : \x1b[38;2;255;201;163m%.2f��\x1b[0m\n", elapsed_s);  // �ð� ���
			printf(" - \x1b[38;2;180;190;255mŸ��\x1b[0m : \x1b[38;2;176;184;255m%.2fŸ\x1b[0m\n", wpm);        // Ÿ�� ���
			// �������������������������������������������������������������������������������������� //
			total_minus_count = total_minus_count + minus_count; // �� ��Ÿ ���� �հ�

			// ���� �ݺ� �� ������ �ʱ�ȭ�� ���� ���� ���� (�ʼ��� �ƴ�)
			minus_count = reset; // ��Ÿ ���� ���� ����
			score = reset;       // ��� ���� ���� ����
			elapsed_ms = 0;      // �ð� ���� ����
			elapsed_s = 0;       // �ð� ���� ����
			linenum++;           // �ٹ�ȣ +1
			Sleep(3000);         // 3�� ���
			system("cls");       // �ܼ� û��
		}

		else if (difnum == 3)  // ���� ���̵��� 3��°��(crazy)
		{
			if (linenum % 10 != 0) // �ٹ�ȣ�� 10�� ����� �ƴϸ�
			{
				printf("[ %d ] ", linenum); // �ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", crazy_diffculty[non_overlap]); // �Է��ؾ� �ϴ� ���� ���
				printf("�Է�: "); // :�� �پ ���
			}
			else // �ٹ�ȣ�� 10�� ����̸�
			{
				printf("[ %d ] ", linenum); // �ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", crazy_diffculty[non_overlap]); // �Է��ؾ� �ϴ� ���� ���
				printf("�Է� : "); // :�� �� ���
			}

			ULONGLONG start_time = GetTickCount64(); // ���� �ð�

			scanf_s(" %[^\n]s", &input, 700); // ���� ���� ���ڿ� �Է� �ޱ�

			ULONGLONG end_time = GetTickCount64(); // ���� �ð� ����
			arr[random_num] = arr[size - 1];
			size--;

			system("cls");  // �ܼ� û��
			printf("[ %d ] ", linenum); // �ٹ�ȣ ���
			printf("\x1b[1;36m%s\n\x1b[0m", crazy_diffculty[non_overlap]); // �Է��ؾ� �ϴ� ���� ���

			compare(crazy_diffculty[non_overlap], input); // ���� ��, ��Ÿ ���� ����

			total_score = total_score + get_count; // �� ���� �հ�
			score = get_count; // ��� ���� ���

			// �ð� ���
			ULONGLONG elapsed_ms = end_time - start_time;       // �ð� ���
			double elapsed_s = elapsed_ms / 1000.0;             // �Ǽ� ������
			total_time = total_time + elapsed_s;                // �� �ð� ���
			double wpm = total_sentence_len / elapsed_s * 60.0; // Ÿ�� ���
			total_wpm = total_wpm + wpm;                        // �� Ÿ�� ���

			printf("\n\n");
			// ������������������������������[made by ����]������������������������������ //
			printf(" - \x1b[38;2;255;150;175m��Ÿ\x1b[0m : \x1b[38;2;255;154;162m%d��\x1b[0m\n", minus_count);  // ��Ÿ ���� ���
			printf(" - \x1b[38;2;150;255;215m����\x1b[0m : \x1b[38;2;166;255;211m+%d��\x1b[0m\n", score);       // ��� ���� ���
			printf(" - \x1b[38;2;255;200;170m�ð�\x1b[0m : \x1b[38;2;255;201;163m%.2f��\x1b[0m\n", elapsed_s);  // �ð� ���
			printf(" - \x1b[38;2;180;190;255mŸ��\x1b[0m : \x1b[38;2;176;184;255m%.2fŸ\x1b[0m\n", wpm);        // Ÿ�� ���
			// �������������������������������������������������������������������������������������� //

			total_minus_count = total_minus_count + minus_count; // �� ��Ÿ ���� �հ�

			// ���� �ݺ� �� ������ �ʱ�ȭ�� ���� ���� ���� (�ʼ��� �ƴ�)
			minus_count = reset; // ��Ÿ ���� ���� ����
			score = reset;       // ��� ���� ���� ����
			elapsed_ms = 0;      // �ð� ���� ����
			elapsed_s = 0;       // �ð� ���� ����
			linenum++;           // �ٹ�ȣ +1
			Sleep(3000);         // 3�� ���
			system("cls");       // �ܼ� û��
		}
	}
	double total_avg_time = 0;          // ��� Ÿ���� �ӵ� ����
	total_avg_time = total_time / 10;   // ��� Ÿ���� �ӵ� ���
	double total_avg_wpm = 0;           // ��� Ÿ�� ����
	total_avg_wpm = total_wpm / 10;     // ��� Ÿ�� ���

	// ������������������������������[made by ����]������������������������������ //
	printf("\x1b[38;5;230m����� ���̵��� \x1b[38;5;219m%s\x1b[38;5;230m�Դϴ�.\x1b[0m\n", dif[difnum]);                   // ���̵� ���
	printf("\x1b[38;5;230m����� ��� Ÿ���� �ӵ��� \x1b[38;5;219m%.2f��\x1b[38;5;230m�Դϴ�.\x1b[0m\n", total_avg_time);  // ��� Ÿ���� �ӵ� ���
	printf("\x1b[38;5;230m����� �� ������ \x1b[38;5;219m%d��\x1b[38;5;230m�Դϴ�.\x1b[0m\n", total_score);                // �� ���� ���
	printf("\x1b[38;5;230m����� ��� Ÿ���� \x1b[38;5;219m%.2fŸ\x1b[38;5;230m�Դϴ�.\x1b[0m\n", total_avg_wpm);          // ��� Ÿ�� ���
	printf("\x1b[38;5;230m����� �� ��Ÿ ������ \x1b[38;5;219m%d��\x1b[38;5;230m�Դϴ�.\x1b[0m\n", total_minus_count);     // �� ��Ÿ���� ���
	// �������������������������������������������������������������������������������������� //
	
	// �ؾ��� �� �� ���� ���̵��� ���� ��� ������� 
	// ��޵� �ϰ� �Ͱ� �� �ټ����� �ϰ� �Ͱ�
	// 100������ ������ �Ǵµ� �����ϰ�


}