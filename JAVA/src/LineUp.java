import java.util.*;

public class LineUp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] kids = new int[n];
        for (int i = 0; i < n; ++i)
            kids[i] = sc.nextInt();
        int[] dp = new int[n];

        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (kids[i] > kids[j])
                    dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }

        System.out.println((n - Arrays.stream(dp).max().orElse(0)));
    }
}
