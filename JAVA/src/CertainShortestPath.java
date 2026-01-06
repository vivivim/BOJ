import java.io.*;
import java.util.*;

public class CertainShortestPath {
    static class Node implements Comparable<Node> {
        int loc, o1, o2;
        long cost;

        Node(int loc, long cost, int o1, int o2) {
            this.loc = loc;
            this.cost = cost;
            this.o1 = o1;
            this.o2 = o2;
        }

        public int compareTo(Node o) {
            return Long.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<List<Node>> graph = new ArrayList<>();
        for (int i = 0; i <= n; ++i)
            graph.add(new ArrayList<>());
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph.get(a).add(new Node(b, c, 0, 0));
            graph.get(b).add(new Node(a, c, 0, 0));
        }
        st = new StringTokenizer(br.readLine());
        int o1 = Integer.parseInt(st.nextToken());
        int o2 = Integer.parseInt(st.nextToken());
        long[][][] dist = new long[n+1][2][2];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 2; ++j)
                Arrays.fill(dist[i][j], Integer.MAX_VALUE);
        }
        PriorityQueue<Node> pq = new PriorityQueue<>();
        if (o1 == 1)
            pq.offer(new Node(1, 0, 1, 0));
        else
            pq.offer(new Node(1, 0, 0, 0));
        dist[1][0][0] = 0;

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (cur.cost > dist[cur.loc][cur.o1][cur.o2]) continue;

            for (Node nd : graph.get(cur.loc)) {
                long newCost = cur.cost + nd.cost;
                int co1 = nd.loc == o1 ? 1 : cur.o1;
                int co2 = nd.loc == o2 ? 1 : cur.o2;

                if (newCost < dist[nd.loc][co1][co2]) {
                    dist[nd.loc][co1][co2] = newCost;
                    pq.offer(new Node(nd.loc, newCost, co1, co2));
                }
            }
        }

        System.out.println(dist[n][1][1] == Integer.MAX_VALUE ? -1 : dist[n][1][1]);
    }
}
