#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>

int* MAX(int ar[]);
int* MIN(int ar[]);

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int ar[101] = { 0 };
		for (int* p = ar; p < ar + 100; p++) {
			scanf("%d", p);
			if (*p == 0)
				break;
		}
		int max = *MAX(ar);
		int min = *MIN(ar);
		printf("%d %d\n", max, min);
	}
}

int* MAX(int ar[]) {
	int* max = ar;
	for (int* p = ar;; p++) {
		if (*p == 0)
			break;
		if (*p > *max) {
			max = p;
		}
	}
	return max;
}
int* MIN(int ar[]) {
	int* min = ar;
	for (int* p = ar;; p++) {
		if (*p == 0)
			break;
		if (*p < *min) {
			min = p;
		}
	}
	return min;
}