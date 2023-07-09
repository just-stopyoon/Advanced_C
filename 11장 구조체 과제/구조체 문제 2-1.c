#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h> 

struct student {
	char name[21];
	int kor, eng, math;
};

struct average {
	double ave_kor, ave_eng, ave_math;
};

struct average calculate_avg (struct student* st, int N);

int main() {
	struct student st[51];
	struct average aver;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", &st[i].name, &st[i].kor, &st[i].eng, &st[i].math);
	}
	aver = calculate_avg(st, N);
	printf("%0.1f %0.1f %0.1f", aver.ave_kor, aver.ave_eng, aver.ave_math);

	int x = 0, y = 0, z = 0;
	for (int i = 0; i < N; i++) {
		if (aver.ave_kor > st[i].kor)
			x++;
		if (aver.ave_eng > st[i].eng)
			y++;
		if (aver.ave_math > st[i].math)
			z++;
	}
	printf("\n");
	printf("%d %d %d", x, y, z);

	return 0;
}

struct average calculate_avg(struct student* st, int N) {
	struct average aver = { 0 };
	
	for (int i = 0; i < N; i++) {
		aver.ave_kor = aver.ave_kor + (*(st+i)).kor;
		aver.ave_eng = aver.ave_eng + (*(st+i)).eng;
		aver.ave_math = aver.ave_math + (*(st+i)).math;
	}
	aver.ave_kor = aver.ave_kor / N;
	aver.ave_eng = aver.ave_eng / N;
	aver.ave_math = aver.ave_math / N;

	return aver;
}