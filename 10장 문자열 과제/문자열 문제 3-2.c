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
		if ((strncmp(p, y, strlen(y)) == 0) && !((*(p + strlen(y)) >= 'a') && (*(p + strlen(y)) <= 'z') || (*(p + strlen(y)) >= 'A' && *(p + strlen(y)) <= 'Z') || (*(p - 1) >= 'a' && *(p - 1) <= 'z') || (*(p - 1) >= 'A' && *(p - 1) <= 'Z')))
			cnt++;
	}
	printf("%d", cnt);



	return 0;
}