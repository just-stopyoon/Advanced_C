#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	int arr[3];
	for (int* p = arr; p < arr + 3; p++) {
		scanf("%d", p);
	}
	for (int* p = arr; p < arr + 3; p++) {
		for (int* q = arr; q < p; q++) {
			if (*p < *q) {
				int tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}
	printf("%d", *(arr + 1));
}