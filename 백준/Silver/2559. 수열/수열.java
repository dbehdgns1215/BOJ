import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int window;
	static int[] arr;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		arr = new int[N];
		
		st = new StringTokenizer(br.readLine());
		
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		int maxSum = Integer.MIN_VALUE;
		for (int i = 0; i < K; i++) {
			window += arr[i];
		}
		maxSum = Math.max(maxSum, window);
		
		for (int i = 0; i < N - K; i++) {
			window -= arr[i];
			window += arr[K + i];
			maxSum = Math.max(maxSum, window);
		}
		
		System.out.println(maxSum);
	}
}
