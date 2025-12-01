import java.util.*;

class Solution {
    
    class Info {
        String str;
        int ct;
        
        Info(String str, int ct) {
            this.str = str;
            this.ct = ct;
        }
    }
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        int n = words.length;
        Queue<Info> q = new LinkedList<>();
        boolean[] visited = new boolean[n];
        
        q.offer(new Info(begin, 0));
        
        while (!q.isEmpty()) {
            Info cur = q.poll();
            
            if (cur.str.equals(target)) {
                answer = cur.ct;
                break ;
            }
            
            for (int i = 0; i < n; ++i) {
                if (!visited[i] && isChange(cur.str, words[i])) {
                    visited[i] = true;
                    q.offer(new Info(words[i], cur.ct+1));
                }
            }
        }
        
        return answer;
    }
    
    private boolean isChange(String cur, String next) {
        boolean oneCoin = true;
        
        for (int i = 0; i < cur.length(); ++i) {
            if (cur.charAt(i) != next.charAt(i)) {
                if (!oneCoin)
                    return false;
                else
                    oneCoin = false;
            }
        }
        
        return true;
    }
}
