import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		int[] grading = {100, 100, 200, 200, 300, 300, 400, 400, 500};
		int sum = 0;
		boolean isHacker = false;
		for (int i = 0; i < 9; i++) {
			int score = Integer.parseInt(st.nextToken());
			
			if (score > grading[i]) {
				sb.append("hacker");
				isHacker = true;
				sum += score;
				break;
			} else {
				sum += score;
			}
		}
		
		if (sum < 100) {
			sb.append("none");
		} else if (sum >= 100 && !isHacker) {
			sb.append("draw");
		}
		
		System.out.println(sb);
	}

}
