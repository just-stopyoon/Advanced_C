#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
	char name[10];
	int a;
	int b;
	int c;
	double average;
};

void read_data(struct student *st);
void cal_avg(struct student *st);
void sort(struct student *st);
void print_score(struct student *st);

int main() {
	struct student st[11];
	read_data(st);
	cal_avg(st);
	sort(st);
	print_score(st);
	return 0;
}

void read_data(struct student *st) {
	for (struct student* p = st; p < st + 10; p++) {
		scanf("%s %d %d %d", &(*p).name, &(*p).a, &(*p).b, &(*p).c);
	}
}

void cal_avg(struct student *st) {
	for (struct student* p = st; p < st + 10; p++) {
		int total = 0;
		total = (*p).a + (*p).b + (*p).c;
		(*p).average = total / 3.00;
	}
}

void sort(struct student *st) {
	for (struct student* p = st; p < st + 10; p++) {
		for (struct student* q = st; q < p; q++) {
			if ((*p).average > (*q).average) {
				struct student tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}
}

void print_score(struct student st[]) {
	printf("%s %.2f\n", st[0].name, st[0].average);
	printf("%s %.2f\n", st[9].name, st[9].average);
	printf("%s %.2f\n", st[7].name, st[7].average);
	printf("%s %.2f\n", st[8].name, st[8].average);
	printf("%s %.2f\n", st[9].name, st[9].average);
}