import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N; // 색종이의 수
	static int[][] arr;
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		arr = new int[100][100];
		
		N = Integer.parseInt(br.readLine());
		
		for (int cnt = 0; cnt < N; cnt++) {
			st = new StringTokenizer(br.readLine());
			
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			for (int i = y; i < 10 + y; i++) {
				for (int j = x; j < 10 + x; j++) {
					arr[i][j] = 1;
				}
			}
		}
		
		int width = 0;
		for (int i = 0; i < 100 ; i++) {
			for (int j = 0; j < 100; j++) {
				if (arr[i][j] == 1) {
					width++;
				}
			}
		} 
		System.out.println(width);
	}
}
