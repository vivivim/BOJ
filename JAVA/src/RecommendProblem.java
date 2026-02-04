import java.util.*;
import java.io.*;

public class RecommendProblem {
    static class Problem implements Comparable<Problem> {
        int p, l;

        Problem(int p, int l) {
            this.p = p;
            this.l = l;
        }

        @Override
        public int compareTo(Problem o) {
            if (this.l == o.l)
                return Integer.compare(o.p, this.p);
            return Integer.compare(o.l, this.l);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        TreeSet<Problem> set = new TreeSet<>();
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());

            set.add(new Problem(p, l));
            map.put(p, l);
        }

        int m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String commend = st.nextToken();

            if (commend.equals("recommend")) {
                int p = Integer.parseInt(st.nextToken());
                Problem out = p == 1 ? set.first() : set.last();

                System.out.println(out.p);
            } else if (commend.equals("add")) {
                int p = Integer.parseInt(st.nextToken());
                int l = Integer.parseInt(st.nextToken());

                set.add(new Problem(p, l));
                map.put(p, l);
            } else if(commend.equals("solved")) {
                int p = Integer.parseInt(st.nextToken());
                int l = map.get(p);

                set.remove(new Problem(p, l));
                map.remove(p);
            }
        }
    }
}
