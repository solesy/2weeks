#include "Header.h"
//line: 한줄
//Count: 현재 줄에 출력할 글자의 개수
//B_Flag: 같은줄에서 계속출력 하는가 여부
//를 입력받아 조건에 맞게 출력한다.
void Print_Line(char* line, int* Count, int* B_Flag) {
	int i, N_Blanks, N_Chars, Start;
	
	//에러: Start를 초기화 해주어야 한다.
	Start = 0;
	Get_Blanks_Chars(line, Start, &N_Blanks, &N_Chars);
	while (N_Chars != 0) {
		if ((*B_Flag == 1) && ((*Count + N_Chars + 1) <= LIMIT)) {

			/* In this part, N_Blanks == 0 in order that L1 and L2 should be merged.
			* "N_Blanks != 0" means that L2 is written at the next line.
			*/
			if (N_Blanks != 0) {
				printf("Something Wrong!\n");
				exit(-1);
			}

			putchar(' ');
			*B_Flag = 0;
			//에러: 등호
			for (i = Start; i <= Start + N_Chars - 1; i++) {
				putchar(line[i]);
			}
			Start = Start + N_Chars;
			*Count = *Count + N_Chars + 1;
			Get_Blanks_Chars(line, Start, &N_Blanks, &N_Chars);
		}
		else if ((*Count + N_Blanks + N_Chars) <= LIMIT) {
			//에러: 등호
			for (i = Start; i <= Start + N_Blanks + N_Chars - 1; i++) {
				putchar(line[i]);
			}
			Start = Start + N_Blanks + N_Chars;
			*Count = *Count + N_Blanks + N_Chars;
			Get_Blanks_Chars(line, Start, &N_Blanks, &N_Chars);
		}
		else {
			if (*Count == 0) {
				//에러: 등호
				for (i = Start; i <= Start + N_Blanks + N_Chars - 1; i++) {
					putchar(line[i]);
				}
				Start = Start + N_Blanks + N_Chars;
				putchar('\n');
				Get_Blanks_Chars(line, Start, &N_Blanks, &N_Chars);
				//에러: 이 경우 Start+=N_Blanks로 추가적인 이동을 필요로 한다.
				Start += N_Blanks;
			}
			else {
				putchar('\n');
				*B_Flag = 0;
				//에러: 등호
				for (i = Start + N_Blanks; i <= Start + N_Blanks + N_Chars - 1; i++) {
					putchar(line[i]);
				}
				Start = Start + N_Blanks + N_Chars;
				*Count = N_Chars;
				Get_Blanks_Chars(line, Start, &N_Blanks, &N_Chars);
			}
		}
	}
}
