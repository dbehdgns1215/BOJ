import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 5 -> 1 1 3, 1 1 1 1 1, 3 1 1, 1 3 1

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        
        // 돌이 i개일 때, 상근 or 창영의 승패 테이블
        boolean dp[] = new boolean[N + 1];
        
        dp[1] = true;
        
        if (N >= 2) dp[2] = false;
        if (N >= 3) dp[3] = true;
        if (N >= 4) dp[4] = false;
        
        if (N >= 5) {
            for (int i = 5; i <= N; i++) {
            	if (!dp[i - 1]) {
            		dp[i] = true;
            	}
            	
            	if (!dp[i - 3]) {
            		dp[i] = true;
            	}
            }
        }

        
        if (dp[N]) {
        	System.out.print("SK");
        } else {
        	System.out.print("CY");
        }
	}
}