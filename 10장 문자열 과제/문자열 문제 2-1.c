#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	char x[201] = { 0 };
	char y[21][201];
	char z[10000];
	int index = 0;
	gets(x);
	char* p = x;
	
	for (index = 0; index < 21; index++) {
		for (int i = 0; i < 201; i++) {
			if (*p == ' ' || *p == '\0') {
				y[index][i] = '\0';
				p++;
				break;
			}
			y[index][i] = *p;
			p++;
		}
		if (*(p-1) == '\0')
			break;
	}
	for (int i = 0; i <= index; i++) {
		printf("%s", y[i]);
		printf("\n");
	}
	char tmp[201] = { 0 };

	for (int i = 0; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (strcmp(y[i], y[j]) > 0) {
				strcpy(tmp, y[i]);
				strcpy(y[i], y[j]);
				strcpy(y[j], tmp);


			}
		}
	}
	for (int i = 0; i <= index; i++) {
		printf("%s ", y[i]);	
	}
	return 0;
}