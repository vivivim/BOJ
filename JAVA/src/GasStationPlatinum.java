import java.util.*;
import java.io.*;

public class GasStationPlatinum {
    static class Node implements Comparable<Node> {
        int loc, gas;
        long cost;

        Node(int loc, long cost, int gas) {
            this.loc = loc;
            this.cost = cost;
            this.gas = gas;
        }

        @Override
        public int compareTo(Node o) {
            return Long.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] gas = new int[n+1];
        List<List<Node>> graph = new ArrayList<>();
        for (int i = 0; i <= n; ++i)
            graph.add(new ArrayList<>());
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; ++i)
            gas[i] = Integer.parseInt(st.nextToken());
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());

            graph.get(from).add(new Node(to, dist, to));
            graph.get(to).add(new Node(from, dist, from));
        }
        long[][] dp = new long[n+1][n+1];
        for (int i = 0; i <= n; ++i) {
            Arrays.fill(dp[i], Long.MAX_VALUE);
        }
        dp[1][1] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(1, 0, 1));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (cur.loc == n) {
                System.out.println(cur.cost);
                return ;
            }
            if (cur.cost > dp[cur.loc][cur.gas]) continue;

            for (Node nd : graph.get(cur.loc)) {
                long nc = cur.cost + nd.cost * gas[cur.gas];
                int ng = gas[cur.gas] > gas[nd.gas] ? nd.gas : cur.gas;

                if (nc >= dp[nd.loc][ng]) continue;

                dp[nd.loc][ng] = nc;
                pq.offer(new Node(nd.loc, nc, ng));
            }

        }
    }
}
