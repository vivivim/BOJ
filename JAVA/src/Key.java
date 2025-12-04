import java.util.*;

public class Key {
    static class Coordinate {
        int y, x;

        Coordinate(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static int n, m, answer;
    static char[][] map;
    static Queue<Coordinate> q;
    static List<Coordinate> list;
    static Set<Character> set;
    static boolean[][] visited;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        for (int t = 0; t < tc; ++t) {
            input(sc);

            while(!q.isEmpty()) {
                Coordinate cur = q.poll();
                char curMap = map[cur.y][cur.x];

                if (curMap == '$') {
                    map[cur.y][cur.x] = '.';
                    ++answer;
                } else if (curMap >= 'a' && curMap <= 'z') {
                    set.add((char) (curMap - 32));
                    map[cur.y][cur.x] = '.';
                    q.clear();
                    visited = new boolean[n][m];
                    visited[cur.y][cur.x] = true;

                    for (Coordinate coord : list) {
                        q.offer(coord);
                        visited[coord.y][coord.x] = true;
                    }
                } else if (curMap >= 'A' && curMap <= 'Z' && !isOpen(curMap)) continue;

                for (int i = 0; i < 4; ++i) {
                    int ny = cur.y + dy[i];
                    int nx = cur.x + dx[i];

                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    if (map[ny][nx] == '*') continue;
                    if (visited[ny][nx]) continue;
                    if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z' && !isOpen(map[ny][nx])) continue;

                    visited[ny][nx] = true;
                    q.offer(new Coordinate(ny, nx));
                }
            }

            System.out.println(answer);
        }


    }

    private static boolean isOpen(char door) {
        return set.contains(door);
    }

    private static void input(Scanner sc) {
        n = sc.nextInt();
        m = sc.nextInt();
        map = new char[n][m];
        q = new LinkedList<>();
        list = new ArrayList<>();
        set = new HashSet<>();
        answer = 0;
        visited = new boolean[n][m];

        for (int i = 0; i < n; ++i) {
            String str = sc.next();
            for (int j = 0; j < m; ++j) {
                map[i][j] = str.charAt(j);
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && map[i][j] != '*') {
                    visited[i][j] = true;
                    q.offer(new Coordinate(i, j));
                    list.add(new Coordinate(i, j));
                }
            }
        }

        String str = sc.next();
        if (str.equals("0")) return ;
        for (int i = 0; i < str.length(); ++i)
            set.add((char) (str.charAt(i) - 32));
    }
}
