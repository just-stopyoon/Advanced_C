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

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (strlen(x[i]) > strlen(x[j])) {
				char tmp[101];
				strcpy(tmp, x[i]);
				strcpy(x[i], x[j]);
				strcpy(x[j], tmp);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%s\n", x[i]);
	}
}