import java.util.Scanner;

public class PadovanSequence {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            long[] dp = new long[100];

            dp[0] = 1;
            dp[1] = 1;
            dp[2] = 1;
            for (int i = 3; i < n; ++i)
                dp[i] = dp[i - 3] + dp[i - 2];

            System.out.println(dp[n-1]);
        }
    }
}
