#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	char x[201] = { 0 };
	char x1[201] = { 0 };
	char y[21][201];
	char z[10000] = { 0 };
	int index = 0;
	gets(x);
	scanf("%s", x1);
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

	int chk = 0;

	for (int i = 0; i <= index; i++) {
		if (strcmp (y[i], x1) == 0) {
			chk = 1;
		}
		printf("%s\n", y[i]);
	}
	if (chk == 0) {
		printf("%s\n", x1);
		strcpy(y[++index], x1);
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
		strcat(z, y[i]);
		strcat(z, " ");
	}

	printf("%s", z);

	return 0;
}