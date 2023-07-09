#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>

struct data {
	int a;
	int rank;
};

int main() {
	struct data x[10];
	for (struct data* p = x; p < x + 10; p++) {
		scanf("%d", &(*p).a);
		(*p).rank = 1;
	}

	for (struct data* p = x; p < x + 10; p++) {
		for (struct data* q = x; q < x + 10; q++) {
			if ((*p).a < (*q).a) {
				(*p).rank += 1;
			}
		}
	}
	for (struct data* p = x; p < x + 10; p++) {
		if ((*p).rank == 3)
			printf("%d", (*p).a);
	}
	for (struct data* p = x; p < x + 10; p++) {
		if ((*p).rank == 7)
			printf(" %d", (*p).a);
	}
}