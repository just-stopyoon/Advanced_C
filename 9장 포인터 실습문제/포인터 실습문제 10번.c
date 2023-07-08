#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

void gcdlcm(int a, int b, int* x, int* y);

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int x, y;
	gcdlcm(a, b, &x, &y);
	printf("%d %d", x, y);
}

void gcdlcm(int a, int b, int* x, int* y) {
	int great = 0, least = 0;
	if (a > b) {
		for (int i = 1; i <= b; i++) {
			if (a % i == 0 && b % i == 0) {
				great = i;
			}
		}
		for (int i = a; i <= a * b; i++) {
			if (i % a == 0 && i % b == 0) {
				least = i;
				break;
			}
		}
	}
	else {
		for (int i = 1; i <= a; i++) {
			if (a % i == 0 && b % i == 0) {
				great = i;
			}
		}
		for (int i = b; i <= a * b; i++) {
			if (i % a == 0 && i % b == 0) {
				least = i;
				break;
			}
		}
	}
	*x = great;
	*y = least;
}