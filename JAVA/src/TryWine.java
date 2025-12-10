import java.util.Scanner;

public class TryWine {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] wine = new int[n];
        for (int i = 0; i < n; ++i)
            wine[i] = sc.nextInt();
        int[] dp = new int[n];

        dp[0] = wine[0];
        if (n > 1)
            dp[1] = wine[0] + wine[1];
        if (n > 2) {
            dp[2] = Math.max(wine[0] + wine[2], wine[1] + wine[2]);
            dp[2] = Math.max(dp[1], dp[2]);
        }
        if (n > 3) {
            for (int i = 3; i < n; ++i) {
                dp[i] = Math.max(wine[i - 1] + dp[i - 3], dp[i - 2]) + wine[i];
                dp[i] = Math.max(dp[i], dp[i - 1]);
            }
        }

        System.out.println(dp[n-1]);
    }
}
