#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	char* str = (char*)malloc((N+1) * sizeof(char));
	scanf("%s", str);
	char a, b;
	getchar();
	scanf("%c %c", &a, &b);

	int cnt1 = 0, cnt2 = 0;

	for (char* p = str; p < str + N ; p++) {
		if (*p == a)
			cnt1++;
		if (*p == b)
			cnt2++;
	}
	printf("%d %d", cnt1, cnt2);
	return 0;
}