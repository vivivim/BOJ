import java.util.*;

class Solution {
    public String solution(int n, int k, String[] cmd) {
        int[] prev = new int[n];
        int[] next = new int[n];
        int cur = k;
        Stack<Integer> trash = new Stack<>();
        char[] answer = new char[n];
        
        for (int i = 0; i < n; ++i) {
            prev[i] = i - 1;
            next[i] = i + 1;
            answer[i] = 'O';
        }
        
        for (String c : cmd) {
            char ch = c.charAt(0);
            
            if (ch == 'U') {
                int num = Integer.parseInt(c.substring(2));
                
                while (num-- > 0) cur = prev[cur];
            } else if (ch == 'D') {
                int num = Integer.parseInt(c.substring(2));
                
                while (num-- > 0) cur = next[cur];
            } else if (ch == 'C') {
                trash.push(cur);
                
                int curPrev = prev[cur];
                int curNext = next[cur];
                
                if (curPrev > -1)
                    next[curPrev] = curNext;
                if (curNext < n)
                    prev[curNext] = curPrev;
                cur = curNext == n ? curPrev : curNext;
            } else if (ch == 'Z') {
                int re = trash.pop();
                
                int rePrev = prev[re];
                int reNext = next[re];
                
                if (rePrev > -1)
                    next[rePrev] = re;
                if (reNext < n)
                    prev[reNext] = re;
            }
        }
        
        while (!trash.isEmpty())
            answer[trash.pop()] = 'X';
        
        return new String(answer);
    }
}
