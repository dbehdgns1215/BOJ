import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int[] alpha;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		alpha = new int[26]; // 0 ~ 25
		
		for (int i = 0; i < 26; i++) { // 0 ~ (N - 1)
			alpha[i] = -1;
		}
		
		String sentence = br.readLine();
		
		for (int i = 0; i < sentence.length(); i++) { // 0 ~ (N - 1)
			if (alpha[sentence.charAt(i) - 'a'] >= 0) {
				continue;
			} else {
				alpha[sentence.charAt(i) - 'a'] = i; 
			}
			
		}

		for (int a : alpha) {
			System.out.print(a + " ");
		}
	}

}