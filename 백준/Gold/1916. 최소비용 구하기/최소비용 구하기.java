import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	public static class Vertex implements Comparable<Vertex>{
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
        StringTokenizer st;
        
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        
        ArrayList<Vertex>[] graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) graph[i] = new ArrayList<>();
        
        for (int i = 0; i < M; i++) {
        	st = new StringTokenizer(br.readLine());
        	
        	int start = Integer.parseInt(st.nextToken());
        	int end = Integer.parseInt(st.nextToken());
        	int weight = Integer.parseInt(st.nextToken());
        	
        	graph[start].add(new Vertex(end, weight));
        }

    	st = new StringTokenizer(br.readLine());
    	
    	int start = Integer.parseInt(st.nextToken());
    	int end = Integer.parseInt(st.nextToken());
    	
    	int[] dist = new int[N + 1];
    	Arrays.fill(dist, Integer.MAX_VALUE - 100_000);
    	
    	PriorityQueue<Vertex> pq = new PriorityQueue<>();
    	boolean[] visited = new boolean[N + 1];
    	
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
    	
    	System.out.println(dist[end]);
    	
    }
}
