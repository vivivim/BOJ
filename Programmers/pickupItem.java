import java.util.*;

class Solution {
    class Coordinate {
        int y, x, ct;
        
        Coordinate(int y, int x, int ct) {
            this.y = y;
            this.x = x;
            this.ct = ct;
        }
    }
    
    int[][] map;
    Queue<Coordinate> q;
    boolean[][] visited;
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, 1, 0, -1};
    int ct;
    int[][] rectangle;
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int answer = 0;
        this.rectangle = rectangle;
        map = new int[101][101];
        q = new LinkedList<>();
        visited = new boolean[101][101];
        
        setRectangle();
        deleteInside();
        
        int cx = characterX*2 - 1, cy = characterY*2 - 1;
        int ix = itemX*2 - 1, iy = itemY*2 - 1;
        
        q.offer(new Coordinate(cy, cx, 0));
        visited[cy][cx] = true;
        
        while(!q.isEmpty()) {
            Coordinate cur = q.poll();
            
            if (cur.y == iy && cur.x == ix) {
                answer = cur.ct/2;
                break ;
            }
            
            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                
                if (ny < 0 || nx < 0 || ny >= 100 || nx >= 100) continue;
                if (map[ny][nx] == 0 || visited[ny][nx]) continue;
                
                visited[ny][nx] = true;
                q.offer(new Coordinate(ny, nx, cur.ct+1));
            }
        }
        
        return answer;
    }
    
    private void setRectangle() {
        for (int[] r : rectangle) {
            int lx = r[0]*2-1;
            int ly = r[1]*2-1;
            int rx = r[2]*2-1;
            int ry = r[3]*2-1;
            
            for (int i = lx; i <= rx; ++i) {
                map[ly][i] = 1;
                map[ry][i] = 1;
            }
            for (int i = ly; i <= ry; ++i) {
                map[i][lx] = 1;
                map[i][rx] = 1;
            }
        }
    }
    
    private void deleteInside() {
        for (int[] r : rectangle) {
            int lx = r[0]*2-1;
            int ly = r[1]*2-1;
            int rx = r[2]*2-1;
            int ry = r[3]*2-1;
            
            for (int i = lx+1; i <= rx-1; ++i) {
                for (int j = ly+1; j <= ry-1; ++j)
                    map[j][i] = 0;
            }
        }
    }
}
