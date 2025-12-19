import java.util.*;

public class Alphabet {
    static boolean[] alpha = new boolean[27];
    static int answer = 0;
    static int r, c;
    static char[][] map;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        map = new char[r][c];
        for (int i = 0; i < r; ++i) {
            String str = sc.next();
            for (int j = 0; j < c; ++j)
                map[i][j] = str.charAt(j);
        }

        alpha[map[0][0] - 'A'] = true;
        dfs(1, 0, 0);

        System.out.println(answer);
    }

    private static void dfs(int depth, int y, int x) {
        answer = Math.max(answer, depth);

       for (int i = 0; i < 4; ++i) {
           int ny = y + dy[i];
           int nx = x + dx[i];

           if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
           if (alpha[map[ny][nx] - 'A']) continue;

           alpha[map[ny][nx] - 'A'] = true;
           dfs(depth+1, ny, nx);
           alpha[map[ny][nx] - 'A'] = false;
       }
    }
}
