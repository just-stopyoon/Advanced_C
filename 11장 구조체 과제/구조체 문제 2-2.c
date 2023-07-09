#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct student {
	char name[21];
	int kor, eng, math;
	double avg;
};

void read_data(struct student* st, int N);
void sort_score(struct student* st, int N);
struct student *select_out(struct student* st1, struct student* st2, int N);


int main() {
	struct student st1[50], st2[50];
	int N;
	scanf("%d", &N);
	getchar();
	read_data(st1, N);
	read_data(st2, N);
	sort_score(st1, N);
	sort_score(st2, N);
	struct student *st = select_out(st1, st2, N);
	for (struct student* p = st; p < st + N; p++) {
		printf("%s %d %d %d %0.1f\n", p->name, p->kor, p->eng, p->math, p->avg);
	}
	

	return 0;
}

void read_data(struct student* st, int N) {
	for (struct student *p = st ; p < st + N; p++) {
		scanf("%s %d %d %d", &(*p).name, &(*p).kor, &(*p).eng, &(*p).math);
		getchar();
		(*p).avg = ((*p).kor + (*p).eng + (*p).math) / 3.0 ;
	}
}
void sort_score(struct student* st, int N) {
	for (struct student* p = st; p < st + N; p++) {
		for (struct student* q = st; q < st + N; q++) {
			if ((*p).avg > (*q).avg) {
				struct student tmp = *p;
				*p = *q;
				*q = tmp;
			}
			if ((*p).avg == (*q).avg) {
				if ((*p).kor > (*q).kor) {
					struct student tmp = *p;
					*p = *q;
					*q = tmp;
				}
			}
			if ((*p).avg == (*q).avg && (*p).kor == (*q).kor) {
				if ((*p).eng > (*q).eng) {
					struct student tmp = *p;
					*p = *q;
					*q = tmp;
				}
			}
			if ((*p).avg == (*q).avg && (*p).kor == (*q).kor && (*p).eng == (*q).eng) {
				if ((*p).math > (*q).math) {
					struct student tmp = *p;
					*p = *q;
					*q = tmp;
				}
			}
		}
	}
}

struct student *select_out(struct student* st1, struct student* st2, int N){
	int mid = (N - 1) / 2;

	if (st1[mid].avg > st2[mid].avg)
		return st1;
	else
		return st2;
}
