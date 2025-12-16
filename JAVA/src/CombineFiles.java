import java.util.Scanner;

public class CombineFiles {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int a = 0; a < t; ++a) {
            int k = sc.nextInt();
            int[] file = new int[k];
            for (int i = 0; i < k; ++i)
                file[i] = sc.nextInt();
            int[][] dp = new int[k + 1][k + 1];
            for (int i = 0; i <= k; ++i) {
                for (int j = 0; j <= k; ++j)
                    dp[i][j] = i == j ? 0 : 10000000;
            }
            int[] hap = new int[k+1];
            for (int i = 1; i <= k; ++i)
                hap[i] = hap[i-1] + file[i-1];

            for (int i = 0; i < k+1; ++i)
                System.out.print(hap[i] + " ");
            System.out.println();

            for (int i = 1; i < k; ++i) {
                for (int j = 1; j <= k - i; ++j) {
                    for (int l = j; l < i+j; ++l)
                        dp[j][j+i] = Math.min(dp[j][j+i], dp[j][l] + dp[l+1][j+i] + hap[j+i] - hap[j-1]);
                    System.out.println("dp["+j+"]["+(int)(j+i)+"]: " + dp[j][j+i]);
                }
            }
            System.out.println(dp[1][k]);
        }
    }
}
