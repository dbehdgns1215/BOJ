import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        
        boolean[] isUsed = new boolean[words.length];
        
        Queue<String> q = new LinkedList<>();
        Queue<Integer> depth = new LinkedList<>();
        
        q.add(begin);
        depth.add(0);
        
        while (!q.isEmpty()) {
            String cur = q.poll();
            int d = depth.poll();
            
            if (cur.equals(target)) return d;
            
            for (int i = 0; i < words.length; i++) {
                if (isUsed[i]) continue;
                
                if (is_one_diff(cur, words[i])) {
                    isUsed[i] = true;
                    q.add(words[i]);
                    depth.add(d + 1);
                }
            }
        }
        
        return 0;
    }
    
    public boolean is_one_diff(String cur, String word) {
        int diff = 0;
        for (int i = 0; i < cur.length(); i++) {
            if (cur.charAt(i) != word.charAt(i)) diff++;
            if (diff > 1) break;
        }
        return diff == 1;
    }
}