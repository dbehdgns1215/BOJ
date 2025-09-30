import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void make() {
		for (int i = 0; i <= N; i++) {
			parents[i] = -1;
		}
	}
	
	public static int find(int cur) {
		if (parents[cur] < 0) return cur;
		return parents[cur] = find(parents[cur]);
	}
	
	public static boolean union(int a, int b) {
		int aP = find(a);
		int bP = find(b);
		
		if (aP == bP) return false;
		
		if (parents[aP] > parents[bP]) {
			int temp = aP;
			aP = bP;
			bP = temp;
		}
		
		if (parents[aP] == parents[bP]) {
			parents[aP]--;
		}
		
		parents[bP] = aP;
		return true;
	}
	
	static int[] parents;
	static int N, M;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		
		parents = new int[N + 1];
		
		make();
		
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			
			for (int k = 1; k <= N; k++) {
				int target = Integer.parseInt((st.nextToken()));
				if (target == 1) {
					union(i, k);					
				}
			}	
		}
		
		st = new StringTokenizer(br.readLine());
		
		int prevNum = 0;
		boolean isFind = false;
		for (int i = 0; i < M; i++) {
			int curNum = Integer.parseInt(st.nextToken());
			if (i == 0) {
				prevNum = curNum;
				continue;
			}
			if (union(prevNum, curNum)) {
				System.out.println("NO");
				isFind = true;
				break;
			} else {				
				prevNum = curNum;
			}
		}
		if (!isFind) {
			System.out.println("YES");			
		}
	}

}
