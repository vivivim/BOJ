class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        
        for (String user : skill_trees) {
            int learned = 0;
            
            for (int i = 0; i < user.length(); ++i) {
                int idx = skill.indexOf(user.charAt(i));
                
                if (idx != -1) {
                    if (idx != learned)
                        break;
                    ++learned;
                }
                
                if (i == user.length() - 1)
                    ++answer;
            }
        }

        return answer;
    }
}
