import java.util.*;

public class Guitarist {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int s = sc.nextInt();
        int m = sc.nextInt();
        int[] volume = new int[n];
        for (int i = 0; i < n; ++i)
            volume[i] = sc.nextInt();
        int[] dp = new int[m+1];

        if (s - volume[0] >= 0)
            dp[s - volume[0]] = 1;
        if (s + volume[0] <= m)
            dp[s + volume[0]] = 1;

        Queue<Integer> q = new LinkedList<>();

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (dp[j] != i) continue;

                if (j + volume[i] <= m)
                    q.offer(j + volume[i]);
                if (j - volume[i] >= 0)
                    q.offer(j - volume[i]);
            }

            while (!q.isEmpty())
                dp[q.poll()] = i+1;
        }

        int answer = -1;
        for (int i = m; i >= 0; --i) {
            if (dp[i] == n) {
                answer = i;
                break;
            }
        }
        System.out.println(answer);
    }
}
