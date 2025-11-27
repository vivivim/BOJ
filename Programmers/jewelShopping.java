import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        Map<String, Integer> map = new HashMap<>();
        Set<String> jewels = new HashSet<>();
        
        for (String gem : gems)
            jewels.add(gem);
        
        int start = 0;
        int end = 0;
        int min = 2147483647;
        
        while (true) {
            if (map.size() == jewels.size()) {
                if (end - start < min) {
                    answer[0] = start + 1;
                    answer[1] = end;
                    min = end - start;
                }
                
                map.put(gems[start], map.get(gems[start]) - 1);
                if (map.get(gems[start]) == 0)
                    map.remove(gems[start]);
                ++start;
            } else {
                if (end == gems.length) break ;
                map.put(gems[end], map.getOrDefault(gems[end], 0) + 1);
                ++end;
            }
        }
        
        return answer;
    }
}
