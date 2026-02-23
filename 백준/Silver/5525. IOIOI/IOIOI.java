import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		String S = br.readLine();
		
//		System.out.println(N + " , " + M + " , " + S);
		
		int cnt_i = 0;
		int cnt_o = 0;
		int ans = 0;
		
		for (int i = 0; i < S.length(); i++) {
			if (S.charAt(i) == 'I') {
				if (cnt_i == cnt_o) {
					cnt_i++;					
				} else {
					cnt_i = 1;
					cnt_o = 0;
				}
			} else {
				if (cnt_i - cnt_o == 1) {
					cnt_o++;
				} else {
					cnt_i = 0;
					cnt_o = 0;
				}
			}
			
			if ( (N + 1) == cnt_i && (N) == cnt_o) {
				ans++;
				cnt_i--;
				cnt_o--;
			}
		}
		
		System.out.println(ans);

	}

}
