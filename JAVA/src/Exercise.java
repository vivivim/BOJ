import java.util.*;

public class Exercise {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt();
        int e = sc.nextInt();
        int[][] dp = new int[v+1][v+1];
        for (int i = 1; i <= v; ++i)
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        for (int i = 0; i < e; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();

            dp[a][b] = c;
        }

        for (int k = 1; k <= v; ++k) {
            for (int i = 1; i <= v; ++i) {
                for (int j = 1; j <= v; ++j) {
                    if (dp[i][k] != Integer.MAX_VALUE && dp[k][j] != Integer.MAX_VALUE)
                        dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        int answer = Integer.MAX_VALUE;
        for (int i = 1; i <= v; ++i) {
            answer = Math.min(answer, dp[i][i]);
        }

        System.out.println(answer == Integer.MAX_VALUE ? -1 : answer);
    }
}
