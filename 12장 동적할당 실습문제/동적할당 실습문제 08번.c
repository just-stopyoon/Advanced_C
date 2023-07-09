#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	getchar();

	char** x = (char**)malloc(N * sizeof(char*));
	int* length = (char*)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		x[i] = (char*)malloc(100 * sizeof(char));
	}

	for (int i = 0; i < N; i++) {
		gets(x[i]);
		length[i] = strlen(x[i]);
	}
	int min = length[0];
	char result[101];
	strcpy(result, x[0]);
	for (int i = 0; i < N; i++) {
		if (min > length[i]) {
			min = length[i];
			strcpy(result, x[i]);
		}
	}
	printf("%s", result);
}