import java.util.Arrays;
import java.util.Scanner;

public class Rope {
    static int n = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        int[] a = new int[n];
        int[] b = new int[n];

        for (int i = 0; i < n; ++i)
            a[i] = sc.nextInt();
        for (int i = 0; i < n; ++i)
            b[i] = sc.nextInt();

        int answer = 0;

        Arrays.sort(a);
        Arrays.sort(b);

        for (int i = 0; i < n; ++i)
            answer += a[i] * b[n-i-1];

        System.out.println(answer);
        sc.close();
    }
}