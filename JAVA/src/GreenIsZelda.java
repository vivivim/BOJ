import java.util.*;

public class GreenIsZelda {
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    static class Node implements Comparable<Node> {
        int y, x, cost;

        Node(int y, int x, int cost) {
            this.y = y;
            this.x = x;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int test = 1;
        while (n != 0) {
            int[][] map = new int[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j)
                    map[i][j] = sc.nextInt();
            }
            int[][] dist = new int[n][n];
            for (int i = 0; i < n; ++i)
                Arrays.fill(dist[i], Integer.MAX_VALUE);
            PriorityQueue<Node> pq = new PriorityQueue<>();
            pq.offer(new Node(0, 0,  map[0][0]));
            dist[0][0] = map[0][0];

            while(!pq.isEmpty()) {
                Node cur = pq.poll();

                if (cur.cost > dist[cur.y][cur.x]) continue;

                for (int i = 0; i < 4; ++i) {
                    int ny = cur.y + dy[i];
                    int nx = cur.x + dx[i];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

                    int newCost = cur.cost + map[ny][nx];
                    if (newCost >= dist[ny][nx]) continue;

                    pq.offer(new Node(ny, nx, newCost));
                    dist[ny][nx] = newCost;
                }
            }

            System.out.println("Problem " + test + ": " + dist[n-1][n-1]);
            n = sc.nextInt();
            ++test;
        }
    }
}
