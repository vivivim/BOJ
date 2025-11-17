import java.util.*;

class Solution {
    public int solution(String name) {
        int answer = 0;
        int l = name.length();
        int dist = l - 1;
        int tmp = 0;
        
        for (char c : name.toCharArray()) {
            if (c <= 'M')
                answer += c - 'A';
            else
                answer += 'Z' - c + 1;
        }
        
        for (int i = 0; i < l; ++i) {
            int next = i+1;
            while (next < l && name.charAt(next) == 'A') ++next;
            
            tmp = Math.min(i * 2 + (l-next), (l-next)*2 + i);
            dist = Math.min(dist, tmp);
        }
        answer += dist;
        
        return answer;
    }
}
