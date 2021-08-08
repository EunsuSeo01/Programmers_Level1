/*
 Programmers Lv1 월간 코드 챌린지 시즌2 - 음양 더하기
 Created by EunSu Seo
 Last modified 2021-08-09
*/
class NegativePlusPositive {
    public int negativepluspositive(int[] absolutes, boolean[] signs) {
        int answer = 0;
        for (int i = 0; i < absolutes.length; i++) {
            if (!signs[i])
                absolutes[i] = -absolutes[i];
            answer += absolutes[i];
        }
        
        return answer;
    }
}
