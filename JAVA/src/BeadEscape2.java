import java.util.*;
import java.io.*;

public class BeadEscape2 {
    static class Node {
        int ry, rx, by, bx, cost;

        Node(int ry, int rx, int by, int bx, int cost) {
            this.ry = ry;
            this.rx = rx;
            this.by = by;
            this.bx = bx;
            this.cost = cost;
        }
    }

    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static char[][] map;
    static boolean[][][][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int ry = -1, rx = -1, by = -1, bx = -1;
        map = new char[n][m];
        for (int i = 0; i < n; ++i) {
            String str = new StringTokenizer(br.readLine()).nextToken();
            for (int j = 0; j < m; ++j) {
                map[i][j] = str.charAt(j);
                if (map[i][j] == 'R') {
                    ry = i;
                    rx = j;
                }
                if (map[i][j] == 'B') {
                    by = i;
                    bx = j;
                }
            }
        }
        visited = new boolean[n][m][n][m];
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(ry, rx, by, bx, 0));
        visited[ry][rx][by][bx] = true;

        while (!q.isEmpty()) {
            Node cur = q.poll();

            if (cur.cost >= 10) continue;

            for (int i = 0; i < 4; ++i) {
                int moveR = move(cur.ry, cur.rx, i);
                int nry = cur.ry + dy[i] * moveR;
                int nrx = cur.rx + dx[i] * moveR;

                int moveB = move(cur.by, cur.bx, i);
                int nby = cur.by + dy[i] * moveB;
                int nbx = cur.bx + dx[i] * moveB;

                if (map[nby+dy[i]][nbx+dx[i]] == 'O') continue;
                if (map[nry+dy[i]][nrx+dx[i]] == 'O') {
                    System.out.println((cur.cost+1));
                    return;
                }

                if (nry == nby && nrx == nbx) {
                    if (moveR > moveB) {
                        nry -= dy[i];
                        nrx -= dx[i];
                    } else {
                        nby -= dy[i];
                        nbx -= dx[i];
                    }
                }

                if (visited[nry][nrx][nby][nbx]) continue;

                visited[nry][nrx][nby][nbx] = true;
                q.offer(new Node(nry, nrx, nby, nbx, cur.cost+1));
            }
        }

        System.out.println(-1);
    }

    private static int move(int y, int x, int i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        int count = 0;

        while (map[ny][nx] != '#' && map[ny][nx] != 'O') {
            ny += dy[i];
            nx += dx[i];
            ++count;
        }

        return count;
    }
}
