import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class FindLowestCost {
    static class Edge {
        int to, cost;

        Edge (int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }

    static class Node implements Comparable<Node> {
        int loc, cost;

        Node(int loc, int cost) {
            this.loc = loc;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<List<Edge>> bus = new ArrayList<>();
        int[] dist = new int[n+1];
        for (int i = 0; i <= n; ++i) {
            bus.add(new ArrayList<>());
            dist[i] = 2147483647;
        }
        for (int i = 0; i < m; ++i) {
            int from = sc.nextInt();
            int to = sc.nextInt();
            int cost = sc.nextInt();

            bus.get(from).add(new Edge(to, cost));
        }
        int start = sc.nextInt();
        int end = sc.nextInt();
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        dist[start] = 0;

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (cur.cost > dist[cur.loc]) continue;
            if (cur.loc == end) {
                System.out.println(dist[end]);
                return;
            }

            for (Edge e : bus.get(cur.loc)) {
                int newCost = cur.cost + e.cost;

                if (newCost < dist[e.to]) {
                    dist[e.to] = newCost;
                    pq.offer(new Node(e.to, newCost));
                }
            }
        }
    }
}
