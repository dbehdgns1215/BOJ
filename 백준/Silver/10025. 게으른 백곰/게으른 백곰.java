import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		
		int[] arr = new int[3000001];
//		int[] arr = new int[1000001];
		// 배열 인덱스 관련한 런타임 에러 계속 났음
		// 백곰이 만약, 1,000,000에 위치해 있고, 백곰의 이동 반경인 K가 2,000,000 일 경우가 존재하기 때문인듯
		
		
		int maxIdx = 0;
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int ice = Integer.parseInt(st.nextToken());
			int idx = Integer.parseInt(st.nextToken());
			maxIdx = Math.max(maxIdx, idx);
			arr[idx] = ice;
		}
		
		int maxSum = 0;
		int sum = 0;
		
		// 백곰이 x에 위치한다고 하면, [x - K, x + K]의 구간을 탐색할 수 있음. -> 2K + 1
		// 최초의 2K + 1 만큼의 합을 구한 뒤, 슬라이딩 윈도우를 진행시키면 됨.
		int searchLen = (K * 2) + 1;
		for (int i = 0; i < searchLen; i++) {
			if (i >= arr.length) break; // 안전 장치?.. 왜 자꾸 배열 인덱스 초과 에러가 뜰까
			sum += arr[i];
		}
		maxSum = Math.max(maxSum, sum);
		
		for (int i = searchLen; i <= maxIdx; i++) { // maxIdx는 실제 인덱스니까 포함 시켜야 함.
			if (i >= arr.length) break; 
			sum += arr[i] - arr[i - searchLen];
            maxSum = Math.max(maxSum, sum);
		}
		
		System.out.println(maxSum);
	}
}
