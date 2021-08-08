/*
 Programmers Lv1 Summer/Winter Coding(~2018) - �Ҽ� �����
 Created by EunSu Seo
 Last modified 2021-08-09
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// nums_len�� �迭 nums�� �����Դϴ�.
int solution(int nums[], size_t nums_len) {
    int answer = 0;

    // �� ���� ���� 7�̶�� �ϸ� 2~6������ ���� �� ���� ���� �� �ڿ����� ������ �������� �� ������ �Ҽ��� �Ǵ�.
    for (int i = 0; i < nums_len - 2; i++) {
        for (int j = i + 1; j < nums_len - 1; j++) {
            for (int k = j + 1; k < nums_len; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                for (int n = 2; n < sum - 1; n++) {
                    if ((sum % n) == 0) {   // ������ �������� �� ����. -> �Ҽ� �ƴ�.
                        break;
                    }
                    if (n == sum - 2) {     // ������ Ȯ���� �ôµ��� ������ �������� �� ����. -> �Ҽ�!
                        answer++;
                    }
                }
            }
        }
    }

    return answer;
}