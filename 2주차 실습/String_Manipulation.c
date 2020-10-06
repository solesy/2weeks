#include "Header.h"
//line뒤의 빈칸을 삭제한다.
void Remove_Blanks_At_The_End(char* line) {
	int i, k, newline_flag = 0;

	for (k = 0; ; k++) {
		if (line[k] == '\n') {
			newline_flag = 1;
			break;
		}
		else if (line[k] == '\0') {
			break;
		}
	}
	//에러: i=k는 항상 \n이다.
	for (i = k - 1; i >= 0; --i) {
		if (line[i] != ' ') {
			break;
		}
	}
	++i;
	if (newline_flag == 1) {
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else {
		line[i] = '\0';
	}
}
//N_Blanks: Start 이후 다음단어까지 존재하는 빈칸의 개수
//N_Chars: 다음 단어의 글자수
//를 초기화한다.
void Get_Blanks_Chars(char* line, int Start, int* N_Blanks, int* N_Chars) {
	int i, blank_flag;
	//에러: blank_flag가 초기화되지 않았다.
	//에러: N_Blanks가 초기화 하기 위해서 0으로 미리 초기화 해주어야한다.
	//에러: N_Chars가 초기화 하기 위해서 0으로 미리 초기화 해주어야한다.
	blank_flag = 0;
	*N_Blanks = 0;
	*N_Chars = 0;
	for (i = Start; ; i++) {
		if ((line[i] == '\n') || (line[i] == '\0')) {
			break;
		}
		else if (line[i] == ' ') {
			if (blank_flag == 0) {
				++(*N_Blanks);
			}
			else {
				break;
			}
		}
		else {
			blank_flag = 1;
			++(*N_Chars);
		}
	}
}
