#pragma warning(disable : 4996)
#include<stdio.h>

int *max(int ar[]);
int *min(int ar[]);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int ar[100] = { 0 };
		int j = 0;
		for (int* j = ar; j < ar + 100; j++) {
			scanf("%d", j);
			if (*j == 0)
				break;
		}
		int chk = 0;
		if (max(ar) < min(ar)) {
			for (int* p = max(ar)+1; p < min(ar); p++) {
				printf("%d ", *p);
				chk = 1;
			}
		}
		else if (max(ar) > min(ar)) {
			for (int* p = min(ar)+1; p < max(ar); p++) {
				printf("%d ", *p);
				chk = 1;
			}
		}
		if (chk == 0)
			printf("none");
	}
	return 0;
}

int* max(int ar[]) {
	int* max;
	max = ar;
	for (int* i = ar;; i++) {
		if (*i == 0) break;
		if (*max < *i)
			max = i;
	}
	return (max);
}
int* min(int ar[]) {
	int* min;
	min = ar;
	for (int* i = ar; ; i++) {
		if (*i == 0) break;
		if (*min > *i)
			min = i;
	}
	return (min);
}