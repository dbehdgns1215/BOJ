import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < N; i++) {
			String tag = br.readLine();
			
			ArrayDeque<Character> dq = new ArrayDeque<>();
			
			boolean flag = false;
			for (int j = 0; j < tag.length(); j++) {
				if (tag.charAt(j) == '(') {
					dq.addLast(tag.charAt(j));					
				} else {
					if (!dq.isEmpty()) {
						dq.pollLast();
					} else {
						sb.append("NO\n");
						flag = true;
						break;
					}
				}
			}
			
			if (!flag && dq.isEmpty()) {
				sb.append("YES\n");				
			} else if (!flag && !dq.isEmpty()){
				sb.append("NO\n");
			}
		}
		
		System.out.println(sb.toString());
	}
}
