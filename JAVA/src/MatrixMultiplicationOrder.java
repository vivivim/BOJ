import java.util.*;
import java.io.*;

public class MatrixMultiplicationOrder {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
            dp[i][i] = 0;
        }
        int[] row = new int[n];
        int[] col = new int[n];
        for (int i = 0; i < n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            row[i] = Integer.parseInt(st.nextToken());
            col[i] = Integer.parseInt(st.nextToken());
        }

        for (int len = 1; len < n; ++len) {
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;

                for (int k = i; k < j; ++k) {
                    int times = row[i] * col[k] * col[j];

                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k+1][j] + times);
                }
            }
        }

        System.out.println(dp[0][n-1]);
    }
}
