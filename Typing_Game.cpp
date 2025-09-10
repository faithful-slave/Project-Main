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

#define MENU_COUNT 5 // 메뉴 갯수

// ───────────────[made by 수범]─────────────── //
// 타이핑 게임 실행 함수
void showTypingGame()  
{
	srand((unsigned)time(NULL)); // 시간을 이용한 난수 생성
	int reset = 0;               // 초기화 상태 표시 변수
	int difnum = 0;              // 난이도 등급
	char input[700];             // 입력 저장 배열
	int score = 0;               // 현재 점수
	int total_score = 0;         // 누적 점수 합계
	int total_minus_count = 0;   // 총 오타 수
	double total_time = 0;       // 누적 소요 시간 (초)
	double total_wpm = 0;        // 평균 타수 (WPM)
	int linenum = 1;             // 라인 번호

	int arr[45]; // 배열을 하나 더 만들어서 50번 반복
	for (int i = 0; i < 45; i++)
	{
		arr[i] = i;
	}

	char menu[MENU_COUNT][40] = 
	{
		"쉬움",
		"보통",
		"어려움",
		"매우 어려움\n",
		"게임 선택 화면으로 나가기"
	};

	int selected = 0; // 난이도 메뉴 선택되었는지 확인을 위한 변수
	int ch;

	//난이도 선택 메뉴 출력 (세로)
	while (1) 
	{
		system("cls");  // 콘솔 화면 지우기
		printf("난이도를 선택해주세요\n");

		// 메뉴 출력
		for (int i = 0; i < MENU_COUNT; i++) 
		{
			if (i == selected) // i가 선택된 메뉴인 경우
				printf("\x1b[38;2;255;220;120m▶ %s\x1b[0m\n", menu[i]); // 화살표를 앞에 붙이고 노란색으로 메뉴 출력
			else if (i == selected && selected == 4)
			{
				printf("\x1b[38;2;255;220;120m▶ %s\x1b[0m\n", menu[i]); // 화살표를 앞에 붙이고 노란색으로 메뉴 출력
			}
			else // 선택되지 않은 메뉴인 경우
				printf("  \x1b[38;2;80;80;80m%s\x1b[0m\n", menu[i]);  // 화살표를 붙이지 않고 진한 회색으로 메뉴 출력
		}

		ch = _getch(); 

		// 방향키는 두 번 _getch() 해야 함
		if (ch == 224) 
		{
			ch = _getch();

			switch (ch) 
			{
			case 72: // ch에 입력 받은 키가 ↑ 이면
				selected--; // 선택된 메뉴의 인덱스를 1 뒤로 이동
				if (selected < 0) selected = MENU_COUNT - 1; // 0보다 작으면 메뉴 갯수 -1 만큼 이동
				break;
			case 80: // ch에 입력 받은 키가 ↓ 이면
				selected++;  // 선택된 메뉴의 인덱스를 1 앞으로 이동
				if (selected >= MENU_COUNT) selected = 0; // 메뉴 갯수보다 크거나 같으면 0으로 이동
				break;
			}
		}
		else if (selected == 4 && ch == 13)
		{
			system("cls");
			printf("\n");
			gotoXY(47, 5);
			printf("[ 게임을 중지하고 게임 선택 화면으로 돌아갑니다 ]\n");
			Sleep(700);
			Treturnnum = 1;
			break;
		}
		else if (ch == 13) // ch에 입력 받은 키가 Enter키 이면
		{ 
			difnum = selected;  // 선택된 메뉴의 인덱스를 difnum에 저장
			printf("\n\n[%s] 난이도를 선택하였습니다\n", dif[difnum]);  // 선택된 난이도 출력
			Sleep(2000); // 2초 대기
			system("cls"); // 콘솔 청소
			break;
		}
	}

	int size = 45;  // 문장의 갯수가 45개이기에 랜덤으로 출력하는 숫자의 최대 크기는 45


	// 카운트다운 함수 실행
	startCountdown(); 


	for (int i = 0; i < 2; i++)  // 10개의 문장 출력
	{
		int random_num = rand() % size; // 0 ~ 45의 랜덤 숫자 출력

		int non_overlap = arr[random_num];  
		// 랜덤 숫자와 같은 번째의 문장을 출력하기 위해 배열의 랜덤숫자를 non_overlap에 저장

		if (difnum == 0) // 만약 난이도가 0번째면(easy)
		{
			if (linenum % 10 != 0) // 줄번호가 10의 배수가 아니면
			{
				printf("[ %d ] ", linenum); // 줄번호 출력
				printf("\x1b[1;36m%s\n\x1b[0m", easy_diffculty[non_overlap]); // 입력해야 하는 랜덤한 문장 출력
				printf("입력: "); // :을 붙어서 출력
			}
			else // 줄번호가 10의 배수이면
			{
				printf("[ %d ] ", linenum); // 줄번호 출력
				printf("\x1b[1;36m%s\n\x1b[0m", easy_diffculty[non_overlap]); // 입력해야 하는 랜덤한 문장 출력
				printf("입력 : "); // :을 띄어서 출력
			}

			ULONGLONG start_time = GetTickCount64(); // 시작 시간

			scanf_s(" %[^\n]s", &input, 700); // 공백 포함 문자열 입력 받기

			ULONGLONG end_time = GetTickCount64(); // 종료 시간 저장
			arr[random_num] = arr[size - 1];
			size--;

			system("cls");  // 콘솔 청소
			printf("[ %d ] ", linenum); // 줄번호 출력
			printf("\x1b[1;36m%s\n\x1b[0m", easy_diffculty[non_overlap]); // 입력해야 하는 문장 출력

			compare(easy_diffculty[non_overlap], input); // 글자 비교, 오타 갯수 추출

			total_score = total_score + get_count; // 총 점수 합계
			score = get_count; // 얻는 점수 계산

			// 시간 계산
			ULONGLONG elapsed_ms = end_time - start_time;        // 시간 계산
			double elapsed_s = elapsed_ms / 1000.0;              // 실수 나눗셈
			total_time = total_time + elapsed_s;                 // 총 시간 계산
			double wpm = total_sentence_len / elapsed_s * 60.0;  // 타수 계산
			total_wpm = total_wpm + wpm;                         // 총 타수 계산
			printf("\n\n");
			// ───────────────[made by 은혁]─────────────── //
			printf(" - \x1b[38;2;255;150;175m오타\x1b[0m : \x1b[38;2;255;154;162m%d개\x1b[0m\n", minus_count);  // 오타 갯수 출력
			printf(" - \x1b[38;2;150;255;215m점수\x1b[0m : \x1b[38;2;166;255;211m+%d점\x1b[0m\n", score);       // 얻는 점수 출력
			printf(" - \x1b[38;2;255;200;170m시간\x1b[0m : \x1b[38;2;255;201;163m%.2f초\x1b[0m\n", elapsed_s);  // 시간 출력
			printf(" - \x1b[38;2;180;190;255m타수\x1b[0m : \x1b[38;2;176;184;255m%.2f타\x1b[0m\n", wpm);        // 타수 출력
			// ─────────────────────────────────────────── //
			total_minus_count = total_minus_count + minus_count; // 총 오타 갯수 합계
			
			// 루프 반복 시 안전한 초기화를 위한 변수 리셋 (필수는 아님)
			minus_count = reset; // 오타 갯수 변수 리셋
			score = reset;       // 얻는 점수 변수 리셋
			elapsed_ms = 0;      // 시간 변수 리셋
			elapsed_s = 0;       // 시간 변수 리셋
			linenum++;           // 줄번호 +1
			Sleep(3000);         // 3초 대기
			system("cls");       // 콘솔 청소
		}

		else if (difnum == 1)  // 만약 난이도가 1번째면(normal)
		{
			if (linenum % 10 != 0) // 줄번호가 10의 배수가 아니면
			{
				printf("[ %d ] ", linenum); // 줄번호 출력
				printf("\x1b[1;36m%s\n\x1b[0m", normal_diffculty[non_overlap]); // 입력해야 하는 문장 출력
				printf("입력: "); // :을 붙어서 출력
			}
			else // 줄번호가 10의 배수이면
			{
				printf("[ %d ] ", linenum); // 줄번호 출력
				printf("\x1b[1;36m%s\n\x1b[0m", normal_diffculty[non_overlap]); // 입력해야 하는 문장 출력
				printf("입력 : "); // :을 띄어서 출력
			}

			ULONGLONG start_time = GetTickCount64(); // 시작 시간

			scanf_s(" %[^\n]s", &input, 700); // 공백 포함 문자열 입력 받기

			ULONGLONG end_time = GetTickCount64(); // 종료 시간 저장
			arr[random_num] = arr[size - 1];
			size--;

			system("cls");  // 콘솔 청소
			printf("[ %d ] ", linenum); // 줄번호 출력
			printf("\x1b[1;36m%s\n\x1b[0m", normal_diffculty[non_overlap]); // 입력해야 하는 문장 출력

			compare(normal_diffculty[non_overlap], input); // 글자 비교, 오타 갯수 추출

			total_score = total_score + get_count; // 총 점수 합계
			score = get_count; // 얻는 점수 계산

			// 시간 계산
			ULONGLONG elapsed_ms = end_time - start_time;       // 시간 계산
			double elapsed_s = elapsed_ms / 1000.0;             // 실수 나눗셈
			total_time = total_time + elapsed_s;                // 총 시간 계산
			double wpm = total_sentence_len / elapsed_s * 60.0; // 타수 계산
			total_wpm = total_wpm + wpm;                        // 총 타수 계산

			printf("\n\n");
			// ───────────────[made by 은혁]─────────────── //
			printf(" - \x1b[38;2;255;150;175m오타\x1b[0m : \x1b[38;2;255;154;162m%d개\x1b[0m\n", minus_count);  // 오타 갯수 출력
			printf(" - \x1b[38;2;150;255;215m점수\x1b[0m : \x1b[38;2;166;255;211m+%d점\x1b[0m\n", score);       // 얻는 점수 출력
			printf(" - \x1b[38;2;255;200;170m시간\x1b[0m : \x1b[38;2;255;201;163m%.2f초\x1b[0m\n", elapsed_s);  // 시간 출력
			printf(" - \x1b[38;2;180;190;255m타수\x1b[0m : \x1b[38;2;176;184;255m%.2f타\x1b[0m\n", wpm);        // 타수 출력
			// ─────────────────────────────────────────── //
			total_minus_count = total_minus_count + minus_count; // 총 오타 갯수 합계

			// 루프 반복 시 안전한 초기화를 위한 변수 리셋 (필수는 아님)
			minus_count = reset; // 오타 갯수 변수 리셋
			score = reset;       // 얻는 점수 변수 리셋
			elapsed_ms = 0;      // 시간 변수 리셋
			elapsed_s = 0;       // 시간 변수 리셋
			linenum++;           // 줄번호 +1
			Sleep(3000);         // 3초 대기
			system("cls");       // 콘솔 청소
		}

		else if (difnum == 2)  // 만약 난이도가 2번째면(hard)
		{
			if (linenum % 10 != 0) // 줄번호가 10의 배수가 아니면
			{
				printf("[ %d ] ", linenum); // 줄번호 출력
				printf("\x1b[1;36m%s\n\x1b[0m", hard_diffculty[non_overlap]); // 입력해야 하는 문장 출력
				printf("입력: "); // :을 붙어서 출력
			}
			else // 줄번호가 10의 배수이면
			{
				printf("[ %d ] ", linenum); // 줄번호 출력
				printf("\x1b[1;36m%s\n\x1b[0m", hard_diffculty[non_overlap]); // 입력해야 하는 문장 출력
				printf("입력 : "); // :을 띄어서 출력
			}

			ULONGLONG start_time = GetTickCount64(); // 시작 시간

			scanf_s(" %[^\n]s", &input, 700); // 공백 포함 문자열 입력 받기

			ULONGLONG end_time = GetTickCount64(); // 종료 시간 저장
			arr[random_num] = arr[size - 1];
			size--;

			system("cls");  // 콘솔 청소
			printf("[ %d ] ", linenum); // 줄번호 출력
			printf("\x1b[1;36m%s\n\x1b[0m", hard_diffculty[non_overlap]); // 입력해야 하는 문장 출력

			compare(hard_diffculty[non_overlap], input); // 글자 비교, 오타 갯수 추출

			total_score = total_score + get_count; // 총 점수 합계
			score = get_count; // 얻는 점수 계산

			// 시간 계산
			ULONGLONG elapsed_ms = end_time - start_time;       // 시간 계산
			double elapsed_s = elapsed_ms / 1000.0;             // 실수 나눗셈
			total_time = total_time + elapsed_s;                // 총 시간 계산
			double wpm = total_sentence_len / elapsed_s * 60.0; // 타수 계산
			total_wpm = total_wpm + wpm;                        // 총 타수 계산

			printf("\n\n");
			// ───────────────[made by 은혁]─────────────── //
			printf(" - \x1b[38;2;255;150;175m오타\x1b[0m : \x1b[38;2;255;154;162m%d개\x1b[0m\n", minus_count);  // 오타 갯수 출력
			printf(" - \x1b[38;2;150;255;215m점수\x1b[0m : \x1b[38;2;166;255;211m+%d점\x1b[0m\n", score);       // 얻는 점수 출력
			printf(" - \x1b[38;2;255;200;170m시간\x1b[0m : \x1b[38;2;255;201;163m%.2f초\x1b[0m\n", elapsed_s);  // 시간 출력
			printf(" - \x1b[38;2;180;190;255m타수\x1b[0m : \x1b[38;2;176;184;255m%.2f타\x1b[0m\n", wpm);        // 타수 출력
			// ─────────────────────────────────────────── //
			total_minus_count = total_minus_count + minus_count; // 총 오타 갯수 합계

			// 루프 반복 시 안전한 초기화를 위한 변수 리셋 (필수는 아님)
			minus_count = reset; // 오타 갯수 변수 리셋
			score = reset;       // 얻는 점수 변수 리셋
			elapsed_ms = 0;      // 시간 변수 리셋
			elapsed_s = 0;       // 시간 변수 리셋
			linenum++;           // 줄번호 +1
			Sleep(3000);         // 3초 대기
			system("cls");       // 콘솔 청소
		}

		else if (difnum == 3)  // 만약 난이도가 3번째면(crazy)
		{
			if (linenum % 10 != 0) // 줄번호가 10의 배수가 아니면
			{
				printf("[ %d ] ", linenum); // 줄번호 출력
				printf("\x1b[1;36m%s\n\x1b[0m", crazy_diffculty[non_overlap]); // 입력해야 하는 문장 출력
				printf("입력: "); // :을 붙어서 출력
			}
			else // 줄번호가 10의 배수이면
			{
				printf("[ %d ] ", linenum); // 줄번호 출력
				printf("\x1b[1;36m%s\n\x1b[0m", crazy_diffculty[non_overlap]); // 입력해야 하는 문장 출력
				printf("입력 : "); // :을 띄어서 출력
			}

			ULONGLONG start_time = GetTickCount64(); // 시작 시간

			scanf_s(" %[^\n]s", &input, 700); // 공백 포함 문자열 입력 받기

			ULONGLONG end_time = GetTickCount64(); // 종료 시간 저장
			arr[random_num] = arr[size - 1];
			size--;

			system("cls");  // 콘솔 청소
			printf("[ %d ] ", linenum); // 줄번호 출력
			printf("\x1b[1;36m%s\n\x1b[0m", crazy_diffculty[non_overlap]); // 입력해야 하는 문장 출력

			compare(crazy_diffculty[non_overlap], input); // 글자 비교, 오타 갯수 추출

			total_score = total_score + get_count; // 총 점수 합계
			score = get_count; // 얻는 점수 계산

			// 시간 계산
			ULONGLONG elapsed_ms = end_time - start_time;       // 시간 계산
			double elapsed_s = elapsed_ms / 1000.0;             // 실수 나눗셈
			total_time = total_time + elapsed_s;                // 총 시간 계산
			double wpm = total_sentence_len / elapsed_s * 60.0; // 타수 계산
			total_wpm = total_wpm + wpm;                        // 총 타수 계산

			printf("\n\n");
			// ───────────────[made by 은혁]─────────────── //
			printf(" - \x1b[38;2;255;150;175m오타\x1b[0m : \x1b[38;2;255;154;162m%d개\x1b[0m\n", minus_count);  // 오타 갯수 출력
			printf(" - \x1b[38;2;150;255;215m점수\x1b[0m : \x1b[38;2;166;255;211m+%d점\x1b[0m\n", score);       // 얻는 점수 출력
			printf(" - \x1b[38;2;255;200;170m시간\x1b[0m : \x1b[38;2;255;201;163m%.2f초\x1b[0m\n", elapsed_s);  // 시간 출력
			printf(" - \x1b[38;2;180;190;255m타수\x1b[0m : \x1b[38;2;176;184;255m%.2f타\x1b[0m\n", wpm);        // 타수 출력
			// ─────────────────────────────────────────── //

			total_minus_count = total_minus_count + minus_count; // 총 오타 갯수 합계

			// 루프 반복 시 안전한 초기화를 위한 변수 리셋 (필수는 아님)
			minus_count = reset; // 오타 갯수 변수 리셋
			score = reset;       // 얻는 점수 변수 리셋
			elapsed_ms = 0;      // 시간 변수 리셋
			elapsed_s = 0;       // 시간 변수 리셋
			linenum++;           // 줄번호 +1
			Sleep(3000);         // 3초 대기
			system("cls");       // 콘솔 청소
		}
	}
	double total_avg_time = 0;          // 평균 타이핑 속도 변수
	total_avg_time = total_time / 10;   // 평균 타이핑 속도 계산
	double total_avg_wpm = 0;           // 평균 타수 변수
	total_avg_wpm = total_wpm / 10;     // 평균 타수 계산

	// ───────────────[made by 은혁]─────────────── //
	printf("\x1b[38;5;230m당신의 난이도는 \x1b[38;5;219m%s\x1b[38;5;230m입니다.\x1b[0m\n", dif[difnum]);                   // 난이도 출력
	printf("\x1b[38;5;230m당신의 평균 타이핑 속도는 \x1b[38;5;219m%.2f초\x1b[38;5;230m입니다.\x1b[0m\n", total_avg_time);  // 평균 타이핑 속도 출력
	printf("\x1b[38;5;230m당신의 총 점수는 \x1b[38;5;219m%d점\x1b[38;5;230m입니다.\x1b[0m\n", total_score);                // 총 점수 출력
	printf("\x1b[38;5;230m당신의 평균 타수는 \x1b[38;5;219m%.2f타\x1b[38;5;230m입니다.\x1b[0m\n", total_avg_wpm);          // 평균 타수 출력
	printf("\x1b[38;5;230m당신의 총 오타 갯수는 \x1b[38;5;219m%d개\x1b[38;5;230m입니다.\x1b[0m\n", total_minus_count);     // 총 오타갯수 출력
	// ─────────────────────────────────────────── //
	
	// 해야할 것 총 점수 난이도에 따라 어떻게 계산할지 
	// 등급도 하고 싶고 별 다섯개도 하고 싶고
	// 100점으로 끝내야 되는데 오버하고


}