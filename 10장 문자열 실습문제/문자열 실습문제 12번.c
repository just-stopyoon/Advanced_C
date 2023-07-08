#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	char str1[81], str2[11];
	int len_min = 0, len_max = 0, chk = 0;
	int len = 0, check = 0;

	gets(str1);
	scanf("%s", str2);


	if (strlen(str1) >= strlen(str2)) {
		len_min = strlen(str2);
		len_max = strlen(str1);
		chk = 1;
	}

	if (chk == 1) {
		for (char* p = str1; p < str1 + len_max; p++) {
			len = 0;
			for (char* q = str2, *r = p; q < str2 + len_min; q++, r++) {
				if (*r == *q) {
					len++;
					
				}
				if (len == len_min) {
					check++;
					p = p + len_min - 1;
				}
			}
		}
	}

	printf("%d", check);
	return 0;
}