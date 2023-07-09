#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	char x[100] = { 0 };
	char y[100] = { 0 };
	int N;
	int index = 0;
	scanf("%s", x);
	scanf("%d", &N);

	for (char* p = x; p < x + strlen(x); p++) {
		if (*p >= 'A' && *p <= 'Z') {
			*p = *p + N;
			*(y + index) = *p;
			index++;
		}

		else if (*p >= 'a' && *p <= 'z') {
			*p = *p - N;
			*(y+index) = *p;
			index++;
		}

		else if (*p >= '0' && *p <= '9') {
			if (*p == '1') {
				if (*(p + 1) >= '0' && *(p + 1) <= '9') {
					int rst = 0;
					rst = *(p + 1) - '0' - 1;
					rst = rst + 10;

					*p = 'A' + rst;

					for (int i = 0; i < N; i++) {
						*(y+index) = *p;
						index++;
					}
					p++;
				}

				else {
					*p = 'A' + *p - '0' - 1;
					for (int i = 0; i < N; i++) {
						*(y+index) = *p;
						index++;
					}
				}
			}


			else if (*p == '2') {
				if (*(p + 1) >= '0' && *(p + 1) < '7') {
					int rst = 0;
					rst = *(p + 1) - '0' - 1;
					rst = rst + 20;

					*p = 'A' + rst;

					for (int i = 0; i < N; i++) {
						*(y+index) = *p;
						index++;
					}
					p++;
					continue;
				}

				else {
					*p = 'A' + *p - '0' - 1;
					for (int i = 0; i < N; i++) {
						*(y+index) = *p;
						index++;
					}

				}
			}
			else {
				*p = 'A' + *p - '0' - 1;
				for (int i = 0; i < N; i++) {
					*(y+index) = *p;
					index++;
				}
			}
		}
		else {
			*p = ' ';
			*(y+index) = *p;
			index++;
		}
	}
	printf("%s", y);
	return 0;
}