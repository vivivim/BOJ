import java.util.*;
import java.io.*;

public class TreeAndQuery {
    static List<List<Integer>> tree;
    static boolean[] visited;
    static int[] size;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        tree = new ArrayList<>();
        size = new int[n+1];
        Arrays.fill(size, 1);
        for (int i = 0; i <= n; ++i)
            tree.add(new ArrayList<>());
        visited = new boolean[n+1];
        for (int i = 0; i < n-1; ++i) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            tree.get(u).add(v);
            tree.get(v).add(u);
        }
        visited[r] = true;
        dfs(r);

        for (int i = 0; i < q; ++i) {
            int root = Integer.parseInt(br.readLine());

            System.out.println(size[root]);
        }
    }

    static private void dfs(int cur) {
        for (int next : tree.get(cur)) {
            if (visited[next]) continue;

            visited[next] = true;
            dfs(next);
            size[cur] += size[next];
        }
    }
}