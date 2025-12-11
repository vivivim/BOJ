import java.util.Arrays;
import java.util.Scanner;

public class NormalBackpack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[][] info = new int[n][2];
        for (int i = 0; i < n; ++i) {
            info[i][0] = sc.nextInt();
            info[i][1] = sc.nextInt();
        }
        int[] dp = new int[k+1];

        for (int i = 0; i < n; ++i) {
            for (int j = k - info[i][0]; j >= 0; --j) {
                if (j != 0 && dp[j] == 0) continue;

                int weight = info[i][0] + j;

                dp[weight] = Math.max(dp[weight], dp[j] + info[i][1]);
            }
        }

        System.out.println(Arrays.stream(dp).max().getAsInt());
    }
}
