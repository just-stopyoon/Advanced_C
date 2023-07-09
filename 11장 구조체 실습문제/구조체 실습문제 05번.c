#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>

struct student {
	char name[8];
	int kor, eng, math;
	double average;
	char grade;
};

int main() {
	struct student st[50];
	int N;
	scanf("%d", &N);
	for (struct student* p = st; p < st + N; p++) {
		scanf("%s %d %d %d", &(*p).name, &(*p).kor, &(*p).eng, &(*p).math);
		(*p).average = ((*p).kor + (*p).eng + (*p).math) / 3.0;
		if ((*p).average >= 90)
			(*p).grade = 'A';
		else if ((*p).average >= 80)
			(*p).grade = 'B';
		else if ((*p).average >= 70)
			(*p).grade = 'C';
		else
			(*p).grade = 'D';
	}
	for (struct student* p = st; p < st + N; p++) {
		printf("%s %0.1lf %c\n", (*p).name, (*p).average, (*p).grade);
	}
}