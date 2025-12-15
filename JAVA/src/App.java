import java.util.Arrays;
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] memory = new int[n];
        int[] c = new int[n];
        for (int i = 0; i < n; ++i)
            memory[i] = sc.nextInt();
        for (int i = 0; i < n; ++i)
            c[i] = sc.nextInt();
        int[] dp = new int[10001];

        for (int i = 0; i < n; ++i) {
            for (int j = 10000; j >= c[i]; --j) {
                dp[j] = Math.max(dp[j], dp[j-c[i]] + memory[i]);
            }
        }

        int answer = 20000;
        for (int i = 0; i < 10001; ++i) {
            if (dp[i] >= m)
                answer = Math.min(answer, i);
        }
        System.out.println(answer);
    }
}
