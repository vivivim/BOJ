class Solution {
    class Node {
        Node[] child = new Node[26];
        int preCt;
            
        Node(int preCt) {
            this.preCt = preCt;
        }
    }
    
    public int solution(String[] words) {
        int answer = 0;
        Node root = new Node(0);
        
        for (String word : words) {
            int n = word.length();
            Node cur = root;
            
            for (int i = 0; i < n; ++i) {
                char c = word.charAt(i);
                
                if (cur.child[c - 'a'] == null) {
                    cur.child[c - 'a'] = i == n-1 ? new Node(1) : new Node(1);
                    cur = cur.child[c - 'a'];
                } else {
                    cur = cur.child[c - 'a'];
                    ++cur.preCt;
                }
            }
        }
        
        for (String word : words) {
            int n = word.length();
            int ct = 0;
            Node cur = root;
            
            for (int i = 0; i < n; ++i) {
                char c = word.charAt(i);
                
                cur = cur.child[c - 'a'];
                ++ct;
                
                if (cur.preCt == 1)
                    break ;
            }
            
            answer += ct;
        }
        
        
        return answer;
    }
}
