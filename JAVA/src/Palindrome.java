import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Palindrome {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int[] num = new int[n+1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; ++i)
            num[i] = Integer.parseInt(st.nextToken());

        boolean[][] dp = new boolean[n+1][n+1];
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j+i <= n; ++j) {
                if (i == 0)
                    dp[j][j] = true;
                else if (i == 1 && num[j] == num[j+1])
                    dp[j][j+1] = true;
                else if (num[j] == num[j+i] && dp[j+1][j+i-1])
                    dp[j][j+i] = true;
            }
        }

        int m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            if (dp[s][e])
                sb.append("1\n");
            else
                sb.append("0\n");
        }

        System.out.print(sb);
    }
}
