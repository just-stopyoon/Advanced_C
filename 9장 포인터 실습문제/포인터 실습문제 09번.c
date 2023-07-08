#pragma warning(disable : 4996)
#include<stdio.h>

int mid(int x[]);

int main() {
	int x[3];
	int* p;
	for (int* p = x; p < x + 3; p++) {
		scanf("%d", p);
	}
	printf("%d", mid(x));
	return 0;
}

int mid(int x[]) {
	if (((*(x + 1) >= *x) && (*(x + 1) <= *(x + 2))) || ((*(x + 2) <= *(x + 1)) && (*(x + 1) <= *x)))
		return *(x + 1);
	else if (((*x >= *(x + 2)) && (*(x + 2) >= *(x + 1))) || ((*(x + 1) >= *(x + 2)) && (*(x + 2) >= *x)))
		return *(x + 2);
	else
		return *x;
}
