class Solution {
    public int solution(String s) {
        int answer = 2147483647;
        
        for (int i = 1; i <= s.length()/2; ++i) {
            int tmp = s.length();
            int ct = 0;
            String unit = s.substring(0, i);
            
            for (int j = 0; j <= s.length() - i; j = j+i) {
                String cur = s.substring(j, j+i);
                
                if (unit.equals(cur)) {
                    ++ct;
                } else {
                    if (ct > 1) {
                        tmp -= i * (ct - 1);
                        tmp += String.valueOf(ct).length();
                    }
                    unit = cur;
                    ct = 1;
                }
            }
            
            if (ct > 1) {
                tmp -= i * (ct - 1);
                tmp += String.valueOf(ct).length();
            }
            
            answer = Math.min(answer, tmp);
        }
        return answer == 2147483647 ? 1 : answer;
    }
}
