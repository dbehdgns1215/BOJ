import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static String[] line;
	static int T;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			StringBuilder sb = new StringBuilder();
			
			line = br.readLine().split(" ");
			
			int R = Integer.parseInt(line[0]);
			String sentence = line[1];
			
			
			for (int i = 0; i < sentence.length(); i++) {
				for (int j = 0; j < R; j++) {
					sb.append(sentence.charAt(i));
				}
			}
			
			System.out.println(sb);
		}
	}
}
