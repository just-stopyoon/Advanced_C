#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st {
	char* str; //문자열 저장
	int cnt1; //자음 수 저장
	int cnt2; //총 문자수 저장
};

//정수 N 입력
//문자열 최대 길이 100, 구조체 배열, 문자열 배열 동적할당
//반드시 메모리 해제
//공백을 포함하지 않은 N개의 문자열 입력 받기
//각 문자열에 포함된 자음의 수 세기
//자음의 수가 가장 많은 것부터 내림차순 정렬 > 순서대로 문자열 출력
//자음의 수가 같다면 총 문자수가 많은 것부터 출력
//자음, 문자수 같다면 먼저 입력된 순

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
		for (char* q = p->str; q < p->str + length; q++) {
			if (*q == 'a' || *q == 'e' || *q == 'i' || *q == 'o' || *q == 'u' || *q == 'A' || *q == 'E' || *q == 'I' || *q == 'O' || *q == 'U') {
				mom++;
			}
			p->cnt2 = length;
			p->cnt1 = length - mom;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (s[j].cnt1 < s[j + 1].cnt1) {
				struct st tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
			else if (s[j].cnt1 == s[j + 1].cnt1) {
				if (s[j].cnt2 < s[j + 1].cnt2) {
					struct st tmp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = tmp;
				}
			}
		}
	}
	for (struct st* p = s ; p < s + N; p++) {
		printf("%s\n", (*p).str);
	}

	for (int i = 0; i < N; i++) {
		free(s[i].str);
	}
	free(s);
}