#pragma warning(disable : 4996)
#include<stdio.h>

int main() {
	int N, count = 0, cnt = 0, chk = 2;
	scanf("%d", &N);
	int x[22], y[22];

	for (int* p = x; p < x + N; p++) {
		scanf("%d", p);
	}
	if (N < 5) {
		chk = 1;
	}

	if (chk == 1) {
		printf("-1");
	}
	

	for (int *i = x; i < x + N; i++) {
		cnt = 0;
		for (int *j = x; j < i; j++) {
			if (*i == *j) {
				cnt++;
				chk = 0;
			}
		}
		if (cnt == 0) {
			*(y + count) = *i;
			count++;
		}
	}

	if (chk == 2)
		printf("0");

	for (int *i = y ; i < y + count; i++) {
		cnt = 0;
		for (int *j = x ; j <x + N; j++) {
			if (*i == *j) {
				cnt++;
			}
		}
		if(cnt >= 2 && chk == 0 && N >= 5)
			printf("%d %d\n", *i, cnt);
	}


	return 0;
}