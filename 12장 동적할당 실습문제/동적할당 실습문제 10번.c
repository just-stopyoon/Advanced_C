#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int* x = (int*)malloc(N * sizeof(int));
	int* y = (int*)malloc((N- 1) * sizeof(int));
	int num = 0, idx = 0;
	for (int i = 0; i < N; i++) {
		x[i] = num;
		num++;
	}
	for (int i = 0; i < N; i++) {
		if (i != (N - 1) / 2)
			y[idx++] = x[i];
	}

	for (int i = 0; i < N - 1; i++) {
		printf(" %d", y[i]);
	}
}