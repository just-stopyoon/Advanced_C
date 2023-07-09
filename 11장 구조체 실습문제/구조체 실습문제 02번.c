#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>

struct time {
	int hour;
	int minute;
	int second;
};

int main() {
	struct time x[2];
	for (struct time* p = x; p < x + 2; p++) {
		scanf("%d %d %d", &p->hour, &p->minute, &p->second);
	}
	int total1 = x[0].hour * 3600 + x[0].minute * 60 + x[0].second;
	int total2 = x[1].hour * 3600 + x[1].minute * 60 + x[1].second;
	int result = total2 - total1;
	int hour = result / 3600;
	int minute = result % 3600 / 60;
	int second = result % 3600 % 60 % 60;

	printf("%d %d %d", hour, minute, second);
}