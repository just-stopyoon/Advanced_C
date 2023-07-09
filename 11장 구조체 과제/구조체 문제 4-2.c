#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct parking_info {
	int carnum; //차량 번호
	int phone; //고객 전화번호
	char sub; //상품 (S/D)
	char month; //정기권 가입유무 (Y/N)
	int day; //정기권 종류 (7/30/180)
	int parking; //주차시간
	double money; //요금
};

void input(struct parking_info* p, int N);
void compute(struct parking_info* p);
void display(struct parking_info* p, int N);
void parking_info_sort(struct parking_info* p, int N);

int main() {
	struct parking_info st[101];
	int N;
	double total_S = 0;
	double total_D = 0;
	double total = 0;
	scanf("%d", &N);
	input(st, N);
	for (struct parking_info* h = st; h < st + N; h++) {
		compute(h);
		if ((*h).sub == 'S') {
			total_S = total_S + (*h).money;
		}
		else {
			total_D = total_D + (*h).money;
		}
	}
	parking_info_sort(st, N);
	display(st, N);
	total = total_D + total_S;
	printf("%.f %.f %.f", total_D, total_S, total);
}

void input(struct parking_info* p, int N) {
	for (struct parking_info* h = p; h < p + N; h++) {
		scanf("%d %d %c", &(*h).carnum, &(*h).phone, &(*h).sub);
		getchar();
		if ((*h).sub == 'D') {
			scanf("%d", &(*h).parking);
			getchar();
		}
		else {
			scanf("%c %d %d", &(*h).month, &(*h).day, &(*h).parking);
			getchar();
		}
	}
}

void compute(struct parking_info* p) {
	if ((*p).sub == 'S' && (*p).month == 'N') {
		//종류별에 따른 가입비용을 대여비용에 합산
		if ((*p).day == 7) {
			(*p).money = 30000;
		}
		if ((*p).day == 30) {
			(*p).money = 100000;
		}
		if ((*p).day == 180) {
			(*p).money = 500000;
		}
		if ((*p).parking > 240) {
			(*p).money = (*p).money + (((*p).parking - 240) / 10) * 200;
		}
	}
	if ((*p).sub == 'S' && (*p).month == 'Y') {
		//종류에 따른 일자를 초과하지 않으면서 4시간을 넘지 않으면 비용이 청구되지 않음
		if ((*p).parking <= 240) {
			(*p).money = 0;
		}
		if ((*p).parking > 240) {
			(*p).money = (*p).money + (((*p).parking - 240) / 10) * 200;
		}
	}
	if ((*p).sub == 'D') {
		(*p).money = 5000;
		if ((*p).parking > 240) {
			(*p).money = (*p).money + (((*p).parking - 240) / 10) * 200;
		}
	}
}

void display(struct parking_info* p, int N) {
	for (struct parking_info* h = p; h < p + N; h++) {
		printf("%d %d %c %.f\n", (*h).carnum, (*h).phone, (*h).sub, (*h).money);
	}
}

void parking_info_sort(struct parking_info* p, int N) {
	for (struct parking_info* x = p; x < p + N; x++) {
		for (struct parking_info* y = p; y < x; y++) {
			if ((*x).sub < (*y).sub) {
				struct parking_info tmp = *x;
				*x = *y;
				*y = tmp;
			}
		}
	}
	for (struct parking_info* x = p; x < p + N; x++) {
		for (struct parking_info* y = p; y < x; y++) {
			if (((*x).sub == (*y).sub) && ((*x).carnum < (*y).carnum)) {
				struct parking_info tmp = *x;
				*x = *y;
				*y = tmp;
			}
		}
	}
}
