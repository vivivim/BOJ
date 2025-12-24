import java.util.*;

public class UnidentifiedDestination {
    static class Node implements Comparable<Node> {
        int loc, cost;
        boolean gh;

        Node(int loc, int cost, boolean gh) {
            this.loc = loc;
            this.cost = cost;
            this.gh = gh;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int t = sc.nextInt();
            int s = sc.nextInt();
            int g = sc.nextInt();
            int h = sc.nextInt();
            List<List<Node>> graph = new ArrayList<>();
            for (int i = 0; i <= n; ++i)
                graph.add(new ArrayList<>());
            for (int i = 0; i < m; ++i) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                int d = sc.nextInt();

                graph.get(a).add(new Node(b, d, false));
                graph.get(b).add(new Node(a, d, false));
            }
            List<Integer> dest = new ArrayList<>();
            Set<Integer> set = new HashSet<>();
            for (int i = 0; i < t; ++i)
                set.add(sc.nextInt());
            PriorityQueue<Node> pq = new PriorityQueue<>();
            pq.offer(new Node(s, 0, false));
            int[][] dist = new int[n+1][2];
            for (int i = 0; i <= n; ++i)
                Arrays.fill(dist[i], Integer.MAX_VALUE);

            while (!pq.isEmpty()) {
                Node cur = pq.poll();

                if (cur.cost > dist[cur.loc][1]) continue;

                for (Node nd : graph.get(cur.loc)) {
                    int newCost = cur.cost + nd.cost;

                    if (newCost < dist[nd.loc][0]) {
                        dist[nd.loc][0] = newCost;
                        pq.offer(new Node(nd.loc, newCost, false));
                    }
                    if ((cur.loc == g && nd.loc == h) || (cur.loc == h && nd.loc == g) || cur.gh) {
                        if (newCost < dist[nd.loc][1]) {
                            dist[nd.loc][1] = newCost;
                            pq.offer(new Node(nd.loc, newCost, true));
                        }
                    }
                }
            }

            for (Integer c : set) {
                if (dist[c][0] == dist[c][1] && dist[c][0] != Integer.MAX_VALUE)
                    dest.add(c);
            }

            Collections.sort(dest);
            for (Integer de : dest)
                System.out.print(de + " ");
            System.out.println();
        }
    }
}
