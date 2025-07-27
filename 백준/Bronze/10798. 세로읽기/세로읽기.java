import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static String[] lines;
	static StringBuilder sb;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		lines = new String[5];
		int maxLen = 0;

		for (int i = 0; i < 5; i++) {
			lines[i] = br.readLine();
			maxLen = Math.max(maxLen, lines[i].length());
		}

		sb = new StringBuilder();


		for (int j = 0; j < maxLen; j++) {
			for (int i = 0; i < 5; i++) {
				if (j < lines[i].length()) { // **.length() -> 길이 반환 -> idx 사용 시에는 -1 해야함을 명심 (Zero-Index) -> 가능한 경우 j(idx: 2) < 길이 3(idx: 2) / 불가능 j(idx: 2) < 길이 2(idx: 1)
					sb.append(lines[i].charAt(j));
				}
			}
		}

		System.out.println(sb);
	}
}