import java.util.*;

public class SixRuleOfKevinBacon {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] dp = new int[n+1][n+1];
        for (int i = 1; i <= n; ++i) {
            Arrays.fill(dp[i], 100000000);
            dp[i][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            dp[a][b] = 1;
            dp[b][a] = 1;
        }

        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j)
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }

        int answer = 0, sum = Integer.MAX_VALUE;
        for (int i = 1; i <= n; ++i) {
            int tmp = Arrays.stream(dp[i]).sum();
            if (sum > tmp) {
                sum = tmp;
                answer = i;
            }
        }

        System.out.println(answer);
    }
}
