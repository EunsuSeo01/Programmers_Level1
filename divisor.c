#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        if (find_divisor_num(i) % 2 == 0)
            answer += i;
        else
            answer -= i;
    }

    return answer;
}

int find_divisor_num(int num) {
    int res = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0)
            res++;
    }
    return res;
}
