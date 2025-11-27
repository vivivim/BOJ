class Solution {
    int answer;
    
    public int solution(int[] numbers, int target) {
        this.answer = 0;
        
        dfs(numbers, target, 0, 0);
        
        return this.answer;
    }
    
    private void dfs(int[] numbers, int target, int depth, int sum) {
        if (depth == numbers.length) {
            if (sum == target)
                ++this.answer;
            return ;
        }
        
        dfs(numbers, target, depth+1, sum + numbers[depth]);
        dfs(numbers, target, depth+1, sum - numbers[depth]);
    }
}
