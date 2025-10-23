import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static class Sticker {
		int[][] shape;

		public Sticker(int[][] shape) {
			this.shape = shape;
		}

		public void rotate() {
			int[][] temp = new int[shape[0].length][shape.length];

			for (int i = 0; i < shape[0].length; i++) {
				for (int j = 0; j < shape.length; j++) {
					temp[i][j] = shape[shape.length - j - 1][i];
				}
			}

			shape = temp;
		}

		public void sysout() {
			for (int i = 0; i < shape.length; i++) {
				for (int j = 0; j < shape[0].length; j++) {
					System.out.print(shape[i][j] + " ");
				}
				System.out.println("");
			}
		}
	}

	static int N, M, K;
	static int[][] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M];
		
		for (int i = 0; i < K; i++) {
			
			st = new StringTokenizer(br.readLine());
			
			int R = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			
			int[][] temp = new int[R][C];
			for (int r = 0; r < R; r++) {
				st = new StringTokenizer(br.readLine());
				for (int c = 0; c < C; c++) {
					temp[r][c] = Integer.parseInt(st.nextToken());
				}
			}
			
			Sticker sticker = new Sticker(temp);
//			System.out.println("배치전~");
//			for (int rrr = 0; rrr < N; rrr++) {
//				for (int ccc = 0; ccc < M; ccc++) {
//					System.out.print(arr[rrr][ccc] + " ");
//				} System.out.println("");
//			}
			
			// 배치했니?
			boolean yes = false;
			
			for (int rotateCnt = 0; rotateCnt < 4; rotateCnt++) {
//			sticker.sysout();
//			System.out.println("--------");
			
			// 전체 모눈종이에서 한 칸씩 스티커 붙여봐용
			for (int r = 0; r < N; r++) {
				for (int c = 0; c < M; c++) {
					if (yes) break;
						boolean isCanBatch = true;
						R = sticker.shape.length;
						C = sticker.shape[0].length;
						for (int rr = 0; rr < R; rr++) {
							for (int cc = 0; cc < C; cc++) {
//								System.out.println("r, c" + r + ", " + c  + "여기에 붙일거야ㅐ" + R + ",,, " + C);
								if (sticker.shape[rr][cc] == 0) continue;
								if (r + rr >= N || c + cc >= M) {
									isCanBatch = false;
									break;
								}
								if (arr[r + rr][c + cc] == 1) {
									// 이미 모눈종이에 스티커가 있는 경우엔 배치 불가.
									isCanBatch = false;
									break;
								}
							}
							if (!isCanBatch) break;
						}
						if (isCanBatch) {
							R = sticker.shape.length;
							C = sticker.shape[0].length;
							
							for (int rr = 0; rr < R; rr++) {
								for (int cc = 0; cc < C; cc++) {
									if (r + rr >= N || c + cc >= M) continue;
									if (sticker.shape[rr][cc] == 1) {
										arr[r + rr][c + cc] = 1;							
									}									
								}
							}
							yes = true;					
							break;
						}
					}
				}
				if (yes) break;
				sticker.rotate();
			}
		}
		int cnt = 0;
		for (int rrr = 0; rrr < N; rrr++) {
			for (int ccc = 0; ccc < M; ccc++) {
				if (arr[rrr][ccc] == 1) cnt++;
			} 
		}
		System.out.println(cnt);
	}
}

//System.out.println("배치후~");
//for (int rrr = 0; rrr < N; rrr++) {
//	for (int ccc = 0; ccc < M; ccc++) {
//		System.out.print(arr[rrr][ccc] + " ");
//	} System.out.println("");
//}
//
//
//System.out.println("1차 배치 완료ㅕ");

//sticker.sysout();
//sticker.rotate();
//System.out.println("==1==");
//sticker.sysout();