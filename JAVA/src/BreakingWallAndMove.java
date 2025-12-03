import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BreakingWallAndMove {
    static class Info {
        int y, x, ct;
        int isBreak;

        Info(int y, int x, int isBreak, int ct) {
            this.y = y;
            this.x = x;
            this.isBreak = isBreak;
            this.ct = ct;
        }
    }

    static int n;
    static int m;
    static boolean[][] map;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        map = new boolean[n][m];

        for (int i = 0; i < n; ++i) {
            String str = sc.next();
            for (int j = 0; j < m; ++j)
                map[i][j] = str.charAt(j) != '0';
        }

        Queue<Info> q = new LinkedList<>();
        boolean[][][] visited = new boolean[n][m][2];
        int answer = -1;

        q.offer(new Info(0, 0, 0, 1));
        visited[0][0][0] = true;

        while (!q.isEmpty()) {
            Info cur = q.poll();

            if (cur.y == n - 1 && cur.x == m - 1) {
                answer = cur.ct;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (visited[ny][nx][cur.isBreak]) continue;
                if (map[ny][nx] && cur.isBreak == 1) continue;

                if (map[ny][nx]) {
                    visited[ny][nx][cur.isBreak] = true;
                    q.offer(new Info(ny, nx, 1, cur.ct + 1));
                } else {
                    visited[ny][nx][cur.isBreak] = true;
                    q.offer(new Info(ny, nx, cur.isBreak, cur.ct + 1));
                }
            }
        }

        System.out.println(answer);
    }
}
