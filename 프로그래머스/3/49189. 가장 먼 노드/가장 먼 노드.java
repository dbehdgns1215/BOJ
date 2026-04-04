import java.util.*;

class Solution {
    
    public int solution(int n, int[][] edge) {
        int answer = 0;
        
        List<ArrayList<Integer>> graph = new ArrayList<>();
        
        // 정점 초기화
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] e : edge) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        
        int[] dist = new int[n + 1];
        Queue<Integer> q = new LinkedList<>();
        
        q.offer(1);
        dist[1] = 1;
        
        int maxDist = 0;
        while (!q.isEmpty()) {
            int cur = q.poll();
            
            for (int next : graph.get(cur)) {
                if (dist[next] == 0) {
                    dist[next] = dist[cur] + 1;
                    maxDist = Math.max(maxDist, dist[next]);
                    q.offer(next);
                }
                
            }
        }
        
        for (int d : dist) {
            if (d == maxDist) answer++;
        }
        
        return answer;
    }
}