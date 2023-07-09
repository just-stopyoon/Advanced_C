#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char tmp1[101], tmp2[100];
	gets(tmp1);
	gets(tmp2);
	int len1 = strlen(tmp1), len2 = strlen(tmp2);
	char* p1 = tmp1, * p2 = tmp2;
	int cnt1 = 1, cnt2 = 1;

	for (char* p = tmp1; p < tmp1 + len1; p++) {
		if (*p == ' ') {
			*p = '\0';
			cnt1++;
		}
	}

	for (char* p = tmp2; p < tmp2 + len2; p++) {
		if (*p == ' ') {
			*p = '\0';
			cnt2++;
		}
	}

	char** arr1 = (char**)malloc(cnt1 * sizeof(char*));
	if (arr1 == NULL) {
		printf("ERROR");
		exit(1);
	}
	char** arr2 = (char**)malloc(cnt2 * sizeof(char*));
	if (arr2 == NULL) {
		printf("ERROR");
		exit(1);
	}

	for (int i = 0; i < cnt1; i++) {
		arr1[i] = (char*)malloc((strlen(p1) + 1) * sizeof(char));
		if (arr1[i] == NULL) {
			printf("ERROR");
			exit(1);
		}
		strcpy(arr1[i], p1);
		p1 = p1 + strlen(p1) + 1;
	}

	for (int i = 0; i < cnt2; i++) {
		arr2[i] = (char*)malloc((strlen(p2) + 1) * sizeof(char));
		if (arr2[i] == NULL) {
			printf("ERROR");
			exit(1);
		}
		strcpy(arr2[i], p2);
		p2 = p2 + strlen(p2) + 1;
	}

	char** arr3 = (char**)malloc((cnt1 * cnt1 - cnt1) * sizeof(char*));
	if (arr3 == NULL) {
		printf("ERROR");
		exit(1);
	}
	int idx = 0;

	for (int i = 0; i < cnt1; i++) {
		for (int j = 0; j < cnt1; j++) {
			int length = strlen(arr1[i]) + strlen(arr1[j]);
			if (i != j) {
				arr3[idx] = (char*)malloc((length + 1) * sizeof(char*));
				strcpy(arr3[idx], arr1[i]);
				strcat(arr3[idx++], arr1[j]);
			}
		}
	}
	char *ttmp;
	for (int i = 0; i < cnt2; i++) {
		for (int j = 0; j < i; j++) {
			if (strlen(arr2[i]) > strlen(arr2[j])) {
				ttmp = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = ttmp;
			}
			else if (strlen(arr2[i]) == strlen(arr2[j])) {
				if (strcmp(arr2[i], arr2[j]) < 0) {
					ttmp = arr2[i];
					arr2[i] = arr2[j];
					arr2[j] = ttmp;
				}
			}
		}
	}

	for (int i = 0; i < cnt2 ; i++) {
		for (int j = 0; j < idx; j++) {
			if (strcmp(arr3[j], arr2[i]) == 0) {
				printf("%s\n", arr2[i]);
				strcpy(arr2[i], " ");
			}
		}
	}

	for (int i = 0; i < cnt1; i++) {
		free(arr1[i]);
	}
	free(arr1);

	for (int i = 0; i < cnt2; i++) {
		free(arr2[i]);
	}
	free(arr2);

	for (int i = 0; i < idx; i++) {
		free(arr3[i]);
	}
	free(arr3);
}