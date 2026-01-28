import java.util.*;
import java.io.*;

public class Tomato {
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int[][] box;

    static class Node {
        int y, x, day;

        Node(int y, int x, int day) {
            this.y = y;
            this.x = x;
            this.day = day;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        box = new int[n][m];
        Queue<Node> q = new LinkedList<>();
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; ++j) {
                box[i][j] = Integer.parseInt(st.nextToken());
                if (box[i][j] == 1)
                    q.offer(new Node(i, j, 0));
            }
        }
        int answer = -1;

        while (!q.isEmpty()) {
            Node cur = q.poll();

            answer = Math.max(answer, cur.day);

            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (box[ny][nx] != 0) continue;

                q.offer(new Node(ny, nx, cur.day+1));
                box[ny][nx] = 1;
            }
        }

        if (!isRiped(n, m))
            answer = -1;
        System.out.println(answer);
    }

    private static boolean isRiped(int n, int m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (box[i][j] == 0)
                    return false;
            }
        }

        return true;
    }
}
