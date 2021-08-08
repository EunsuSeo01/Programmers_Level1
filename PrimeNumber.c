/*
 Programmers Lv1 Summer/Winter Coding(~2018) - 소수 만들기
 Created by EunSu Seo
 Last modified 2021-08-09
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// nums_len은 배열 nums의 길이입니다.
int countPrimeNumber(int nums[], size_t nums_len) {
    int answer = 0;

    // 세 개의 합이 7이라고 하면 2~6까지의 수랑 다 나눠 봤을 때 자연수로 나누어 떨어지는 게 없으니 소수로 판단.
    for (int i = 0; i < nums_len - 2; i++) {
        for (int j = i + 1; j < nums_len - 1; j++) {
            for (int k = j + 1; k < nums_len; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                for (int n = 2; n < sum - 1; n++) {
                    if ((sum % n) == 0) {   // 나누어 떨어지는 게 있음. -> 소수 아님.
                        break;
                    }
                    if (n == sum - 2) {     // 끝까지 확인해 봤는데도 나누어 떨어지는 게 없음. -> 소수!
                        answer++;
                    }
                }
            }
        }
    }

    return answer;
}
