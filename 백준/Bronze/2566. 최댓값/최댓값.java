import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static int[][] arr;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		arr = new int[9][9];
		
		int maxNum = 0;
		int maxX = 0;
		int maxY = 0;
		
		for (int i = 0; i < 9; i++) {
			String[] line = br.readLine().split(" ");
			for (int j = 0; j < 9; j++) {
				arr[i][j] = Integer.parseInt(line[j]);
				if (maxNum < arr[i][j]) {
					maxNum = arr[i][j];
					maxX = j;
					maxY = i;
				}
			}
		}
		
		System.out.println(maxNum);
		System.out.println((maxY + 1) + " " + (maxX + 1));
		
	}

}
