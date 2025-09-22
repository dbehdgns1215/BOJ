import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static void make() {
		for (int i = 1; i <= V; i++) {
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
	
	public static class Edge implements Comparable<Edge> {
		int from;
		int to;
		int weight;
		
		public Edge(int from, int to, int weight) {
			this.from = from;
			this.to = to;
			this.weight = weight;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(this.weight, o.weight);
		}
	}
	
	
	static int[] parents;
	static int V, E;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		Edge[] edges = new Edge[E];
		parents = new int[V + 1];
		
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			edges[i] = new Edge(from, to, weight);
		}
		
		Arrays.sort(edges);
		
		make();
		
		int sum = 0;
		int cnt = 0;
		for (Edge e : edges) {
			if (!union(e.from, e.to)) continue;
			sum += e.weight;
			cnt++;
			
			if (cnt == V - 1) break; 
		}
		
		System.out.println(sum);
	}
}
