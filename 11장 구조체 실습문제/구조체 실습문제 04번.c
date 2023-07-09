#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>

struct student {
	char name[20];
	int x, y, z;
	double average;
};

int main() {
	struct student st[20];
	int N;
	scanf("%d", &N);
	for (struct student* p = st; p < st + N; p++) {
		scanf("%s %d %d %d", &(*p).name, &(*p).x, &(*p).y, &(*p).z);
		(*p).average = ((*p).x +(*p).y +(*p).z) / 3.0;
		if ((*p).average >= 90)
			printf("%s %0.1lf A", (*p).name, (*p).average);
		else if ((*p).average >= 80 )
			printf("%s %0.1lf B", (*p).name, (*p).average);
		else if ((*p).average >= 70)
			printf("%s %0.1lf C", (*p).name, (*p).average);
		else
			printf("%s %0.1lf F", (*p).name, (*p).average);
	}
}