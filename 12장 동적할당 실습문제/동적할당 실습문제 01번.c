#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N;
	int* score;
	int sum = 0;
	scanf("%d", &N);

	score = (int*)malloc(N * sizeof(int));

	for (int* p = score; p < score + N; p++) {
		scanf("%d", p);
		sum = sum + *p;
	}

	printf("%d", sum);

	free(score);
	return 0;
}

