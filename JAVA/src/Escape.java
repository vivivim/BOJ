import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Escape {
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    static int r, c;
    static char[][] map;
    static int[][] wMap;

    static class Coordinate {
        int y, x, ct;
        Coordinate(int y, int x, int ct) {
            this.y = y;
            this.x = x;
            this.ct = ct;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        map = new char[r][c];
        wMap = new int[r][c];
        Queue<Coordinate> q = new LinkedList<>();
        boolean[][] visited = new boolean[r][c];
        for (int i = 0; i < r; ++i) {
            String str = sc.next();
            for (int j = 0; j < c; ++j) {
                map[i][j] = str.charAt(j);

                if (map[i][j] == 'S') {
                    q.offer(new Coordinate(i, j, 0));
                    visited[i][j] = true;
                }
            }
        }

        goWater();

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j)
                System.out.print(wMap[i][j] + " ");
            System.out.println();
        }

        while (!q.isEmpty()) {
            Coordinate cur = q.poll();
            System.out.println("cur : " + cur.y + " " + cur.x + " " + cur.ct);

            if (map[cur.y][cur.x] == 'D') {
                System.out.println(cur.ct);
                return ;
            }


            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if (map[ny][nx] == '*' || map[ny][nx] == 'X') continue;
                if (wMap[ny][nx] <= cur.ct+1) continue;
                if (visited[ny][nx]) continue;

                visited[ny][nx] = true;
                q.offer(new Coordinate(ny, nx, cur.ct+1));
            }
        }

        System.out.println("KAKTUS");
    }

    private static void goWater() {
        Queue<Coordinate> q = new LinkedList<>();
        boolean[][] visited = new boolean[r][c];

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (map[i][j] == '*') {
                    q.offer(new Coordinate(i, j, 0));
                    visited[i][j] = true;
                }
                wMap[i][j] = 10000;
            }
        }

        while (!q.isEmpty()) {
            Coordinate cur = q.poll();

            wMap[cur.y][cur.x] = cur.ct;

            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if (map[ny][nx] == 'X' || map[ny][nx] == 'D') continue;
                if (visited[ny][nx]) continue;

                visited[ny][nx] = true;
                q.offer(new Coordinate(ny, nx, cur.ct+1));
            }
        }
    }
}
