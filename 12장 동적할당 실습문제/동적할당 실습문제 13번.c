#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int* a = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int D;
	scanf("%d", &D);
	realloc(a, sizeof(int)*(N-D));
	for (int i = 0; i < N - D; i++) {
		printf("%d\n", a[i]);
	}

	free(a);
}