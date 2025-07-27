import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static int[] timeTable;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		timeTable = new int[] {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

		String num = br.readLine();
		
		int time = 0;
		for (int i = 0; i < num.length(); i++) {
			time += timeTable[num.charAt(i) - 'A'];
		}
		System.out.println(time);
	}

}
