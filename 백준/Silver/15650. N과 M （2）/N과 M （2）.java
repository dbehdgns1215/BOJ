import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int M;
	static boolean[] isUsed;
	static List<Integer> li;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer sb = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(sb.nextToken());
		M = Integer.parseInt(sb.nextToken());
		
		isUsed = new boolean[N];
		li = new ArrayList<Integer>(); 
		int k = 0;
		
		func(k);
	}

	private static void func(int k) {
		if (k == M) {
//			Collections.sort(li); 사실 필요 없는 코드임. 원래 로직은 그냥 리스트에 값 넣고 sort하면 되는거 아닌가? 하고 풀었는데, 이러면 중복 순열도 출력하는 문제가 있었음.
			for (int a : li) {
				System.out.print(a + " ");
			} System.out.println("");
			return;
		}
		
		for (int i = 0; i < N; i++) {
			if (!isUsed[i]) {
				if (li.isEmpty() || li.get(k - 1) < i + 1) { // 제일 최근 값을 가져와서 지금 넣으려는 숫자가 제일 최근 값보다 클 때만 li에 추가. 자동으로 오름차순 구현.
					li.add(i + 1);
					isUsed[i] = true;
					func(k + 1);
					isUsed[i] = false;
					li.remove(k);
				}
			}
		}
	}

}
