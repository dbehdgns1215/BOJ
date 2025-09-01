import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static int[] ans;
	static int[][] arr;
	static int cnt;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			cnt = 0;
			arr = new int[4][4];
			
			for (int i = 0; i < 4; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < 4; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
//			boolean[][] visited = new boolean[4][4];
			ans = new int[10000000];
			
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					String a = "";
					a += arr[i][j];
//					visited[i][j] = true;
					letsgo(j, i, 0, a);
//					visited[i][j] = false;
//					System.out.println("i j " + i + " " + j);
				}
			}
			
			sb.append("#").append(test_case).append(" ").append(cnt).append("\n");
		}
		
		System.out.print(sb);
	}

	private static void letsgo(int x, int y, int idx, String num) {
		if (idx == 6) {
			if (ans[Integer.parseInt(num)] > 0) {
//				System.out.println("어디서 걸림? " + "(" + y + ", " + x + ")");
				return;
			}
			ans[Integer.parseInt(num)] = 1;
//			System.out.println(y + ", " + x + ") " + Integer.parseInt(num));
			cnt++;
			return;
		}
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + x;
			int ny = dy[dir] + y;
			
			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
//			if (visited[ny][nx]) continue;
			
			String temp = num;
			
			num += arr[ny][nx];
//			visited[ny][nx] = true;
			
			letsgo(nx, ny, idx + 1, num);
			
//			visited[ny][nx] = false;
			num = temp;
		}
		
	}

}
