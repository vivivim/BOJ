import java.util.*;

public class PavingRoad {
    static class Node implements Comparable<Node> {
        int loc, paved;
        long cost;

        Node(int loc, int paved, long cost) {
            this.loc = loc;
            this.paved = paved;
            this.cost = cost;
        }

        public int compareTo(Node o) {
            return Long.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        List<List<Node>> road = new ArrayList<>();
        for (int i = 0; i <= n; ++i)
            road.add(new ArrayList<>());
        for (int i = 0; i < m; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();

            road.get(a).add(new Node(b, 0, c));
            road.get(b).add(new Node(a, 0, c));
        }
        long[][] dist = new long[n+1][k+1];
        for (int i = 1; i <= n; ++i)
            Arrays.fill(dist[i], Long.MAX_VALUE);
        dist[1][0] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(1, 0, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (cur.cost > dist[cur.loc][cur.paved]) continue;

            for (Node nd : road.get(cur.loc)) {
                long newCost = cur.cost + nd.cost;

                if (newCost < dist[nd.loc][cur.paved]) {
                    dist[nd.loc][cur.paved] = newCost;
                    pq.offer(new Node(nd.loc, cur.paved, newCost));
                }

                if (cur.paved < k && cur.cost < dist[nd.loc][cur.paved+1]) {
                    dist[nd.loc][cur.paved+1] = cur.cost;
                    pq.offer(new Node(nd.loc, cur.paved+1, cur.cost));
                }
            }
        }

        System.out.println(Arrays.stream(dist[n]).min().orElse(0));
    }
}
