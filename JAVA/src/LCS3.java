import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LCS3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String one = br.readLine();
        String two = br.readLine();
        String three = br.readLine();
        int ol = one.length();
        int tl = two.length();
        int hl = three.length();
        int[][][] dp = new int[ol+1][tl+1][hl+1];

        for (int i = 0; i < ol; ++i) {
            for (int j = 0; j < tl; ++j) {
                for (int k = 0; k < hl; ++k) {
                    if (one.charAt(i) == two.charAt(j) && two.charAt(j) == three.charAt(k))
                        dp[i+1][j+1][k+1] = dp[i][j][k] + 1;
                    else
                        dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k], dp[i+1][j][k+1], dp[i][j+1][k+1]);
                }
            }
        }

        System.out.println(dp[ol][tl][hl]);
        br.close();
    }

    private static int max(int a, int b, int c) {
        return Math.max(a, Math.max(b, c));
    }
}
