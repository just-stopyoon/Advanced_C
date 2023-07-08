#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>

int main() {
	char str[101], tmp;
	scanf("%s", str);
	
	for (int i = 0 ; i < strlen(str) ; i++){
		printf("%s\n", str);
		for (int j = 0; j < strlen(str); j++) {
			if (j == 0) {
				tmp = *str;
				*(str + j) = *(str + j + 1);
			}
			else if (j == strlen(str)-1) {
				*(str + j) = tmp;
			}
			else {
				*(str + j) = *(str + j + 1);

			}
		}
	}
}