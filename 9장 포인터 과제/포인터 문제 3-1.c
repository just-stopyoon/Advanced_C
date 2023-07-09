#pragma warning(disable : 4996)
#include<stdio.h>

int main() {
	char x[100];
	int count = 0;

	for (char * p = x; p < x + 100; p++) {
		scanf("%c", p);
		if (*p == '#')
			break;
		count++;
	}

	int counta = 0;
	int max = 0;
	int chk = 0;

	for (char * p = x ; p < x + count; p++) {
		if (*p >= 'a' && *p <= 'z') {
			printf("%c", *p);
			counta++;
			chk = 0;
		}
		else{
			if (counta != 0)
				printf("\n");
			if (max < counta) {
				max = counta;
			}
			counta = 0;
		}
	}
	if (max < counta)
		max = counta;
	
	if (counta != 0)
		printf("\n");

	printf("%d", max);


	return 0;
}