#pragma warning(disable : 4996)
#include<stdio.h>

int strlen(char* str);
int chk (char *st);

int main() {
	char x[31];
	scanf("%s", x);
	printf("%d %d", strlen(x), chk(x));
	return 0;
}

int chk(char* st) {
	int check = 0;
	for (int i = 0; i < strlen(st); i++) {
		if (*(st + i) == *(st + strlen(st) - 1 - i)) {
			check = 1;
		}
		else {
			check = 0;
			break;
		}
	}
	if (check == 1)
		return 1;
	else
		return 0;
}

int strlen(char* str) {
	int len = 0;
	while (str++) {
		len++;
		if (*str == '\0')
			break;
	}
	return len;
}