import java.util.PriorityQueue;
import java.util.Scanner;

public class SortCard {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < n; ++i)
            pq.offer(sc.nextInt());

        int answer = 0;
        int tmp = 0;
        while (pq.size() > 1) {
            tmp = pq.poll();
            tmp += pq.poll();
            answer += tmp;
            pq.offer(tmp);
        }

        System.out.println(answer);
        sc.close();
    }
}
