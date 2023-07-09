#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
	int a, b, c;
};

int main() {
	struct student st[11];
	int N;
	int x = 0, y = 0, z = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &st[i].a, &st[i].b, &st[i].c);
		if (st[i].a == 1) { //남자일 때
			if (st[i].b < 60) {
				if (st[i].c < 165) {
					x++;
				}
				else if (175 <= st[i].c) {
					z++;
				}
				else {
					y++;
				}
			}
			else if ((60 <= st[i].b) && (st[i].b < 70)) {
				if (st[i].c < 165) {
					z++;
				}
				else if (175 <= st[i].c) {
					y++;
				}
				else {
					x++;
				}

			}
			else if (st[i].a == 1) {
				if (st[i].c < 165) {
					y++;
				}
				else if (175 <= st[i].c) {
					x++;
				}
				else {
					z++;
				}

			}
		}
		else { //여자일 때
			if (st[i].b < 50) {
				if (st[i].c < 165) {
					x++;
				}
				else if (175 <= st[i].c) {
					z++;
				}
				else {
					y++;
				}
			}
			else if ((50 <= st[i].b) && (st[i].b < 60)) {
				if (st[i].c < 165) {
					z++;
				}
				else if (175 <= st[i].c) {
					y++;
				}
				else {
					x++;
				}
			}
			else {
				if (st[i].c < 165) {
					y++;
				}
				else if (175 <= st[i].c) {
					x++;
				}
				else {
					z++;
				}
			}
		}
	}
	printf("%d %d %d", x, y, z);
	return 0;
}