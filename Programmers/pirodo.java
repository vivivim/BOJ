class Solution {
    int[][] dungeons;
    int n;
    boolean[] visited;
    int answer;
    
    public int solution(int k, int[][] dungeons) {
        this.answer = -1;
        this.dungeons = dungeons;
        this. n = dungeons.length;
        visited = new boolean[n];
        
        dfs(k, 0);
        
        return answer;
    }
    
    private void dfs(int k, int depth) {
        if (depth == n) {
            answer = Math.max(answer, depth);
            return ;
        }
        
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            if (k < dungeons[i][0]) {
                answer = Math.max(answer, depth);
                continue;
            }
            
            visited[i] = true;
            k -= dungeons[i][1];
            
            dfs(k, depth+1);
            
            visited[i] = false;
            k += dungeons[i][1];
        }
    }
}
