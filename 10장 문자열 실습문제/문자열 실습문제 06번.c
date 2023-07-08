#pragma warning(disable : 4996)
#include<stdio.h>

int strlen(char* str);

int main() {
	char str1[42] = { ' ' }, str2[21];
	scanf("%s", str1);
	scanf("%s", str2);

	int a, n;
	scanf("%d", &a);
	scanf("%d", &n);

	int len1, len2;
	len1 = strlen(str1);
	len2 = strlen(str2);

	for (char* p = str1 + len1 - 1; p > str1 + a - 1; p--) {
		*(p + len2) = *p;
	}
	if (n == 1 && len2 > 1) {
		for (int i = 0; i < len2; i++) {
			*(str1 + a + len2 - i - 1) = *(str2 + i);
		}
	}
	else {
		for (int i = 0; i < len2; i++) {
			*(str1 + a +i) = *(str2 + i);
		}
	}
	printf("%s", str1);


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