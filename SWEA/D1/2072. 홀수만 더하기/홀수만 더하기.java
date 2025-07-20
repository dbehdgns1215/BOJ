import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;


class Solution
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt((br.readLine()));
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
			String[] numbers = br.readLine().split(" ");
			int sum = 0;
			
			for (String number : numbers) {
                int num = Integer.parseInt(number);
                if (num % 2 == 1) {
                    sum += num;
                }
            }
			
			bw.write("#" + test_case + " " + sum + "\n");
			bw.flush();
		}
	}
}