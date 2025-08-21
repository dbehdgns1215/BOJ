import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	/**
	 * @throws IOException 
	 * @link: https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AZgruskKCQnHBIT9&contestProbId=AV18TrIqIwUCFAZN&probBoxId=AZjKuOkq4C_HBIO0+&type=PROBLEM&problemBoxTitle=0821&problemBoxCnt=++3+
	 * @performance: 
	 * @note: 
	 * @timecomplex:
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for (int test_case = 1; test_case <= 10; test_case++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int V = Integer.parseInt(st.nextToken()); // 정점 개수
			int E = Integer.parseInt(st.nextToken()); // 간선
			
			Queue<Integer> q = new LinkedList<>();
			ArrayList<Integer>[] adj = new ArrayList[V + 1]; // 인접 리스트
			ArrayList<Integer> result = new ArrayList<>(); // 위상 정렬 결과를 담을 리스트

            for (int i = 0; i <= V; i++) {
                adj[i] = new ArrayList<>(); // adj[0]은 zero-index
            }
			int[] deg = new int[V + 1]; // Indegree를 저장할 배열, 진입 차수
			
			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= E; i++) {
				int vertex = Integer.parseInt(st.nextToken());
				int node = Integer.parseInt(st.nextToken());
				adj[vertex].add(node); // 인접 리스트에 관계 저장
				deg[node]++; // 진입 차수 증가
				
//				System.out.println("v: " + vertex + "  " + "e: " + node);
			}
			
			for (int i = 1; i <= V; i++) {
				if (deg[i] == 0) q.add(i); // 진입 차수가 0인 노드부터 add
			}
			
			while(!q.isEmpty()) {
				int cur = q.poll();
				result.add(cur);
				for (int next : adj[cur]) {
					deg[next]--;
					if (deg[next] == 0) {
						q.add(next);
					}
				}
			}
			
			StringBuilder sb = new StringBuilder();
			sb.append("#").append(test_case).append(" ");
			
			// 사이클이 존재하는 경우
//			if (result.size() != V) {
//				// 사이클이 있을 때 실행할 로직...
//			}
			
			for (int i = 0; i < V; i++) {
				sb.append(result.get(i)).append(" ");
			}
			
			System.out.println(sb);
		}

	}

}
