import java.util.*;

public class Wormhole {
    static class Node {
        int loc, cost;

        Node(int loc, int cost) {
            this.loc = loc;
            this.cost = cost;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();
        while (tc-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int w = sc.nextInt();

            List<List<Node>> graph = new ArrayList<>();
            for (int i = 0; i <= n; ++i)
                graph.add(new ArrayList<>());

            for (int i = 0; i < m; ++i) {
                int s = sc.nextInt();
                int e = sc.nextInt();
                int t = sc.nextInt();

                graph.get(s).add(new Node(e, t));
                graph.get(e).add(new Node(s, t));
            }

            for (int i = 0; i < w; ++i) {
                int s = sc.nextInt();
                int e = sc.nextInt();
                int t = sc.nextInt() * -1;

                graph.get(s).add(new Node(e, t));
            }
            int[] dist = new int[n+1];

            for (int a = 1; a < n; ++a) {
                for (int i = 1; i <= n; ++i) {
                    for (Node nd : graph.get(i)) {
                        int newTime = dist[i] + nd.cost;

                        if (newTime < dist[nd.loc]) {
                            dist[nd.loc] = newTime;
                        }
                    }
                }
            }

            boolean isCycle = false;

            for (int i = 1; i <= n; ++i) {
                for (Node nd : graph.get(i)) {
                    int newTime = dist[i] + nd.cost;

                    if (newTime < dist[nd.loc])
                        isCycle = true;
                }
            }

            if (isCycle)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
