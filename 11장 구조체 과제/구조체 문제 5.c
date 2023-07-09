#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct student {
    char name[31], sub[10][31];
    int id, n;
    double grade[10], total;
};

void insert_s(struct student* st, int cnt);
void sort_s(struct student* st, int cnt);
int delete_s(struct student* st, int cnt, char* name);
void print_s(struct student* st, int cnt);

int main() {
    struct student st[100];
    int cnt = 0;
    char c, name[31];

    while (1) {
        scanf("%c", &c);
        if (c == 'I') {
            insert_s(st, cnt);
            cnt++;
        }
        else if (c == 'S') {
            sort_s(st, cnt);
        }
        else if (c == 'D') {
            scanf("%s", name);
            if (delete_s(st, cnt, name)) {
                cnt--;
            }
        }
        else if (c == 'P') {
            print_s(st, cnt);
        }
        else if (c == 'Q') {
            break;
        }
    }

    return 0;
}

void insert_s(struct student* st, int cnt) {
    struct student* p = st + cnt;
    p->total = 0;
    scanf("%s %d %d", p->name, &p->id, &p->n);
    for (int i = 0; i < p->n; i++) {
        scanf("%s %lf", p->sub[i], &p->grade[i]);
        p->total += p->grade[i];
    }
    p->total /= p->n;
}

void sort_s(struct student* st, int cnt) {
    struct student st1[100];
    for (int i = 0; i < cnt; i++) {
        st1[i] = st[i];
    }

    for (struct student* p = st1; p < st1 + cnt; p++) {
        for (struct student* q = st1; q < p; q++) {
            if (strcmp(p->name, q->name) < 0) {
                struct student tmp = *p;
                *p = *q;
                *q = tmp;
            }
        }
    }
    print_s(st1, cnt);
}

int delete_s(struct student* st, int cnt, char* name) {
    for (struct student* p = st; p < st + cnt; p++) {
        if (!strcmp(p->name, name)) {
            for (struct student* q = p; q < st + cnt - 1; q++) {
                *q = *(q + 1);
            }
            return 1;
        }
    }
    return 0;
}

void print_s(struct student* st, int cnt) {
    for (struct student* p = st; p < st + cnt; p++) {
        printf("%s %d %d %.2f\n", p->name, p->id, p->n, p->total);
    }
}
