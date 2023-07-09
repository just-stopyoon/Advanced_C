#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main() {
	char A[101][251] = { 0 };
	char B[101][251] = { 0 };
	char tmp[251] = "";
	gets(A[0]);
	gets(B[0]);

	int i1 = 1, j1 = 0;
	for (char* p = A[0] ; *p; p++) {
		if (*p == ' ') {
			A[i1++][j1] = '\0';
			j1 = 0;
		}
		else {
			A[i1][j1++] = *p;
		}
	}
	A[i1++][j1] = '\0';

	int i2 = 1, j2 = 0;

	for (char* p = B[0]; *p; p++) {
		if (*p == ' ') {
			B[i2++][j2] = '\0';
			j2 = 0;
		}
		else {
			B[i2][j2++] = *p;
		}
	}
	B[i2++][j2] = '\0';

	int cnt = 1;

	for (int x = 1; x < i1; x++) {
		for (int y = 1; y < x; y++) {
			if (strcmp(A[x], A[y]) == 0) {
				strcpy(A[x], B[cnt]);
				cnt++;
			}
		}
	}
	for (int a = 1; a < i1; a++) {
		strcat(tmp, A[a]);
		strcat(tmp, " ");
	}

	printf("%s", tmp);
}