import java.util.*;

class Solution {
    class Node implements Comparable<Node> {
        int to, cost;
        
        Node(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
        
        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.cost, o.cost);
        }
    }
    
    public int solution(int n, int[][] road, int k) {
        int answer = 0;
        List<List<Node>> graph = new ArrayList<>();
        for (int i = 0; i <= n; ++i)
            graph.add(new ArrayList<>());
        for (int[] r : road) {
            graph.get(r[0]).add(new Node(r[1], r[2]));
            graph.get(r[1]).add(new Node(r[0], r[2]));
        }
        int[] dist = new int[n+1];
        Arrays.fill(dist, 2147483647);
        dist[1] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(1, 0));
        
        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            
            if (cur.cost > dist[cur.to]) continue;
            
            for (Node nd : graph.get(cur.to)) {
                int nc = cur.cost + nd.cost;
                
                if (nc < dist[nd.to]) {
                    dist[nd.to] = nc;
                    pq.offer(new Node(nd.to, nc));
                }
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            if (dist[i] <= k)
                ++answer;
        }
        
        return answer;
    }
}
