import java.util.*;

class Solution {
    int answer;
    String[][] relation;
    List<Integer> combi;
    int c;
    int r;
    List<List<Integer>> isCandi;
    
    public int solution(String[][] relation) {
        answer = 0;
        this.relation = relation;
        c = relation[0].length;
        r = relation.length;
        combi = new ArrayList<>();
        isCandi = new ArrayList<>();
        
        for (int i = 1; i <= c; ++i)
	        letsGo(0, i);
        
        return answer;
    }
    
    private void can() {
        Set<String> set = new HashSet<>();
        
        for (int i = 0; i < r; ++i) {
            StringBuilder sb = new StringBuilder();
            
            for (int c : combi)
                sb.append(relation[i][c]);
            set.add(sb.toString());
        }
        
        
        if (set.size() == r) {
            for (List<Integer> candi : isCandi) {
                if (combi.containsAll(candi))
                    return ;
            }
            
            isCandi.add(new ArrayList(combi));
            ++answer;
        }
    }
    
    private void letsGo(int start, int ct) {
        if (combi.size() == ct) {
            can();
            return ;
        }
        
        for (int i = start; i < c; ++i) {
            combi.add(i);
            letsGo(i+1, ct);
            combi.remove(combi.size() - 1);
        }
    }
}
