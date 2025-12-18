import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Migration {
    static class Node {
        int y, x;

        Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), l = sc.nextInt(), r = sc.nextInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                a[i][j] = sc.nextInt();
        }
        Queue<Node> q = new LinkedList<>();
        int answer = 0;

        while (true) {
            boolean[][] visited = new boolean[n][n];
            boolean isMoved = false;

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (visited[i][j]) continue;

                    q.offer(new Node(i, j));
                    visited[i][j] = true;
                    int sum = 0;
                    int ct = 0;
                    Queue<Node> union = new LinkedList<>();

                    while (!q.isEmpty()) {
                        Node cur = q.poll();
                        ++ct;
                        sum += a[cur.y][cur.x];
                        union.offer(cur);

                        for (int k = 0; k < 4; ++k) {
                            int ny = cur.y + dy[k];
                            int nx = cur.x + dx[k];

                            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                            if (visited[ny][nx]) continue;

                            int diff = Math.abs(a[ny][nx] - a[cur.y][cur.x]);
                            if (diff < l || diff > r) continue;

                            visited[ny][nx] = true;
                            q.offer(new Node(ny, nx));
                            isMoved = true;
                        }
                    }

                    while (!union.isEmpty()) {
                        Node cur = union.poll();

                        a[cur.y][cur.x] = sum/ct;
                    }
                }
            }

            if (!isMoved) break ;
            ++answer;
        }

        System.out.println(answer);
    }
}
