import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @link: https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AZgruskKCQnHBIT9&contestProbId=AV5LwsHaD1MDFAXc&probBoxId=AZjez6Y6OpXHBITM+&type=PROBLEM&problemBoxTitle=0825&problemBoxCnt=++3+
 * @performance: 295 ms, 101,300 kb
 * @note: 왜 크루스칼로 풀 수 없나? -> 최소신장트리(크루스칼)로 풀려면 단순하게 정점의 연결에만 관심이 있어야 함. (무방향. 경로 순서 필요 없음)
 * 여러분의 프로그램은 가장 짧은 경로의 이동거리만 밝히면 된다.
 * 이 문제는 가장 짧은 경로를 ‘효율적으로’ 찾는 것이 목적이 아니다.
 * 여러분은 모든 가능한 경로를 살펴서 해를 찾아도 좋다.
 * -> 그냥 구현해도 통과한다고 광고 중 (순열)
 * 와 근데 내가 풀고도 힙하게 풀어서 감탄함 누가 보면 자바 알고리즘의 신인 줄 알겠는데
 * 
 * 그리고 문제에서 가장 짧은 경로를 효울적으로 찾는 것이 목적이 아니라고 강조한 이유를 알겠음.
 * 첫 번째 집을 선택할 때는 무조건 가장 가까운 집이 먼저 나와야 하지 않을까 생각했는데, 아마도 반례가 존재하는 듯.
 * @timecomplex: 
 */
public class Solution {

	static int N;
	static Human[] humans;
	static Company company;
	static Home home;
	static int minDist;
	static boolean[] visited;
	
	public static class Location {
		int x, y;
		public Location(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	public static class Company extends Location {
		public Company(int x, int y) {
			super(x, y);
		}
	}
	
	public static class Home extends Location {
		public Home(int x, int y) {
			super(x, y);
		}
	}
	
	public static class Human extends Location {
		public Human(int x, int y) {
			super(x, y);
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			N = Integer.parseInt(br.readLine());
			minDist = Integer.MAX_VALUE;
			
			humans = new Human[N];
			
			st = new StringTokenizer(br.readLine());
			
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			company = new Company(x, y);
			
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			home = new Home(x, y);
			
//			int mostNear = Integer.MAX_VALUE;
//			int mostNearIdx = 0;
			
			for (int i = 0; i < N; i++) {
				x = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());
				humans[i] = new Human(x, y);
				
//				int near = getDistance(company, humans[i]);
//				if (near < mostNear) {
//					mostNear = near;
//					mostNearIdx = i;
//				}
			}
			
			visited = new boolean[N];
//			visited[mostNearIdx] = true;
			// 초기 위치는 회사니까 인자로 넘겨줌
			// 이었는데 첫 번째 거리는 무조건 가장 가까운 걸 고르는 게 베스트가 아닐까?
			// 아니네 -> dfs(0, mostNear, visited, humans[mostNearIdx]);
			dfs(0, 0, visited, company);
			
			sb.append("#").append(test_case).append(" ").append(minDist).append("\n");
		}
		System.out.print(sb);
	}

	private static void dfs(int cnt, int dist, boolean[] vis, Location cur) {
		if (dist >= minDist) return;
		
		if (cnt == N) {
			dist += getDistance(cur, home);
			minDist = Math.min(minDist, dist);
			return;
		}
		
		for (int i = 0; i < N; i++) {
			if (vis[i]) continue;
			
			dist += getDistance(cur, humans[i]);
			vis[i] = true;
			
			dfs(cnt + 1, dist, vis, humans[i]);

			dist -= getDistance(cur, humans[i]);
			vis[i] = false;
		}
	}

	private static int getDistance(Location a, Location b) {
		return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
	}

}
