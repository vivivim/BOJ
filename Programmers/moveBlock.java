import java.util.*;

class Solution {
    class Info {
        int ly, lx, ry, rx, time;

        Info(int ly, int lx, int ry, int rx, int time) {
            // normalize
            if (ly > ry || (ly == ry && lx > rx)) {
                this.ly = ry;
                this.lx = rx;
                this.ry = ly;
                this.rx = lx;
            } else {
                this.ly = ly;
                this.lx = lx;
                this.ry = ry;
                this.rx = rx;
            }
            this.time = time;
        }
    }

    boolean[][][][] visited;
    int n;
    final int[] dy = {-1, 0, 1, 0};
    final int[] dx = {0, 1, 0, -1};

    public int solution(int[][] board) {
        n = board.length;
        visited = new boolean[n][n][n][n];
        Queue<Info> q = new LinkedList<>();

        Info start = new Info(0, 0, 0, 1, 0);
        visited[start.ly][start.lx][start.ry][start.rx] = true;
        q.offer(start);

        while (!q.isEmpty()) {
            Info cur = q.poll();

            if ((cur.ly == n - 1 && cur.lx == n - 1) ||
                (cur.ry == n - 1 && cur.rx == n - 1)) {
                return cur.time;
            }

            // 이동
            for (int i = 0; i < 4; i++) {
                int nly = cur.ly + dy[i];
                int nlx = cur.lx + dx[i];
                int nry = cur.ry + dy[i];
                int nrx = cur.rx + dx[i];

                if (out(nly, nlx) || out(nry, nrx)) continue;
                if (board[nly][nlx] == 1 || board[nry][nrx] == 1) continue;

                Info next = new Info(nly, nlx, nry, nrx, cur.time + 1);
                
                if (visited[next.ly][next.lx][next.ry][next.rx]) continue;
                
                visited[next.ly][next.lx][next.ry][next.rx] = true;
                q.offer(next);
            }

            boolean isGaro = cur.ly == cur.ry;

            // 회전
            if (isGaro) {
                // 위
                int ny = cur.ly - 1;
                if (ny >= 0 && board[ny][cur.lx] == 0 && board[ny][cur.rx] == 0) {
                    rotate(cur.ly, cur.lx, ny, cur.lx, cur.time, q);
                    rotate(cur.ry, cur.rx, ny, cur.rx, cur.time, q);
                }

                // 아래
                ny = cur.ly + 1;
                if (ny < n && board[ny][cur.lx] == 0 && board[ny][cur.rx] == 0) {
                    rotate(cur.ly, cur.lx, ny, cur.lx, cur.time, q);
                    rotate(cur.ry, cur.rx, ny, cur.rx, cur.time, q);
                }
            } else {
                // 오른쪽
                int nx = cur.lx + 1;
                if (nx < n && board[cur.ly][nx] == 0 && board[cur.ry][nx] == 0) {
                    rotate(cur.ly, cur.lx, cur.ly, nx, cur.time, q);
                    rotate(cur.ry, cur.rx, cur.ry, nx, cur.time, q);
                }

                // 왼쪽
                nx = cur.lx - 1;
                if (nx >= 0 && board[cur.ly][nx] == 0 && board[cur.ry][nx] == 0) {
                    rotate(cur.ly, cur.lx, cur.ly, nx, cur.time, q);
                    rotate(cur.ry, cur.rx, cur.ry, nx, cur.time, q);
                }
            }
        }

        return 0;
    }

    private void rotate(int ay, int ax, int by, int bx, int time, Queue<Info> q) {
        Info next = new Info(ay, ax, by, bx, time + 1);
        
        if (visited[next.ly][next.lx][next.ry][next.rx]) return;
        
        visited[next.ly][next.lx][next.ry][next.rx] = true;
        q.offer(next);
    }

    private boolean out(int y, int x) {
        return y < 0 || x < 0 || y >= n || x >= n;
    }
}

