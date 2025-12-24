import java.util.*;

public class SundayMorningDate {
    static class Node implements Comparable<Node> {
        int y, x, t, st;

        Node(int y, int x, int t, int st) {
            this.y = y;
            this.x = x;
            this.t = t;
            this.st = st;
        }

        @Override
        public int compareTo(Node o) {
            if (this.t == o.t)
                return Integer.compare(this.st, o.st);
            return Integer.compare(this.t, o.t);
        }
    }

    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int n, m;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        char[][] map = new char[n][m];
        int[][][] dist = new int[n][m][2];
        PriorityQueue<Node> pq = new PriorityQueue<>();
        int fy = 0, fx = 0;
        for (int i = 0; i < n; ++i) {
            String str = sc.next();
            for (int j = 0; j < m; ++j) {
                map[i][j] = str.charAt(j);
                dist[i][j][0] = Integer.MAX_VALUE;
                dist[i][j][1] = Integer.MAX_VALUE;

                if (map[i][j] == 'S') {
                    pq.offer(new Node(i, j, 0, 0));
                    dist[i][j][0] = 0;
                    dist[i][j][1] = 0;
                } else if (map[i][j] == 'F') {
                    fy = i;
                    fx = j;
                }
            }
        }

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (cur.t > dist[cur.y][cur.x][0] || cur.st > dist[cur.y][cur.x][1]) continue;
            if (cur.y == fy && cur.x == fx) break;

            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                int nt = cur.t;
                int nst = cur.st;

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (map[ny][nx] == 'g') ++nt;
                if (map[ny][nx] == '.' && isNextTrash(map, ny, nx)) ++nst;

                if (nt < dist[ny][nx][0]) {
                    dist[ny][nx][0] = nt;
                    dist[ny][nx][1] = nst;
                    pq.offer(new Node(ny, nx, nt, nst));
                }
                if (nt == dist[ny][nx][0] && nst < dist[ny][nx][1]) {
                    dist[ny][nx][1] = nst;
                    pq.offer(new Node(ny, nx, nt, nst));
                }
            }
        }

        System.out.println(dist[fy][fx][0] + " " + dist[fy][fx][1]);
    }

    private static boolean isNextTrash(char[][] map, int y, int x) {
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (map[ny][nx] == 'g') return true;
        }

        return false;
    }
}
