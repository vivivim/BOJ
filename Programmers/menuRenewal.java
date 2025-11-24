import java.util.*;

class Solution {
    Map<String, Integer> combi;
    
    public String[] solution(String[] orders, int[] course) {
        List<String> answer = new ArrayList<>();
        combi = new HashMap<>();
        
        orders = sortOrders(orders);
        
        for (String order : orders) {
            for (int c : course) {
                StringBuilder cur = new StringBuilder();
                makeCombi(order, cur, 0, c);
            }
        }
        
        for (int c : course) {
            int max = combi.entrySet().stream()
                .filter(e -> e.getKey().length() == c)
                .mapToInt(Map.Entry::getValue)
                .max()
                .orElse(0);
            
            if (max < 2) continue;

            combi.entrySet(). stream()
                .filter(e -> e.getKey().length() == c && e.getValue() == max)
                .forEach(e -> answer.add(e.getKey()));
        }
        
        Collections.sort(answer);
        
        return answer.toArray(new String[answer.size()]);
    }
    
    private void makeCombi(String order, StringBuilder cur, int i, int c) {
        if (cur.length() == c) {
            String curStr = cur.toString();
            combi.put(curStr, combi.getOrDefault(curStr, 0) + 1);
            return ;
        }
        
        for (; i < order.length(); ++i) {
            cur.append(order.charAt(i));
            makeCombi(order, cur, i+1, c);
            cur.deleteCharAt(cur.length() - 1);
        }
    }
    
    private String[] sortOrders(String[] orders) {
        return Arrays.stream(orders).map(
            o -> {
                char[] arr = o.toCharArray();
                Arrays.sort(arr);
                return new String(arr);
            })
            .toArray(String[]::new);
    }
}
