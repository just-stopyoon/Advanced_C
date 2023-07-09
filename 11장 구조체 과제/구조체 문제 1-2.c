#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h> 

struct student {
	char name[10];
	char num[11];
	char grade;
};


int main() {
	struct student st[5];
	char x[10];
	int chk = 11;
	for (int i = 0; i < 5; i++) {
		scanf("%s %s %c", &st[i].name, &st[i].num, &st[i].grade);
	}
	scanf("%s", x);
	for (int i = 0; i < 5; i++) {
		if (strcmp(st[i].name, x) == 0) {
			chk = i;
		}
	}
	int year = atoi(st[chk].num) / 1000000;
	int check = 0;
	for (int i = 0; i < 5; i++) {
		if (i == chk)
			continue;
		if (st[i].grade == st[chk].grade && year == atoi(st[i].num) / 1000000) {
			printf("%s ", st[i].name);
			check = 1;
		}
	}
	if (check == 0) {
		printf("0");
	}

	printf("\n");
	int result = year % 131;
	printf("%d %d", year, result);
	return 0;
}