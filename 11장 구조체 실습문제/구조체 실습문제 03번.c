#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>

struct student {
	char name[10];
	int score;
};

int main() {
	struct student st[5];
	int total = 0;
	for (struct student* p = st; p < st + 5; p++) {
		scanf("%s %d", &(*p).name, &(*p).score);
		total += (*p).score;
	}
	int average = total / 5;
	for (struct student* p = st; p < st + 5; p++) {
		if ((*p).score <= average) {
			printf("%s\n", (*p).name);
		}
	}
}
