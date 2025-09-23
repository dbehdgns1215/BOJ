import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	public static class Vertex implements Comparable<Vertex> {
		int idx;
		int weight;
		
		public Vertex(int idx, int weight) {
			this.idx = idx;
			this.weight = weight;
		}

		@Override
		public int compareTo(Vertex o) {
			return Integer.compare(this.weight, o.weight);
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		
		int start = Integer.parseInt(br.readLine());
		
		ArrayList<Vertex>[] graph = new ArrayList[V + 1];
		for (int i = 0; i <= V; i++) graph[i] = new ArrayList<>();
		
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			
			graph[u].add(new Vertex(v, w));
		}
		
		int[] dist = new int[V + 1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		
		PriorityQueue<Vertex> pq = new PriorityQueue<>();
		boolean[] visited = new boolean[V + 1];
		
		pq.add(new Vertex(start, 0));
		dist[start] = 0;
		
		while (!pq.isEmpty()) {
			Vertex cur = pq.poll();
			if (visited[cur.idx]) continue;
			visited[cur.idx] = true;
			
			for (Vertex next : graph[cur.idx]) {
				if (dist[next.idx] > dist[cur.idx] + next.weight) {
					dist[next.idx] = dist[cur.idx] + next.weight;
					pq.add(new Vertex(next.idx, dist[next.idx]));
				}
			}
		}
		
		for (int i = 1; i <= V; i++) {
			if (dist[i] == Integer.MAX_VALUE) System.out.println("INF");
			else System.out.println(dist[i]);
		}
	}
}
