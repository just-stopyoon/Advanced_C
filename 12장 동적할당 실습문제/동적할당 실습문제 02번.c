#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N;
	float *score;
	float max = 0.0;
	scanf("%d", &N);

	score = (float*)malloc(N * sizeof(float));

	for (float* p = score; p < score + N; p++) {
		scanf("%f", p);
	}
	max = *score;
	for (float* p = score; p < score + N; p++) {
		if (max < *p)
			max = *p;
	}

	printf("%.2lf", max);

	free(score);
	return 0;
}

