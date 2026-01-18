import java.util.*;
import java.io.*;

public class MoonGo {
    static class Node {
        int y, x, time, key;

        Node(int y, int x, int time, int key) {
            this.y = y;
            this.x = x;
            this.time = time;
            this.key = key;
        }
    }

    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        char[][] map = new char[n][m];
        boolean[][][] visited = new boolean[n][m][1 << 6];
        Queue<Node> q = new LinkedList<>();
        for (int i = 0; i < n; ++i) {
            String str = br.readLine();
            for (int j = 0; j < m; ++j) {
                map[i][j] = str.charAt(j);
                if (map[i][j] == '0') {
                    visited[i][j][0] = true;
                    q.offer(new Node(i, j, 0, 0));
                }
            }
        }
        int answer = -1;

        while (!q.isEmpty()) {
            Node cur = q.poll();

            if (map[cur.y][cur.x] == '1') {
                answer = cur.time;
                break ;
            }

            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (map[ny][nx] == '#') continue;

                int nk = cur.key | getKey(map[ny][nx]);

                if (visited[ny][nx][nk]) continue;
                if (!hasKey(nk, map[ny][nx])) continue;

                q.offer(new Node(ny, nx, cur.time+1, nk));
                visited[ny][nx][nk] = true;
            }
        }

        System.out.println(answer);
    }

    private static boolean hasKey(int key, char map) {
        if (map < 'A' || map > 'F') return true;

        return (key & (1 << map - 'A')) != 0;
    }

    private static int getKey(char map) {
        if (map < 'a' || map > 'f') return 0;

        return 1 << (map - 'a');
    }
}
