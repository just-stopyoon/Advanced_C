#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	char x[101] = { 0 };
	char y[101] = { 0 };
	gets(x);
	scanf("%s", y);
	int cnt = 0;

	for (char* p = x; p < x + strlen(x); p++) {
		if (strncmp(p, y, strlen(y)) == 0)
			cnt++;
	}
	printf("%d", cnt);



	return 0;
}