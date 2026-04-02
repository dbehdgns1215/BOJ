class Solution {
    
    public static int maxIdx;
    public static int answer;
    public static int[] numbers;
    public static int target;
    public int solution(int[] numbers, int target) {
        answer = 0;
        this.numbers = numbers;
        maxIdx = numbers.length;
        this.target = target;
        
        dfs(0, 0);
        // System.out.println(answer);
        return answer;
    }
    
    public int dfs(int idx, int curSum) {
        if (idx == maxIdx) {
            if (curSum == target) {
                answer++;
            }
            return 0;
        }

                // System.out.println(idx + ": " + " numbers[" + idx + "] : " + numbers[idx]);
        dfs(idx + 1, curSum + numbers[idx]);

        dfs(idx + 1, curSum - numbers[idx]);
    
        return 0;
    }
}