import java.util.*;

class Solution {
    int n;
    int[] dist;
    int[] weak;
    int weakNum;
    int dn;
    int answer;
    
    int[] weaks;
    int[] order;
    
    public int solution(int n, int[] weak, int[] dist) {
        this.n = n;
        this.dist = dist;
        this.weak = weak;
        this.answer = 2147483647;
        this.weakNum = weak.length;
        this.dn = dist.length;
        this.weaks = setWeak();
        this.order = new int[dn];
        
        letsGo(new boolean[dn], 0);
        
        return answer > dn ? -1 : answer;
    }
    
    private void letsGo(boolean[] visited, int depth) {
        if (depth == dn) {
            check();
            return ;
        }
        for (int i = 0; i < dn; ++i) {
            if (visited[i]) continue;
            
            visited[i] = true;
            order[depth] = dist[i];
            letsGo(visited, depth+1);
            visited[i] = false;
        }
    }
    
    private void check() {
        for (int i = 0; i < weakNum; ++i) {
            int friendIdx = 0;
            int friendCt = 1;
            int cover = weak[i] + order[friendIdx];
            
            for (int j = i+1; j < i + weakNum; ++j) {
                if (cover < weaks[j]) {
                    ++friendIdx;
                    ++friendCt;
                    if (friendCt > dn) {
                        friendCt = dn + 1;
                        break ;
                    }
                    cover = weaks[j] + order[friendIdx];
                }
            }
            answer = Math.min(friendCt, answer);
        }
    }
    
    private int[] setWeak() {
        int[] w = new int[weakNum * 2];
        
        for (int i = 0; i < weakNum * 2; ++i) {
            if (i < weakNum)
                w[i] = weak[i];
            else
                w[i] = weak[i%weakNum] + n;
        }
        
        return w;
    }
}
