import java.util.*;

class Solution {
    public int[] solution(String[] g) {
        List<Integer> answer = new ArrayList<>();
        int c = g.length;
        int r = g[0].length();
        char[][] grid = makeGrid(g, c, r);
         boolean[][][] visited = new boolean[c][r][4];
        // 0 - up, 1 - right, 2 - down, 3 - left;
        
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < r; ++j) {                
                for (int k = 0; k < 4; ++k) {
                    int ct = 0, y = i, x = j, dir = k;
                    
                    while (true) {
                        if (grid[y][x] == 'S') {
                            if (visited[y][x][dir]) break;
                            
                            visited[y][x][dir] = true;
                            switch (dir) {
                                case 0: --y;
                                    if (y < 0) y = c - 1;
                                    break ;
                                case 1: ++x;
                                    if (x == r) x = 0;
                                    break ;
                                case 2: ++y;
                                    if (y == c) y = 0;
                                    break ;
                                case 3: --x;
                                    if (x < 0) x = r - 1;
                                    break ;
                            }
                        } else if (grid[y][x] == 'L') {
                            if (dir == 0) {
                                dir = 3;
                                if (visited[y][x][dir]) break;
                                visited[y][x][dir] = true;
                                --x;
                                if (x < 0) x = r - 1;
                            } else if (dir == 1) {
                                dir = 0;
                                if (visited[y][x][dir]) break;
                                visited[y][x][dir] = true;
                                --y;
                                if (y < 0) y = c - 1;
                            } else if (dir == 2) {
                                dir = 1;
                                if (visited[y][x][dir]) break;
                                visited[y][x][dir] = true;
                                ++x;
                                if (x == r) x = 0;
                            } else if (dir == 3) {
                                dir = 2;
                                if (visited[y][x][dir]) break;
                                visited[y][x][dir] = true;
                                ++y;
                                if (y == c) y = 0;
                            }
                        } else if (grid[y][x] == 'R') {
                            if (dir == 0) {
                                dir = 1;
                                if (visited[y][x][dir]) break;
                                visited[y][x][dir] = true;
                                ++x;
                                if (x == r) x = 0;
                            } else if (dir == 1) {
                                dir = 2;
                                if (visited[y][x][dir]) break;
                                visited[y][x][dir] = true;
                                ++y;
                                if (y == c) y = 0;
                            } else if (dir == 2) {
                                dir = 3;
                                if (visited[y][x][dir]) break;
                                visited[y][x][dir] = true;
                                --x;
                                if (x < 0) x = r - 1;
                            } else if (dir == 3) {
                                dir = 0;
                                if (visited[y][x][dir]) break;
                                visited[y][x][dir] = true;
                                --y;
                                if (y < 0) y = c - 1;
                            }
                        }
                        ++ct;
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
