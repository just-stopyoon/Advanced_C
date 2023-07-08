#pragma warning(disable : 4996)
#include<stdio.h>

void ABC(int* a, int k);

int main() {
	int x[100];
	for (int* p = x; p < x + 10; p++) {
		scanf("%d", p);
	}
	for (int i = 10; i > 0; i--) {
		ABC(x + (10 - i), i);
	}
	for (int* p = x; p < x + 10; p++) {
		printf(" %d", *p);
	}
}

void ABC(int* a, int k) {
	int* max = a, tmp = 0;
	for (int* p = a; p < a + k; p++) {
		if (*p > *max) {
			max = p;
		}
	}
	tmp = *max;
	*max = *a;
	*a = tmp;
}
