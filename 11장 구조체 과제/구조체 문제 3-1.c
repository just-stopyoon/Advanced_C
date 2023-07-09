#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct hotel_info {
	char name[31];
	int grade;
	double star;
	double distance;
	char bre;
};

int in_hotel_info(struct hotel_info* p);
void out_hotel_info(struct hotel_info* p, int N, int G, double D);


int main() {
	struct hotel_info hotel[101];
	int G;
	double D;
	int count = 0;
	count =	in_hotel_info(hotel);
	scanf("%d %lf", &G, &D);
	out_hotel_info(hotel, count, G, D);

	return 0;
}

int in_hotel_info(struct hotel_info* p) {
	int cnt = 0;
	for (struct hotel_info *h = p ; h < p + 100 ; h++) {
		scanf("%s", (*h).name);
		if (strcmp((*h).name, "0") == 0)
			break;
		scanf("%d %lf %lf %c", &(*h).grade, &(*h).star, &(*h).distance, &(*h).bre);
		getchar();
		cnt++;
	}
	return cnt;
}

void out_hotel_info(struct hotel_info* p, int N, int G, double D) {
	for (struct hotel_info* x = p; x < p + N; x++) {
		for (struct hotel_info* y = p; y < x; y++) {
			if ((*x).star > (*y).star) {
					struct hotel_info tmp = *x;
					*x = *y;
					*y = tmp;
			}
		}
	}
	for (struct hotel_info* x = p; x < p + N; x++) {
		for (struct hotel_info* y = p; y < x; y++) {
			if ((strcmp((*x).name, (*y).name) < 0) && ((*x).star == (*y).star)) {
				struct hotel_info tmp = *x;
				*x = *y;
				*y = tmp;
			}
		}
	}
	for (struct hotel_info* h = p; h < p + N; h++) {
		if ((*h).grade >= G && (*h).distance <= D) {
			printf("%s %d %0.1lf %0.1lf %c\n", (*h).name, (*h).grade, (*h).star, (*h).distance, (*h).bre);
			break;
		}
	}
}