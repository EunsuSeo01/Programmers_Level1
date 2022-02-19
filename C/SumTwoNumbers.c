/*
 Programmers Lv1. 두 개 뽑아서 더하기 C언어 풀이 - 서은수
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * numbers_len * (numbers_len - 1));

    int size = 0, check = 0;

    for (int i = 0; i < numbers_len - 1; i++) {
        for (int j = i + 1; j < numbers_len; j++) {
            // 이미 들어가 있는 수인지 확인.
            if (size > 0) {
                for (int k = 0; k < size; k++) {
                    if (answer[k] == numbers[i] + numbers[j]) {
                        check = 1;  // 확인 표시.
                        break;
                    }
                }
            }

            // 없는 숫자면 answer에 추가.
            if (check == 0) {
                answer[size] = numbers[i] + numbers[j];
                size++;
            } else {
                check = 0;  // 표시 초기화.
            }
        }
    }

    int temp = 0;

    // 오름차순으로 정렬.
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (answer[i] > answer[j]) {
                temp = answer[j];
                answer[j] = answer[i];
                answer[i] = temp;
            }
        }
    }

    return answer;
}
