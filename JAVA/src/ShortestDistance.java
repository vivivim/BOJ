import java.util.*;

public class ShortestDistance {
    static class Edge {
        int to, cost;

        Edge(int to, int cost) {
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
        int v = sc.nextInt();
        int e = sc.nextInt();
        int k = sc.nextInt();
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i <= v; ++i)
            graph.add(new ArrayList<>());
        for (int i = 0; i < e; ++i) {
            int u = sc.nextInt();
            int x = sc.nextInt();
            int w = sc.nextInt();

            graph.get(u).add(new Edge(x, w));
        }
        int[] dist = new int[v+1];
        Arrays.fill(dist, 2147483647);
        dist[k] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(k, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (cur.cost > dist[cur.loc]) continue;

            for (Edge ed : graph.get(cur.loc)) {
                int nc = cur.cost + ed.cost;
                if (dist[ed.to] > nc) {
                    dist[ed.to] = nc;
                    pq.offer(new Node(ed.to, nc));
                }
            }
        }

        for (int i = 1; i <= v; ++i) {
            if (dist[i] == 2147483647)
                System.out.println("INF");
            else
                System.out.println(dist[i]);
        }

    }
}
