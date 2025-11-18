import java.util.*;

class Solution {
    public String solution(String number, int k) {
        String answer = "";
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < number.length(); ++i) {
            while (sb.length() > 0 && k > 0 && sb.charAt(sb.length() - 1) < number.charAt(i)) {
                sb.deleteCharAt(sb.length() - 1);
                --k;
            }
            sb.append(number.charAt(i));
        }
        sb.setLength(sb.length() - k);
        
        return sb.toString();
    }
}
