import java.util.*;

class Solution {
    class Coordi {
        int y, x;
        
        Coordi(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    
    int[][] picture;
    int m;
    int n;
    
    Queue<Coordi> q = new LinkedList<>();
    final int[] dy = {-1, 0, 1, 0};
    final int[] dx = {0, 1, 0, -1};
    boolean[][] visited;
    
    public int[] solution(int m, int n, int[][] picture) {
        this.m = m;
        this.n = n;
        this.picture = picture;
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        visited = new boolean[m][n];
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] > 0 && !visited[i][j]) {
                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea, bfs(i, j));
                    ++numberOfArea;
                }
            }
        }

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
    
    private int bfs(int i, int j) {
        int color = picture[i][j];
        int area = 1;
        
        visited[i][j] = true;
        q.offer(new Coordi(i, j));
        
        while (!q.isEmpty()) {
            Coordi coordi = q.poll();
            
            for (int a = 0; a < 4; ++a) {
                int ny = coordi.y + dy[a];
                int nx = coordi.x + dx[a];
                
                if (ny < 0 || nx < 0 || ny >= this.m || nx >= this.n) continue;
                if (picture[ny][nx] != color) continue;
                if (visited[ny][nx]) continue;
                
                visited[ny][nx] = true;
                q.offer(new Coordi(ny, nx));
                ++area;
            }
        }
        
        return area;
    }
}
