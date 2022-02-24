/*
 Programmers Lv 1. 직사각형 별찍기 (C언어 풀이) - 서은수
 별(*) 문자를 이용해 가로의 길이가 n, 세로의 길이가 m인 직사각형 형태를 출력해보세요.
 제한사항: n과 m은 각각 1000 이하인 자연수.
*/

#include <stdio.h>

int main(void) {
    int a;
    int b;
    scanf("%d %d", &a, &b);

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
