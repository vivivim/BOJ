import java.util.*;
import java.io.*;

public class TallOrder {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        boolean[][] dp = new boolean[n+1][n+1];
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; ++i)
            graph.add(new ArrayList<>());
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            dp[a][b] = true;
        }

        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dp[i][k] && dp[k][j])
                        dp[i][j] = true;
                }
            }
        }

        int answer = 0, tmp = 0;
        for (int i = 1; i <= n; ++i) {
            tmp = 0;
            for (int j = 1; j <= n; ++j) {
                if (dp[i][j] || dp[j][i])
                    ++tmp;
            }

            if (tmp == n-1)
                ++answer;
        }


        System.out.println(answer);
    }
}
