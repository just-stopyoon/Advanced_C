#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N;
	int cnt = 0;
	scanf("%d", &N);
	char* x = (char*)malloc(N * sizeof(char));
	scanf("%s", x);
	for (char* p = x; p < x + N; p++) {
		if (strncmp(p, "cat", 3) == 0) {
			cnt++;
		}
	}
	printf("%d", cnt);
}