import java.util.*;

class Solution {
    
    class Info {
        int x;
        int y;
        int ct;
        
        Info(int x, int y, int ct) {
            this.x = x;
            this.y = y;
            this.ct = ct;
        }
    }
    
    public int solution(int[][] maps) {
        int answer = -1;
        Queue<Info> q = new LinkedList<>();
        int n = maps.length;
        int m = maps[0].length;
        boolean[][] visited = new boolean[n][m];
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, 1, 0, -1};
        
        q.offer(new Info(0, 0, 1));
        
        while (!q.isEmpty()) {
            Info info = q.poll();
            
            if (info.y == n-1 && info.x == m-1) {
                answer = info.ct;
                break ;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nx = info.x + dx[i];
                int ny = info.y + dy[i];
                
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (visited[ny][nx]) continue;
                if (maps[ny][nx] == 0) continue;
                
                visited[ny][nx] = true;
                q.offer(new Info(nx, ny, info.ct + 1));
            }
        }
        
        return answer;
    }
}
