import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class RGBDistance2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] rgb = new int[n][3];
        StringTokenizer st;
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            rgb[i][0] = Integer.parseInt(st.nextToken());
            rgb[i][1] = Integer.parseInt(st.nextToken());
            rgb[i][2] = Integer.parseInt(st.nextToken());
        }
        int[][] dp = new int[n][3];
        int answer = 1000000000;

        for (int i = 0; i < 3; ++i) {
            int o1 = (i+1)%3;
            int o2 = (i+2)%3;

            dp[0][i] = rgb[0][i];
            dp[0][o1] = 1000000000;
            dp[0][o2] = 1000000000;

            for (int j = 1; j < n; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int k1 = (k+1)%3;
                    int k2 = (k+2)%3;

                    dp[j][k] = Math.min(dp[j-1][k1], dp[j-1][k2]) + rgb[j][k];
                }
            }
            answer = Math.min(answer, Math.min(dp[n-1][o1], dp[n-1][o2]));
        }

        System.out.println(answer);
    }
}
