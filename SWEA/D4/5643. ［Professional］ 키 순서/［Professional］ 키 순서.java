import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	static int N; // 학생의 수
	static int M; // 키를 비교한 횟수
	static ArrayList<Integer>[] forward; // 부모 노드로의 경로 (방향성)
	static ArrayList<Integer>[] backward; // 자식 노드로의 경로 (방향성)
	static int ans;
	static int pCnt; // 부모 노드 개수
	static int cCnt; // 자식 노드 개수
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			N = Integer.parseInt(br.readLine());
			M = Integer.parseInt(br.readLine());
			ans = 0;
			
			// 학생 키 비교를 이용한 트리 구조 저장
			forward = new ArrayList[N + 1];
			backward = new ArrayList[N + 1];
			
			for (int i = 1; i <= N; i++) {
				forward[i] = new ArrayList<>();
				backward[i] = new ArrayList<>();
			}
			
			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				forward[a].add(b);
				backward[b].add(a);
			}
			
			Queue<Integer> q = new LinkedList<>();
			
			// 1번 노드부터 N번 노드까지 키 순서 노드 탐색
			for (int i = 1; i <= N; i++) {
				// 부모쪽으로 탐색
				q.add(i);
				pCnt = bfs(forward, q);
//				System.out.println(i + ") " + pCnt);
				
				// 자식쪽으로 탐색
				q.add(i);
				cCnt = bfs(backward, q);
//				System.out.println(i + ") " + cCnt);
				
				// 탐색 결과 두 cnt가 N - 1(자신 제외)이랑 일치하면 해당 학생은 키 순서를 알 수 있음.
				if (pCnt + cCnt == N - 1) {
					ans++;
				}
			}
			
			sb.append("#").append(test_case).append(" ").append(ans).append("\n");
		}
		System.out.print(sb);
	}

	private static int bfs(ArrayList<Integer>[] li, Queue<Integer> q) {
		int cnt = 0;
		boolean[] visited = new boolean[N + 1];
		
		while (!q.isEmpty()) { 
			int cur = q.poll();
			
			for (int next : li[cur]) {
				if (visited[next]) continue;
				cnt++;
				q.add(next);
				visited[next] = true;
			}
		}
		
		return cnt;
	}

}
