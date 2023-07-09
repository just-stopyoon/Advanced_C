#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
	char name[10];
	int score;
};

struct student *select_min(struct student* st);

int main() {
	struct student st[5];
	for (struct student* p = st; p < st + 5; p++) {
		scanf("%s %d", &(*p).name, &(*p).score);
	}
	struct student* p = select_min(st);
	printf("%s %d", (*p).name, (*p).score);
	return 0;
}

struct student *select_min(struct student* st) {
	int min = 100;
	struct student *tmp = st;
	for (struct student* p = st; p < st + 5; p++) {
		if ((*p).score < min) {
			min = (*p).score;
			tmp = p;
		}
	}
	return tmp;
}
