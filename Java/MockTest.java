class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};

        int[] first = { 1, 2, 3, 4, 5 };
        int[] second = { 2, 1, 2, 3, 2, 4, 2, 5 };
        int[] third = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
        
        int[] right = { 0, 0, 0 };

        // 정답과 일치하면 정답 수 증가시킨다.
        for (int i = 0; i < answers.length; i++) {
            if (answers[i] == first[i % first.length])
                right[0]++;
            if (answers[i] == second[i % second.length])
                right[1]++;
            if (answers[i] == third[i % third.length])
                right[2]++;
        }

        // 일단 수포자 1이 일등이고, 동점자는 없다고 가정.
        int max = right[0], maxIdx = 0, answerNum = 1;
        int[] maxNum = { 1, 0, 0 };

        // 일등 찾기 & 동점자 있다면 몇 명인지 세기.
        for (int j = 1; j < right.length; j++) {
            if (max < right[j]) {
                maxNum[maxIdx] = 0;
                maxIdx = j;
                maxNum[maxIdx] = 1;
                max = right[maxIdx];
            }
            else if (max == right[j]) {
                answerNum++;
                maxNum[j] = 1;
            }
        }
        
        answer = new int[answerNum];
        
        // answer에 일등(들)의 인덱스를 입력.
        int answerIdx = 0;
        for (int k = 0; k < maxNum.length; k++) {
            if (maxNum[k] == 1) {
                answer[answerIdx] = k + 1;
                answerIdx++;
            }
        }
        
        return answer;
    }
}
