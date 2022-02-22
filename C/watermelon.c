/*
 Programmers Lv 1. 수박수박수박수박수박수? (C언어 풀이) - 서은수
 길이가 n이고, "수박수박수박수...."와 같은 패턴을 유지하는 문자열을 리턴하는 함수, solution을 완성하세요.
 제한사항: n은 길이 10,000이하인 자연수.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n) {
    n *= 3;
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)calloc(n, 1);
    char* pattern = "수박";

    for (int i = 0; i < n; i++)
        answer[i] = pattern[i % 6];
    
    return answer;
}
