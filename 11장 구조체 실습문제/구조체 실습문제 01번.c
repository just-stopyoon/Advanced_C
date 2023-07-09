#pragma warning (disable : 4996)
#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>

struct vector {
	int v1;
	int v2;
	int v3;
};

int main() {
	struct vector x[3];
	int input = 0;
	for (int i = 0; i < 2; i++) {
		scanf("%d %d %d", &x[i].v1, &x[i].v2, &x[i].v3);
	}
	x[2].v1 = x[0].v1 * x[1].v1;
	x[2].v2 = x[0].v2 * x[1].v2;
	x[2].v3 = x[0].v3 * x[1].v3;
	input = x[2].v1 + x[2].v2 + x[2].v3;
	printf("%d %d %d\n", x[2].v1, x[2].v2, x[2].v3);
	printf("%d", input);
}