import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * @link: https://swexpertacademy.com/main/talk/solvingClub/problemView.do?contestProbId=AV5-BEE6AK0DFAVl&solveclubId=AZgruskKCQnHBIT9&problemBoxTitle=0911&problemBoxCnt=2&probBoxId=AZk2hDLa3UjHBIO0+
 * @performance: 102 ms, 26,880 kb
 * @note: 일단 최대한 주석을 달아봤음.
 * 시간 계산하는 로직은 진짜 도저히 짤 수가 없어서 다른 사람 코드 참고했었는데
 * 주경이 형이랑 내 로직이 비슷해서 많이많이 참고해보았음
 * 전체적으로는 각 사람들마다 2개의 계단으로 향하는 시간들을 모두 계산해서 pq에 담고 그걸 dist 배열에 저장해주었음 (재사용을 위해)
 * 이후 각 사람들이 2개의 계단을 선택하는 부분 집합을 구한 뒤, 각 케이스마다 시간을 계산해주었음.
 * 
 * pq 1개 q 1개로도 풀 수 있다는대 알고킹들이 틀림없는 듯
 * @timecomplex: 
 */
public class Solution {
	// 계단 클래스
	public static class Stair {
		int x;
		int y;
		int downTime;

		public Stair(int x, int y, int downTime) {
			this.x = x;
			this.y = y;
			this.downTime = downTime;
		}
	}

	// 특정 사람이 어떤 계단을 선택했느냐에 대한 정보를 가진 클래스
	public static class Choice implements Comparable<Choice> {
		int peopleIdx;
		Stair choiceStair;
		int dist;

		public Choice(int peopleIdx, Stair choiceStair, int dist) {
			this.peopleIdx = peopleIdx;
			this.choiceStair = choiceStair;
			this.dist = dist;
		}

		@Override
		public int compareTo(Choice o) {
			return Integer.compare(this.dist, o.dist);
		}
	}

	static int[][] arr;
	static Stair[] stairs = new Stair[2];
	static int[][] dist;
	static PriorityQueue<Choice> people;
	static int peopleCnt;
	static int[] escape;
	static int ans;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(br.readLine());
			peopleCnt = 0;
			ans = Integer.MAX_VALUE;

			arr = new int[N][N];
			Queue<Stair> s = new LinkedList<>();

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
					if (arr[i][j] > 1)
						s.add(new Stair(j, i, arr[i][j]));
				}
			}

			stairs[0] = s.poll();
			stairs[1] = s.poll();

			people = new PriorityQueue<>();

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (arr[i][j] == 1) {
						int dist1 = Math.abs(i - stairs[0].y) + Math.abs(j - stairs[0].x);
						int dist2 = Math.abs(i - stairs[1].y) + Math.abs(j - stairs[1].x);

						people.add(new Choice(peopleCnt, stairs[0], dist1)); // i번째 사람이, 첫 번째 계단을 향해, dist1의 시간이 걸림
						people.add(new Choice(peopleCnt, stairs[1], dist2)); // i번째 사람이, 두 번째 계단을 향해, dist2의 시간이 걸림

						peopleCnt++;
					}
				}
			}

			dist = new int[peopleCnt][2]; // i번째 사람이 두 계단 중 하나의 계단에 도달하는 시간
			escape = new int[peopleCnt]; // i번째 사람이 선택할 계단 0 or 1

			while (!people.isEmpty()) {
				Choice c = people.poll();
				int stairIdx;
				if (c.choiceStair == stairs[0]) {
					stairIdx = 0;
				} else {
					stairIdx = 1;
				}
				dist[c.peopleIdx][stairIdx] = c.dist;
			}

			subset(0);

			sb.append("#").append(test_case).append(" ").append(ans).append("\n");
		}
		System.out.print(sb);
	}

	static void subset(int i) {
		if (i == peopleCnt) {
			ans = Math.min(ans, calc());
			return;
		}

		// i번째 사람을 계단에 배정하는 부분 집합
		escape[i] = 0;
		subset(i + 1);

		escape[i] = 1;
		subset(i + 1);
	}

	private static int calc() {
		PriorityQueue<Integer> pq1 = new PriorityQueue<>(); // 첫 번째 계단으로 향하는 사람들의 계단으로 가는 이동 시간
		PriorityQueue<Integer> pq2 = new PriorityQueue<>(); // 두 번째 계단으로 향하는 사람들의 계단으로 가는 이동 시간

		for (int i = 0; i < peopleCnt; i++) {
			int d = dist[i][escape[i]];
			if (escape[i] == 0) {
				pq1.add(d);
			} else {
				pq2.add(d);
			}
		}

		int t1 = stairTime(pq1, stairs[0].downTime);
		int t2 = stairTime(pq2, stairs[1].downTime);

		// t1과 t2는 각 계단에서 마지막으로 내려간 사람들의 시간이 담겨있음.
		// 결국 최종 시간은 둘 중에서도 가장 마지막에 내려간 시간이 반환되어야 함
		return Math.max(t1, t2);
	}

	/*
	 * 각 위치에서 각자의 시간(t_n)만큼의 시간이 걸려서 계단 입구에 도달할 수 있고 계단의 길이만큼의 추가 시간 K가 필요하게 됨.
	 * 
	 * 각 계단은 3명이 동시에 내려갈 수가 있고 이후에 도착하는 사람들은 기다려야 함.
	 * 만약 4번째 사람이 계단에 도착한 경우에는 1번째로 내려간 사람이 완전히 내려가야 4번째 사람이 내려갈 수 있게 됨.
	 * 
	 * 그렇다면 전체 시간을 기준으로 봤을 때는 마지막 사람이 계단을 내려가는 시간이 전체 기준 시간이 되게 됨.
	 * 
	 * 이 말의 요지는, 대기열이 존재하지 않을 때는 이동 시간이 계단을 내려가는 시간에 영향을 주지만,
	 * 대기열이 존재하는 순간부터는 이동 시간이 아니라 가장 일찍 계단을 탈출하는 사람의 시간이 영향을 주게 된다는 말과 같음.
	 * 
	 * 근데 이 시간 계산하는 로직이 도저히 안짜져서 다른 사람들 코드를 구경해봤는데
	 * 주경이 형 코드가 너무 이해하기 편해서 그걸 참고해서 로직을 작성했음!
	 */
	private static int stairTime(PriorityQueue<Integer> arrivals, int downTime) {
		if (arrivals.isEmpty())
			return 0;

		// 계단을 내려가는 사람들의 종료 시간
		PriorityQueue<Integer> finishTimes = new PriorityQueue<>();

		int lastFinish = 0; // 이 계단에서 마지막으로 내려간 시간

		while (!arrivals.isEmpty()) {
			int arriveTime = arrivals.poll(); // 해당 계단으로의 가장 빠른 도착 시간 순서대로 꺼내짐
			int goDownTime = arriveTime + 1; // 도착 시간의 1분 뒤부터 계단 진입 가능

			/*
			 * 특정 사람이 내려가는 그 시간 기준으로 만약 다 내려간 사람이 있다면 반영해주어야 함.
			 * 앞서 언급한대로 4번째 사람이 들어가려면 1번째 사람이 끝난 뒤여야 하기 때문.
			 */
			while (!finishTimes.isEmpty() && finishTimes.peek() <= goDownTime) {
				finishTimes.poll();
			}

			if (finishTimes.size() < 3) {
				// 지금 당장 내려갈 수 있는 경우
				int finish = goDownTime + downTime; // (계단 입구로 가는 시간 + 계단 대기 시간 1분) + 내려가는 시간
				finishTimes.add(finish);
				lastFinish = finish;
			} else {
				// 지금 당장 내려갈 수 없는 경우
				int doneTime = finishTimes.poll(); // 가장 빠르게 내려갈 수 있는 사람을 꺼내서 시간 반영해주어야 함.
				int finish = doneTime + downTime; // 해당 계단에서 가장 빠르게 내려간 사람의 시간 + 내려가는 시간 (대기열에 들어가는 시점부터 계단 입구로 가는 시간은 무의미)
				finishTimes.add(finish);
				lastFinish = finish;
			}
		}
		return lastFinish;
	}

}
