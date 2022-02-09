/*
 Programmers Weekly Challenge Week1
 Created by EunSu Seo
 Last modified 2021-08-09
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long solution(int price, int money, int count) {
    long answer = -1;
    long amount = 0;
    
    for (int i = 1; i <= count; i++) {
        amount += price * i;
    }
    if (money > amount) return 0;
    
    answer = amount - money;
    return answer;
}
