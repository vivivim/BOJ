import java.util.*;

public class TimeMachine {
    static class Node{
        int loc, cost;

        Node(int loc, int cost) {
            this.loc = loc;
            this.cost = cost;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<List<Node>> bus = new ArrayList<>();
        for (int i = 0; i <= n; ++i)
            bus.add(new ArrayList<>());
        for (int i = 0; i < m; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            bus.get(a).add(new Node(b, c));
        }
        long[] dist = new long[n+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[1] = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[j] == Integer.MAX_VALUE) continue;

                for (Node nd : bus.get(j)) {
                    long newTime = dist[j] + nd.cost;

                    if (newTime < dist[nd.loc])
                        dist[nd.loc] = newTime;
                }
            }
        }

        for (int i = 1; i < n; ++i) {
            if (dist[i] == Integer.MAX_VALUE) continue;

            for (Node nd : bus.get(i)) {
                long newTime = dist[i] + nd.cost;

                if (dist[nd.loc] > newTime) {
                    System.out.println(-1);
                    return;
                }
            }
        }

        for (int i = 2; i <= n; ++i) {
            if (dist[i] == Integer.MAX_VALUE)
                System.out.println(-1);
            else
                System.out.println(dist[i]);
        }
    }
}
