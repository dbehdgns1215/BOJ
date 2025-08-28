import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * @link: https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AZgruskKCQnHBIT9&contestProbId=AV597vbqAH0DFAVl&probBoxId=AZjpQ-k6F1rHBIO0+&type=PROBLEM&problemBoxTitle=0827&problemBoxCnt=++3+
 * @performance: 1,082 ms, 128,580 kb
 * @note: 미생물 객체 + 선형적으로 이동 로직 호출 및 합체? 처리
 * 추가로 마지막에 2차원 배열을 매번 훑고 있는데, 이 부분을 최적화하면 더 빠르게 탐색이 가능할 듯.
 * @timecomplex: 
 */
public class Solution {
	public static class Microbe {
		int x;
		int y;
		int mCnt;
		int dir;
		public Microbe(int x, int y, int mCnt, int dir) {
			this.x = x;
			this.y = y;
			this.mCnt = mCnt;
			this.dir = dir;
		}
		
		// 1, 2, 3, 4 -> 상, 하, 좌, 우
		public void changeDir() {
			if (dir % 2 == 0) {
				dir--;
			} else {
				dir++;
			}
		}
		
		public void outOfBoundFkiller(int n) {
			if (n == 0 || n == N - 1) {
				mCnt /= 2;
				changeDir();
			}
		}
		
		public void fusion(int mCnt) {
			this.mCnt += mCnt;
		}
		
		public void move() {
			if (dir == 1) {
				this.y--;
				outOfBoundFkiller(this.y);
			} else if (dir == 2) {
				this.y++;
				outOfBoundFkiller(this.y);
			} else if (dir == 3) {
				this.x--;
				outOfBoundFkiller(this.x);
			}else {
				this.x++;
				outOfBoundFkiller(this.x);
			}
		}
	}
	
	static int N; // 셀 크기
	static int M; // 격리 시간
	static int K; // 군집 개수
	static Queue<Microbe> microbes;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {		
			st = new StringTokenizer(br.readLine());
			
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			
			microbes = new LinkedList<>();
			// 미생물 생성
			for (int i = 0; i < K; i++) {
				st = new StringTokenizer(br.readLine());
				int y = Integer.parseInt(st.nextToken());
				int x = Integer.parseInt(st.nextToken());
				int mCnt = Integer.parseInt(st.nextToken());
				int dir = Integer.parseInt(st.nextToken());
				microbes.add(new Microbe(x, y, mCnt, dir));
			}
			
			// 시간 진행
			for (int t = 0; t < M; t++) {
			    Microbe[][] cell = new Microbe[N][N]; // 2차원 배열 -> 각 칸을 대표하는 미생물
			    int[][] maxCnt = new int[N][N];       // 해당 칸에 모인 미생물 중 군집 수가 가장 많은 미생물
			    
			    int size = microbes.size();
			    for (int s = 0; s < size; s++) {
			        Microbe cur = microbes.poll();
			        
//			        if (cur.mCnt == 0) continue; // 이미 합쳐진 미생물들은 스킵
			        
			        cur.move();
			        
			        int x = cur.x;
			        int y = cur.y;
			        
			        if (cell[y][x] == null) {
			            cell[y][x] = cur;
			            maxCnt[y][x] = cur.mCnt;
			        } else {
			            cell[y][x].fusion(cur.mCnt); // 일단 합치고
			            if (maxCnt[y][x] < cur.mCnt) { // 기존 대표, 굴러온 돌 중에서 굴러온 돌의 세력이 더 크면
			                cell[y][x].dir = cur.dir; // 대표는 이제부터 굴러온 돌이..
			                maxCnt[y][x] = cur.mCnt;
			            }
			        }
			    }

			    for (int i = 0; i < N; i++) {
			        for (int j = 0; j < N; j++) {
			            if (cell[i][j] != null && cell[i][j].mCnt > 0) {
			                microbes.add(cell[i][j]);
			            }
			        }
			    }
			}

			long ans = 0;
			for (Microbe m : microbes) {
				ans += m.mCnt;
			}
			sb.append("#").append(test_case).append(" ").append(ans).append("\n");
		}
		System.out.println(sb);
	}

}
