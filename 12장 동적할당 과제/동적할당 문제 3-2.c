#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sub {
    char* name; // 과목 이름
    double score; // 과목 점수
};

struct st {
    char* name; // 학생 이름
    char id[5]; // 학생 학번
    int num; // 과목 개수
    struct sub* psub; // 과목 구조체 포인터
    double avg; // 모든 과목의 평균 점수
};

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    struct st *s1 = (struct st *) malloc(N * sizeof(struct st));
    //struct st *s1 오류 학인
    if (s1 == NULL) {
        printf("ERROR STRUCT STUDENT");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        char tmp[101] = {0};
        char *p = tmp;
        gets(tmp);
        int len = strlen(tmp), cnt = 1;
        //공백에 널 넣기
        for (int j = 0; j < len; j++) {
            if (tmp[j] == ' ') {
                tmp[j] = '\0';
                cnt++;
            }
        }
        //이름 넣기
        s1[i].name = (char *) malloc((strlen(p) + 1) * sizeof(char));
        if (s1[i].name == NULL) {
            printf("ERROR NAME");
            exit(1);
        }
        strcpy(s1[i].name, p);
        p = p + strlen(p) + 1;
        strcpy(s1[i].id, p);
        p = p + strlen(p) + 1;
        s1[i].num = (cnt - 2) / 2;
        s1[i].psub = (struct sub *) malloc(s1[i].num * sizeof(struct sub));
        if (s1[i].psub == NULL) {
            printf("ERROR PSUB");
            exit(1);
        }
        s1[i].avg = 0;
        for (int j = 0; j < s1[i].num; j++) {
            s1[i].psub[j].name = (char *) malloc((strlen(p) + 1) * sizeof(char));
            if (s1[i].psub[j].name == NULL) {
                printf("ERROR PSUB");
                exit(1);
            }
            strcpy(s1[i].psub[j].name, p);
            p = p + strlen(p) + 1;
            s1[i].psub[j].score = atof(p);
            p = p + strlen(p) + 1;
            s1[i].avg += s1[i].psub[j].score;
        }
        s1[i].avg = s1[i].avg / s1[i].num;
    }
    for (struct st *x = s1; x < s1 + N; x++) {
        for (struct st *y = s1; y < x; y++) {
            if ((*x).avg > (*y).avg) {
                struct st stmp = *x;
                *x = *y;
                *y = stmp;
            } else if ((*x).avg == (*y).avg) {
                if (strcmp((*x).id, (*y).id) < 0) {
                    struct st stmp = *x;
                    *x = *y;
                    *y = stmp;
                }
            }
        }
    }
    int K;
    scanf("%d", &K);
    K = K - 1;

    int maxIdx = 0;
    for (int i = 0; i < s1[K].num; i++) {
        if (s1[K].psub[i].score > s1[K].psub[maxIdx].score) {
            maxIdx = i;
        }
    }

    printf("%s %s %.2lf %s %.2lf", s1[K].name, s1[K].id, s1[K].avg, s1[K].psub[maxIdx].name, s1[K].psub[maxIdx].score);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < s1[i].num; j++) {
            free(s1[i].psub[j].name);
        }
        free(s1[i].psub);
    }
    for (int i = 0; i < N; i++) {
        free(s1[i].name);
    }
    free(s1);
}