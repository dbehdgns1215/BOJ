import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		// 기본형: 우선순위가 낮은 숫자가 먼저 나옴 (작은 숫자)
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		 
		// 우선순위가 높은 숫자가 먼저 나옴 (큰 숫자)
//		PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
		
		// 추가로 커스텀 우선 순위 정렬은 Comparator<자료형>을 구현(implements)해서 만들어야 함.
		
		int N = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < N; i++) {
			int comm = Integer.parseInt(br.readLine());
			if (comm == 0) {
				int ans;
				if (pq.isEmpty()) {
					ans = 0;
				} else {
					ans = pq.poll();
				}
				
				System.out.println(ans);
			}
			else {
				pq.add(comm);
			}
		}
	}
}
