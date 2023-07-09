#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct person { //지원자 구조체
	char name[11]; //이름
	int test1;
	int test2;
	double score;
};

void swap(struct person* p, struct person* q);

int main() {
	struct person ap1[101], ap2[101];
	int N, M; //지원자 합격자
	scanf("%d %d", &N, &M);
	for (struct person* p = ap1; p < ap1 + N; p++) {
		scanf("%s %d %d", (*p).name, &(*p).test1, &(*p).test2);
		(*p).score = (0.8 * (*p).test1) + (0.2 * (*p).test2);
	}
	for (struct person* p = ap1; p < ap1 + N; p++) {
		for (struct person* q = ap1; q < p; q++) {
			swap(p, q);
		}
	}
	for (struct person* p = ap1; p < ap1 + M; p++) {
		printf("%s %.1f\n", (*p).name, (*p).score);
	}
	return 0;
}

void swap(struct person* p, struct person* q) {
	if ((*p).score > (*q).score) {
		struct person tmp = *p;
		*p = *q;
		*q = tmp;
	}
	else if ((*p).score == (*q).score) {
		if ((*p).test1 > (*q).test1) {
			struct person tmp = *p;
			*p = *q;
			*q = tmp;
		}
	}
}
