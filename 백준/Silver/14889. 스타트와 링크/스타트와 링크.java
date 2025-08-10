import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int[] team = new int[21];
	static int N;
	static int halfN;
	static int[][] arr;
	static int people = 1;
	static int minSum = Integer.MAX_VALUE;
	static int abc = 0;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		halfN = N / 2;
		arr = new int[N + 1][N + 1];
		
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
//		for (int i = 0; i <= N; i++) {
//			for (int j = 0; j <= N; j++) {
//				System.out.print(arr[i][j] + " ");
//			} System.out.println("");
//		}
//		
		func(0, 1);
		
		System.out.println(minSum);
	}

	public static void func(int k, int idx) {
		if (k == N / 2) {
			calc();
			return;
		}

		for (int i = idx; i <= N; i++) {
			if (team[people - 1] >= i) continue;
			team[people++] = i;
			func(k + 1, idx + 1);
			people--;
		}
	}

	private static void calc() {
//		System.out.println("호출 카운트 : " + (++abc));
		
		int[] anotherTeam = new int[21 - halfN];
		int[] candidate = new int[21];
		for (int i = 1; i <= N; i++) {
			if (team[i] > 0) {
				candidate[team[i]] = 1;
			}
		}
		
		int people = 1;
		for (int i = 1; i <= N; i++) {
			if (candidate[i] == 0) {
				anotherTeam[people++] = i;
			}
		}
		
		int sum = 0;
		for (int i = 1; i <= halfN; i++) {
			if (i + 1 > halfN) break; 
			for (int j = i + 1; j <= halfN; j++) {
//				System.out.println(i + " : " + j);
//				System.out.println("team[]: " + team[i] + " " + team[j]);
//				System.out.println("a : " + arr[team[i]][team[j]]);
				sum += arr[team[i]][team[j]] + arr[team[j]][team[i]];
//				System.out.println("중간 sum : " + sum);
			}
		}
		
		int sum_ = 0;
		for (int i = 1; i <= halfN; i++) {
			if (i + 1 > halfN) break; 
			for (int j = i + 1; j <= halfN; j++) {
//				System.out.println(i + " v:s " + j);
//				System.out.println("team[]: " + team[i] + " " + team[j]);
//				System.out.println("b : " + arr[team[i]][team[j]]);
				sum_ += arr[anotherTeam[i]][anotherTeam[j]] + arr[anotherTeam[j]][anotherTeam[i]];
			}
		}
		int sum__ = Math.abs(sum - sum_);
		
//		System.out.println("team A");
//		for (int a : team) {
//			if (a > 0) {
//				System.out.println(a);
//			}
//			
//		}
//		
//		System.out.println("team B");
//		for (int a : anotherTeam) {
//			if (a > 0) {
//				System.out.println(a);
//			}
//		}
		
//		System.out.println("sum : " + sum + " sum2 : " + sum_);
//		System.out.println("");
//		System.out.println("절대값 " + sum__);
//		System.out.println("");
		minSum = Math.min(minSum, sum__);
	}
}
