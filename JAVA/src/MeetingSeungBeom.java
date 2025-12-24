import java.util.*;

public class MeetingSeungBeom {
    static class Node implements Comparable<Node> {
        int loc;
        long cost;

        Node(int loc, long cost) {
            this.loc = loc;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return Long.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        List<List<Node>> graph = new ArrayList<>();
        for (int i = 0; i <= n; ++i)
            graph.add(new ArrayList<>());
        for (int i = 0; i < m; ++i) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int c = sc.nextInt();
            graph.get(v).add(new Node(u, c));
        }
        List<Integer> meeting = new ArrayList<>();
        for (int i = 0; i < k; ++i)
            meeting.add(sc.nextInt());
        long[] dist = new long[n+1];
        for (int i = 0; i <= n; ++i)
            dist[i] = Long.MAX_VALUE;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        for (int meet : meeting) {
            pq.offer(new Node(meet, 0));
            dist[meet] = 0;
        }

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (cur.cost > dist[cur.loc]) continue;

            for (Node nd : graph.get(cur.loc)) {
                long newCost = cur.cost + nd.cost;

                if (newCost < dist[nd.loc]) {
                    dist[nd.loc] = newCost;
                    pq.offer(new Node(nd.loc, newCost));
                }
            }
        }

        int city = 0;
        long distance = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] != Integer.MAX_VALUE && dist[i] > distance) {
                distance = dist[i];
                city = i;
            }
        }

        System.out.println(city);
        System.out.println(distance);
    }
}
