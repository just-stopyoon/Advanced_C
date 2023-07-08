#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>

void addArray(int* x, int* y, int* z, int N);

int main() {
	int N;
	scanf("%d", &N);
	int x[20], y[20], z[20];
	for (int* p = x; p < x + N; p++) {
		scanf("%d", p);
	}
	for (int* p = y; p < y + N; p++) {
		scanf("%d", p);
	}
	addArray(x, y, z, N);
	for (int* p = z; p < z + N; p++) {
		printf(" %d", *p);
	}
}

void addArray(int* x, int* y, int* z, int N) {
	for (int* p = x, *q = y + N - 1, *r = z; p < x + N, q >= y, r < z + N; p++, q--, r++) {
		*r = *p + *q;
	}
}