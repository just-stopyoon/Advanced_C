#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	char ch[10];
	for (char* p = ch; p < ch + 10; p++) {
		scanf("%c", p);
	}
	int max = 0;
	int max_char = '0';

	for (char* p = ch; p < ch + 10; p++) {
		int cnt = 0;
		for (char* q = ch; q < ch + 10; q++) {
			if (*p == *q) {
				cnt++;
			}
		}
		if (cnt > max) {
			max = cnt;
			max_char = *p;
		}
	}
	printf("%c %d", max_char, max);
}