#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st {
	char* str; //문자열 저장
	int cnt1; //자음 수 저장
	int cnt2; //총 문자수 저장
	int num; //숫자 저장
	int pos; //위치 저장
	int result; //곱셈결과 저장
};

int main() {
	int N;
	scanf("%d", &N);
	getchar();
	struct st* s = (struct st*)malloc(N * sizeof(struct st));
	if (s == NULL) {
		printf("ERROR");
		exit(1);
	}
	for (struct st* p = s; p < s + N; p++) {
		int mom = 0;
		char tmp[101];
		scanf("%s", tmp);
		(*p).str = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
		if ((*p).str == NULL) {
			printf("ERROR");
			exit(1);
		}
		strcpy((*p).str, tmp);
		int length = strlen(p->str);
		int idx = 0;
		for (char* q = p->str; q < p->str + length; q++) {
			if (*q == 'a' || *q == 'e' || *q == 'i' || *q == 'o' || *q == 'u' || *q == 'A' || *q == 'E' || *q == 'I' || *q == 'O' || *q == 'U') {
				mom++;
			}
			p->cnt2 = length;
			p->cnt1 = length - mom - 1;
			idx++;
			if (*q - '0' >= 0 && *q - '0' <= 9) {
				(*p).num = *q - '0';
				(*p).pos = idx;
			}
		}
		(*p).result = (*p).num * (*p).pos * (*p).cnt1 * (*p).cnt2;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (s[j].result < s[j + 1].result) {
				struct st tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
	for (struct st* p = s; p < s + N; p++) {
		printf("%s\n", (*p).str);
	}
	for (int i = 0; i < N; i++) {
		free(s[i].str);
	}
	free(s);
}
