#pragma once
#ifndef TYPING_GAME
#define TYPING_GAME

#pragma once

#define easy_sentences_count    45
#define normal_sentences_count  45
#define hard_sentences_count    45
#define crazy_sentences_count   45

void startCountdown();
void compare(const char* a, const char* b);
extern char easy_diffculty[easy_sentences_count][500];     // 난이도 하의 문장들을 저장하는 배열 선언

extern char normal_diffculty[normal_sentences_count][500]; // 난이도 중의 문장들을 저장하는 배열 선언

extern char hard_diffculty[hard_sentences_count][500];     // 난이도 상의 문장들을 저장하는 배열 선언

extern char crazy_diffculty[crazy_sentences_count][500];   // 난이도 최상의 문장들을 저장하는 배열 선언

extern char dif[4][10];  
extern int diff_count;
extern int get_count;
extern int minus_count;
extern int total_sentence_len;
#endif 