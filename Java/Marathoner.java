import java.util.HashMap;
import java.util.Map;

public class Marathoner {
    public void main(String[] args) {
        String[] participant = { "leo", "kiki", "eden" };
        String[] completion = { "eden", "kiki" };
    
        Solution sol = new Solution();
        System.out.println(sol.solution(participant, completion));
    }
    
    class Solution {
        public String solution(String[] participant, String[] completion) {
            String answer = "";
        
            Map<String, Integer> compHashMap = new HashMap<String, Integer>();
            for (int i = 0; i < completion.length; i++)
                compHashMap.put(completion[i], 0);
        
            for (int i = 0; i < participant.length; i++) {
                if (!compHashMap.containsKey(participant[i]) || compHashMap.get(participant[i]) > 0) {
                    answer = participant[i];
                }
                else {
                    compHashMap.replace(participant[i], compHashMap.get(participant[i]) + 1);
                }
            }
            
            return answer;
        }
    }
}
