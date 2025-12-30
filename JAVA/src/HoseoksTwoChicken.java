import java.util.*;

public class HoseoksTwoChicken {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] dp = new int[n+1][n+1];
        for (int i = 1; i <= n; ++i) {
            Arrays.fill(dp[i], 1000000000);
            dp[i][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            dp[a][b] = 1;
            dp[b][a] = 1;
        }
        int[] answer = new int[2];
        int sum = Integer.MAX_VALUE;

        for (int k = 1; k <= n-1; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j)
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                int tmp = 0;
                for (int k = 1; k <= n; ++k)
                    tmp += Math.min(dp[i][k], dp[j][k]) * 2;

                if (sum > tmp) {
                    sum = tmp;
                    answer[0] = i;
                    answer[1] = j;
                }
            }
        }

        System.out.println(answer[0] + " " + answer[1] + " " + sum);
    }
}
