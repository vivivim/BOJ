import java.util.*;
import java.io.*;

public class TomorrowTravel {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        Map<String, Integer> city = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        String[] places = getPlaces(st);
        for (int i = 0; i < places.length; ++i)
            city.put(places[i], i);
        n = places.length;

        int m = Integer.parseInt(br.readLine());
        List<Integer> travel = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; ++i)
            travel.add(city.get(st.nextToken()));

        int k = Integer.parseInt(br.readLine());
        double[][] yes = new double[n][n];
        double[][] no = new double[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(yes[i], Long.MAX_VALUE);
            Arrays.fill(no[i], Long.MAX_VALUE);
            yes[i][i] = 0;
            no[i][i] = 0;
        }
        for (int i = 0; i < k; ++i) {
            st = new StringTokenizer(br.readLine());
            String type = st.nextToken();
            Integer from = city.get(st.nextToken());
            Integer to = city.get(st.nextToken());
            double cost = Double.parseDouble(st.nextToken());

            if (type.equals("Mugunghwa") || type.equals("ITX-Saemaeul") || type.equals("ITX-Cheongchun")) {
                yes[from][to] = Math.min(yes[from][to], 0);
                yes[to][from] = Math.min(yes[to][from], 0);
            }
            else if (type.equals("S-Train") || type.equals("V-Train")) {
                yes[from][to] = Math.min(yes[from][to], cost / 2);
                yes[to][from] = Math.min(yes[to][from], cost / 2);
            }
            else {
                yes[from][to] = Math.min(yes[from][to], cost);
                yes[to][from] = Math.min(yes[to][from], cost);
            }
            no[from][to] = Math.min(no[from][to], cost);
            no[to][from] = Math.min(no[to][from], cost);
        }

        for (int a = 0; a < n; ++a) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (yes[i][a] != Long.MAX_VALUE && yes[a][j] != Long.MAX_VALUE)
                        yes[i][j] = Math.min(yes[i][j], yes[i][a] + yes[a][j]);
                    if (no[i][a] != Long.MAX_VALUE && no[a][j] != Long.MAX_VALUE)
                        no[i][j] = Math.min(no[i][j], no[i][a] + no[a][j]);
                }
            }
        }

        double noCost = 0, yesCost = r;
        int from = -1;
        for (int t : travel) {

            if (from == -1) {
                from = t;
                continue;
            }
            noCost += no[from][t];
            yesCost += yes[from][t];
            from = t;
        }

        System.out.println(noCost + " " + yesCost);
        if (noCost <= yesCost)
            System.out.println("No");
        else
            System.out.println("Yes");
    }

    private static String[] getPlaces(StringTokenizer st) {
        Set<String> set = new HashSet<>();

        while (st.hasMoreTokens()) {
            set.add(st.nextToken());
        }

        return set.toArray(String[]::new);
    }
}
