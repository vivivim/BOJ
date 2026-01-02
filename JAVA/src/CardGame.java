import java.util.*;

public class CardGame {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] left = new int[n];
        int[] right = new int[n];
        for (int i = 0; i < n; ++i)
            left[i] = sc.nextInt();
        for (int i = 0; i < n; ++i)
            right[i] = sc.nextInt();
        int[][] dp = new int[n+1][n+1];

        for (int i = n-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                dp[i][j] = Math.max(dp[i+1][j+1], dp[i+1][j]);
                if (right[j] < left[i])
                    dp[i][j] = Math.max(dp[i][j], dp[i][j+1] + right[j]);
            }
        }

        System.out.println(dp[0][0]);
    }
}
