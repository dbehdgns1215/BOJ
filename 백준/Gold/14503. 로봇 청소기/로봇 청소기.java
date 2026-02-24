import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int arr[][];
	
	public static class Robo {
		static int x;
		static int y;
		int d;
		
		public Robo(int x, int y, int d) {
			this.x = x;
			this.y = y;
			this.d = d;
		}
		
		public void back() {
			if (this.d == 0) {
				y++;
			} else if (this.d == 1) {
				x--;
			} else if (this.d == 2) {
				y--;
			} else {
				x++;
			}
		}
		
		public void rotate() {
			this.d--;
			if (this.d < 0) {
				d = 3;
			}
		}
	}
	
	public static class Pair {
		int x;
		int y;
		
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	public static int dx[] = {0, 1, 0, -1};
	public static int dy[] = {-1, 0, 1, 0};
	
	public static void main(String[] args) throws IOException {
		/**
		 * 1. 현재 칸
		 * 2. 주위 청소할 곳 X면 후진 (벽이면 종료)
		 * 2. 주위 청소할 곳 O면 반시계로 돌면서 ㄱㄱ
		 * 
		 *   0
		 * 3 d 1
		 *   2
		 */
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int R = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());	
		
		int r = Integer.parseInt(st.nextToken()); // y
		int c = Integer.parseInt(st.nextToken()); // x
		int d = Integer.parseInt(st.nextToken());
		
		arr = new int[R][C]; // 0은 청소해야함 1은 벽
		
		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < C; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		Robo robo = new Robo(c, r, d);
		
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(robo.x, robo.y));
		int ans = 0;
		
		boolean isEnded = false;
		
		int cnt = 0;
		while(!q.isEmpty()) {
//			System.out.println("cnt: " + (++cnt));
			Pair cur = q.poll();
//			System.out.println("cur: " + cur.x + ", " + cur.y);
			boolean isNeedClean = false;
			
			if (arr[cur.y][cur.x] == 0) {
				ans++;
				arr[robo.y][robo.x] = 2;
			}
			
			for (int dir = 0; dir < 4; dir++) {
				int nx = dx[dir] + cur.x;
				int ny = dy[dir] + cur.y;
//				System.out.println("cur(x, y) " + cur.x + ", " + cur.y + " (nx, ny): " + "(" + nx + ", " + ny + ")");
				
				// 청소할 곳 있음
				if (arr[ny][nx] == 0) {
					isNeedClean = true;
					break;
				}	
			}
			
			if (!isNeedClean) {
				// 청소할 곳 없음
				// 방향 유지한 채로 한 칸 후진?
				robo.back();
				
				// 벽이면 끝
				if (arr[robo.y][robo.x] == 1) {
					isEnded = true;
					break;
				}
				
				q.add(new Pair(robo.x, robo.y));
			} else {
				// 청소할 곳 있음
				// 90도 반시계로 회전하면서 찾아					
				int rCnt = 0;
				while (rCnt != 4) {
					robo.rotate();
					int nx = dx[robo.d] + cur.x;
					int ny = dy[robo.d] + cur.y;
					
					// 청소할 곳 있음
					if (arr[ny][nx] == 0) {
						robo.x = nx;
						robo.y = ny;
						
						arr[ny][nx] = 2;
						ans++;
						q.add(new Pair(nx, ny));
						break;
					}

					rCnt++; // 탐색 시행 횟수
					if (rCnt == 4) break;
				}
			}
		}
		
		if (isEnded) {
			System.out.println(ans);
		}
		
	}

}
