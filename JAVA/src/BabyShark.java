import java.util.PriorityQueue;
import java.util.Scanner;

public class BabyShark {
    static class Info implements Comparable<Info> {
        int y, x, ate, size, time;

        Info(int y, int x, int size, int ate, int time) {
            this.y = y;
            this.x = x;
            this.size = size;
            this.ate = ate;
            this.time = time;
        }

        @Override
        public int compareTo(Info o) {
            if (this.time != o.time) return this.time - o.time;
            if (this.y != o.y) return this.y - o.y;
            return this.x - o.x;
        }
    }

    static int n;
    static boolean[][] visited;
    static int[] dy = {-1, 0, 0, 1};
    static int[] dx = {0, -1, 1, 0};
    static int[][] map;
    static PriorityQueue<Info> q;
    static int ct;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        visited = new boolean[n][n];
        map = new int[n][n];
        q = new PriorityQueue<>();
        ct = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                map[i][j] = sc.nextInt();

                if (map[i][j] == 9) {
                    visited[i][j] = true;
                    q.offer(new Info(i, j, 2, 0, 0));
                }
            }
        }

        while (!q.isEmpty()) {
            Info cur = q.poll();

            int what = map[cur.y][cur.x];
            if (what > 0 && what <= 6) {
                if (cur.size > what) {
                    ct += cur.time;
                    map[cur.y][cur.x] = 0;
                    q.clear();
                    visited = new boolean[n][n];
                    visited[cur.y][cur.x] = true;
                    cur.time = 0;

                    if (cur.ate + 1 == cur.size) {
                        ++cur.size;
                        cur.ate = 0;
                    }
                    else
                        ++cur.ate;
                }
            }

            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (visited[ny][nx]) continue;
                if (map[ny][nx] != 9 && map[ny][nx] > cur.size) continue;

                visited[ny][nx] = true;
                q.offer(new Info(ny, nx, cur.size, cur.ate, cur.time+1));
            }
        }

        System.out.println(ct);
    }
}
