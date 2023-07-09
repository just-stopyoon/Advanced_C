#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void input(int* p, int M);
int* sel_max(int* p, int M);
void output(int* p, int N);

int main(void) {
    int in[100], out[100], * max, i, N, M;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++) { //N번 반복
        input(in, M); //정수 입력
        max = sel_max(in, M);
        out[i] = *max;
    }
    output(out, N);
    return 0;
}

void input(int* p, int M) {
    for (int* x = p; x < p + M; x++) {
        scanf("%d", x);
    }
}
int* sel_max(int* p, int M) {
    int* result = 0; //저장된 배열 원소의 주소
    int max = 0;
    int check = 0;
    for (int* x = p; x < p + M; x++) {
        int cnt = 0;
        for (int* y = p; y < p + M; y++) {
            if (*x == *y) {
                cnt++;
            }
        }
        if (cnt > max) {
            max = cnt;
            result = x;
            check = 1;
        }
    }
    return result;
}
void output(int* p, int N) {
    for (int* x = p; x < p + N; x++) {
        printf(" %d", *x);
    }
}