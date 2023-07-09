#pragma warning(disable : 4996)
#include<stdio.h>

int main() {
	int a[11], b[11], counta = 0, countb = 0;
	int max = 0, min = 100;

	for (int* p = a; p < a + 11; p++) {
		scanf("%d", p);
		if (*p == -1)
			break;
		counta++;
	}

	for (int *i = a; i < a+ counta; i++) {
		if (max < *i)
			max = *i;
		if (min > *i)
			min = *i;
	}

	for (int* p = b ; p < b + 11; p++) {
		scanf("%d", p);
		if (*p == -1)
			break;
		countb++;
	}

	for (int *i = b; i <b+ countb; i++) {
		if (max < *i)
			max = *i;
		if (min > *i)
			min = *i;
	}

	printf("%d %d\n", counta, countb);
	printf("%d %d", max, min);
	return 0;
}