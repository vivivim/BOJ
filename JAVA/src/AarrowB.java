import java.util.Scanner;

public class AarrowB {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int answer = 1;

        while (b > a) {
            if (b % 10 == 1)
                b /= 10;
            else if (b % 2 == 0)
                b /= 2;
            else
                break;
            ++answer;
        }
        if (b != a) answer = -1;

        System.out.println(answer);
        sc.close();
    }
}
