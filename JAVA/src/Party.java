import java.util.*;
import java.io.*;

public class Party {
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

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        List<List<Node>> road = new ArrayList<>();
        List<List<Node>> reverse = new ArrayList<>();
        for (int i = 0; i <= n; ++i) {
            road.add(new ArrayList<>());
            reverse.add(new ArrayList<>());
        }
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            road.get(a).add(new Node(b, c));
            reverse.get(b).add(new Node(a, c));
        }

        int[] toX = dijkstra(x, reverse, n);
        int[] fromX = dijkstra(x, road, n);
        int answer = 0;
        for (int i = 1; i <= n; ++i) {
            int tmp = toX[i] + fromX[i];

            if (answer < tmp)
                answer = tmp;
        }

        System.out.println(answer);
    }

    private static int[] dijkstra(int start, List<List<Node>> graph, int n) {
        int[] dist = new int[n+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        dist[start] = 0;

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (dist[cur.loc] < cur.cost) continue;

            for (Node nd : graph.get(cur.loc)) {
                int newCost = cur.cost + nd.cost;

                if (dist[nd.loc] > newCost) {
                    dist[nd.loc] = newCost;
                    pq.offer(new Node(nd.loc, newCost));
                }
            }
        }

        return dist;
    }
}
