#pragma warning(disable : 4996)
#include<stdio.h>

int main() {
	int a[21], b[11], counta = 0, countb = 0;

	for (int* p = a; p < a + 11; p++) {
		scanf("%d", p);
		if (*p == -1)
			break;
		counta++;
	}

	for (int* p = b; p < b + 11; p++) {
		scanf("%d", p);
		if (*p == -1)
			break;
		countb++;
	}
	int tmp = 0;

	int i = 0;
	for (int* p = a + counta -1; p < a + counta + countb -1; p++) {
		*(p + 1)= *(b + i);
		i++;
	}

	for (int *i = a ; i < a+ counta + countb ; i++){
		for (int *j = a; j < i; j++) {
			if (*i < *j) {
				tmp = *i;
				*i = *j;
				*j = tmp;
			}
		}
	}


	for (int *p = a + counta + countb - 1; p >= a + countb ; p--)
		printf("%d ", *p);

	printf("\n");

	for (int* p = a; p < a + countb; p++)
		printf("%d ", *p);

	return 0;
}