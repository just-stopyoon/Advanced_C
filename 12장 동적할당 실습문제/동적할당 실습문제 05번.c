#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);

	int* x = (int*)malloc(N * sizeof(int));

	for (int* p = x; p < x + N; p++) {
		scanf("%d", p);
	}

	for (int* p = x; p < x + N - 1; p++) {
		if (*p > *(p + 1)) {
			int tmp = *p;
			*p = *(p + 1);
			*(p + 1) = tmp;
		}
	}

	for (int* p = x; p < x + N; p++) {
		printf("%d\n", *p);
	}
}