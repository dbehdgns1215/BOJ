import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	public static class Pair {
		int a;
		int b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		
		@Override
		public String toString() {
			return Integer.toString(a);
		}
		
		/*
		 * contains 메서드는 내부적으로 equals() 메서드를 호출해서 '내용'을 비교함.
		 * 근데 Pair 클래스 내에서 equals()를 오버라이드 안해서 Object의 기본 구현을 따라가게 됨.
		 * Object는 단순하게 같은 객체인지(==) 비교함.
		 * 따라서 서로 다른 메모리 주소를 가지는 Pair는 쌍의 값이 같더라도 다른 객체라고 나옴.
		 */
		@Override
		public boolean equals(Object o) {
		    if (this == o) return true;
		    if (o == null || getClass() != o.getClass()) return false;
		    Pair pair = (Pair) o;
		    return a == pair.a && b == pair.b;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		Map<Integer, Integer> list = new HashMap<>();
		ArrayList<Pair> isUsed = new ArrayList<>();
		
		PriorityQueue<Pair> lowest = new PriorityQueue<>(new java.util.Comparator<Pair>() {
		    @Override
		    public int compare(Pair o1, Pair o2) {
		    	if (o1.b == o2.b) {
		    		return Integer.compare(o1.a, o2.a);
		    	} else {		    		
		    		return Integer.compare(o1.b, o2.b); // 오름차순
		    	}
		    }
		});

		PriorityQueue<Pair> highest = new PriorityQueue<>(new java.util.Comparator<Pair>() {
		    @Override
		    public int compare(Pair o1, Pair o2) {
		    	if (o1.b == o2.b) {
		    		return Integer.compare(o2.a, o1.a);
		    	} else {		    		
		    		return Integer.compare(o2.b, o1.b); // 내림차순
		    	}
		    }
		});

		int N = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int P = Integer.parseInt(st.nextToken());
			int L = Integer.parseInt(st.nextToken());
			
			list.put(P, L);
			highest.add(new Pair(P, L));
			lowest.add(new Pair(P, L));
		}
		
		N = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			
			String comm = st.nextToken();

			if (comm.equals("recommend")) {
				int x = Integer.parseInt(st.nextToken());
				
				if (x == 1) {
					Pair cur = highest.peek();
					while (isUsed.contains(new Pair(cur.a, cur.b))) cur = highest.poll();
					sb.append(cur).append("\n");
					highest.add(cur);
				} else if (x == -1) {
					Pair cur = lowest.peek();
					while (isUsed.contains(new Pair(cur.a, cur.b))) cur = lowest.poll();
					sb.append(cur).append("\n");
					lowest.add(cur);
				}
			} else if (comm.equals("add")) {
				int P = Integer.parseInt(st.nextToken());
				int L = Integer.parseInt(st.nextToken());
				
				if (list.containsKey(P)) {
					isUsed.add(new Pair(P, list.get(P)));
					list.put(P, L);					
				} else {
					list.put(P, L);					
				}
				
				highest.add(new Pair(P, L));
				lowest.add(new Pair(P, L));
			} else if (comm.equals("solved")) {
				int P = Integer.parseInt(st.nextToken());
				isUsed.add(new Pair(P, list.get(P)));									
				list.remove(P);
			}
		}
		System.out.println(sb);
	}
}
