#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int** x = (int**)malloc(21 * sizeof(int*));
	x[0] = (int*)malloc(5 * sizeof(int));
	int cnt = 5;
	int i = 0, j = 0;
	int k = 0;
	for (i = 0 ; i < 21 ; i++)  {
		for (j = 0; j < cnt; j++) {
			scanf("%d", &x[i][j]);
			if (x [i][j] == -1)
				break;
		}
		if (x[i][j] == -1) {
			k = i+1;
			break;
		}
		x[i+1] = (int*)malloc(3 * sizeof(int));
		cnt = 3;
		k = i+1;
	}
	cnt = 5;
	for (int t = 0; t < k; t++) {
		for (int l = 0; l < cnt; l++) {
			printf(" %d", x[t][l]);
			if (x[t][l] == -1)
				break;
		}
		cnt = 3;
	}
}