#pragma warning(disable : 4996)
#include<stdio.h>

int main() {
	int n;
	char str[10], rev[10];
	scanf("%d", &n);

	int i = 0;
	while (n) {
		str[i] = (n % 10) + '0';
		i++;
		n /= 10;
	}
	str[i] = '\0'; 
	printf("%s", str);
	return 0;
}