#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	char x[100] = { 0 };
	char y[1000] = { 0 };
	char z[1000] = { 0 };
	char tmp = '0';
	int N;
	int index = 0;
	gets(x);
	gets(z);

	for (int j = 1; j <= 10; j++) {
		index = 0;
		char y[100] = { 0 };
		char tmp = '0';
		for (char* p = x; p < x + strlen(x); p++) {
			if (*p >= 'A' && *p <= 'Z') {
				*(y + index) = *p + j;
				index++;
			}
			else if (*p >= 'a' && *p <= 'z') {
				*(y + index) = *p - j;
				index++;
			}
			else if (*p >= '0' && *p <= '9') {
				if (*p == '1') {
					if (*(p + 1) >= '0' && *(p + 1) <= '9') {
						int rst = 0;
						rst = *(p + 1) - '0' - 1;
						rst = rst + 10;

						tmp= 'A' + rst;

						for (int i = 0; i < j; i++) {
							*(y+index) = tmp;
							index++;
						}
						p++;
					}

					else {
						tmp = 'A' + *p - '0' - 1;
						for (int i = 0; i < j; i++) {
							*(y+index) = tmp;
							index++;
						}
					}
				}


				else if (*p == '2') {
					if (*(p + 1) >= '0' && *(p + 1) < '7') {
						int rst = 0;
						rst = *(p + 1) - '0' - 1;
						rst = rst + 20;

						tmp = 'A' + rst;

						for (int i = 0; i < j; i++) {
							*(y+index) = tmp;
							index++;
						}
						p++;
						continue;
					}

					else {
						tmp = 'A' + *p - '0' - 1;
						for (int i = 0; i < j; i++) {
							*(y+index) = tmp;
							index++;
						}

					}
				}
				else {
					tmp = 'A' + *p - '0' - 1;
					for (int i = 0; i < j; i++) {
						*(y+index) = tmp;
						index++;
					}
				}
			}
			else {
				*(y+index) = ' ';
				index++;
			}
		}
		if (strcmp(y,z) == 0) {
			printf("1");
			return 0;
		}
	}
	
	for (int j = 1; j <= 10; j++) {
		index = 0;
		char y[100] = { 0 };
		char tmp = '0';
		for (char* p = z; p < z + strlen(z); p++) {
			if (*p >= 'A' && *p <= 'Z') {
				*(y + index) = *p + j;
				index++;
			}
			else if (*p >= 'a' && *p <= 'z') {
				*(y + index) = *p - j;
				index++;
			}
			else if (*p >= '0' && *p <= '9') {
				if (*p == '1') {
					if (*(p + 1) >= '0' && *(p + 1) <= '9') {
						int rst = 0;
						rst = *(p + 1) - '0' - 1;
						rst = rst + 10;

						tmp = 'A' + rst;

						for (int i = 0; i < j; i++) {
							*(y + index) = tmp;
							index++;
						}
						p++;
					}

					else {
						tmp = 'A' + *p - '0' - 1;
						for (int i = 0; i < j; i++) {
							*(y + index) = tmp;
							index++;
						}
					}
				}


				else if (*p == '2') {
					if (*(p + 1) >= '0' && *(p + 1) < '7') {
						int rst = 0;
						rst = *(p + 1) - '0' - 1;
						rst = rst + 20;

						tmp = 'A' + rst;

						for (int i = 0; i < j; i++) {
							*(y + index) = tmp;
							index++;
						}
						p++;
						continue;
					}

					else {
						tmp = 'A' + *p - '0' - 1;
						for (int i = 0; i < j; i++) {
							*(y + index) = tmp;
							index++;
						}

					}
				}
				else {
					tmp = 'A' + *p - '0' - 1;
					for (int i = 0; i < j; i++) {
						*(y + index) = tmp;
						index++;
					}
				}
			}
			else {
				*(y + index) = ' ';
				index++;
			}
		}
		if (strcmp(y, x) == 0) {
			printf("2");
			return 0;
		}
	}

	printf("0");

	return 0;
}