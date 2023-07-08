#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

void swap(int* a, int* b);

int main() {
	int N;
	scanf("%d", &N);
	int x[50];
	for (int* p = x; p < x + N; p++) {
		scanf("%d", p);
	}
	int a, b;
	scanf("%d %d", &a, &b);
	swap(x + a, x + b);
	for (int* p = x; p < x + N; p++) {
		printf(" %d", *p);
	}
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}