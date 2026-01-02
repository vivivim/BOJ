import java.util.*;

public class CommonSubstring {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String one = sc.next();
        String two = sc.next();
        int ol = one.length();
        int tl = two.length();
        int[][] dp = new int[ol+1][tl+1];
        int answer = 0;

        for (int i = 0; i < ol; ++i) {
            for (int j = 0; j < tl; ++j) {
                if (one.charAt(i) == two.charAt(j))
                    dp[i+1][j+1] = dp[i][j] + 1;
                else
                    dp[i+1][j+1] = 0;
                answer = Math.max(answer, dp[i+1][j+1]);
            }
        }

        System.out.println(answer);
    }
}
