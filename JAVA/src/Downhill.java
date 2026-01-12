import java.util.*;
import java.io.*;

public class Downhill {
    static int[][] map;
    static int[][] dp;
    static int m, n;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0,1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        map = new int[m][n];
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; ++j)
                map[i][j] = Integer.parseInt(st.nextToken());
        }
        dp = new int[m][n];
        for (int i = 0; i < m; ++i)
            Arrays.fill(dp[i], -1);

        dfs(0, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println(dp[0][0]);
    }

    private static int dfs(int y, int x) {
        if (y == m-1 && x == n-1) return 1;
        if (dp[y][x] > -1) return dp[y][x];

        dp[y][x] = 0;
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if (map[ny][nx] < map[y][x])
                dp[y][x] += dfs(ny, nx);
        }

        return dp[y][x];
    }
}