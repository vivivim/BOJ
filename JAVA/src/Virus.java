import java.util.*;

public class Virus {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        boolean[] infected = new boolean[n+1];
        List<List<Integer>> list = new ArrayList<>();
        int answer = -1;

        for (int i = 0; i <= n; ++i)
            list.add(new ArrayList<>());

        for (int i = 0; i < m; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            list.get(a).add(b);
            list.get(b).add(a);
        }

        Queue<Integer> q = new LinkedList<>();

        infected[1] = true;
        q.offer(1);
        while (!q.isEmpty()) {
            int cur = q.poll();
            ++answer;

            for (int next : list.get(cur)) {
                if (infected[next]) continue;

                infected[next] = true;
                q.offer(next);
            }
        }

        System.out.println(answer);
    }
}