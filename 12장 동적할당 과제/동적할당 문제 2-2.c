#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	char tmp1[101], tmp2[100];
	gets(tmp1);
	int len1 = strlen(tmp1);
	char* p1 = tmp1;
	gets(tmp2);
	int len2 = strlen(tmp2);
	char* p2 = tmp2;
	int cnt1 = 1;
	int cnt2 = 1;

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


	char* ttmp;
	for (int i = 0; i < cnt1; i++) {
		for (int j = 0; j < i; j++) {
			if (strlen(arr1[i]) > strlen(arr1[j])) {
				ttmp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = ttmp;
			}
			else if (strlen(arr1[i]) == strlen(arr1[j])) {
				if (strcmp(arr1[i], arr1[j]) < 0) {
					ttmp = arr1[i];
					arr1[i] = arr1[j];
					arr1[j] = ttmp;
				}
			}
		}
	}
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

	for (int i = 0; i < cnt1; i++) {
		for (int j = 0; j < cnt2; j++) {
			if (strcmp(arr1[i], arr2[j]) == 0) {
				printf("%s\n", arr1[i]);
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
}