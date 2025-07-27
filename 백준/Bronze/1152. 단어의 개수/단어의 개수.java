import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	/*
	 * 문자열, 객체 값 비교 → .equals() 사용
	 * 기본형(int, double 등) 비교 → == 사용
	 * 참조(같은 객체인지) 확인 → == 사용
	 * 
	 * .trim() → 문자열의 앞 뒤의 공백을 제거 trim 후 split 가능.
	 */
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		String[] sentence = br.readLine().trim().split(" ");
		
		if (sentence[0].equals("")) { // 공백 문자열만 입력된 경우 처리
			System.out.println(sentence.length - 1); // 일반적인 문장의 경우, 이 코드 블럭 내로 들어올 수 없음. -> trim을 사용했기 떄문.
		}
		else {
			System.out.println(sentence.length);
		}
	}
}
