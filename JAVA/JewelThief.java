import java.util.*;

public class JewelThief {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        List<int[]> jewels = new ArrayList<>();
        PriorityQueue<Integer> bags = new PriorityQueue<>();

        for (int i = 0; i < n; ++i)
            jewels.add(new int[] {sc.nextInt(), sc.nextInt()});
        for (int i = 0; i < k; ++i)
            bags.offer(sc.nextInt());

        jewels.sort(Comparator.comparingInt(a -> a[0]));

        long answer = 0;
        int ldx = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        while (!bags.isEmpty()) {
            Integer can = bags.poll();

            while (ldx < n && jewels.get(ldx)[0] <= can) {
                pq.offer(jewels.get(ldx)[1]);
                ++ldx;
            }
            if (!pq.isEmpty())
                answer += pq.poll();
        }

        System.out.println(answer);
        sc.close();
    }
}
