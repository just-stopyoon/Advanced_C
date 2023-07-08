#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int arrsum(int* a, int* b);

int main() {
	int N, S, E;
	scanf("%d %d %d", &N, &S, &E);
	int x[100];
	for (int* p = x; p < x + N; p++) {
		scanf("%d", p);
	}
	printf("%d", arrsum(x + S, x + E));
}

int arrsum(int* a, int* b) {
	int result = 0;
	for (int* p = a; p <= b; p++) {
		result = result + *p;
	}
	return result;
}