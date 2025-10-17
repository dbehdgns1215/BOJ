import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static class Pair {
		int x;
		int y;
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	public static class Human {
		int no;
		int[] following;
		Pair pos;
		
		public Human (int no, int[] following) {
			this.no = no;
			this.following = following;
		}

		@Override
		public String toString() {
			return "Human [pos=" + pos.y + ", " + pos.x + "] : ";
		}
	}
	
	static int[] dx = {0, -1, 1, 0};
	static int[] dy = {-1, 0, 0, 1};
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		
		int[][] arr = new int[N + 1][N + 1];
		
		Human[] humans = new Human[N * N + 1];
		Human[] sortedHumans = new Human[N * N + 1];
		
 		for (int i = 0; i < N * N; i++) {
			st = new StringTokenizer(br.readLine());
			int no = Integer.parseInt(st.nextToken());
			
			int[] p = new int[4];
			for (int k = 0; k < 4; k++) {
				p[k] = Integer.parseInt(st.nextToken());
			}
			
			humans[i] = new Human(no, p); // 입력 순서대로
			sortedHumans[humans[i].no] = humans[i]; // idx 맞춰서 정렬
		}
 		
 		for (int i = 0; i < N * N; i++) {
 			int p1 = humans[i].following[0];
 			int p2 = humans[i].following[1];
 			int p3 = humans[i].following[2];
 			int p4 = humans[i].following[3];
			// 한 명씩 꺼내

 			Pair maxPos = null;
 			int maxLikeCnt = -1;
 			int maxEmptyCnt = -1;

 			for (int q = 1; q <= N; q++) {
 			    for (int w = 1; w <= N; w++) {
 			        if (arr[q][w] != 0) continue; // 이미 차있다면 후보 아님

 			        int likeCnt = 0;
 			        int emptyCnt = 0;

 			        for (int dir = 0; dir < 4; dir++) {
 			            int nx = w + dx[dir];
 			            int ny = q + dy[dir];

 			            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;

 			            if (arr[ny][nx] == 0) {
 			                emptyCnt++;
 			            } else {
 			                int neighbor = arr[ny][nx];
 			                if (neighbor == p1 || neighbor == p2 || neighbor == p3 || neighbor == p4) {
 			                    likeCnt++;
 			                }
 			            }
 			        }

 			        // 우선순위: likeCnt 내림, emptyCnt 내림, row(=q) 오름, col(=w) 오름
 			        if (likeCnt > maxLikeCnt
 			            || (likeCnt == maxLikeCnt && emptyCnt > maxEmptyCnt)
 			            || (likeCnt == maxLikeCnt && emptyCnt == maxEmptyCnt && (maxPos == null || q < maxPos.y))
 			            || (likeCnt == maxLikeCnt && emptyCnt == maxEmptyCnt && maxPos != null && q == maxPos.y && w < maxPos.x)
 			        ) {
 			            maxLikeCnt = likeCnt;
 			            maxEmptyCnt = emptyCnt;
 			            maxPos = new Pair(w, q); // x=col, y=row
 			        }
 			    }
 			}

 			// maxPos에 실제 배치
 			if (maxPos != null) {
 			    arr[maxPos.y][maxPos.x] = humans[i].no;
 			    humans[i].pos = new Pair(maxPos.x, maxPos.y);
 			    sortedHumans[humans[i].no] = humans[i];
 			}
		}
 		
// 		for (int i = 1; i <= N; i++) {
// 			for (int j = 1; j <= N; j++) {
// 				System.out.print(arr[i][j] + " ");
// 			} System.out.println("");
// 		}
 		
 		int score = 0;
 		for (int i = 1; i <= N; i++) {
 			for (int j = 1; j <= N; j++) {
 				if (arr[i][j] > 0) {
 		 			int p1 = sortedHumans[arr[i][j]].following[0];
 		 			int p2 = sortedHumans[arr[i][j]].following[1];
 		 			int p3 = sortedHumans[arr[i][j]].following[2];
 		 			int p4 = sortedHumans[arr[i][j]].following[3];
 		 			
 		 			int cnt = 0;
 					for (int dir = 0; dir < 4; dir++) {
 						int nx = j + dx[dir];
 						int ny = i + dy[dir];
 						
 						if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
 						
		                int neighbor = arr[ny][nx];
//		                System.out.println("얘 " + neighbor + "   :  " + p1 + ", " + p2 + ", " + p3 + ", " + p4);
		                if (neighbor == p1 || neighbor == p2 || neighbor == p3 || neighbor == p4) {
		                    cnt++;
		                }
 					}
 					if (cnt == 1) score += 1;
 					else if (cnt == 2) score += 10;
 					else if (cnt == 3) score += 100;
 					else if (cnt == 4) score += 1000;
 				}
 			}
 		}
 		
 		System.out.println(score);
	}
}
