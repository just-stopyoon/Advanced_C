#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int input(int* p);
int* sel_next(int* p);
int number(int* p, int* q);

int main() {
	int x[101]; //배열
	int N = 0; //배열 원소의 개수
	int* p; //x[M]의 위치
	int* q; //sel_next에서 반환된 위치
	int total = 0; //결과값
	N = input(x);

	for (int *i = x ; i < x + N - 1; i++){
		q = sel_next(i);
		total = number(i, q);
		printf("%d\n", total);
		i = q - 1;
	}
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

int* sel_next(int* p) {
	int* last = 0; //원소 값의 증가가 끝나는 마지막 원소의 주소
	int* x;
	int check = 0;
	for (x = p ; *(x+1) != -1 ; x++) {
		if (check != 2 && *x < *(x + 1)) {
			check = 1;
			continue;
		}
		else if (check != 1 && (*x > *(x + 1))){
			check = 2;
			continue;
		}
		else {
			last = x;
			break;
		}
	}
	if (*(x + 1) == -1) {
		return x;
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