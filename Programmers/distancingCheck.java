import java.util.*;

class Solution {
    
    class Info {
        int x, y, ct;
        
        Info(int y, int x, int ct) {
            this.y = y;
            this.x = x;
            this.ct = ct;
        }
    }
    
    public int[] solution(String[][] places) {
        List<Integer> answer = new ArrayList<>();
        
        for (String[] place : places) {
            boolean isOk = true;
            
            room : for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    
                    if (place[i].charAt(j) == 'P' && !isFarAway(place, i, j)) {
                        isOk = false;
                        break room;
                    }
                }
            }
            
            if (!isOk)
                answer.add(0);
            else
                answer.add(1);
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
    
    private boolean isFarAway(String[] place, int y, int x) {
        boolean[][] visited = new boolean[5][5];
        Queue<Info> q = new LinkedList<>();
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, 1, 0, -1};
        
        q.offer(new Info(y, x, 0));
        visited[y][x] = true;
        
        while (!q.isEmpty()) {
            Info cur = q.poll();
            
            if (cur.ct > 0 && place[cur.y].charAt(cur.x) == 'P')
                return false;
            
            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                
                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                if (visited[ny][nx]) continue;
                if (cur.ct >= 2) continue;
                if (place[ny].charAt(nx) == 'X') continue;
                
                visited[ny][nx] = true;
                q.offer(new Info(ny, nx, cur.ct+1));
            }
        }

        return true;
    }
}
