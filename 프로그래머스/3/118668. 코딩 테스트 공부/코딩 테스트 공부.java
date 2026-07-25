import java.util.*;

class Solution {
    public int solution(int alp, int cop, int[][] problems) {
        int answer = 0;
        
        int maxAlp = Integer.MIN_VALUE;
        int maxCop = Integer.MIN_VALUE;
        
        for (int[] problem : problems) {
            maxAlp = Math.max(maxAlp, problem[0]);
            maxCop = Math.max(maxCop, problem[1]);
        }
        
        int targetAlp = maxAlp;
        int targetCop = maxCop;
        
        alp = Math.min(alp, targetAlp);
        cop = Math.min(cop, targetCop);
        
        int INF = 1_000_000_000;
        int[][] dp = new int[targetAlp + 1][targetCop + 1];

        for (int[] row : dp) {
            Arrays.fill(row, INF);
        }

        dp[alp][cop] = 0;
        
        for (int a = alp; a <= targetAlp; a++) {
            for (int c = cop; c <= targetCop; c++) {
                // 알고력
                if (a < targetAlp) {
                    dp[a + 1][c] = Math.min(dp[a + 1][c], dp[a][c] + 1);
                }
                
                // 코딩력
                if (c < targetCop) {
                    dp[a][c + 1] = Math.min(dp[a][c + 1], dp[a][c] + 1);
                }
                
                // 문제 풀기
                for (int[] problem : problems) {
                    int alpReq = problem[0];
                    int copReq = problem[1];
                    int alpReward = problem[2];
                    int copReward = problem[3];
                    int cost = problem[4];

                    if (a >= alpReq && c >= copReq) {
                        int nextA = Math.min(targetAlp, a + alpReward);
                        int nextC = Math.min(targetCop, c + copReward);
                        dp[nextA][nextC] = Math.min(dp[nextA][nextC], dp[a][c] + cost);
                    }
                }
            }
        }
        return dp[targetAlp][targetCop];
    }
}