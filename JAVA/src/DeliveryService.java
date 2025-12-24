import java.util.*;

public class DeliveryService {
    static class Node implements Comparable<Node> {
        int loc, cost;

        Node(int loc, int cost) {
            this.loc = loc;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<List<Node>> graph = new ArrayList<>();
        for (int i = 0; i <=n; ++i)
            graph.add(new ArrayList<>());
        for (int i = 0; i < m; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();

            graph.get(a).add(new Node(b, c));
            graph.get(b).add(new Node(a, c));
        }
        int[] dist = new int[n+1];
        for (int i = 2; i <= n; ++i)
            dist[i] = Integer.MAX_VALUE;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(1, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (cur.loc == n) {
                System.out.println(cur.cost);
                return ;
            }
            if (cur.cost > dist[cur.loc]) continue;

            for (Node nd : graph.get(cur.loc)) {
                int newCost = cur.cost + nd.cost;

                if (newCost < dist[nd.loc]) {
                    dist[nd.loc] = newCost;
                    pq.offer(new Node(nd.loc, newCost));
                }
            }
        }
    }
}
