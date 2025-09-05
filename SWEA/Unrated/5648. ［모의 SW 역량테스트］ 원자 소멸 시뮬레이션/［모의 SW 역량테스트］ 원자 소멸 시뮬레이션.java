import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Solution {
	public static class Atomic implements Comparable<Atomic>{
		int x;
		int y;
		int E;
		int dir;
		boolean alive = true;
		
		public Atomic(int x, int y, int dir, int E) {
			this.x = x;
			this.y = y;
			this.dir = dir;
			this.E = E;
		}

		@Override
		public int compareTo(Atomic o) {
			// 나의 x좌표가 상대의 x좌표보다 작은 순, 만약 x좌표가 같다면 y좌표가 작은 순
			return this.x < o.x ? -1 : (this.x != o.x ? Integer.compare(this.x, o.x) : Integer.compare(this.y, o.y));
		}
		
//		public boolean isGone(int nx, int ny) {
//			if (this.x + nx < 0 || this.x + nx >= 2000 || this.y + ny < 0 || this.y +ny >= 2000) return true;
//			return false;
//		}
	}
	
	// 충돌 리스트에 담을 충돌하는 두 원자와 그때의 시간 정보 클래스
	static class Pair implements Comparable<Pair> {
		int i, j, time;
		
		public Pair(int i, int j, int time) {
			this.i = i;
			this.j = j;
			this.time = time;
		}

		@Override
		public int compareTo(Pair o) {
			// TODO Auto-generated method stub
			return Integer.compare(this.time, o.time);
		}
	}
	
	static int N;
	static Atomic[][] arr;
	static ArrayList<Atomic> list;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			N = Integer.parseInt(br.readLine());
			list = new ArrayList<>();

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken()) * 2; // 나눴을 때 실수 연산 안하게 좌표 2배로 키우기
				int y = Integer.parseInt(st.nextToken()) * 2;
				int dir = Integer.parseInt(st.nextToken());
				int energy = Integer.parseInt(st.nextToken());
				list.add(new Atomic(x, y, dir, energy));
			}
			sb.append("#").append(test_case).append(" ").append(makeBoomPair()).append("\n");
		}
		System.out.print(sb);
	}
	
	private static int makeBoomPair() {
		// 원자 리스트를 좌표 기준으로 정렬
		Collections.sort(list);
		ArrayList<Pair> boomList = new ArrayList<>();
		// 원자 2개씩 조합 생성
		for (int i = 0; i < N; i++) { // 선택할 첫 번째 원자
			for (int j = i + 1; j < N; j++) { // 선택할 두 번째 원자
				Atomic a = list.get(i);
				Atomic b = list.get(j);
				
				// '|' 수직선에서 만날 때 (같은 x좌표를 갖는 원자들이 수직선에서 만날 때)
				if (a.x == b.x) {
					if (a.dir == 0 && b.dir == 1) {
						boomList.add(new Pair(i, j, Math.abs(b.y - a.y) / 2));
					}
				}
				
				// 'ㅡ' 수평선에서 만날 때 (같은 y좌표를 갖는 원자들이 수평선에서 만날 때)
				if (a.y == b.y) {
					if (a.dir == 3 && b.dir == 2) {
						boomList.add(new Pair(i, j, Math.abs(b.x - a.x) / 2));
					}
				}
				
				// '/' 대각선 라인에 있는 대상들이 만날 때
				//	X <-b
				// 	^  /|
				//	| / V
				// 	a->	X
				if (a.x - a.y == b.x - b.y) {
					if (a.dir == 0 && b.dir == 2 || a.dir == 3 && b.dir == 1) {
						boomList.add(new Pair(i, j, Math.abs(a.x - b.x)));
					}
				}

				// '\' 대각선 라인에 있는 대상을 만날 때
				if (a.x + a.y == b.x + b.y) {
					if (a.dir == 1 && b.dir == 2 || a.dir == 3 && b.dir == 0) {
						boomList.add(new Pair(i, j, Math.abs(a.x - b.x)));
					}
				} 
				
			}
		}
		
		return getTotalEnergy(boomList);
	}

	private static int getTotalEnergy(ArrayList<Pair> boomList) {
		Collections.sort(boomList); // 터지는 시간 기준 오름차순 정렬
		int INF = Integer.MAX_VALUE;
		int boomTimes[] = new int[N];
		Arrays.fill(boomTimes, INF);
		int sum = 0;
		
		for (Pair p : boomList) {
			
			if (boomTimes[p.i] < p.time || boomTimes[p.j] < p.time) continue;
			
			if (boomTimes[p.i] == INF) {
				boomTimes[p.i] = p.time;
				sum += list.get(p.i).E;
			}
			
			if (boomTimes[p.j] == INF) {
				boomTimes[p.j] = p.time;
				sum += list.get(p.j).E;
			}
			
		}
		
		return sum;
	}
}
