import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 * @link: https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AZgruskKCQnHBIT9&contestProbId=AV_mSnmKUckDFAWb&probBoxId=AZjkGae6SiPHBIO0+&type=PROBLEM&problemBoxTitle=0826&problemBoxCnt=++3+
 * @performance: 2,184 ms, 115,960 kb
 * @note: Prim 모르겠엉요
 * @timecomplex: 
 */
public class Solution {
	public static int V;
	public static int E;
	
	public static class Node implements Comparable<Node>{
		int to;
		long weight;
		
		public Node(int to, long weight) {
			this.to = to;
			this.weight = weight;
		}

		@Override
		public int compareTo(Node o) {
//			return this.weight - o.weight;
			return Long.compare(this.weight, o.weight);
		}
	}
	
	static long result;
	static boolean[] visited;
	static List<Node>[] graph;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine());
			
			V = Integer.parseInt(st.nextToken());
			E = Integer.parseInt(st.nextToken());
			result = 0;
			
			visited = new boolean[V + 1];
			
			// 정점을 저장할 인접 리스트
			graph = new ArrayList[V + 1];
            for (int i = 1; i <= V; i++) {
            	graph[i] = new ArrayList<>();
            }
            
			// 입력
			for (int i = 1; i <= E; i++) {
				st = new StringTokenizer(br.readLine());
				int f = Integer.parseInt(st.nextToken());
				int t = Integer.parseInt(st.nextToken());
				int w = Integer.parseInt(st.nextToken());
                graph[f].add(new Node(t, w));
                graph[t].add(new Node(f, w));
			}

			long result = prim(1);
			
			sb.append("#").append(test_case).append(" ").append(result).append("\n");
		}
		System.out.print(sb);
	}


	private static long prim(int start) {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(start, 0)); // 시작 노드는 가중치가 0
		
		long sum = 0;
		long cnt = 0;
		
		while(!pq.isEmpty()) {
			Node cur = pq.poll();
			if (visited[cur.to]) continue;
			
			visited[cur.to] = true;
			sum += cur.weight;
			cnt++;
			
			if (cnt == V) break;
			
			for (Node next : graph[cur.to]) {
				if (!visited[next.to]) {
					pq.add(next);
				}
			}
		}
		
		return sum;
	}
}
