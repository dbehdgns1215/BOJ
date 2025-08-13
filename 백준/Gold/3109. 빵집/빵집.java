import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/***
 * 
 * @author SSAFY
 *
 */
public class Main {
    public static class Pair {
        int x;
        int y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    static int[] dx = {1, 1, 1}; // C
    static int[] dy = {-1, 0, 1}; // R
    static int R;
    static int C;
    static char[][] arr;
    static boolean[][] visited;
    static int ans = 0;
    static boolean flag = false;
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        arr = new char[R][C]; // Row: i, Col: j
        visited = new boolean[R][C];
        
        for (int i = 0; i < R; i++) {
            String input = br.readLine();
            for (int j = 0; j < C; j++) {
                char t = input.charAt(j);
                arr[i][j] = t;
            }
        }

        for (int i = 0; i < R; i++) {
        	visited[i][0] = true;
        	flag = false;
            dfs(i, 0);
        }
        
        
        System.out.println(ans);
    }

    private static void dfs(int row, int col) {
//    	path += "(" + row + "," + col + ") -> ";
    	/*
    	 * 경로: 1 : (0,0) -> (1,1) -> (2,2) -> (1,3) -> (0,4) -> 
		 * 경로: 2 : (0,0) -> (1,1) -> (2,2) -> (1,3) -> (1,4) -> 
		 * 경로: 3 : (0,0) -> (1,1) -> (2,2) -> (1,3) -> (2,4) -> 
		 * 경로: 4 : (0,0) -> (1,1) -> (2,2) -> (2,3) -> (3,4) ->  
		 * 
		 * (1, 3) 에서 한 번 종료 조건에 도달했으면 종료 해줘야 하는데, 계속 돌아서 문제 발생
    	 */
        if (col == C - 1) {
        	ans++;
//          System.out.println("경로: " + ans + " : " + path);
            flag = true;
            return;
        }
        
        for (int dir = 0; dir < 3; dir++) {
            int nr = row + dy[dir];
            int nc = col + dx[dir];
            
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (arr[row][col] == 'x' || visited[nr][nc]) continue;
            

            visited[nr][nc] = true;
            dfs(nr, nc);
            if (flag) {
            	break;
            }
        }
        return;
    }
}
    
    
    
    

//    private static void bfs() {
//        boolean flag = false; // 가지 치기용 변수
//        while (!q.isEmpty()) {
//            Pair cur = q.peek();
//            q.poll();
//            System.out.println("##" + cur.y + " " + cur.x);
//            for (int dir = 0; dir < 3; dir++) {
//                
//                int nx = dx[dir] + cur.x;
//                int ny = dy[dir] + cur.y;
//                System.out.println("#1 " + ny + " " + nx);
//                if (ny < 0 || ny >= R) continue;
//                if (nx >= C) {
//                    System.out.println("####3 " + ny + " " + nx);
//                    ans++;
//                    flag = true; // 이후 탐색은 무의미
//                    break;
//                }
//                if (arr[ny][nx] == 'x' || visited[ny][nx]) continue;
////                System.out.println("#2 " + ny + " " + nx);
//                // 종료 조건
//
//                q.add(new Pair(nx, ny));
//                visited[ny][nx] = true;
//                System.out.println("#4 " + ny + " " + nx);
//            }
//            if (flag) {
//                System.out.println("클리어");
//                q.clear();
//            }
//        }
//    }