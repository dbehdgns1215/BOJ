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
			
			calc(1);
			
			if (dp[12] > tickPrice[3]) {
				dp[12] = tickPrice[3];
			}
			
//			System.out.println(dp[1]);
//			System.out.println(dp[2]);
//			System.out.println(dp[3]);
//			System.out.println(dp[4]);
//			System.out.println(dp[5]);
//			System.out.println(dp[6]);
//			System.out.println(dp[7]);
//			System.out.println(dp[8]);
//			System.out.println(dp[9]);
//			System.out.println(dp[10]);
//			System.out.println(dp[11]);
//			System.out.println(dp[12]);
			sb.append("#").append(test_case).append(" ").append(dp[12]).append("\n");
		}
		System.out.print(sb);
	}
	private static void calc(int curMonth) {
		if (curMonth == 13) {
			return;
		}
		
		int optiamlPrice = dp[curMonth - 1] + Math.min(tickPrice[0] * monthCnt[curMonth], tickPrice[1]);
		
		if (curMonth >= 3) { 
			optiamlPrice = Math.min(optiamlPrice, dp[curMonth - 3] + tickPrice[2]);
		}
		
//		System.out.println(curMonth + "월 : " + optiamlPrice);
		dp[curMonth] = optiamlPrice;
		
		calc(curMonth + 1);
	}
}
