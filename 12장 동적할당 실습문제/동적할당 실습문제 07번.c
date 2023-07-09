#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int x, y;
	char res = 'a';
	scanf("%d %d", &x, &y);
	char** arr = (char**)malloc(x * sizeof(char*));

	for (int i = 0; i < x; i++) {
		arr[i] = (char*)malloc(y * sizeof(char));
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arr[i][j] = res;
			if (res == 'z') {
				res = 'A' - 1;
			}
			if (res == 'Z') {
				res = 'a' - 1;
			}
			printf("%c ", arr[i][j]);
			res++;
		}
		printf("\n");
	}
}