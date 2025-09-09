#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#include "Typing_Game_Screen.h"
#include "Typing_Game.h"  // easy_diffculty �迭�� ���⿡ ���ǵǾ� �ִٰ� ����

#define RED   "\x1b[31m"
#define RESET "\x1b[0m"
#define MENU_COUNT 4

void showTypingGame()
{
	srand((unsigned)time(NULL));
	int reset = 0; //�ʱ�ȭ ����
	int difnum = 0; //���̵� ��� ����
	char input[700]; //�Է¹޴� ����
	int Score = 0; //��� ���� ����
	int total_score = 0; //�� ���� �հ� ����
	int total_minus_count = 0; //�� ��Ÿ ���� ����
	double total_time = 0; //�� �ð� ����
	double total_wpm = 0; //�� Ÿ�� ����
	int linenum = 1;

	int arr[45]; // �迭�� �ϳ� �� ���� 50�� �ݺ�
	for (int i = 0; i < 45; i++)
	{
		arr[i] = i;
	}

	char menu[MENU_COUNT][20] = {
		"����",
		"����",
		"�����",
		"�ſ� �����"
	};

	int selected = 0;
	int ch;

	while (1) {
		system("cls");  // �ܼ� ȭ�� ����� (Windows)
		printf("���̵��� �������ּ���\n");
		// �޴� ���
		for (int i = 0; i < MENU_COUNT; i++) {
			if (i == selected)
				printf("\x1b[38;2;255;220;120m�� %s\x1b[0m\n", menu[i]);
			else
				printf("  \x1b[38;2;80;80;80m%s\x1b[0m\n", menu[i]);
		}

		ch = _getch(); 

		// ����Ű�� �� �� _getch() �ؾ� ��
		if (ch == 224) {
			ch = _getch();

			switch (ch) {
			case 72: // ��
				selected--;
				if (selected < 0) selected = MENU_COUNT - 1;
				break;
			case 80: // ��
				selected++;
				if (selected >= MENU_COUNT) selected = 0;
				break;
			}
		}
		else if (ch == 13) { // Enter
			difnum = selected;
			printf("\n\n[%s] ���̵��� �����Ͽ����ϴ�\n", dif[difnum]);
			Sleep(2000); //2�� ���
			system("cls"); //�ܼ� û��
			break;
		}
	}

	int size = 45;
	startCountdown(); 

	for (int i = 0; i < 10; i++)  // 10�� �ݺ�
	{
		int random_num = rand() % size;
		int non_overlap = arr[random_num];

		//printf("%d\n", non_overlap); //���� ���� ���� ���

		if (difnum == 0) //���� ���̵��� 0�̸�
		{
			if (linenum % 10 != 0) //�ٹ�ȣ�� 10�� ����� �ƴϸ�
			{
				printf("[ %d ] ", linenum); //�ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", easy_diffculty[non_overlap]); //�Է��ؾ� �ϴ� ���� ���
				printf("�Է�: "); // :�� �پ ���
			}
			else //�ٹ�ȣ�� 10�� ����̸�
			{
				printf("[ %d ] ", linenum); //�ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", easy_diffculty[non_overlap]); //�Է��ؾ� �ϴ� ���� ���
				printf("�Է� : "); // :�� �� ���
			}

			ULONGLONG start_time = GetTickCount64(); //���� �ð�

			scanf_s(" %[^\n]s", &input, 700); // ���� ���� ���ڿ� �Է� �ޱ�

			ULONGLONG end_time = GetTickCount64(); //���� �ð� ����
			arr[random_num] = arr[size - 1];
			size--;

			system("cls");  //�ܼ� û��
			printf("[ %d ] ", linenum); //�ٹ�ȣ ���
			printf("\x1b[1;36m%s\n\x1b[0m", easy_diffculty[non_overlap]); //�Է��ؾ� �ϴ� ���� ���

			compare(easy_diffculty[non_overlap], input); //���� ��, ��Ÿ ���� ����

			total_score = total_score + get_count; //�� ���� �հ�
			Score = get_count; //��� ���� ���

			// �ð� ���
			ULONGLONG elapsed_ms = end_time - start_time; // �ð� ���
			double elapsed_s = elapsed_ms / 1000.0;  // �Ǽ� ������
			total_time = total_time + elapsed_s; // �� �ð� ���
			double wpm = total_sentence_len / elapsed_s * 60.0; //Ÿ�� ���
			total_wpm = total_wpm + wpm; //�� Ÿ�� ���
			printf("\n\n");
			printf(" - \x1b[38;2;255;150;175m��Ÿ\x1b[0m : \x1b[38;2;255;154;162m%d��\x1b[0m\n", minus_count);
			printf(" - \x1b[38;2;150;255;215m����\x1b[0m : \x1b[38;2;166;255;211m+%d��\x1b[0m\n", Score);
			printf(" - \x1b[38;2;255;200;170m�ð�\x1b[0m : \x1b[38;2;255;201;163m%.2f��\x1b[0m\n", elapsed_s);
			printf(" - \x1b[38;2;180;190;255mŸ��\x1b[0m : \x1b[38;2;176;184;255m%.2fŸ\x1b[0m\n", wpm);

			total_minus_count = total_minus_count + minus_count; //�� ��Ÿ ���� �հ�
			
			// ���� �ݺ� �� ������ �ʱ�ȭ�� ���� ���� ���� (�ʼ��� �ƴ�)
			minus_count = reset; //��Ÿ ���� ���� ����
			Score = reset; //��� ���� ���� ����
			elapsed_ms = 0; //�ð� ���� ����
			elapsed_s = 0; //�ð� ���� ����
			linenum++; //�ٹ�ȣ +1
			Sleep(3000); //3�� ���
			system("cls"); //�ܼ� û��
		}

		else if (difnum == 1)
		{
			if (linenum % 10 != 0) //�ٹ�ȣ�� 10�� ����� �ƴϸ�
			{
				printf("[ %d ] ", linenum); //�ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", normal_diffculty[non_overlap]); //�Է��ؾ� �ϴ� ���� ���
				printf("�Է�: "); // :�� �پ ���
			}
			else //�ٹ�ȣ�� 10�� ����̸�
			{
				printf("[ %d ] ", linenum); //�ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", normal_diffculty[non_overlap]); //�Է��ؾ� �ϴ� ���� ���
				printf("�Է� : "); // :�� �� ���
			}

			ULONGLONG start_time = GetTickCount64(); //���� �ð�

			scanf_s(" %[^\n]s", &input, 700); // ���� ���� ���ڿ� �Է� �ޱ�

			ULONGLONG end_time = GetTickCount64(); //���� �ð� ����
			arr[random_num] = arr[size - 1];
			size--;

			system("cls");  //�ܼ� û��
			printf("[ %d ] ", linenum); //�ٹ�ȣ ���
			printf("\x1b[1;36m%s\n\x1b[0m", normal_diffculty[non_overlap]); //�Է��ؾ� �ϴ� ���� ���

			compare(normal_diffculty[non_overlap], input); //���� ��, ��Ÿ ���� ����

			total_score = total_score + get_count; //�� ���� �հ�
			Score = get_count; //��� ���� ���

			// �ð� ���
			ULONGLONG elapsed_ms = end_time - start_time; // �ð� ���
			double elapsed_s = elapsed_ms / 1000.0;  // �Ǽ� ������
			total_time = total_time + elapsed_s; // �� �ð� ���
			double wpm = total_sentence_len / elapsed_s * 60.0; //Ÿ�� ���
			total_wpm = total_wpm + wpm; //�� Ÿ�� ���

			printf("\n\n");
			printf(" - \x1b[38;2;255;80;80m��Ÿ\x1b[0m : \x1b[38;2;255;120;120m%d��\x1b[0m\n", minus_count);  //��Ÿ ���� ���
			printf(" - \x1b[38;2;100;255;100m����\x1b[0m : \x1b[38;2;150;255;150m+%d��\x1b[0m\n", Score);  //��� ���� ���
			printf(" - \x1b[38;2;255;220;120m�ð�\x1b[0m : \x1b[38;2;255;240;180m%.2f��\x1b[0m\n", elapsed_s);  //�ð� ���
			printf(" - \x1b[38;2;120;200;255mŸ��\x1b[0m : \x1b[38;2;160;220;255m%.2fŸ\x1b[0m\n", wpm);  //Ÿ�� ���

			total_minus_count = total_minus_count + minus_count; //�� ��Ÿ ���� �հ�

			// ���� �ݺ� �� ������ �ʱ�ȭ�� ���� ���� ���� (�ʼ��� �ƴ�)
			minus_count = reset; //��Ÿ ���� ���� ����
			Score = reset; //��� ���� ���� ����
			elapsed_ms = 0; //�ð� ���� ����
			elapsed_s = 0; //�ð� ���� ����
			linenum++; //�ٹ�ȣ +1
			Sleep(3000); //3�� ���
			system("cls"); //�ܼ� û��
		}

		else if (difnum == 2)
		{
			if (linenum % 10 != 0) //�ٹ�ȣ�� 10�� ����� �ƴϸ�
			{
				printf("[ %d ] ", linenum); //�ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", hard_diffculty[non_overlap]); //�Է��ؾ� �ϴ� ���� ���
				printf("�Է�: "); // :�� �پ ���
			}
			else //�ٹ�ȣ�� 10�� ����̸�
			{
				printf("[ %d ] ", linenum); //�ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", hard_diffculty[non_overlap]); //�Է��ؾ� �ϴ� ���� ���
				printf("�Է� : "); // :�� �� ���
			}

			ULONGLONG start_time = GetTickCount64(); //���� �ð�

			scanf_s(" %[^\n]s", &input, 700); // ���� ���� ���ڿ� �Է� �ޱ�

			ULONGLONG end_time = GetTickCount64(); //���� �ð� ����
			arr[random_num] = arr[size - 1];
			size--;

			system("cls");  //�ܼ� û��
			printf("[ %d ] ", linenum); //�ٹ�ȣ ���
			printf("\x1b[1;36m%s\n\x1b[0m", hard_diffculty[non_overlap]); //�Է��ؾ� �ϴ� ���� ���

			compare(hard_diffculty[non_overlap], input); //���� ��, ��Ÿ ���� ����

			total_score = total_score + get_count; //�� ���� �հ�
			Score = get_count; //��� ���� ���

			// �ð� ���
			ULONGLONG elapsed_ms = end_time - start_time; // �ð� ���
			double elapsed_s = elapsed_ms / 1000.0;  // �Ǽ� ������
			total_time = total_time + elapsed_s; // �� �ð� ���
			double wpm = total_sentence_len / elapsed_s * 60.0; //Ÿ�� ���
			total_wpm = total_wpm + wpm; //�� Ÿ�� ���

			printf("\n\n");
			printf(" - \x1b[38;2;255;80;80m��Ÿ\x1b[0m : \x1b[38;2;255;120;120m%d��\x1b[0m\n", minus_count);  //��Ÿ ���� ���
			printf(" - \x1b[38;2;100;255;100m����\x1b[0m : \x1b[38;2;150;255;150m+%d��\x1b[0m\n", Score);  //��� ���� ���
			printf(" - \x1b[38;2;255;220;120m�ð�\x1b[0m : \x1b[38;2;255;240;180m%.2f��\x1b[0m\n", elapsed_s);  //�ð� ���
			printf(" - \x1b[38;2;120;200;255mŸ��\x1b[0m : \x1b[38;2;160;220;255m%.2fŸ\x1b[0m\n", wpm);  //Ÿ�� ���

			total_minus_count = total_minus_count + minus_count; //�� ��Ÿ ���� �հ�

			// ���� �ݺ� �� ������ �ʱ�ȭ�� ���� ���� ���� (�ʼ��� �ƴ�)
			minus_count = reset; //��Ÿ ���� ���� ����
			Score = reset; //��� ���� ���� ����
			elapsed_ms = 0; //�ð� ���� ����
			elapsed_s = 0; //�ð� ���� ����
			linenum++; //�ٹ�ȣ +1
			Sleep(3000); //3�� ���
			system("cls"); //�ܼ� û��
		}

		else if (difnum == 3)
		{
			if (linenum % 10 != 0) //�ٹ�ȣ�� 10�� ����� �ƴϸ�
			{
				printf("[ %d ] ", linenum); //�ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", crazy_diffculty[non_overlap]); //�Է��ؾ� �ϴ� ���� ���
				printf("�Է�: "); // :�� �پ ���
			}
			else //�ٹ�ȣ�� 10�� ����̸�
			{
				printf("[ %d ] ", linenum); //�ٹ�ȣ ���
				printf("\x1b[1;36m%s\n\x1b[0m", crazy_diffculty[non_overlap]); //�Է��ؾ� �ϴ� ���� ���
				printf("�Է� : "); // :�� �� ���
			}

			ULONGLONG start_time = GetTickCount64(); //���� �ð�

			scanf_s(" %[^\n]s", &input, 700); // ���� ���� ���ڿ� �Է� �ޱ�

			ULONGLONG end_time = GetTickCount64(); //���� �ð� ����
			arr[random_num] = arr[size - 1];
			size--;

			system("cls");  //�ܼ� û��
			printf("[ %d ] ", linenum); //�ٹ�ȣ ���
			printf("\x1b[1;36m%s\n\x1b[0m", crazy_diffculty[non_overlap]); //�Է��ؾ� �ϴ� ���� ���

			compare(crazy_diffculty[non_overlap], input); //���� ��, ��Ÿ ���� ����

			total_score = total_score + get_count; //�� ���� �հ�
			Score = get_count; //��� ���� ���

			// �ð� ���
			ULONGLONG elapsed_ms = end_time - start_time; // �ð� ���
			double elapsed_s = elapsed_ms / 1000.0;  // �Ǽ� ������
			total_time = total_time + elapsed_s; // �� �ð� ���
			double wpm = total_sentence_len / elapsed_s * 60.0; //Ÿ�� ���
			total_wpm = total_wpm + wpm; //�� Ÿ�� ���

			printf("\n\n");
			printf(" - \x1b[38;2;255;80;80m��Ÿ\x1b[0m : \x1b[38;2;255;120;120m%d��\x1b[0m\n", minus_count);  //��Ÿ ���� ���
			printf(" - \x1b[38;2;100;255;100m����\x1b[0m : \x1b[38;2;150;255;150m+%d��\x1b[0m\n", Score);  //��� ���� ���
			printf(" - \x1b[38;2;255;220;120m�ð�\x1b[0m : \x1b[38;2;255;240;180m%.2f��\x1b[0m\n", elapsed_s);  //�ð� ���
			printf(" - \x1b[38;2;120;200;255mŸ��\x1b[0m : \x1b[38;2;160;220;255m%.2fŸ\x1b[0m\n", wpm);  //Ÿ�� ���

			total_minus_count = total_minus_count + minus_count; //�� ��Ÿ ���� �հ�

			// ���� �ݺ� �� ������ �ʱ�ȭ�� ���� ���� ���� (�ʼ��� �ƴ�)
			minus_count = reset; //��Ÿ ���� ���� ����
			Score = reset; //��� ���� ���� ����
			elapsed_ms = 0; //�ð� ���� ����
			elapsed_s = 0; //�ð� ���� ����
			linenum++; //�ٹ�ȣ +1
			Sleep(3000); //3�� ���
			system("cls"); //�ܼ� û��
		}
	}
	double total_avg_time = 0; //��� Ÿ���� �ӵ� ����
	total_avg_time = total_time / 10; //��� Ÿ���� �ӵ� ���
	double total_avg_wpm = 0;  //��� Ÿ�� ����
	total_avg_wpm = total_wpm / 10; //��� Ÿ�� ���

	printf("\x1b[38;5;230m����� ���̵��� \x1b[38;5;219m%s\x1b[38;5;230m�Դϴ�.\x1b[0m\n", dif[difnum]);
	printf("\x1b[38;5;230m����� ��� Ÿ���� �ӵ��� \x1b[38;5;219m%.2f��\x1b[38;5;230m�Դϴ�.\x1b[0m\n", total_avg_time);
	printf("\x1b[38;5;230m����� �� ������ \x1b[38;5;219m%d��\x1b[38;5;230m�Դϴ�.\x1b[0m\n", total_score);
	printf("\x1b[38;5;230m����� ��� Ÿ���� \x1b[38;5;219m%.2fŸ\x1b[38;5;230m�Դϴ�.\x1b[0m\n", total_avg_wpm);
	printf("\x1b[38;5;230m����� �� ��Ÿ ������ \x1b[38;5;219m%d��\x1b[38;5;230m�Դϴ�.\x1b[0m\n", total_minus_count);
	//�ؾ��� �� �� ���� ���̵��� ���� ��� ������� 
	//��޵� �ϰ� �Ͱ� �� �ټ����� �ϰ� �Ͱ�
	//100������ ������ �Ǵµ� �����ϰ�


}