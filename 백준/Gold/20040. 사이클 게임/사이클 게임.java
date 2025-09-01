import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {	
	public static void make() {
		for (int i = 0; i < N; i++) {
			parents[i] = -1;
		}
	}
	
	public static int find(int cur) {
		if (parents[cur] < 0) return cur;
		return parents[cur] = find(parents[cur]);
	}
	
	public static boolean union(int a, int b) {
		int aRoot = find(a);
		int bRoot = find(b);
		
		if (aRoot == bRoot) return false;
	
		if (parents[aRoot] > parents[bRoot]) {
			int temp = aRoot;
			aRoot = bRoot;
			bRoot = temp;
		}
		
		if (parents[aRoot] == parents[bRoot]) {
			parents[aRoot]--;
		}
		
		parents[bRoot] = aRoot;
		return true;
	}
	
	public static int[] parents;
	public static boolean[][] isAlready;
	public static int N;
	public static int M;
	
	public static void main(String[] args) throws IOException {
		//--------------솔루션 코드를 작성하세요.---------------------------
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		parents = new int[N];
		
		make();
		
		int cnt = 0;
		boolean isFlag = false;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
		
			if (!union(a, b)) {
				isFlag = true;
				cnt++;
				break;
			} else {
				cnt++;
			}
		}
		
		if (!isFlag) {
			sb.append(0);
		} else {
			sb.append(cnt);
		}
		
		System.out.println(sb);
	}

}

