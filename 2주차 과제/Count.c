#include"Header.h"
//count를 0으로 초기화한다.
void countInit(int* count) {
	for (int i = 0; i < 10; ++i) count[i] = 0;
}
//숫자 n이 주어졌을때, n의 각자리수를 구해 count를 갱신한다.
void query(int n, int* count) {
	while (1) {
		++count[remainders(n)];
		n = quotient(n);
		if (n == 0) break;
	}
}
//count를 출력한다.
void printCount(int* count) {
	for (int i = 0; i < 10; ++i) printf("%d ", count[i]);
	printf("\n");
}
