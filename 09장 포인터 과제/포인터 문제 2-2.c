#pragma warning(disable : 4996)
#include<stdio.h>

int passengerN(int n);
int rebooking(int* ar);
int changeseat(int* ar);

int main() {
	int N;
	int ar[22] = { 0 };

	scanf("%d", &N);
	for (int* p = ar; p < ar + N; p++) {
		scanf("%d", p);
	}

	printf("%d", passengerN(N));
	printf("\n");

	if (passengerN(N) == 0) {
		rebooking(ar);
		for (int* p = ar; p < ar + N; p++)
			printf("%d ", *p);
	}
	return 0;
}

int passengerN(int n) {
	if (n < 5)
		return -1;
	else
		return 0;
}

int rebooking(int* ar) {
	for (int* p = ar; *p != 0; p++){
		for (int* q = p + 1; *q != 0; q++) {
			if (*p == *q) {
				*q = changeseat(ar);
			}
		}
	}
}

int changeseat(int* ar) {
	int num = 1;
	for (int* p = ar; *p != 0; p++) {
		if (num == *p) {
			num++;
			p = ar;
		}
	}
	return num;
}
