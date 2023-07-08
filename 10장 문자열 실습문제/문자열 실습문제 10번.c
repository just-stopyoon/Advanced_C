#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>


int main() {
	int n, min = 101;
	char x[101], y[101];
	
	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++) {
		gets(x);
		if (min > strlen(x)) {
			min = strlen(x);
			strcpy(y, x);
		}
	}
	printf("%s", y);


	return 0;
}