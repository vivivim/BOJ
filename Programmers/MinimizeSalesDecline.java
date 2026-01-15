import java.util.*;

class Solution {
    List<Integer>[] tree;
    int[][] dp;
    int[] sales;
    
    public int solution(int[] sales, int[][] links) {
        int n = sales.length;
        tree = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            tree[i] = new ArrayList<>();
        for (int[] link : links)
            tree[link[0]-1].add(link[1]-1);
        dp = new int[n][2];
        this.sales = sales;
        
        dfs(0);
        
        return Math.min(dp[0][0], dp[0][1]);
	}
    
    void dfs(int node) {
        dp[node][0] = 0;
        dp[node][1] = sales[node];
        
        if (tree[node].isEmpty()) return;
        int someone = 2147483647;
        
        for (int child : tree[node]) {
            dfs(child);
            
            dp[node][1] += Math.min(dp[child][0], dp[child][1]);
            
            if (dp[child][0] < dp[child][1]) {
                dp[node][0] += dp[child][0];
                someone = Math.min(someone, dp[child][1] - dp[child][0]);
            } else {
                dp[node][0] += dp[child][1];
                someone = 0;
            }
        }
        dp[node][0] += someone;
    }
}

