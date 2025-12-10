import java.util.Scanner;

public class LongestAscendingSubsequence {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] seq = new int[n];
        for (int i = 0; i < n; ++i)
            seq[i] = sc.nextInt();
        int[] dp = new int[n];
        int answer = 0;

        for (int i = 0; i < n; ++i) {
            int temp = 0;
            dp[i] = 1;

            for (int j = i-1; j >= 0; --j) {
                if (seq[j] < seq[i] && temp < dp[j]) {
                    temp = dp[j];
                    dp[i] = dp[j] + 1;
                }
            }
            answer = Math.max(answer, dp[i]);
        }

        System.out.println(answer);
    }
}
