#pragma warning(disable : 4996)
#include<stdio.h>

int main() {
	char str[21];
	scanf("%s", str);

	for (int i = 0; i <= 21; i++) {
		if (*(str + i) >= 'a' && *(str + i) <= 'z')
			printf("%c", *(str + i));
		if (*(str + i) == '/0')
			break;
	}
	return 0;
}