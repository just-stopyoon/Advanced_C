#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int input(int* p);
int* sel_next(int* p, int N, int M);
int number(int* p, int* q);

int main() {
	int x[101]; //배열
	int N = 0; //배열 원소의 개수
	int M;
	int* p; //x[M]의 위치
	int* q; //sel_next에서 반환된 위치
	int total = 0; //결과값
	N = input(x);
	scanf("%d", &M);
	p = x + M;
	q = sel_next(x, N, M);
	total = number(p, q);
	printf("%d", total);
}

int input(int* p) {
	int num = 0; //배열 원소의 개수
	while (1) {
		scanf("%d", p);
		if (*p == -1)
			break;
		p++;
		num++;
	}
	return num;
}
int* sel_next(int* p, int N, int M) { 
	int* last = 0; //원소 값의 증가가 끝나는 마지막 원소의 주소
	for (int* x = p + M; x < p + N; x++) {
		if (*x < *(x + 1)) {
			continue;
		}
		else {
			last = x;
			break;
		}
	}
	return last;
}
int number(int* p, int* q) {
	int result = 0; //두 포인터 사이의 한 자리 정수를 모은 정수
	for (int* x = p; x <= q; x++) {
		result = result * 10 + *x;
	}
	return result;
}