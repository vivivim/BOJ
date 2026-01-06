import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class LIS4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] num = new int[n];
        for (int i = 0; i < n; ++i)
            num[i] = Integer.parseInt(st.nextToken());
        int[] dp = new int[n];
        int[] prev = new int[n];
        Arrays.fill(prev, -1);
        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (num[j] < num[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                    if (dp[j] + 1 == dp[i])
                        prev[i] = j;
                }
            }
        }

        int lastIdx = 0, max = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > max) {
                max = dp[i];
                lastIdx = i;
            }
        }

        while (lastIdx != -1) {
            s.push(num[lastIdx]);
            lastIdx = prev[lastIdx];
        }

        System.out.println(max);
        while (!s.isEmpty())
            System.out.print(s.pop()+ " ");
    }
}
