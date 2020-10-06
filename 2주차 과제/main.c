#include"Header.h"
int main() {
	int t;
	scanf("%d", &t);
	//답을 저장하는 count를 초기화한다.
	int** count = (int**)malloc(t * sizeof(int*));
	for (int i = 0; i < t; ++i)
		count[i] = (int*)malloc(10 * sizeof(int));
	//각 테스트 케이스를 실행한다.
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		//count[i]를 0으로 초기화한다.
		countInit(count[i]);
		//count[i]를 증가시킨다.
		for (int j = 1; j <= n; ++j)
			query(j, count[i]);
	}
	for (int i = 0; i < t; ++i)
		printCount(count[i]);
}
