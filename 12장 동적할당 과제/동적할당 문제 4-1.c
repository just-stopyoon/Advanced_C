#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st {
	char* name; // 이름 저장
	int s1; // 1단계 점수 저장
	int s2; // 면접 점수 저장
	double sum; // 총점 저장
};

//1단계 70 + 2단계 30
//1단계 합격자 N명 최종 M명 선발
//총점 높은 부터 낮은

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	getchar();
	struct st* s = (struct st*)malloc(N * sizeof(struct st));
	if (s == NULL) {
		printf("ERROR");
		exit(1);
	}
	for (struct st* p = s; p < s + N; p++) {
		int mom = 0;
		char tmp[101];
		scanf("%s %d %d", tmp, &(*p).s1, &(*p).s2);
		(*p).name = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
		if ((*p).name == NULL) {
			printf("ERROR");
			exit(1);
		}
		strcpy((*p).name, tmp);
		(*p).sum = (*p).s1 * 0.7 + (*p).s2 * 0.3;
	}

	for (struct st* p = s; p < s + N; p++) {
		for (struct st* q = s; q < p; q++) {
			if ((*p).sum > (*q).sum) {
				struct st ttmp = *p;
				*p = *q;
				*q = ttmp;
			}
		}
	}
	for (struct st* p = s; p < s + M; p++)
		printf("%s %.1lf\n", (*p).name, (*p).sum);

	for (int i = 0; i < N; i++) {
		free(s[i].name);
	}
	free(s);
}
