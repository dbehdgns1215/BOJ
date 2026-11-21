import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	public static class Pair {
		int x;
		int y;
		
		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static Queue<Pair> q = new LinkedList<>();
	
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static int N;
	static int[][] arr;
	static int[][] islandNum;
	static int[][] bridgeLen;
	static int minBridgeLen;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		arr = new int[N][N];
		islandNum = new int[N][N];
		bridgeLen = new int[N][N];
		minBridgeLen = Integer.MAX_VALUE;
		

		// 섬 입력
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int islandIdx = 1;
		
		// 섬 구분
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1 && islandNum[i][j] == 0) {
					q.add(new Pair(j, i));
					islandNum[i][j] = islandIdx;
					divide(new Pair(j, i));
					islandIdx++;
				}
			}
		}
		
		int cc = 0;
		// 다리 건설
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (arr[i][j] == 1) {
					q.add(new Pair(j, i));
					bridge(new Pair(j, i), islandNum[i][j]);
//					pr(cc++);
					init();
//					System.out.println(++cc + " : " + minBridgeLen);
				}
			}
		}
		
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				System.out.print(islandNum[i][j] + " ");
//			} System.out.println("");
//		}
//		
//		System.out.println("");
//		
		
//		
		System.out.println(minBridgeLen);
	}



	private static void pr(int cc) {
		System.out.println("====" + cc + "====");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (islandNum[i][j] != 0) {
					System.out.print("? ");
				} else {
					System.out.print(bridgeLen[i][j] + " ");
				}
			} System.out.println("");
		}
	}

	
	
	private static void divide(Pair pair) {
		while (!q.isEmpty()) {
			Pair cur = q.poll();
			
			for (int dir = 0; dir < 4; dir++) {
				
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (islandNum[ny][nx] != 0 || arr[ny][nx] == 0) continue;
				
				islandNum[ny][nx] = islandNum[cur.y][cur.x];
				q.add(new Pair(nx, ny));
			}
		}
	}
	
	private static void bridge(Pair pair, int num) {
		while (!q.isEmpty()) {
			Pair cur = q.poll();
			
			for (int dir = 0; dir < 4; dir++) {
				
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (islandNum[ny][nx] == num) continue;
				
				if (islandNum[ny][nx] != 0) {
					minBridgeLen = Math.min(minBridgeLen, bridgeLen[cur.y][cur.x]);
				}
				
	            if (bridgeLen[ny][nx] == 0) {
	                bridgeLen[ny][nx] = bridgeLen[cur.y][cur.x] + 1;
	                q.add(new Pair(nx, ny));
	            }
			}
		}
	}
	
	private static void init() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				bridgeLen[i][j] = 0;
			}
		}
	}
}
