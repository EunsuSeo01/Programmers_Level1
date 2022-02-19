/*
 Programmers Lv 1. 나머지가 1이 되는 수 찾기 (C언어 풀이) - 서은수
 n % x == 1을 만족하는 가장 작은 자연수 x 찾기.
 제한사항: 3 ≤ n ≤ 1,000,000
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;

    // n % x == 1이라는 것은, n = x 곱하기 몫 + 1 => 즉 n은 늘 x보다 크다.
    for (int x = 1; x < n; x++) {
        if (n % x == 1) {
            answer = x;
            break;
        }
    }

    return answer;
}
