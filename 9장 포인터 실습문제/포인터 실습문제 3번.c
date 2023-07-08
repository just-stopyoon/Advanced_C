#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	int N;
	scanf("%d", &N);
	int arr[50];
	int cnt = 0, result = 0;
	for (int* p = arr; p < arr + N; p++) {
		scanf("%d", p);
		cnt++;
		if (*p == 0) {
			result = cnt - 1;
		}
	}
	printf("%d", result);
}