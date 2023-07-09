#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	int len = 0;
	char ttmp[101];
	char ** x = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		scanf("%s", ttmp);
		getchar();
		len = strlen(ttmp);
		x[i] = (char*)malloc((len+1) *sizeof(char));
		strcpy(x[i], ttmp);
	}
	char *tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (strcmp(x[i], x[j]) < 0) {
				tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%s\n", x[i]);
	}
}