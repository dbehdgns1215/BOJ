import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	public static class Pair {
		int x, y;
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	public static int ans = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int[][] map = new int[N + 1][N + 1];
		
		ArrayList<Pair> home = new ArrayList<>();
		ArrayList<Pair> chicken = new ArrayList<>();
		
		boolean[] isVisitedChicken = new boolean[14];
		
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 1) home.add(new Pair(j, i));
				else if (map[i][j] == 2) chicken.add(new Pair(j, i));
			}
		}
		
		findCombi(home, chicken, isVisitedChicken, 0, 0, M);
		
		System.out.println(ans);
	}

	private static void findCombi(ArrayList<Pair> home, ArrayList<Pair> chicken,
			boolean[] isVisitedChicken, int cnt, int start, int M) {
		
		if (cnt == M) {
			int totalMinDist = 0;
			for (Pair h : home) {
				int minDist = Integer.MAX_VALUE;
				for (int i = 0; i < chicken.size(); i++) {
					if (isVisitedChicken[i]) {
						minDist = Math.min(minDist, (Math.abs(h.x - chicken.get(i).x) + Math.abs(h.y - chicken.get(i).y)));
					}
				}
				totalMinDist += minDist;
			}			
			ans = Math.min(ans, totalMinDist);
			return;
		}
		
		for (int i = start; i < chicken.size(); i++) {
			isVisitedChicken[i] = true;
			findCombi(home, chicken, isVisitedChicken, cnt + 1, i + 1, M);
			isVisitedChicken[i] = false;
		}
	}
}
