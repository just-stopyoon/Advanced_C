#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

struct student {
	char name[10];
	char num[11];
	char grade;
};


int main() {
	struct student st[5];
	char x[10];
	for (int i = 0; i < 5; i++) {
		scanf("%s %s %c", &st[i].name, &st[i].num, &st[i].grade);
	}
	scanf("%s", x);
	for (int i = 0; i < 5; i++) {
		if (strcmp(st[i].name, x) == 0) {
			printf(" %s %c", st[i].num, st[i].grade);
		}
	}

	return 0;
}