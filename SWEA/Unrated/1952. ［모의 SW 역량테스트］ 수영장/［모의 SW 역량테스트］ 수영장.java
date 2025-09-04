import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static int[] tickPrice;
	static int[] monthCnt;
	static int[] dp;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		
		for (int test_case = 1; test_case <= T; test_case++) {
			tickPrice = new int[4];
			monthCnt = new int[13];
			dp = new int[13];
			
			st = new StringTokenizer(br.readLine()); 
			for (int i = 0; i < 4; i++) {
				tickPrice[i] = Integer.parseInt(st.nextToken());
			}
			
			st = new StringTokenizer(br.readLine()); 
			for (int i = 1; i <= 12; i++) {
				monthCnt[i] = Integer.parseInt(st.nextToken());
			}
			
			calc();
			
			if (dp[12] > tickPrice[3]) {
				dp[12] = tickPrice[3];
			}
			
			sb.append("#").append(test_case).append(" ").append(dp[12]).append("\n");
		}
		System.out.print(sb);
	}
	private static void calc() {
		for (int curMonth = 1; curMonth < 13; curMonth++) {			
			// 현재 달의 최적해 정의 -> 바로 이전달의 최적해 + 1일권 or 1달권
			int optiamlPrice = dp[curMonth - 1] + Math.min(tickPrice[0] * monthCnt[curMonth], tickPrice[1]);
			
			// 3월 이상부터는 이전 3달과 3달권을 비교해서 최적해 갱신
			if (curMonth >= 3) { 
				optiamlPrice = Math.min(optiamlPrice, dp[curMonth - 3] + tickPrice[2]);
			}
			
			// 현재 달에 방금 구한 최적해 갱신
			dp[curMonth] = optiamlPrice;
		}
	}
}
