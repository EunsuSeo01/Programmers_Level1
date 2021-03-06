/*
 Programmers Lv1. 짝수와 홀수 (C언어 풀이) - 서은수
 정수 num이 짝수일 경우 "Even"을 반환하고 홀수인 경우 "Odd"를 반환하는 함수, solution을 완성해주세요.
 제한사항: 0은 짝수.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int num) {
    // 리턴할 값은 메모리를 동적 할당해주세요
    char* answer = (char*)malloc(4);

    if (num % 2 == 0)
        answer = "Even";
    else
        answer = "Odd";

    return answer;
}
