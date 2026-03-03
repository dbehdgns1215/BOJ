import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	public static class Bound implements Comparable<Bound>{
		int start;
		int end;
		
		public Bound(int start, int end) {
			this.start = start;
			this.end = end;
		}

		@Override
		public int compareTo(Bound o) {
			int a = Integer.compare(start, o.start);
			if (a == 0) {
				return Integer.compare(end, o.end);
			}
			return a;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		PriorityQueue<Bound> pq = new PriorityQueue<Bound>();
		
		StringTokenizer st;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			
			pq.add(new Bound(start, end));
		}
		
		Bound bd = pq.poll();
		
		int min = bd.start;
		int max = bd.end;
		
		int ans = 0;

		while (!pq.isEmpty()) {
			Bound cur = pq.poll();
			
			if (max < cur.start) {
				ans += (max - min);
				min = Integer.MAX_VALUE;
				max = Integer.MIN_VALUE;
			}
			
			if (min > cur.start) {
				min = cur.start;
			}
			if (max < cur.end) {
				max = cur.end;
			}
		}
		
		ans += (max - min);
		
		System.out.println(ans);
	}

}
