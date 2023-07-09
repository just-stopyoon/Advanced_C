#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//공백 포함 문자열 하나
//입력받은 문자열 단어로
//이차원 동적할당에 저장

int main() {
	char tmp[101];
	char* p = tmp; 
	int cnt = 1;
	gets(tmp);
	int len = strlen(tmp);

	for (int i = 0; i < len; i++) {
		if (tmp[i] == ' ') { 
			tmp[i] = '\0';
			cnt++;
		}
	}

	char** arr = (char**)malloc(cnt * sizeof(char*));
    if (arr == NULL) {
        printf("ERROR");
        exit(1);
    }

	for (int i = 0; i < cnt; i++) {
		arr[i] = (char*)malloc((strlen(p) + 1) * sizeof(char));
        if (arr[i] == NULL) {
            printf("ERROR");
            exit(1);
        }
		strcpy(arr[i], p);
		p = p + strlen(p) + 1;
	}
    char* ttmp;

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < i; j++) {
            if (strlen(arr[i]) > strlen(arr[j])) {
                ttmp = arr[i];
                arr[i] = arr[j];
                arr[j] = ttmp;
            }
            else if (strlen(arr[i]) == strlen(arr[j])) {
                if (strcmp(arr[i], arr[j]) < 0) {
                    ttmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = ttmp;
                }
            }
        }
    }
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", arr[i]);
    }

    for (int i = 0; i < cnt; i++) {
        free(arr[i]);
    }
    free(arr);
}