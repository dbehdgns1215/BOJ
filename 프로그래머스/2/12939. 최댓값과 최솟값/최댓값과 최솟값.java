import java.util.*;

class Solution {
    public String solution(String s) {
        StringTokenizer st = new StringTokenizer(s);
        
        int minNum = Integer.MAX_VALUE;
        int maxNum = Integer.MIN_VALUE;
        
        while (st.hasMoreTokens()) {
            int current = Integer.parseInt(st.nextToken());
            
            minNum = Math.min(minNum, current);
            maxNum = Math.max(maxNum, current);
        }        

        return minNum + " " + maxNum;
    }
}