import java.io.*;

class Solution
{
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

	    int[] maxDays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	    
	    for(int test_case = 1; test_case <= T; test_case++)
		{
			String input = br.readLine();
            String result;
		
            int year = Integer.parseInt(input.substring(0, 4));
            int month = Integer.parseInt(input.substring(4, 6));
            int day = Integer.parseInt(input.substring(6, 8));
            
            if (month >= 1 && month <= 12) {
            	int maxDay = maxDays[month];
            	if (day >= 1 && day <= maxDay) {
            		result = String.format("%04d/%02d/%02d", year, month, day);
            	} else {
            		result = "-1";
            	}
            } else {
            	result = "-1";
            }
            
            System.out.println("#" + test_case + " " + result);
		}
	}
}