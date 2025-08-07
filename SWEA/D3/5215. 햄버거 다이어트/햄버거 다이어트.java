import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import org.omg.CORBA.INTERNAL;

public class Solution {

	static BufferedReader br;
	static StringTokenizer st;
	static StringBuilder sb;
	static int N, L;
	static int[] michelinScore;
	static int[] kcal;
//	static boolean[] ate;
	static int curKcal;
	static int curMicehlinScore;
	static int maxMichelinScore;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			
			curKcal = 0;
			curMicehlinScore = 0;
			maxMichelinScore = Integer.MIN_VALUE;
			 
			st = new StringTokenizer(br.readLine());
			
			N = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());
			
			michelinScore = new int[N];
			kcal = new int[N];
//			ate = new boolean[N];
			
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				michelinScore[i] = Integer.parseInt(st.nextToken());
				kcal[i] = Integer.parseInt(st.nextToken());
			}
			
			hambugi(0);
			
			sb = new StringBuilder().append("#").append(test_case).append(" ").append(maxMichelinScore);
			System.out.println(sb);
		}

	}

	// 순열 버전
//	private static void hambugi(int eatingCnt) {
//		if (curKcal > L) return;
//		
//		if (eatingCnt == N) {
//			// 다 먹어도 제한 칼로리 미만이면 그게 최대값
//			maxMichelinScore = Math.max(maxMichelinScore, curMicehlinScore);
//			return;
//		}
//		
//		maxMichelinScore = Math.max(maxMichelinScore, curMicehlinScore);
//		
//		for (int i = 0; i < N; i++) {
//			if (ate[i]) continue;
//			
//			ate[i] = true;
//			curKcal += kcal[i];
//			curMicehlinScore += michelinScore[i];
//
//			hambugi(eatingCnt + 1);
//			
//			ate[i] = false;
//			curKcal -= kcal[i];
//			curMicehlinScore -= michelinScore[i];
//		}
//		
//	}
	
	private static void hambugi(int eatingIdx) {
		if (curKcal > L) return;
		
		maxMichelinScore = Math.max(maxMichelinScore, curMicehlinScore);
		
		for (int i = eatingIdx; i < N; i++) {
			curKcal += kcal[i];
			curMicehlinScore += michelinScore[i];
	
			hambugi(i + 1);
			
			curKcal -= kcal[i];
			curMicehlinScore -= michelinScore[i];
		}
	}
}
