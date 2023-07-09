#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	char a[101] = { 0 };
	char y[101] = { 0 };
	char b[11] = { 0 };
	char c[11] = { 0 };
	gets(a);
	int length_a = 0, length_b = 0, length_c = 0;
	scanf("%s", b);
	scanf("%s", c);
	length_a = strlen(a);
	length_b = strlen(b);
	length_c = strlen(c);

	int cnt = 0;

	for (char* p = a ; p < a + length_a ; p++) {
		if (strncmp(p, b, length_b) == 0) {
			strcat(y, c);
			p =p + length_b - 1;
			cnt += length_c;
		}
		else {
			y[cnt++] = *p;
		}
	}
		printf("%s", y);
	return 0;
}