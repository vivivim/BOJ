import java.util.*;

public class AttachVillageNumber {
    static class Coordinate {
        int y, x;

        Coordinate(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static int n;
    static int[][] village;
    static Queue<Coordinate> q;
    static boolean[][] visited;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        village = new int[n][n];

        for (int i = 0; i < n; ++i) {
            String str = sc.next();
            for (int j = 0; j < n; ++j) {
                village[i][j] = str.charAt(j) - '0';
            }
        }

        q = new LinkedList<>();
        visited = new boolean[n][n];
        int totalCt = 0;
        List<Integer> ct = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (village[i][j] == 1 && !visited[i][j]) {
                    ++totalCt;
                    visited[i][j] = true;
                    q.offer(new Coordinate(i, j));
                    ct.add(bfs());
                }
            }
        }

        Collections.sort(ct);
        System.out.println(totalCt);
        for (int house : ct) {
            System.out.println(house);
        }
    }

    private static int bfs() {
        int ct = 0;
        while (!q.isEmpty()) {
            Coordinate cur = q.poll();
            ++ct;

            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (visited[ny][nx]) continue;
                if (village[ny][nx] == 0) continue;

                visited[ny][nx] = true;
                q.offer(new Coordinate(ny, nx));
            }
        }

        return ct;
    }
}
