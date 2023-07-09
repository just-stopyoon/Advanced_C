#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st {
	char* name; // 학생 이름
	char id[5]; // 학생 학번
	char* sub; // 과목 이름
	double s; // 과목 점수
};

int main() {
	int N;
	scanf("%d", &N);
	struct st* s = (struct st*)malloc(N * sizeof(struct st));
	if (s == NULL) {
		printf("ERROR");
		exit(1);
	}
	for (struct st* p = s; p < s + N; p++) {
		char tmp[101], ttmp[101];
		scanf("%s %s %s %lf", tmp, (*p).id, ttmp, &(*p).s);
		(*p).name = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
		if ((*p).name == NULL) {
			printf("ERROR");
			exit(1);
		}
		strcpy((*p).name, tmp);
		(*p).sub = (char*)malloc((strlen(ttmp) + 1) * sizeof(char));
		if ((*p).sub == NULL) {
			printf("ERROR");
			exit(1);
		}
		strcpy((*p).sub, ttmp);
	}
	int K;
	scanf("%d", &K);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (s[j].s < s[j + 1].s) {
				struct st tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
	K = K - 1;
	printf("%s %s %s %.2lf", (*(s + K)).name, (*(s + K)).id, (*(s + K)).sub, (*(s + K)).s);

	for (int i = 0; i < N; i++) {
		free(s[i].name);
	}
	free(s);

	for (int i = 0; i < N; i++) {
		free(s[i].sub);
	}
	free(s);
}