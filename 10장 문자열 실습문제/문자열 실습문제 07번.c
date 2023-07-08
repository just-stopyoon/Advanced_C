#pragma warning(disable : 4996)
#include<stdio.h>

int main() {
	int N;
	char x[10][100] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char y[5][100] = { "THO", "HUN", "TEN", "" };

	int a = 1, chk ;

	scanf("%d", &N);

	for (int i = 1000, j = 0 ; i != 0 ; i /= 10, j++){
		a = N / i;
		if (a != 0)
			printf("%s %s ", x[a-1], y[j]);
		N = N % i;
	}
	return 0;
}