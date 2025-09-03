import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @link: https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AZgruskKCQnHBIT9&contestProbId=AWT-lPB6dHUDFAVT&probBoxId=AZkNTvgayUrHBITM+&type=PROBLEM&problemBoxTitle=0903&problemBoxCnt=++2+
 * @performance:
 * @note:
 * @timecomplex: 
 */
public class Solution {
	static int N;
	static int L;
    static int[] score;
    static int[] kcal;
    static int[][] memo; // memo[i][c] = i부터, 남은 칼로리 c에서 최대 맛 점수. -1 -> 미계산

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            st = new StringTokenizer(br.readLine());
            
            N = Integer.parseInt(st.nextToken()); // 재료 수
            L = Integer.parseInt(st.nextToken()); // 최대 칼로리
            score = new int[N]; // 맛 점수들
            kcal = new int[N];  // 칼로리들
            
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                score[i] = Integer.parseInt(st.nextToken());
                kcal[i] = Integer.parseInt(st.nextToken());
            }
            
            memo = new int[N][L + 1]; // 각 재료마다 
            
            for (int i = 0; i < N; i++) Arrays.fill(memo[i], -1);
            
            int ans = dp(0, L);
            
            sb.append('#').append(test_case).append(' ').append(ans).append('\n');
        }
        System.out.print(sb);
    }
    
    static int dp(int idx, int maxKcal) {
        if (idx == N) return 0;
        
        if (memo[idx][maxKcal] != -1) return memo[idx][maxKcal];

        // idx번째 재료 사용 X
        int temp = dp(idx + 1, maxKcal);
        
        if (kcal[idx] <= maxKcal) {
        	// idx번째 재료 사용 O
        	// idx번째 재료를 사용했다? -> idx번째 재료 점수 + idx번째 재료를 사용한 분기의 반환 값
        	temp = Math.max(temp, score[idx] + dp(idx + 1, maxKcal - kcal[idx]));
        }
        
        return memo[idx][maxKcal] = temp; // idx 번째 재료에 대한 최적해 (사용했을 수도, 안했을 수도 있음.) 단, 유무와 관계 없이 현재 상황에서의 최적해임이 보장 됨.
    }
}
