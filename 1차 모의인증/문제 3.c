#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h> 

void StringAdd(char arr[], char ch, int index);
int Convertor(char x);

int main() {
	char str[50] = { 0, };
	int len = 0;
	int index = 0;
	scanf("%s", str);
	for (int i = 0; i < strlen(str) ; i++) {
		int x = Convertor(str[i]);
		int y = Convertor(str[i + 1]);

		if (str[i + 1] == '\0')
			break;
		if (x % 2 == 1 && y % 2 == 1) {
			char ch = '+';
			StringAdd(str, ch, i+1);
			i++;
		}
		if (x % 2 == 0 && y % 2 == 0) {
			char ch = '*';
			StringAdd(str, ch, i+1);
			i++;
		}
	}
	printf("%s", str);
	return 0;
}

void StringAdd(char arr[], char ch, int index) {
	int length = strlen(arr);
	char* p = arr;
	for (p = arr + length + 1; p > arr + index; p--) {
		*p = *(p - 1);
	}
	*(arr + index) = ch;
}
int Convertor(char x) {
	int num;
	num = x - '0';
	return num;
}