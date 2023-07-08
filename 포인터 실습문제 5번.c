#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	int arr[5];
	int rank[5];
	for (int* p = arr; p < arr + 5; p++) {
		scanf("%d", p);
	}
	for (int* p = rank, *q = arr; p < rank + 5, q < arr + 5; p++, q++) {
		*p = *q;
	}
	for (int* p = rank; p < rank + 5; p++) {
		for (int* q = rank; q < p; q++) {
			if (*p > *q) {
				int tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}
	for (int* p = arr; p < arr + 5; p++) {
		int cnt = 0;
		for (int* q = rank; q < rank + 5; q++) {
			cnt++;
			if (*p == *q) {
				printf("%d=r%d ", *p, cnt);
				break;
			}
		}
	}
}