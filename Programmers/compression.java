import java.util.*;

class Solution {
    public int[] solution(String msg) {
        Map<String, Integer> dict = new HashMap<>();
        List<Integer> list = new ArrayList<>();
        
        for (int i = 0; i < 26; ++i)
            dict.put(String.valueOf((char)('A' + i)), i+1);

        for (int i = 0; i < msg.length();) {
            String cur = String.valueOf(msg.charAt(i));
            String w = cur;
            int j = i + 2;
            
            while (dict.containsKey(cur)) {
                w = cur;
                if (j > msg.length()) break ;
                cur = msg.substring(i, j);
                ++j;
            }

            list.add(dict.get(w));
            if (j < msg.length())
                dict.put(w + msg.charAt(j-2), dict.size()+1);
            i += w.length();
        }
        
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}
