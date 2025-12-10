import java.util.Arrays;
import java.util.Scanner;

public class RGBDistance {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] rgb = new int[n][3];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j)
                rgb[i][j] = sc.nextInt();
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j)
                rgb[i][j] += Math.min(rgb[i - 1][(j + 1) % 3], rgb[i - 1][(j + 2) % 3]);
        }

        System.out.println(Arrays.stream(rgb[n-1]).min().getAsInt());
    }
}
