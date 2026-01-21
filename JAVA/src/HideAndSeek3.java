import java.util.*;
import java.io.*;

public class HideAndSeek3 {
    static class Node implements Comparable<Node> {
        int loc, time;

        Node(int loc, int time) {
            this.loc = loc;
            this.time = time;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.time, o.time);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        PriorityQueue<Node> q = new PriorityQueue<>();
        int[] dist = new int[100001];
        Arrays.fill(dist, Integer.MAX_VALUE);
        q.offer(new Node(n, 0));
        dist[n] = 0;

        while (!q.isEmpty()) {
            Node cur = q.poll();

            if (dist[cur.loc] < cur.time) continue;

            if (cur.loc - 1 >= 0 && dist[cur.loc-1] > cur.time+1) {
                dist[cur.loc - 1] = cur.time + 1;
                q.offer(new Node(cur.loc - 1, cur.time + 1));
            }

            if (cur.loc + 1 <= 100000 && dist[cur.loc+1] > cur.time+1) {
                q.offer(new Node(cur.loc + 1, cur.time + 1));
                dist[cur.loc + 1] = cur.time + 1;
            }

            if (cur.loc * 2 <= 100000 && dist[cur.loc*2] > cur.time) {
                q.offer(new Node(cur.loc * 2, cur.time));
                dist[cur.loc * 2] = cur.time;
            }
        }

        System.out.println(dist[k]);
    }
}
