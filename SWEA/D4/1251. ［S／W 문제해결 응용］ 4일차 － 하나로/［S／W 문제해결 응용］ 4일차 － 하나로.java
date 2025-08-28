import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution {
	public static class Node implements Comparable<Node>{
		int to;
		long weight;
		public Node (int to, long weight) {
			this.to = to;
			this.weight = weight;
		}
		@Override
		public int compareTo(Node o) {
			return Long.compare(this.weight, o.weight);
		}
	}
	
	static int N;
	static double E;
	static long[] x;
	static long[] y;
	static long[][] dist;
	static long result;
	static boolean[] visited;
	static List<Node>[] graph;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			
			// 섬 개수
			N = Integer.parseInt(br.readLine());
			
			// 섬 X 좌표
			x = new long[N];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				x[i] = Long.parseLong(st.nextToken());
			}
			
			// 섬 Y 좌표
			y = new long[N];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				y[i] = Long.parseLong(st.nextToken());
			}
			
			// 환경 부담금
			E = Double.parseDouble(br.readLine());
			
			dist = new long[N][N];

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (i == j) continue;
					dist[i][j] = ((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j]));
				}
			}
			
			graph = new ArrayList[N];
			visited = new boolean[N];

			for (int i = 0; i < N; i++) {
            	graph[i] = new ArrayList<>();
            }
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (i == j) continue;
					graph[i].add(new Node(j, dist[i][j]));
				}
            }
			
			result = prim(0);
			sb.append("#").append(test_case).append(" ").append(Math.round(result * E)).append("\n");
		}
		System.out.print(sb);
	}

	private static long prim(int start) {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(start, 0));
		
		long sum = 0;
		long cnt = 0;
		
		while(!pq.isEmpty()) {
			Node cur = pq.poll();
			if (visited[cur.to]) continue;
			
			visited[cur.to] = true;
			sum += cur.weight;
			cnt++;
			
			if (cnt == N) break;
			
			for (Node next : graph[cur.to]) {
				if (!visited[next.to]) {
					pq.add(next);
				}
			}
		}
		
		return sum;
	}

}
