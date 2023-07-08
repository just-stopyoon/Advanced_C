#pragma warning(disable : 4996)
#include<stdio.h>

int main() {
	char x[51], y[51];
	scanf("%s", x);
	scanf("%s", y);

	for (char* p = x, *q = y; p != '\0'|| q != '\0'; p++, q++) {
		if (*p == *q) {
			continue;
		}
		else if (*p > *q) {
			printf("%s", x);
			printf("%s", y);
			break;
		}
		else {
			printf("%s", y);
			printf("%s", x);
			break;
		}
	}

	return 0;
}