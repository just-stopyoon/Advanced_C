#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
	char* name; // 이름 저장
	int test1; // 1단계 점수 저장
	int test2; // 면접 점수 저장
	double sum; // 총점 저장
};

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	struct student* st = (struct student*)malloc(N * sizeof(struct student));
	for (struct student* p = st; p < st + N; p++) {
		char tmp[101] = { 0 };
		scanf("%s %d %d", tmp, &(*p).test1, &(*p).test2);
		(*p).name = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
		strcpy((*p).name, tmp);
		(*p).sum = ((*p).test1 * 7 + (*p).test2 * 3) * 1.0;
		(*p).sum = (*p).sum / 10;
	}
	for (struct student* p = st; p < st + N; p++) {
		for (struct student* q = st; q < p; q++) {
			if ((*p).sum > (*q).sum) {
				struct student tmp = *p;
				*p = *q;
				*q = tmp;
			}
			else if ((*p).sum == (*q).sum && (*p).test1 > (*q).test1) {
				struct student tmp = *p;
				*p = *q;
				*q = tmp;
			}
			else if ((*p).sum == (*q).sum && (*p).test1 == (*q).test1 && strcmp((*p).name, (*q).name) < 0) {
				struct student tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}

	int cnt = M;
	for (int i = cnt - 1; i < cnt; i++) {
		if (st[i].test2 == st[i + 1].test2 && st[i].test1 == st[i + 1].test1)
			cnt++;
	}

	for (struct student* p = st; p < st + cnt; p++) {
		printf("%s %d %d %.1lf\n", (*p).name, (*p).test1, (*p).test2, (*p).sum);
	}
	printf("%d", cnt);
}

