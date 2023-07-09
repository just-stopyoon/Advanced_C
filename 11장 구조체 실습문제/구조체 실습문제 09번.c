#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>

struct student {
	int high;
	int low;
	char pass;
	int pass_gap;
	int score_gap;
};

struct student* passorfail(struct student* x);

int main() {
	struct student x[1];
	scanf("%d %d %d", &x->high, &x->low, &x->pass_gap);
	passorfail(x);
	printf("%d %c", x->score_gap, x->pass);
}

struct student* passorfail(struct student* x) {
	(*x).score_gap = (*x).high - (*x).low;
	if ((*x).pass_gap >= (*x).score_gap) {
		(*x).pass = 'P';
	}
	else {
		(*x).pass = 'F';
	}
}