#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

add_to_k(int* a, int* b);

int main() {
	int N;
	scanf("%d", &N);
	int d[100];
	int result = 0;
	for (int* p = d; p < d + N; p++) {
		scanf("%d", p);
	}
	for (int* p = d; p < d + N; p++) {
		result = result + add_to_k(d, p);
	}
	printf("%d", result);
}

add_to_k(int* a, int* b) {
	int result = 0;
	for (int* p = a; p <= b; p++) {
		result = result + *p;
	}
	return result;
}