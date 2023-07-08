#pragma warning(disable : 4996)
#include<stdio.h>

int strlen(char *str);
int strcmp(char *str1, char *str2);

int main() {
	char str1[101], str2[101];
	scanf("%s", str1);
	scanf("%s", str2);

	printf("%d ", strlen(str1));
	printf("%d", strcmp(str1, str2));
	return 0;
}

int strlen(char *str) {
	int len = 0;
	while (str++) {
		len++;
		if (*str == '\0')
			break;
	}
	return len;
}

int strcmp(char *str1, char *str2) {
	if (strlen(str1) != strlen(str2))
		return 0;
	for (int i = 0; i <= strlen(str1); i++) {
		if (*(str1 + i) != *(str2 + i))
			return 0;
	}
	return 1;
}