#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char name[8];
	int kor;
	int eng;
	int math;
	double score;
}st;

int main() {
	int N;
	scanf("%d", &N);

	st* s = (st*)malloc(N * sizeof(st));

	for (st* p = s; p < s + N; p++) {
		scanf("%s %d %d %d", (*p).name, &(*p).kor, &(*p).eng, &(*p).math);
		(*p).score = (*p).kor + (*p).eng + (*p).math;
		printf("%s %.1lf", (*p).name, (*p).score/3.0);
		if ((*p).kor >= 90 || (*p).eng >= 90 || (*p).math >= 90)
			printf(" GREAT");
		if ((*p).kor < 70 || (*p).eng < 70 || (*p).math < 70)
			printf(" BAD");
		printf("\n");
	}

}