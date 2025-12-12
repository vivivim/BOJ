import java.util.Arrays;
import java.util.Scanner;

public class Coin2 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        int[] coins = new int[n];
        for (int i = 0; i < n; ++i)
            coins[i] = sc.nextInt();
        Arrays.sort(coins);

        int[] dp = new int[k+1];
        dp[0] = 0;
        for (int i = 1; i <= k; ++i)
            dp[i] = 20000;

        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= k; ++j)
                dp[j] = Math.min(dp[j], dp[j-coins[i]]+1);
        }

        System.out.println(dp[k] == 20000 ? -1 : dp[k]);
    }
}
