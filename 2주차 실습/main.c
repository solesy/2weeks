#include "Header.h"
int main(int argc, char* argv[]) {
	FILE* fp;
	char* line1, * line2, * tmpline;
	int  Count, Blanks = 0;
	int  i, B_Flag, B_Line;

	if (argc != 2) {
		printf("Usuage: fmt filename | > outfile\n");
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("File open error.\n");
	}
	line1 = (char*)malloc(BNUM * sizeof(char));
	line2 = (char*)malloc(BNUM * sizeof(char));
	if (line1 == NULL || line2 == NULL) {
		printf("Memory allocation error\n");
		exit(-1);
	}

	if (fgets(line1, BNUM, fp) == NULL) {
		// empty file, just return
		return 0;
	}
	Remove_Blanks_At_The_End(line1);
	//B_Line: Remove_Blanks_At_The_End를 실행한 후 그 줄이 빈 줄이라면 1으로 설정한다.
	//B_Flag: 이전의 line과 같은줄에서 계속출력 하는가 여부
	//에러: B_Line이 초기화되지 않았다.
	//에러: B_Flag가 초기화되지 않았다. 첫실행땐 이전의 line이 없으므로 0으로 초기화한다.
	B_Line = 0;
	B_Flag = 0;
	if (line1[0] == '\n') {
		putchar('\n');
		B_Line = 1;
	}
	Count = 0;
	while (1) {
		if (B_Line == 0) {
			Print_Line(line1, &Count, &B_Flag);
		}
		else {
			B_Line = 0;
		}
		if (Count != 0) {
			B_Flag = 1;
		}
		if (fgets(line2, BNUM, fp) == NULL) {
			break;	// EOF. Exit the while loop
		}
		Remove_Blanks_At_The_End(line2);
		if (line2[0] == ' ' && Count != 0) {
			putchar('\n');
			B_Flag = 0;
			Count = 0;
		}
		else if (line2[0] == '\n') {
			if (B_Flag == 1) {
				putchar('\n');
				B_Flag = 0;
			}
			putchar('\n');
			B_Line = 1;
			Count = 0;
		}
		tmpline = line1;
		line1 = line2;
		line2 = tmpline;
	}
	if (line1[0] != '\n') {
		// if the last line is not empty line,
		// check if the last char is '\n' and ouput it if it is.
		for (i = 0; ; i++) {
			if ((line1[i] == '\n') || (line1[i] == '\0')) {
				break;
			}
		}
		if (line1[i] == '\n') {
			putchar('\n');
		}
	}
}
