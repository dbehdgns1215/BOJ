import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
    static int minSum;
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
         
        for (int test_case = 1; test_case <= T; test_case++) {
            int[] price = new int[4];
            int[] month = new int[12];
             
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 4; i++) {
                price[i] = Integer.parseInt(st.nextToken());
            }
             
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 12; i++) {
                month[i] = Integer.parseInt(st.nextToken());
            }
             
            minSum = price[3];
            dfs(0, price, month, 0);
             
            StringBuilder sb = new StringBuilder();
            sb.append("#").append(test_case).append(" ").append(minSum);
            System.out.println(sb);
        }
    }
 
 
    private static void dfs(int idx, int[] price, int[] month, int sum) {
        int idxSuffix = 1;
        if (idx == 12) {
            minSum = Math.min(minSum, sum);
            return;
        }
     
//      if (month[idx] == 0) {
//          dfs(idx + 1, price, month, sum);
//          return;
//      }
        // 위 최적화는, 3개월 권의 특성상 위험한 최적화임.
        // 예를 들어, 7월, 8월, 9월이 3개월을 썼을 때, 그리고 10, 11, 12도 3개월 권을 쓰는 게 최적해라면
        // 만약 7월 이용 횟수가 0번이면 위 로직에 따라 다음 달로 넘어가서 3개월 권을 사용하게 되니까
        // 11월, 12월 같은 경우에는 한달 권밖에 사용할 수 없음.
        // 결론적으로는 불필요한 최적화
         
        if (minSum <= sum) return;
         
        for (int i = 2; i >= 0; i--) {
            if (i == 2) {
                if (idx > 9) continue;
                idxSuffix = 3;
                sum += price[i];
            } else if (i == 1) {
                sum += price[i];
            } else {
                int sumCal = month[idx] * price[i];
                sum += sumCal;
            }
             
            dfs(idx + idxSuffix, price, month, sum);
             
            if (i == 2) {
                idxSuffix = 1;
                sum -= price[i];
            } else if (i == 1) {
                sum -= price[i];
            } else {
                int sumCal = month[idx] * price[i];
                sum -= sumCal;
            }
        }
    }
}