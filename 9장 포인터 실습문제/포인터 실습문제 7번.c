#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

void input(int* x, int* y, int* z);
void output(int* x, int* y, int* z);

int main() {
	int x, y, z;
	input(&x, &y, &z);
	output(&x, &y, &z);
}

void input(int* x, int* y, int* z) {
	scanf("%d %d %d", x, y, z);
}

void output(int* x, int* y, int* z) {
	printf("%d %d %d", *x, *y, *z);
}