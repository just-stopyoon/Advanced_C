#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>

struct complex {
	double real;
	double com;
};
struct complex add(struct complex c1, struct complex c2);

int main() {
	struct complex c1, c2, c3;
	scanf("%lf %lf", &c1.real, &c1.com);
	scanf("%lf %lf", &c2.real, &c2.com);
	c3 = add(c1, c2);
	printf("%.1lf + %.1lfi", c3.real, c3.com);
}

struct complex add(struct complex c1, struct complex c2) {
	struct complex c3;
	c3.real = c1.real + c2.real;
	c3.com = c1.com + c2.com;
	return c3;
}