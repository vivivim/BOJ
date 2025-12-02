import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Rope {
    static int n = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        Integer[] r = new Integer[n];
        for (int i = 0; i < n; ++i)
            r[i] = sc.nextInt();

        int answer = 0;

        Arrays.sort(r, Collections.reverseOrder());

        for (int i = 0; i < n; ++i) {
            answer = Math.max(answer, r[i] * (i+1));
        }

        System.out.println(answer);
        sc.close();
    }
}