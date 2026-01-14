import java.util.*;
import java.io.*;

public class OhUmbrella {
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    static class Node {
        int y, x, mask, time;

        Node(int y, int x, int mask, int time) {
            this.y = y;
            this.x = x;
            this.mask = mask;
            this.time = time;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        char[][] map = new char[m][n];
        int[][] ix = new int[m][n];
        int xCount = 0;
        Queue<Node> q = new LinkedList<>();
        boolean[][][] visited = new boolean[m][n][1 << 5];
        for (int i = 0; i < m; ++i) {
            String str = new StringTokenizer(br.readLine()).nextToken();
            for (int j = 0; j < n; ++j) {
                map[i][j] = str.charAt(j);
                if (map[i][j] == 'S') {
                    q.offer(new Node(i, j, 0, 0));
                    visited[i][j][0] = true;
                }
                else if (map[i][j] == 'X')
                    ix[i][j] = xCount++;
            }
        }
        int answer = 0;

        while (!q.isEmpty()) {
            Node cur = q.poll();

            if (map[cur.y][cur.x] == 'E' && cur.mask == (1 << xCount) -1) {
                answer = cur.time;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                if (map[ny][nx] == '#') continue;

                int nm = map[ny][nx] == 'X' ? cur.mask | 1 << ix[ny][nx] : cur.mask;

                if (visited[ny][nx][nm]) continue;

                visited[ny][nx][nm] = true;
                q.offer(new Node(ny, nx, nm, cur.time+1));
            }
        }

        System.out.println(answer);
    }
}
