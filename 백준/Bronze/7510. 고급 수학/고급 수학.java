import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		
		for (int i = 1; i <= N; i++) {
			sb.append("Scenario #").append(i).append(":").append("\n");
			st = new StringTokenizer(br.readLine());
			int maxNum = -1;
			int maxNumIdx = -1;
			int a = Integer.parseInt(st.nextToken());
			if (a > maxNum) {
				maxNum = a;
				maxNumIdx = 0;
			}
			int b = Integer.parseInt(st.nextToken());
			if (b > maxNum) {
				maxNum = b;
				maxNumIdx = 1;
			}
			int c = Integer.parseInt(st.nextToken());
			if (c > maxNum) {
				maxNum = c;
				maxNumIdx = 2;
			}
			
			int arr[] = {a, b, c};
			
			if (maxNumIdx == 0) {
				int sum = (int) (Math.pow(arr[1], 2) + Math.pow(arr[2], 2));
				if (Math.pow(maxNum, 2) == sum) {
					sb.append("yes");
				} else {
					sb.append("no");
				}
			} else if (maxNumIdx == 1) {
				int sum = (int) (Math.pow(arr[0], 2) + Math.pow(arr[2], 2));
				if (Math.pow(maxNum, 2) == sum) {
					sb.append("yes");
				} else {
					sb.append("no");
				}
			} else {
				int sum = (int) (Math.pow(arr[0], 2) + Math.pow(arr[1], 2));
				if (Math.pow(maxNum, 2) == sum) {
					sb.append("yes");
				} else {
					sb.append("no");
				}
			}
			
			sb.append("\n\n");
		}
		
		System.out.println(sb);
	}

}
