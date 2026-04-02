import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public static int[][] maps;
    public static int n;
    public static int m;
    public static int[] dx = {1, 0, -1, 0};
    public static int[] dy = {0, 1, 0, -1};
    public static int[][] dist;
    
    public static class Pos {
        int x, y;
        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    public int solution(int[][] maps) {
        int answer = 0;
        
        // n: 가로
        // m: 세로
        
        // maps[0] = 1 -> dist[0] = -1, dist[1] = 0
        // maps는 zero idx, 내 코드는 1부터 사이즈 + 1 까지.
        
        n = maps[0].length;
        m = maps.length;
        
        Deque<Pos> dq = new ArrayDeque<>();
        
        dist = new int[m + 1][n + 1];
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = -1;
            }
        }
        
        dq.add(new Pos(1, 1));
        dist[1][1] = 1;
        
        while (!dq.isEmpty()) {
            Pos cur = dq.poll();
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = dx[dir] + cur.x;
                int ny = dy[dir] + cur.y;
                
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (maps[ny - 1][nx - 1] == 0) continue;
                if (dist[ny][nx] >= 0) continue;
                
                dist[ny][nx] = dist[cur.y][cur.x] + 1;
                
                dq.add(new Pos(nx, ny));
            }
        }
        
        answer = dist[m][n];
        return answer;
    }
}