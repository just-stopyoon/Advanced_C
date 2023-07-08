#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	char ch[20];
	for (char* p = ch; p < ch + 20; p++) {
		scanf("%c", p);
		if (*p == '#') {
			for (char* q = p - 1; q >= ch; q--) {
				printf("%c", *q);
			}
			break;
		}
	}
}