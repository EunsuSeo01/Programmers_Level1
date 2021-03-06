#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
 [Sol]
 1. report를 분석해서 누가 몇 번 신고되었는지 파악.
 -> 띄어쓰기를 기준으로 앞의 값, 뒤의 값 분리.
 -> 앞의 값은 다르면서 뒤의 값이 같은 경우가 몇 개인지 count.
 -> !! 본인을 신고한 사람의 아이디를 저장하고 그 unique 갯수 세면 몇 번 신고되었는지 파악 가능!!
 -> 배열의 인덱스가 다른데 안의 값이 일치한다면 1번으로 간주.
 2. 위의 값이 k보다 크거나 같은 사람이 있는지 없는지.
  2-1. 있으면 누군지 파악.
   3-1. 그 사람을 신고한 사람들이 받을 result++
  2-2. 없으면 아무 일도 없음.
*/


// id_list_len은 배열 id_list의 길이입니다.
// report_len은 배열 report의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(char* id_list[], size_t id_list_len, char* report[], size_t report_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(id_list_len * sizeof(int));

    // id_list에서의 인덱스를 사용하여 해당 인덱스의 회원을 신고한 회원의 인덱스를 2차원 배열에 저장한다.
    int** report_res = (int**)malloc(id_list_len * sizeof(int*));
    // 2차원 배열 동적할당
    for (int i = 0; i < id_list_len; i++) {
        report_res[i] = (int*)malloc(id_list_len * sizeof(int));
    }

    int reporting_index, reported_index, condition = 1;
    int* reported_count = (int*)calloc(id_list_len, sizeof(int)); // 초기화까지.

    for (int i = 0; i < report_len; i++) {
        char* ptr = strtok(report[i], " ");      // " " 공백 문자를 기준으로 문자열 report[i]를 자름, 포인터 반환 -> 신고한 사람의 아이디가 저장돼 있음.
        printf("%s\n", ptr); // test
        
        reporting_index = get_id_index(ptr, id_list, id_list_len);
        if (reported_index == -1)
            exit(0);

        ptr = strtok(NULL, " ");      // 다음 문자열을 잘라서 포인터를 반환 -> 신고받은 사람의 아이디가 저장돼 있음.
        reported_index = get_id_index(ptr, id_list, id_list_len);
        if (reported_index == -1)
            exit(0);

        // 중복 신고 확인.
        for (int i = 0; i < id_list_len; i++) {
            for (int j = 0; j < reported_count[reported_index]; j++) {
                for (int k = 1; k < reported_count[reported_index] - 1; k++) {
                    if (report_res[i][j] == reporting_index) {
                        condition = 0;
                        break;
                    }
                }
            }
        }

        // 중복 없으면 값 저장,
        if (condition == 1) {
            report_res[reported_index][reported_count[reported_index]] = reporting_index;
            reported_count[reported_index]++;
        }
        else
            condition = 1; // 초기화.
    }

    // 신고 받은 횟수로 answer 계산.
    for (int i = 0; i < id_list_len; i++) {
        if (reported_count[i] >= k) {
            for (int j = 0; j < reported_count[i]; j++)
                answer[report_res[i][j]]++;
        }
    }

    return answer;
}

// 해당 아이디가 id_list에서 몇 번째 인덱스에 위치하고 있는지 반환.
int get_id_index(char* id, char** id_list, size_t id_list_len) {
    int index = -1;

    for (int i = 0; i < id_list_len; i++) {
        if (strcmp(id, id_list[i]) == 0) {
            index = i;
            break;
        }
    }

    return index;
}

int main() {
    printf("test");

    char *id_list[4];

    id_list[0] = "muzi";
    id_list[1] = "frodo";
    id_list[2] = "apeach";
    id_list[3] = "neo";

    char* report[5];

    report[0] = "muzi frodo";
    report[1] = "apeach frodo";
    report[2] = "frodo neo";
    report[3] = "muzi neo";
    report[4] = "apeach muzi";

    int* res = solution(id_list, 4, report, 5, 2);

    for (int i = 0; i < 4; i++)
        printf("%d ", res[i]);

    return 0;
}
