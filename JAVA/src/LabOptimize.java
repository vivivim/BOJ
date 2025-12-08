import java.util.*;

public class LabOptimize {
    static class Coordinate {
        int y, x;

        Coordinate(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static int[][] map;
    static int n, m, answer;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static List<Coordinate> virus;
    static List<Coordinate> originalWall;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        answer = 0;
        map = new int[n][m];
        virus = new ArrayList<>();
        originalWall = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                map[i][j] = sc.nextInt();

                if (map[i][j] == 2)
                    virus.add(new Coordinate(i, j));
                if (map[i][j] == 1)
                    originalWall.add(new Coordinate(i, j));
            }
        }

        setWalls(0, 0);

        System.out.println(answer);
    }

    // 조합 방식
    private static void setWalls(int start, int depth) {
        if (depth == 3) {
            goVirus();
            return;
        }

        for (int idx = start; idx < n * m; idx++) {
            int y = idx / m;
            int x = idx % m;

            if (map[y][x] == 0) {
                map[y][x] = 1;
                Coordinate newWall = new Coordinate(y, x);

                originalWall.add(newWall);

                setWalls(idx + 1, depth + 1);
                map[y][x] = 0;
                originalWall.remove(newWall);
            }
        }
    }

    private static void goVirus() {
        Queue<Coordinate> q = new LinkedList<>();
        boolean[][] visited = new boolean[n][m];

        for (Coordinate v : virus) {
            visited[v.y][v.x] = true;
            q.offer(v);
        }
        for (Coordinate o : originalWall)
            visited[o.y][o.x] = true;

        while (!q.isEmpty()) {
            Coordinate cur = q.poll();

            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx]) continue;

                visited[ny][nx] = true;
                q.offer(new Coordinate(ny, nx));
            }
        }

        countVirus(visited);
    }

    private static void countVirus(boolean[][] visited) {
        int ct = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j])
                    ++ct;
            }
        }

        answer = Math.max(answer, ct);
    }
}
