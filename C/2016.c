/*
2016년 a월 b일은 무슨 요일일까요? 두 수 a ,b를 입력받아 2016년 a월 b일이 무슨 요일인지 리턴하는 함수, solution을 완성하세요.

조건> 2016년은 윤년입니다. -> 2월이 29일까지 있는 달.
2016년 a월 b일은 실제로 있는 날입니다. (13월 26일이나 2월 45일같은 날짜는 주어지지 않습니다)
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(4);
    
    int startDay[12];
    int lastDay[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    startDay[0] = 5; // 금요일
    
    // 1. 매달의 1일이 무슨 요일인지 계산하여 저장.
    // 0 일 / 1 월 / 2 화 / 3 수 / 4 목 / 5 금 / 6 토
    for (int i = 1; i < 12; i++) {
        startDay[i] = (startDay[i - 1] + lastDay[i - 1]) % 7;
    }
    
    // 2. b일이 a월의 몇 요일인지 계산.
    int res = (startDay[a - 1] + b) % 7;
    
    switch (res)
    {
	    case 0:
		    answer = "SUN";
		    break;
	    case 1:
		    answer = "MON";
		    break;
        case 2:
		    answer = "TUE";
		    break;
        case 3:
		    answer = "WED";
		    break;
        case 4:
		    answer = "THU";
		    break;
        case 5:
		    answer = "FRI";
		    break;
        case 6:
		    answer = "SAT";
		    break;
	}
    
    return answer;
}
