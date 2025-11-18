import java.util.Scanner;

public class GasStation {
    static int n = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        int[] road = new int[n-1];
        int[] gas = new int[n];

        for (int i = 0; i < n-1; i++) {
            road[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            gas[i] = sc.nextInt();
        }

        int minGas = gas[0];
        long answer = 0;

        for (int i = 0; i < n-1; i++) {
            minGas = Math.min(minGas, gas[i]);
            answer += (long) minGas * road[i];
        }
        System.out.println(answer);
        sc.close();
    }
}
