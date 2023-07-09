#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct date {
	int year;
	int month;
	int day;
};

struct date* select_min(struct date* st1, struct date* st2);

int main() {
	struct date st1[1], st2[1];
	scanf("%d/%d/%d", &st1[0].year, &st1[0].month, &st1[0].day);
	scanf("%d/%d/%d", &st2[0].year, &st2[0].month, &st2[0].day);
	struct date* p = select_min(st1, st2);
	printf("%d/%d/%d", (*p).year, (*p).month, (*p).day);
	return 0;
}

struct date* select_min(struct date* st1, struct date* st2) {
	if ((*st1).year < (*st2).year) {
		return st1;
	}
	else if ((*st1).year > (*st2).year) {
		return st2;
	}
	else {
		if ((*st1).month < (*st2).month) {
			return st1;
		}
		else if ((*st1).month > (*st2).month) {
			return st2;
		}
		else {
			if ((*st1).day < (*st2).day) {
				return st1;
			}
			else if ((*st1).day > (*st2).day) {
				return st2;
			}
			else
				return st1;
		}
	}
}
