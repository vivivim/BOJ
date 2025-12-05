class Solution {
    public int solution(int[] stones, int k) {
        int answer = 0;
        int left = 0;
        int right = 2147483647;
        int mid = 0;
        
        while (left <= right) {
            mid = (left + right) / 2;
            
            if (can(stones, k, mid)) {
                left = mid + 1;
                answer = mid;
            }
            else 
                right = mid - 1;
        }
        
        return answer;
    }
    
    private boolean can(int[] stones, int k, int mid) {
        int ct = 0;
        
        for (int stone : stones) {
            if (stone - mid >= 0)
                ct = 0;
            else
                ++ct;
            
            if (ct == k)
                return false;
        }
        
        return true;
    }
}
