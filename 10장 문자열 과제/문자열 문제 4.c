#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int s_check(char* p, char* q);

int main() {
	int M, k1, k2;
	char x[201] = { 0 };
	int tmp = 0;
	scanf("%d", &M);
	scanf("%d %d", &k1, &k2);
	getchar();


	for (int i = 0; i < M; i++) {
		gets(x);
		tmp = k2;
		if (strlen(x) < k2) {
			tmp = strlen(x);
		}
		if (s_check(x + k1, x + tmp) != 0)
			printf("%d\n", s_check(x + k1, x + tmp));
	}
	return 0;
}

int s_check(char* p, char* q) {
	int cnt = 0;
	for (char* r = p; r <= q; r++) {
		if (*r >= 'a' && *r <= 'z') {
			cnt++;
		}
	}
	return cnt;
}