import java.util.*;

public class Floyd {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] dp = new int[n+1][n+1];
        for (int i = 1; i <= n; ++i)
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        for (int i = 0; i < m; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();

            dp[a][b] = Math.min(dp[a][b], c);
        }

        for (int k = 1; k <= n; ++k) {
            dp[k][k] = 0;
            for (int j = 1; j <= n; ++j) {
                for (int i = 1; i <= n; ++i) {
                    if (dp[i][k] != Integer.MAX_VALUE && dp[k][j] != Integer.MAX_VALUE)
                        dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dp[i][j] == Integer.MAX_VALUE)
                    dp[i][j] = 0;
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
    }
}
