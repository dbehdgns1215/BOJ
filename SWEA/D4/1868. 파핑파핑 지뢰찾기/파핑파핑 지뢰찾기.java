import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
	public static class Pair {
		int x;
		int y;
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static char[][] arr;
	static int[][] bomb;
	static Queue<Pair> q;
	static Queue<Pair> subQ;
	static int N;
	static int[] dx = {0, 1, 1, 1, 0, -1, -1, -1};
	static int[] dy = {-1, -1, 0, 1, 1, 1, 0, -1};
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			
			N = Integer.parseInt(br.readLine());
			arr = new char[N][N];
			bomb = new int[N][N];
			q = new LinkedList<>();
			subQ = new LinkedList<>();
			
			for (int i = 0; i < N; i++) {
				Arrays.fill(bomb[i], -1); // bomb: 지뢰 개수 -> {-1: 기본값} {-2, 지뢰} {0 이상: 팔방 지뢰 개수}
			}
			
			for (int i = 0; i < N; i++) {
				String str = br.readLine();
				for (int j = 0; j < N; j++) {
					arr[i][j] = str.charAt(j);
					if (arr[i][j] == '*') {
						bomb[i][j] = -2;
					}
				}
			}
			
			int ans = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					boolean isPoss = isZero(i, j);
					if (isPoss && arr[i][j] == '.' && bomb[i][j] == -1) {
						q.add(new Pair(j, i));
						bomb[i][j] = 0;
						bfs();
						ans++;
					}
				}
			}
			
			for (int i = 0; i < N; i++) {
			    for (int j = 0; j < N; j++) {
			        if (arr[i][j] == '.' && bomb[i][j] == -1) {
			            ans++;
			        }
			    }
			}
			
			sb.append("#").append(test_case).append(" ").append(ans).append("\n");
		}
		System.out.print(sb);
	}

	private static boolean isZero(int y, int x) {
	    if (arr[y][x] == '*') return false;
	    int cnt = 0;
	    for (int d = 0; d < 8; d++) {
	        int nx = x + dx[d];
	        int ny = y + dy[d];
	        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 경계 밖은 무시
	        if (arr[ny][nx] == '*') cnt++;
	    }
	    return cnt == 0;
	}


	private static void bfs() {
		while (!q.isEmpty() ) {
			Pair cur = q.poll();
			
			int bombCnt = 0;
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (bomb[ny][nx] > 0) continue;
				if (arr[ny][nx] == '*') {
					bombCnt++;
					continue;
				}
				subQ.add(new Pair(nx, ny));
			}
			
			if (bombCnt > 0) {
				bomb[cur.y][cur.x] = bombCnt;
				subQ.clear();
			} else {
				while (!subQ.isEmpty()) {
			        Pair nxt = subQ.poll();
			        if (bomb[nxt.y][nxt.x] == -1) {
			            bomb[nxt.y][nxt.x] = 0;
			            q.add(nxt);
			        }
				}
			}
		}
	}
}