#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

void strcopy(char x[], char y[]);

int main() {
	char x[6], y[6];
	for (char* p = x; p < x + 6; p++) {
		scanf("%c", p);
	}
	strcopy(x, y);
	for (char* p = y; p < y + 6; p++) {
		printf("%c", *p);
	}
}

void strcopy(char x[], char y[]) {
	for (char* p = x, *q = y; p < x + 6, q < y + 6; p++, q++) {
		*q = *p;
	}
}