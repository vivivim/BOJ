import java.util.Scanner;

public class RobotVacuum {
    static int n, m, r, c, d;
    static int[][] map;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        r = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt();
        map = new int[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                map[i][j] = sc.nextInt();
        }
        int answer = 0;

        while (true) {
            if (map[r][c] == 0) {
                map[r][c] = 2;
                ++answer;
            }

            if (cleanCheck()) {
                d = (d+3) % 4;
                goFront();
            } else {
                if (canBack())
                    goBack();
                else
                    break ;
            }
        }

        System.out.println(answer);
    }

    private static void goFront() {
        switch (d) {
            case 0:
                if (r - 1 >= 0 && map[r-1][c] == 0)
                    --r;
                break;
            case 1:
                if (c + 1 < m && map[r][c+1] == 0)
                    ++c;
                break;
            case 2:
                if (r + 1 < n && map[r+1][c] == 0)
                    ++r;
                break;
            case 3:
                if (c - 1 >= 0 && map[r][c-1] == 0)
                    --c;
                break;
        }
    }

    private static void goBack() {
        switch (d) {
            case 0:
                ++r;
                break;
            case 1:
                --c;
                break;
            case 2:
                --r;
                break;
            case 3:
                ++c;
                break;
        }
    }

    private static boolean canBack() {
        switch(d) {
            case 0:
                return r + 1 < n && map[r + 1][c] != 1;
            case 1:
                return c - 1 >= 0 && map[r][c - 1] != 1;
            case 2:
                return r - 1 >= 0 && map[r - 1][c] != 1;
            case 3:
                return c + 1 < m && map[r][c + 1] != 1;
        }
        return false;
    }

    private static boolean cleanCheck() {
        for (int i = 0; i < 4; ++i) {
            int nr = r + dy[i];
            int nc = c + dx[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (map[nr][nc] == 0)
                return true;
        }

        return false;
    }
}
