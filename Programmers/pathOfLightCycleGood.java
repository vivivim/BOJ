import java.util.*;

class Solution {
    public int[] solution(String[] g) {
        List<Integer> answer = new ArrayList<>();
        int c = g.length;
        int r = g[0].length();
        char[][] grid = makeGrid(g, c, r);
        // 0 - up, 1 - right, 2 - down, 3 - left;
        boolean[][][] visited = new boolean[c][r][4];
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, 1, 0, -1};
        
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < r; ++j) {                
                for (int k = 0; k < 4; ++k) {
                    int ct = 0, y = i, x = j, dir = k;
                    
                    while (!visited[y][x][dir]) {
                        visited[y][x][dir] = true;
                        ct++;
                        
                        if (grid[y][x] == 'L') dir = (dir + 3) % 4;
                        else if (grid[y][x] == 'R') dir = (dir + 1) % 4;
                        
                        y = (y + dy[dir] + c) % c;
                        x = (x + dx[dir] + r) % r;
                    }

                    if (ct != 0)
                        answer.add(ct);
                }
            }
        }

        return answer.stream().mapToInt(Integer::intValue).sorted().toArray();
    }
    
    private char[][] makeGrid(String[] grid, int c, int r) {
        char[][] newGrid = new char[c][r];
        
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < r; ++j)
                newGrid[i][j] = grid[i].charAt(j);
        }
        
        
        return newGrid;
    }
}
