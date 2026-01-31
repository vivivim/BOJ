import java.util.Scanner;

public class CodeTree {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[][] grid = new int[n][n];
        int[][][][] dp = new int[n][n][2][k+1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        dp[0][1][0][0] = 1;
        dp[1][0][1][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) continue;

                if (i-1 >= 0) {
                    for (int e = 0; e < k+1; ++e) {
                        dp[i][j][1][e] += dp[i-1][j][1][e];

                        if (e < k)
                            dp[i][j][0][e+1] += dp[i-1][j][1][e];
                    }
                }

                if (j-1 >= 0) {
                    for (int e = 0; e < k+1; ++e) {
                        dp[i][j][0][e] += dp[i][j-1][0][e];

                        if (e < k)
                            dp[i][j][1][e+1] += dp[i][j-1][0][e];
                    }
                }
            }
        }
        int answer = 0;
        for (int i = 0; i < k+1; ++i) {
            answer += dp[n-1][n-1][0][i] + dp[n-1][n-1][1][i];
        }

        System.out.println(answer);
    }
}