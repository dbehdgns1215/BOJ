import java.util.*;

class Solution {
    public int solution(int n, int[][] computers) {
        
        ArrayList<Integer>[] network = new ArrayList[n];
        
        for (int i = 0; i < n; i++) {
            network[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (computers[i][j] == 1 && i != j) {
                    network[i].add(j);
                }
            }
        }
        
        boolean[] isUsed = new boolean[n];
        int netCnt = 0;
        Queue<Integer> q = new LinkedList<>();
        
        for (int i = 0; i < n; i++) {
            if (isUsed[i]) continue;
            
            q.add(i);
            
            while (!q.isEmpty()) {
                int cur = q.poll();
                
                if (isUsed[cur]) continue;
                isUsed[cur] = true;
                
                for (int next : network[cur]) {
                    if (!isUsed[next]) {
                        q.add(next);
                    }
                }
            }
            
            netCnt++;
        }
        
        return netCnt;
    }
}