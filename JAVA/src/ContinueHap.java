import java.util.Scanner;

public class ContinueHap {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] seq = new int[n];
        for (int i = 0; i < n; ++i)
            seq[i] = sc.nextInt();
        int[] dp = new int[n];
        int answer = seq[0];

        dp[0] = seq[0];

        for (int i = 1; i < n; ++i) {
            dp[i] = Math.max(dp[i - 1] + seq[i], seq[i]);
            answer = Math.max(answer, dp[i]);
        }

        System.out.println(answer);
    }
}
