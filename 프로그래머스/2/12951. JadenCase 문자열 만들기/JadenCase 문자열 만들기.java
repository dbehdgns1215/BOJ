import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        StringBuilder sb = new StringBuilder();
        boolean isUp = false;
        boolean skip = false;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                skip = false;
                sb.append(' ');
                continue;
            }
            if (skip) {
                sb.append(Character.toLowerCase(s.charAt(i)));
                continue;
            }
            sb.append(Character.toUpperCase(s.charAt(i)));
            skip = true;            
        }
        
        return sb.toString();
    }
}