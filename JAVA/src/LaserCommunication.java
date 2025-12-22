import java.util.*;

public class LaserCommunication {
    static class Node {
        int y, x, dir;

        Node(int y, int x, int dir) {
            this.y = y;
            this.x = x;
            this.dir = dir;
        }
    }

    static int w, h, answer;
    static char[][] map;
    static int[][][] dist;
    static Deque<Node> dq;

    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        w = sc.nextInt();
        h = sc.nextInt();
        map = new char[h][w];
        dist = new int[h][w][4];
        dq = new ArrayDeque<>();
        answer = 100000000;
        int sy = -1;
        int sx = -1;


        for (int i = 0; i < h; ++i) {
            String str = sc.next();
            for (int j = 0; j < w; ++j) {
                map[i][j] = str.charAt(j);

                for (int k = 0; k < 4; ++k)
                    dist[i][j][k] = 2147483647;

                if (sy == -1 && map[i][j] == 'C') {
                    sy = i;
                    sx = j;

                    for (int k = 0; k < 4; ++k)
                        dist[i][j][k] = 0;
                }

            }
        }

        for (int i = 0; i < 4; ++i) {
            int ny = sy + dy[i];
            int nx = sx + dx[i];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (map[ny][nx] == '*') continue;

            dist[ny][nx][i] = 0;
            dq.offer(new Node(ny, nx, i));
        }

        while (!dq.isEmpty()) {
            Node cur = dq.poll();

            if (map[cur.y][cur.x] == 'C')
                answer = Math.min(answer, dist[cur.y][cur.x][cur.dir]);

            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                int nc = cur.dir != i ? dist[cur.y][cur.x][cur.dir] + 1 : dist[cur.y][cur.x][cur.dir];

                if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                if (map[ny][nx] == '*') continue;
                if (dist[ny][nx][i] <= nc) continue;

                dist[ny][nx][i] = nc;
                if (nc > dist[cur.y][cur.x][cur.dir])
                    dq.offerLast(new Node(ny, nx, i));
                else
                    dq.offer(new Node(ny, nx, i));
            }
        }

        System.out.println(answer);
    }
}
