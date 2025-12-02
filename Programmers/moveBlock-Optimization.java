import java.util.*;

class Solution {
    class Info {
        int x, y, dir, time;

        Info(int y, int x, int dir, int time) {
            this.y = y;
            this.x = x;
            this.dir = dir;
            this.time = time;
        }
    }

    boolean[][][] visited;
    int n;
    final int[] dy = {-1, 0, 1, 0};
    final int[] dx = {0, 1, 0, -1};

    public int solution(int[][] board) {
        n = board.length;
        visited = new boolean[n][n][2];
        Queue<Info> q = new LinkedList<>();

        visited[0][0][0] = true;
        q.offer(new Info(0, 0, 0, 0));

        while (!q.isEmpty()) {
            Info cur = q.poll();
            
            if ((cur.y == n - 1 && cur.x == n - 2 && cur.dir == 0) ||
                (cur.y == n - 2 && cur.x == n - 1 && cur.dir == 1)) {
                return cur.time;
            }

            // 이동
            for (int i = 0; i < 4; i++) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                int my = (cur.dir == 0) ? ny : ny + 1;
                int mx = (cur.dir == 0) ? nx + 1 : nx;
                
                if (out(ny, nx) || out(my, mx)) continue;
                if (board[ny][nx] == 1 || board[my][mx] == 1) continue;
                if (visited[ny][nx][cur.dir]) continue;
                
                visited[ny][nx][cur.dir] = true;
                q.offer(new Info(ny, nx, cur.dir, cur.time+1));
            }

            // 회전
            if (cur.dir == 0) {
                // 위
                if (cur.y-1 >= 0 && board[cur.y-1][cur.x] == 0 && board[cur.y-1][cur.x+1] == 0) {
                    rotate(cur.y-1, cur.x, 1, cur.time, q);
                    rotate(cur.y-1, cur.x+1, 1, cur.time, q);
                }
                // 아래
                if (cur.y + 1 < n && board[cur.y+1][cur.x] == 0 && board[cur.y+1][cur.x+1] == 0) {
                    rotate(cur.y, cur.x, 1, cur.time, q);
                    rotate(cur.y, cur.x+1, 1, cur.time, q);
                }
            } else {
                // 오른쪽
                if (cur.x+1 < n && board[cur.y][cur.x+1] == 0 && board[cur.y+1][cur.x+1] == 0) {
                    rotate(cur.y, cur.x, 0, cur.time, q);
                    rotate(cur.y+1, cur.x, 0, cur.time, q);
                }
                // 왼쪽
                if (cur.x-1 >= 0 && board[cur.y][cur.x-1] == 0 && board[cur.y+1][cur.x-1] == 0) {
                    rotate(cur.y, cur.x-1, 0, cur.time, q);
                    rotate(cur.y+1, cur.x-1, 0, cur.time, q);
                }
            }
        }

        return 0;
    }

    private void rotate(int ay, int ax, int dir, int time, Queue<Info> q) {
        if (visited[ay][ax][dir]) return;
        
        visited[ay][ax][dir] = true;
        q.offer(new Info(ay, ax, dir, time+1));
    }

    private boolean out(int y, int x) {
        return y < 0 || x < 0 || y >= n || x >= n;
    }
}

