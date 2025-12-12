import java.util.Scanner;

public class LCS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String one = sc.next();
        String two = sc.next();
        int[][] dp = new int[one.length()+1][two.length()+1];

        for (int i = 0; i < one.length(); ++i) {
            for (int j = 0; j < two.length(); ++j) {
                if (one.charAt(i) == two.charAt(j))
                    dp[i+1][j+1] = dp[i][j] + 1;
                else
                    dp[i+1][j+1] = Math.max(dp[i+1][j], dp[i][j+1]);
            }
        }

        System.out.println(dp[one.length()][two.length()]);
    }
}
