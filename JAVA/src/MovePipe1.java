import java.io.*;
import java.util.StringTokenizer;

public class MovePipe1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] house = new int[n][n];
        for (int i = 0; i < n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int j = 0; j < n; ++j)
                house[i][j] = Integer.parseInt(st.nextToken());
        }
        int[][][] dp = new int[n][n][3];
        dp[0][1][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (house[i][j] == 1) continue;


                if (j - 1 >= 0)
                    dp[i][j][0] += dp[i][j-1][0] + dp[i][j-1][2];

                if (i - 1 >= 0)
                    dp[i][j][1] += dp[i - 1][j][1] + dp[i-1][j][2];

                if (i - 1 >= 0 && j - 1 >= 0) {
                    if (house[i-1][j] == 1 || house[i][j-1] == 1) continue;
                    dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < 3; ++i)
            answer += dp[n-1][n-1][i];

        System.out.println(answer);
    }
}
