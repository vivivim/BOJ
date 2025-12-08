import java.util.Scanner;

public class FibonacciFunction {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; ++i) {
            int n = sc.nextInt();
            int[] zero = new int[n+1];
            int[] one = new int[n+1];

            zero[0] = 1;
            if (n > 0)
                one[1] = 1;

            for (int a = 2; a <= n; ++a) {
                zero[a] = zero[a-2] + zero[a-1];
                one[a] = one[a-2] + one[a-1];
            }

            System.out.println(zero[n] + " " + one[n]);
        }
    }
}
